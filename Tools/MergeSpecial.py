#!/usr/bin/env python
"""

     MergeFilesAndCalculateEfficiencies.py

        Merges multiple root files containing the numerator and denominator histograms produced by the
        TauTagValidation package.  The efficiency (num/denominator) is then computed 
        as defined Validation/RecoTau/python/RecoTauValidation_cff.py and stored in OutputFile_Eff.root

     Usage: cmsRun MergeFilesAndCalculateEfficiencies.py OutputFile InputFiles

     Example: ./MergeFilesAndCalculateEfficiencies.py CMSSW_3_1_0_Signal.root CMSSW_3_1_0_ZTT_*.root

"""

import os
import sys
import FWCore.ParameterSet.Config as cms
from Validation.RecoTau.ValidationOptions_cff import allowedOptions
import Validation.RecoTau.ValidationUtils as Utils
import PhysicsTools.PatAlgos.tools.helpers as helpers

if len(sys.argv) < 5:
   print "Error. Expected at least 3 arguments\n\nUsage: MergeFilesAndCalculateEfficiencies.py dataType OutputFile InputFileGlob"
   print sys.argv
   sys.exit()

dataType   = sys.argv[2]
OutputFile = sys.argv[3]
Inputs     = sys.argv[4:]

if not dataType in allowedOptions['eventType']:
   print "Error. The first argument must be the dataType. Types availables are:"
   print allowedOptions['eventType']
   sys.exit()

for aFile in Inputs:
   if not os.path.exists(aFile):
      print "Input file %s does not exist!" % aFile
      sys.exit()

if os.path.exists(OutputFile):
   GotGoodValue = False
   userInput = ""
   while not GotGoodValue:
      userInput = raw_input("Output file %s exists; replace it? [yn] " % OutputFile).strip()
      if userInput != 'y' and userInput != 'n':
         print "Please enter y or n"
      else:
         GotGoodValue = True
   if userInput == 'n':
      sys.exit()

# Merge files using hadd utility
commandString  = "hadd -f %s " % OutputFile
for aFile in Inputs:
   commandString += aFile
   commandString += " "

os.system(commandString)

print "Running cmsRun command to generate efficiencies"

process = cms.Process("TEST")

process.source = cms.Source("EmptySource")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

process.DQMStore = cms.Service("DQMStore")
process.load("Validation.RecoTau.dataTypes.ValidateTausOn%s_cff"%dataType)

setattr(process,'TauValNumeratorAndDenominator%s'%(dataType),
        cms.Sequence(
           getattr(process, 'RunHPSValidation%s'%(dataType))
           )
   )

process.makeEff = cms.Sequence(
   getattr(process,'normalizePlots%s'%(dataType) )
   )
postfix = 'plainNewDecayMode'
print 'applying postif: '+postfix
helpers.cloneProcessingSnippet( process, process.runTauValidation, postfix)
assert( hasattr(process,'TauValNumeratorAndDenominator%s%s'%(dataType,postfix) ) )
assert( hasattr(process,'TauEfficiencies%s%s'%(dataType,postfix) ) )
assert( hasattr(process,'efficiencies%s%s'%(dataType,postfix) ) )
for entry in getattr(process, 'RunHPSValidation%s%s'%(dataType, postfix)).discriminators:
   entry.discriminator = entry.discriminator.value() + postfix
getattr(process,'efficiencies%s%s'%(dataType,postfix) ).plots = Utils.SetPlotSequence(getattr(process,'TauValNumeratorAndDenominator%s%s'%(dataType,postfix) ))
#manually fix the paths, don't wanna loose time
effAnalyzer = getattr(process,'efficiencies%s%s'%(dataType,postfix) )
for plotpset in effAnalyzer.plots.parameterNames_():
   num = getattr(effAnalyzer.plots,plotpset).numerator.value()
   den = getattr(effAnalyzer.plots,plotpset).denominator.value()
   eff = getattr(effAnalyzer.plots,plotpset).efficiency.value()
   getattr(effAnalyzer.plots,plotpset).numerator   = num.replace(dataType,postfix+dataType)
   getattr(effAnalyzer.plots,plotpset).denominator = den.replace(dataType,postfix+dataType)
   getattr(effAnalyzer.plots,plotpset).efficiency  = eff.replace(dataType,postfix+dataType)
process.makeEff += getattr(process,'efficiencies%s%s'%(dataType,postfix) )

postfix = 'vtxFilterOnPvFindAlgoOld'
print 'applying postif: '+postfix
helpers.cloneProcessingSnippet( process, process.runTauValidation, postfix)
assert( hasattr(process,'TauValNumeratorAndDenominator%s%s'%(dataType,postfix) ) )
assert( hasattr(process,'TauEfficiencies%s%s'%(dataType,postfix) ) )
assert( hasattr(process,'efficiencies%s%s'%(dataType,postfix) ) )
for entry in getattr(process, 'RunHPSValidation%s%s'%(dataType, postfix)).discriminators:
   entry.discriminator = entry.discriminator.value() + postfix
getattr(process,'efficiencies%s%s'%(dataType,postfix) ).plots = Utils.SetPlotSequence(getattr(process,'TauValNumeratorAndDenominator%s%s'%(dataType,postfix) ))
effAnalyzer = getattr(process,'efficiencies%s%s'%(dataType,postfix) )
for plotpset in effAnalyzer.plots.parameterNames_():
   num = getattr(effAnalyzer.plots,plotpset).numerator.value()
   den = getattr(effAnalyzer.plots,plotpset).denominator.value()
   eff = getattr(effAnalyzer.plots,plotpset).efficiency.value()
   getattr(effAnalyzer.plots,plotpset).numerator   = num.replace(dataType,postfix+dataType)
   getattr(effAnalyzer.plots,plotpset).denominator = den.replace(dataType,postfix+dataType)
   getattr(effAnalyzer.plots,plotpset).efficiency  = eff.replace(dataType,postfix+dataType)
process.makeEff += getattr(process,'efficiencies%s%s'%(dataType,postfix) )

postfix = 'vtxFilterOffPvFindAlgoNew'
print 'applying postif: '+postfix
helpers.cloneProcessingSnippet( process, process.runTauValidation, postfix)
assert( hasattr(process,'TauValNumeratorAndDenominator%s%s'%(dataType,postfix) ) )
assert( hasattr(process,'TauEfficiencies%s%s'%(dataType,postfix) ) )
assert( hasattr(process,'efficiencies%s%s'%(dataType,postfix) ) )
for entry in getattr(process, 'RunHPSValidation%s%s'%(dataType, postfix)).discriminators:
   entry.discriminator = entry.discriminator.value() + postfix
getattr(process,'efficiencies%s%s'%(dataType,postfix) ).plots = Utils.SetPlotSequence(getattr(process,'TauValNumeratorAndDenominator%s%s'%(dataType,postfix) ))
effAnalyzer = getattr(process,'efficiencies%s%s'%(dataType,postfix) )
for plotpset in effAnalyzer.plots.parameterNames_():
   num = getattr(effAnalyzer.plots,plotpset).numerator.value()
   den = getattr(effAnalyzer.plots,plotpset).denominator.value()
   eff = getattr(effAnalyzer.plots,plotpset).efficiency.value()
   getattr(effAnalyzer.plots,plotpset).numerator   = num.replace(dataType,postfix+dataType)
   getattr(effAnalyzer.plots,plotpset).denominator = den.replace(dataType,postfix+dataType)
   getattr(effAnalyzer.plots,plotpset).efficiency  = eff.replace(dataType,postfix+dataType)
process.makeEff += getattr(process,'efficiencies%s%s'%(dataType,postfix) )


process.loadFile   = cms.EDAnalyzer("DQMFileLoader",
      myFiles = cms.PSet(
         inputFileNames = cms.vstring(OutputFile),
         scaleFactor = cms.double(1.),
         )
)

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
#  outputFileName = cms.string(OutputFile.replace('.root', '_Eff.root'))
  outputFileName = cms.string(OutputFile)
)

process.p = cms.Path(
      process.loadFile*
      process.makeEff*
      process.saveTauEff
      )

