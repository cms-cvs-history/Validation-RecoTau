#!/usr/bin/env python

# Script to submit Tau Validation FastSim jobs to lxbatch
#  Author: Evan Friis evan.klose.friis@cern.ch
import sys
import os
import time
import random

def printHelp():
   print ""
   print sys.argv[0]
   print "------------------------------------------------------------------------------------------------------------"
   print "Description: Submit signal and background jobs (as described by GenerateAndValidateEvents_cfg) to lxbatch."
   print ""
   print "Usage: ./SubmitFastSimValidationLxplus.py EventType nEventsPerJob nJobs label edmFileOutput castorLocation"
   print "      EventType:      If 'signal', generate Ztautau (all hadronic) events with tauola.  If 'background', generate QCD FlatPt15_3000 events"
   print "      nEventsPerJob   Events per job"
   print "      nJobs:          Jobs to submit  (total events = nEventsPerJob*nJobs)"
   print "      label:          Apply label to output validation files - e.g. 'CMSSW_3_1_0'"
   print "      emdFileOutput   Write EDM content to root file.  e.g. ./myFile.root  Appropriate batch numbers and sig/bkg labels will be automatically added. "
   print "      castorLocation  Directory in castor to copy EDM content.  Optional, your user directory will be used if not included "
   print ""

if len(sys.argv) < 5:
   printHelp()
   sys.exit()

isSignal = sys.argv[1]
nEvents  = int(sys.argv[2])
nJobs    = int(sys.argv[3])
label    = sys.argv[4]
edmOut   = ""
castorLocation = ""
if len(sys.argv) > 5:
   edmOut   = sys.argv[5]
   if len(sys.argv) > 6:
      castorLocation = sys.argv[6]
   else:
      castorLocation = "/castor/cern.ch/user/%s/%s/" % (os.environ["LOGNAME"][0], os.environ["LOGNAME"])

if castorLocation != "":
   checkCastor = os.system("nsls %s" % castorLocation)
   if checkCastor:
      print "Error: castor reports on error on checking the supplied castor location: ", castorLocation
      sys.exit()
#sanity check
if isSignal != 'signal' and isSignal != 'background':
   printHelp()
   print "Error: EventType parameter must be 'signal' or 'background' (no quotes)."
   sys.exit()
if nEvents == 0 or nJobs == 0:
   printHelp()
   print "Error: nEvents or nJobs is zero."
   sys.exit()

SignalFlag = 1
if isSignal == 'signal':
   SignalFlag = 1
elif isSignal == 'background':
   SignalFlag = 0

print "" 
print "I'm going to submit %i %s jobs, each with %i events, for a total of %i events" % (nJobs, isSignal, nEvents, nJobs*nEvents)

if edmOut != "":
   print "EDM files with the prefix %s will be produced and stored in %s" % (edmOut, castorLocation)
print "Hit Ctrl-c in the next 2 secons to cancel..."
try:
   time.sleep(2)
except KeyboardInterrupt:
   print "Canceled, exiting."
   sys.exit()
print "Submitting jobs..."

for iJob in xrange(0, nJobs):
   preventCollision = random.randint(0, 10000000000)
   setupCommands  = "cd $PWD; scramv1 runtime -sh > tempEnvs_%i; source tempEnvs_%i; rm tempEnvs_%i; cd -; mkdir toCopyToCastor;" % (preventCollision,preventCollision,preventCollision)
   cmsRunCommand  = "cmsRun $PWD/GenerateAndValidateEvents_cfg.py maxEvents=%i isSignal=%i batchNumber=%i " % (nEvents, SignalFlag, iJob)
   edmFileCommands = ""
   if edmOut != "":
      edmFileCommands = "writeEDMFile=toCopyToCastor/%s; rfcp toCopyToCastor/*.root %s;" % (edmOut, castorLocation)
   cleanupCommand = "cp *.root $PWD; "

   totalCommand = setupCommands + cmsRunCommand + edmFileCommands + cleanupCommand
   bsubCommand  = "bsub -J %s_%i -q 1nh \"%s\"" % (isSignal, iJob, totalCommand)
   os.system(bsubCommand)

