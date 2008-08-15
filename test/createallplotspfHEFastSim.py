#!usr/bin/env python

import os
import sys
import string

print "Creating all directories and subdirectories.\n"

currentdirectory = os.curdir
rootfilespftautagHEFastSim = 0
releaseversion = ""

absolutepath = os.path.abspath('')
pathparts = absolutepath.split("/")

print absolutepath, pathparts , len(sys.argv)

for pathpart in pathparts:
   if string.find(pathpart,"MSSW_") > 0:
       releaseversion = pathpart

if len(sys.argv) == 2:
   filenames = os.listdir(os.curdir)
else:
   print
   print 'Usage: ' + sys.argv[0] + ' Release that you would like to compare with'
   print 'e.g.:  ' + sys.argv[0] + ' CMSSW_1_7_0'
   print
   
   sys.exit()
   
for filename in filenames:
   if string.find(filename,".root") > 0:
       print "Are we ever here? ", filename, "\n"
       
       if string.find(filename,"ftautagHEFastSim_CMSSW") > 0:
           print "pftautagHEFastSim_CMSSW\n"
           rootfilespftautagHEFastSim = rootfilespftautagHEFastSim + 1
           
print " ", rootfilespftautagHEFastSim ," ", releaseversion

comparisonrelease= sys.argv[1]

comparisonpath = absolutepath.replace(releaseversion, comparisonrelease)
 
if rootfilespftautagHEFastSim == 1:
    os.system("mkdir pftautagHEFastSim")
    os.system("mkdir pftautagHEFastSim/OneProngAndThreeProng")

    rootfilename = "pftautagHEFastSim_" + releaseversion + "_OneProngAndThreeProng_PFTAU.root"
    comparisonpath = comparisonpath + "/pftautagHE_" + comparisonrelease + "_OneProngAndThreeProng_PFTAU.root"
    print rootfilename

    command = "root -b -q \'pftautag_allplots.C( \""  \
               + rootfilename + "\" , \"" \
               + comparisonpath + "\" , \"" \
               + releaseversion + "\" ,\""  \
               + comparisonrelease + "\" ,\""  \
                "OneProngAndThreeProng\" )\'"  
    print command

    os.system(command)

    os.system("mv *png pftautagHEFastSim/OneProngAndThreeProng")
    print command


    


    
