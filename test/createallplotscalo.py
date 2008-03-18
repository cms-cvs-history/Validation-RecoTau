#!usr/bin/python

import os
import sys
import string

print "Creating all directories and subdirectories.\n"

currentdirectory = os.curdir
rootfilespftautag = 0
rootfilespftautagHE = 0
rootfilestautag = 0
rootfilescalotautag = 0
releaseversion = ""
prongsinfile = ""

absolutepath = os.path.abspath('')
pathparts = absolutepath.split("/")

print absolutepath, pathparts , len(sys.argv)

for pathpart in pathparts:
   if string.find(pathpart,"MSSW_") > 0:
       releaseversion = pathpart
   elif string.find(pathpart,"Prong") > 0:
       prongsinfile = pathpart

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

       elif string.find(filename,"_TAU") > 0:
           rootfilestautag = rootfilestautag + 1
           print "tautag_CMSSW\n"
           
       elif string.find(filename,"ftautagHE_CMSSW") > 0:
           rootfilespftautagHE = rootfilespftautagHE + 1
           print "pftautagHE_CMSSW\n"

       elif string.find(filename,"_CALOTAU") > 0:
           rootfilescalotautag = rootfilescalotautag + 1
           print "calotautag_CMSSW\n"
           
print rootfilestautag," ", rootfilespftautag, " ", rootfilespftautagHE ," ", rootfilescalotautag," ", releaseversion," ", prongsinfile

comparisonrelease= sys.argv[1]

comparisonpath = absolutepath.replace(releaseversion, comparisonrelease)
 
if rootfilescalotautag == 3:
    os.system("mkdir calotautag")
    os.system("mkdir calotautag/OneProngAndThreeProng")
    os.system("mkdir calotautag/OneProng")
    os.system("mkdir calotautag/ThreeProng")
    rootfilename = "calotautag_" + releaseversion + "_OneProngAndThreeProng_CALOTAU.root"
    comparisonpath = comparisonpath + "/calotautag_" + comparisonrelease + "_OneProngAndThreeProng_CALOTAU.root"
    print rootfilename

    command = "root -b -q \'calotautag_allplots.C( \""  \
               + rootfilename + "\" , \"" \
               + comparisonpath + "\" , \"" \
               + releaseversion + "\" ,\""  \
               + comparisonrelease + "\" ,\""  \
                "OneProngAndThreeProng\" )\'"  
    print command

    os.system(command)

    os.system("mv *png calotautag/OneProngAndThreeProng")
    comparisonpath = ""
    comparisonpath = absolutepath.replace(releaseversion, comparisonrelease)
    rootfilename = "calotautag_" + releaseversion + "_OneProng_CALOTAU.root"
    comparisonpath = comparisonpath + "/calotautag_" + comparisonrelease + "_OneProng_CALOTAU.root"
    print rootfilename

    command = "root -b -q \'calotautag_allplots.C( \""  \
               + rootfilename + "\" , \"" \
               + comparisonpath + "\" , \"" \
               + releaseversion + "\" ,\""  \
               + comparisonrelease + "\" ,\""  \
                "OneProng\" )\'"  
    print command

    os.system(command)

    os.system("mv *png calotautag/OneProng")
    comparisonpath = ""
    comparisonpath = absolutepath.replace(releaseversion, comparisonrelease)
    rootfilename = "calotautag_" + releaseversion + "_ThreeProng_CALOTAU.root"
    comparisonpath = comparisonpath + "/calotautag_" + comparisonrelease + "_ThreeProng_CALOTAU.root"
    print rootfilename

    command = "root -b -q \'calotautag_allplots.C( \""  \
               + rootfilename + "\" , \"" \
               + comparisonpath + "\" , \"" \
               + releaseversion + "\" ,\""  \
               + comparisonrelease + "\" ,\""  \
                "ThreeProng\" )\'"  
    print command

    os.system(command)

    os.system("mv *png calotautag/ThreeProng")
