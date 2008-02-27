#!usr/bin/python
import os
import sys
import string

os.system("cmsRun TauTagVal.cfg")

original = ""
typeOne = "OneProng"
typeTwo = "ThreeProng"
firstreplace=""
secondreplace=""

one = 0
two = 0

for line in open("TauTagVal.cfg"):
   if string.find(line,typeOne) > 0:
     one = one +1
   if string.find(line,typeTwo) > 0:
     two = two +1

print " one ", one , " two ", two

if one == 1 and two == 1:
   original = "OneProngAndThreeProng"
   firstreplace = typeOne
   secondreplace = typeTwo

if one == 1 and two == 0:
   original = typeOne
   firstreplace = typeTwo
   secondreplace = "OneProngAndThreeProng"

if one == 0 and two == 1:
   original = typeTwo
   firstreplace = "OneProngAndThreeProng"
   secondreplace = typeOne

if one == 0 and two == 0:
   print " This is not going to work out TauTagVal.cfg./n"

print " original: ", original, " firstreplace: ", firstreplace, " secondreplace: ", secondreplace, "\n"


o = open("newTauTagVal.cfg","a")
for line in open("TauTagVal.cfg"):
   line = line.replace(original,firstreplace)
   o.write(line)
o.close()

os.system("rm -rf TauTagVal.cfg")
os.system("cp newTauTagVal.cfg TauTagVal.cfg")
os.system("rm -rf newTauTagVal.cfg")

os.system("cmsRun TauTagVal.cfg")

o = open("newTauTagVal.cfg","a")

for line in open("TauTagVal.cfg"):
   line = line.replace(firstreplace,secondreplace)
   o.write(line)
o.close()

os.system("rm -rf TauTagVal.cfg")
os.system("cp newTauTagVal.cfg TauTagVal.cfg")
os.system("rm -rf newTauTagVal.cfg")

os.system("cmsRun TauTagVal.cfg")

#------------------------------------------PFTau and PFTauHF------------------------------

one = 0
two = 0

os.system("cmsRun PFTauTagVal.cfg")


for line in open("PFTauTagVal.cfg"):
   if string.find(line,typeOne) > 0:
     one = one +1
   if string.find(line,typeTwo) > 0:
     two = two +1

if one == 1 and two == 1:
   original = "OneProngAndThreeProng"
   firstreplace = typeOne
   secondreplace = typeTwo

if one == 1 and two == 0:
   original = typeOne
   firstreplace = typeTwo
   secondreplace = "OneProngAndThreeProng"

if one == 0 and two == 1:
   original = typeTwo
   firstreplace = "OneProngAndThreeProng"
   secondreplace = typeOne

if one == 0 and two == 0:
   print " This is not going to work out PFTauTagVal.cfg./n"

print " original: ", original, " firstreplace: ", firstreplace, " secondreplace: ", secondreplace, "\n"


o = open("newPFTauTagVal.cfg","a")
for line in open("PFTauTagVal.cfg"):
   line = line.replace(original,firstreplace)
   o.write(line)
o.close()

os.system("rm -rf PFTauTagVal.cfg")
os.system("cp newPFTauTagVal.cfg PFTauTagVal.cfg")
os.system("rm -rf newPFTauTagVal.cfg")

os.system("cmsRun PFTauTagVal.cfg")

o = open("newPFTauTagVal.cfg","a")

for line in open("PFTauTagVal.cfg"):
   line = line.replace(firstreplace,secondreplace)
   o.write(line)
o.close()

os.system("rm -rf PFTauTagVal.cfg")
os.system("cp newPFTauTagVal.cfg PFTauTagVal.cfg")
os.system("rm -rf newPFTauTagVal.cfg")

os.system("cmsRun PFTauTagVal.cfg")

#------------------------------------------PFTau and PFTauHE------------------------------

o = open("PFTauTagValHE.cfg","w")
for line in open("PFTauTagVal.cfg"):
   line = line.replace("pfRecoTauProducer","pfRecoTauProducerHighEfficiency")
   line = line.replace("pfRecoTauDiscriminationByIsolation","pfRecoTauDiscriminationHighEfficiency")
   line = line.replace("pftautag.root","pftautagHE.root")
   o.write(line)
o.close()

os.system("cmsRun PFTauTagValHE.cfg")

original = ""
typeOne = "OneProng"
typeTwo = "ThreeProng"
firstreplace=""
secondreplace=""

one = 0
two = 0

for line in open("PFTauTagValHE.cfg"):
   if string.find(line,typeOne) > 0:
     one = one +1
   if string.find(line,typeTwo) > 0:
     two = two +1

print " one ", one , " two ", two

if one == 1 and two == 1:
   original = "OneProngAndThreeProng"
   firstreplace = typeOne
   secondreplace = typeTwo

if one == 1 and two == 0:
   original = typeOne
   firstreplace = typeTwo
   secondreplace = "OneProngAndThreeProng"

if one == 0 and two == 1:
   original = typeTwo
   firstreplace = "OneProngAndThreeProng"
   secondreplace = typeOne

if one == 0 and two == 0:
   print " This is not going to work out TauTagVal.cfg./n"

print " original: ", original, " firstreplace: ", firstreplace, " secondreplace: ", secondreplace, "\n"

o = open("newPFTauTagValHE.cfg","a")

for line in open("PFTauTagValHE.cfg"):
   line = line.replace(original,firstreplace)
   o.write(line)
o.close()

os.system("rm -rf PFTauTagValHE.cfg")
os.system("cp newPFTauTagValHE.cfg PFTauTagValHE.cfg")
os.system("rm -rf newPFTauTagValHE.cfg")

os.system("cmsRun PFTauTagValHE.cfg")

o = open("newPFTauTagValHE.cfg","a")

for line in open("PFTauTagValHE.cfg"):
   line = line.replace(firstreplace,secondreplace)
   o.write(line)
o.close()

os.system("rm -rf PFTauTagValHE.cfg")
os.system("cp newPFTauTagValHE.cfg PFTauTagValHE.cfg")
os.system("rm -rf newPFTauTagValHE.cfg")

os.system("cmsRun PFTauTagValHE.cfg")
