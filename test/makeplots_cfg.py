import FWCore.ParameterSet.Config as cms
import os

process = cms.Process('MakingPlots')

process.DQMStore = cms.Service("DQMStore")

process.maxEvents = cms.untracked.PSet(            
    input = cms.untracked.int32(0)         
)

def MakeDirIfNecessary(dir):
   if not os.path.exists(dir):
      os.system("mkdir %s" % dir)

MyDirs = [ 'caloRecoTauProducer',
           'fixedConePFTauProducer',
           'fixedConeHighEffPFTauProducer',
           'shrinkingConePFTauProducer',
           'shrinkingConePFTauProducerTanc',
           'shrinkingConePFTauProducerLeadingPion']

map(MakeDirIfNecessary, MyDirs)

process.source = cms.Source("EmptySource")

process.load('Validation.RecoTau.plotterTauTagValidation_cff')
#process.load('Validation.RecoTau.plotterTauTagValidationVersusLegacySequences_cff')

#############################
# Path to be executed
###############################

print process.dumpPython()

process.p = cms.Path( process.loadTau 
                     +process.plotPFTauEfficiencies
                     +process.plotPFTauHighEfficiencyEfficiencies
                     +process.plotCaloTauEfficiencies
                     +process.plotTancValidation
                     +process.plotPFTauHighEfficiencyEfficienciesLeadingPion )

