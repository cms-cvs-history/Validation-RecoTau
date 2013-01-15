#!/usr/bin/env cmsRun

import shutil
import sys

from Validation.RecoTau.ValidationOptions_cff import *

process = cms.Process("TEST")

# command options defined in Validation/RecoTau/python/ValidationOptions_cfi
options.parseArguments()

checkOptionsForBadInput()

## if not calledBycmsRun() and not options.gridJob:
##    print "Run 'cmsRun RunTauValidation_cfg.py help' for options."
##    # quit here so we dont' create a bunch of directories
##    #  if the user only wants the help
##    sys.exit()

# Make sure we dont' clobber another directory! Skip in batch mode (runs from an LSF machine)
if not CMSSWEnvironmentIsCurrent() and options.batchNumber == -1 and not options.gridJob:
   print "CMSSW_BASE points to a different directory, please rerun cmsenv!"
   sys.exit()


# DQM store, PDT sources etc
process.load("Configuration.StandardSequences.Services_cff")

######################################
#                                    #
#       Output Info Store            #
#                                    #
######################################

"""
   Data is stored in

   TauID/[EventType]_[DataSource]_[Conditions][label]

"""

#outputDirName = "Validation_%s" % ReleaseVersion
outputDirName = "TauID"


outputDir = os.path.join(os.getcwd(), outputDirName) 
# This is the directory where we store the stuff about our current configuration
outputBaseDir = outputDir

subDirName = ""

subDirName += "%s_%s" % (options.eventType, options.dataSource)

if options.conditions != "whatever":
   subDirName += "_%s" % options.conditions.replace('::', '_')

if (options.label != "none"):
   subDirName += "_" + options.label

outputDir = os.path.join(outputDir, subDirName)

# Store configuration, showtags, etc in a sub directory
configDir = os.path.join(outputDir, "Config")

if os.path.exists(outputDir) and options.batchNumber < 0:# and not options.gridJob:
   print "Output directory %s already exists!  OK to overwrite?" % outputDir
   while True:
      input = raw_input("Please enter [y/n] ")
      if (input == 'y'):
         break
      elif (input == 'n'):
         print " ...exiting."
         sys.exit()

if not os.path.exists(outputDir):
   os.makedirs(outputDir)

if not os.path.exists(configDir):
   os.makedirs(configDir)

######################################
#                                    #
#       Data Source Setup            #
#                                    #
######################################

def LoadDataCffFile(theFile):
   outputFileName = os.path.join(configDir, "DataSource_cff.py")
   process.load(theFile)
   outputFile = open(outputFileName,'w')
   outputFile.write('import FWCore.ParameterSet.Config as cms\n')
   outputFile.write('source = %s\n'%process.source)

myFile = options.sourceFile
if myFile == 'none':
   myFile = "Validation.RecoTau.sources.EventSource_%s_RECO_cff" % options.eventType
   #myFile = os.path.join(ReleaseBase, "Validation/RecoTau/test", "EventSource_%s_RECO_cff.py" % options.eventType)
LoadDataCffFile(myFile)
#Reruns PFTau
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")

process.GlobalTag.globaltag = options.conditions

# have to set max events here, since it may get written by the 
# dataSource cffs
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(options.maxEvents)
)

# Skip events, if we are running in batch mode on files
if options.batchNumber >= 0 and options.dataSource.find('Files') != -1:
   process.source.skipEvents = cms.untracked.uint32(options.batchNumber*options.maxEvents)

######################################
#                                    #
#       Validation Setup             #
#                                    #
######################################

# Store the tags and CVS diff to the tags, and the current release
#  only do this once in a batch job.  The additional tar file is a fail safe - 
#  the parameters shouldn't change in outputDir.
if (options.batchNumber <= 0 ):#and not options.gridJob):
   os.system("cd $CMSSW_BASE/src; \
              showtags -t -r > showtags.txt; \
              cvs -q diff >& diffToTags.patch;\
              cvs -q diff -r %s >& diffToVanillaRelease.patch; \
              tar -cvzf TagsAndDiff.tar.gz showtags.txt *.patch; \
              mv showtags.txt *.patch %s; \
              mv TagsAndDiff.tar.gz %s" % (ReleaseVersion, configDir, configDir))

if options.batchNumber >= 0:
   # store the batch produced root files in a sub directory
   outputDir = os.path.join(outputDir, "BatchJobs")
   if not os.path.exists(outputDir):
      os.mkdir(outputDir)

#Validation output file
outputFileNameBase = "TauVal_%s" % ReleaseVersion
if options.label != "none":
   outputFileNameBase += "_%s" % options.label
outputFileNameBase += "_"
outputFileNameBase += options.eventType

if options.batchNumber >= 0:
   outputFileNameBase += "_%i" % options.batchNumber
   options.writeEDMFile = options.writeEDMFile.replace(".root", "_%i.root" % options.batchNumber)
outputFileNameBase += "_DBScan.root"

if options.gridJob:
   outputFileName = 'TauVal_GridJob.root'
else:
   outputFileName = os.path.join(outputDir, outputFileNameBase)

print 'The output file will be: '+outputFileName
if options.gridJob:
   cfg=open('./crab.cfg', 'r')
   cfgContent=cfg.read()
   if cfgContent.find(outputFileName) == -1:
      print "ERROR: CRAB output file not matching the grid one!\nexiting..."
      sys.exit()

process.saveTauEff = cms.EDAnalyzer("TauDQMSimpleFileSaver",
  outputFileName = cms.string(outputFileName)
)

process.load("Validation.RecoTau.dataTypes.ValidateTausOn%s_cff" % options.eventType)

process.validation = cms.Sequence(
   process.PFTau*
   process.produceDenominator *
   process.runTauValidationBatchMode #in batch mode, the efficiencies are not computed - only the num/denom
  )

import PhysicsTools.PatAlgos.tools.helpers as helpers
process.study = cms.Sequence()

postfix = 'plainNewDecayMode'
print 'applying postif: '+postfix
helpers.cloneProcessingSnippet( process, process.validation, postfix)
assert( hasattr(process,'validation%s'%(postfix) ) )
assert( hasattr(process,'hpsPFTauDiscriminationByVLooseIsolation%s'%(postfix) ) )
print 'combinatoricRecoTaus%s'%(postfix) in dir(process)
assert( getattr(process, 'combinatoricRecoTaus%s'%(postfix)).builders[0].qualityCuts.vertexTrackFiltering == cms.bool(True) )
assert( getattr(process, 'ak5PFJetsLegacyHPSPiZeros%s'%(postfix)).builders[0].qualityCuts.vertexTrackFiltering == cms.bool(True) )
assert( hasattr(process, 'RunHPSValidation%s%s'%(options.eventType, postfix))  )
for entry in getattr(process, 'RunHPSValidation%s%s'%(options.eventType, postfix)).discriminators:
   entry.discriminator = entry.discriminator.value() + postfix
process.study += getattr(process,'validation%s'%(postfix) )

postfix = 'vtxFilterOnPvFindAlgoOld'
print 'applying postif: '+postfix
helpers.massSearchReplaceParam(process.PFTau,'pvFindingAlgo',cms.string("combined"),cms.string("highestWeightForLeadTrack"),True) 
helpers.cloneProcessingSnippet( process, process.validation, postfix)
assert( hasattr(process,'validation%s'%(postfix) ) )
assert( hasattr(process,'hpsPFTauDiscriminationByVLooseIsolation%s'%(postfix) ) )
assert( getattr(process, 'combinatoricRecoTaus%s'%(postfix)).builders[0].qualityCuts.vertexTrackFiltering == cms.bool(True) )
assert( getattr(process, 'ak5PFJetsLegacyHPSPiZeros%s'%(postfix)).builders[0].qualityCuts.vertexTrackFiltering == cms.bool(True) )
assert( hasattr(process, 'RunHPSValidation%s%s'%(options.eventType, postfix))  )
for entry in getattr(process, 'RunHPSValidation%s%s'%(options.eventType, postfix)).discriminators:
   entry.discriminator = entry.discriminator.value() + postfix
process.study += getattr(process,'validation%s'%(postfix) )

postfix = 'vtxFilterOffPvFindAlgoNew'
print 'applying postif: '+postfix
helpers.massSearchReplaceParam(process.PFTau,'pvFindingAlgo',cms.string("highestWeightForLeadTrack"),cms.string("combined"),True) 
helpers.massSearchReplaceParam(process.PFTau,'vertexTrackFiltering',cms.bool(True),cms.bool(False),True) 
helpers.cloneProcessingSnippet( process, process.validation, postfix)
assert( hasattr(process,'validation%s'%(postfix) ) )
assert( hasattr(process,'hpsPFTauDiscriminationByVLooseIsolation%s'%(postfix) ) )
assert( getattr(process, 'combinatoricRecoTaus%s'%(postfix)).builders[0].qualityCuts.vertexTrackFiltering == cms.bool(True) )
assert( getattr(process, 'ak5PFJetsLegacyHPSPiZeros%s'%(postfix)).builders[0].qualityCuts.vertexTrackFiltering == cms.bool(True) )
assert( hasattr(process, 'RunHPSValidation%s%s'%(options.eventType, postfix))  )
for entry in getattr(process, 'RunHPSValidation%s%s'%(options.eventType, postfix)).discriminators:
   entry.discriminator = entry.discriminator.value() + postfix
process.study += getattr(process,'validation%s'%(postfix) )


#process.validation *= process.saveTauEff #save the output

process.studyPath = cms.Path(process.study)
process.savePath  = cms.Path(process.saveTauEff)

process.schedule = cms.Schedule()
process.schedule.append(process.studyPath)
process.schedule.append(process.savePath)

process.load("RecoTauTag.Configuration.RecoTauTag_EventContent_cff")

TauTagValOutputCommands = cms.PSet(
      outputCommands = cms.untracked.vstring('drop *',
         'keep recoPFCandidates_*_*_*',
         'keep *_genParticles*_*_*',
         'keep *_iterativeCone5GenJets_*_*',
         'keep *_tauGenJets*_*_*',
         'keep *_selectedGenTauDecays*_*_*'
         )
      )

TauTagValOutputCommands.outputCommands.extend(process.RecoTauTagRECO.outputCommands)

######################################
#                                    #
#       CFG dump                     #
#                                    #
######################################
#process.Timing = cms.Service("Timing",
#         useJobReport = cms.untracked.bool(True)
#	 )
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
#         useJobReport = cms.untracked.bool(True)
#	 )

processDumpFile = open('VtxTest.py','w')
print >> processDumpFile, process.dumpPython()
#if grid job end here
## if not options.gridJob:

##    dumpFileName = "cfgDump"
##    if options.batchNumber >= 0:
##       dumpFileName += "_"
##       dumpFileName += str(options.batchNumber)
      
##    dumpFileName += ".py"
   
##    processDumpFile = open('%s/%s' % (configDir, dumpFileName), 'w')
   
##    print >> processDumpFile, process.dumpPython()

