#!usr/bin/env python

import os
import sys
import string

print "Creating all directories and subdirectories.\n"

currentdirectory = os.curdir
rootfilespftautag = 0
rootfilespftautagHE = 0
rootfilestautag = 0
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
       
       if string.find(filename,"ftautag_CMSSW") > 0:
           print "pftautag_CMSSW\n"
           rootfilespftautag = rootfilespftautag + 1

       elif string.find(filename,"autag_CMSSW") > 0:
           rootfilestautag = rootfilestautag + 1
           print "tautag_CMSSW\n"
           
       elif string.find(filename,"ftautagHE_CMSSW") > 0:
           rootfilespftautagHE = rootfilespftautagHE + 1
           print "pftautagHE_CMSSW\n"
           
print rootfilestautag," ", rootfilespftautag, " ", rootfilespftautagHE ," ", releaseversion

comparisonrelease= sys.argv[1]

comparisonpath = absolutepath.replace(releaseversion, comparisonrelease)
 
if rootfilespftautag == 3:
    os.system("mkdir pftautag")
    os.system("mkdir pftautag/OneProngAndThreeProng")
    os.system("mkdir pftautag/OneProng")
    os.system("mkdir pftautag/ThreeProng")
    rootfilename = "pftautag_" + releaseversion + "_OneProngAndThreeProng_PFTAU.root"
    comparisonpath = comparisonpath + "/pftautag_" + comparisonrelease + "_OneProngAndThreeProng_PFTAU.root"
    print rootfilename

    command = "root -b -q \'pftautag_allplots.C( \""  \
               + rootfilename + "\" , \"" \
               + comparisonpath + "\" , \"" \
               + releaseversion + "\" ,\""  \
               + comparisonrelease + "\" ,\""  \
                "OneProngAndThreeProng\" )\'"  
    print command

    os.system(command)

    os.system("mv *png pftautag/OneProngAndThreeProng")
    comparisonpath = ""
    comparisonpath = absolutepath.replace(releaseversion, comparisonrelease)
    rootfilename = "pftautag_" + releaseversion + "_OneProng_PFTAU.root"
    comparisonpath = comparisonpath + "/pftautag_" + comparisonrelease + "_OneProng_PFTAU.root"
    print rootfilename

    command = "root -b -q \'pftautag_allplots.C( \""  \
               + rootfilename + "\" , \"" \
               + comparisonpath + "\" , \"" \
               + releaseversion + "\" ,\""  \
               + comparisonrelease + "\" ,\""  \
                "OneProng\" )\'"  
    print command


    os.system(command)

    os.system("mv *png pftautag/OneProng")
    comparisonpath = ""
    comparisonpath = absolutepath.replace(releaseversion, comparisonrelease)
    rootfilename = "pftautag_" + releaseversion + "_ThreeProng_PFTAU.root"
    comparisonpath = comparisonpath + "/pftautag_" + comparisonrelease + "_ThreeProng_PFTAU.root"
    print rootfilename

    command = "root -b -q \'pftautag_allplots.C( \""  \
               + rootfilename + "\" , \"" \
               + comparisonpath + "\" , \"" \
               + releaseversion + "\" ,\""  \
               + comparisonrelease + "\" ,\""  \
                "ThreeProng\" )\'"  
    print command

    os.system(command)

    os.system("mv *png pftautag/ThreeProng")


    


    
