import FWCore.ParameterSet.Config as cms

process = cms.Process('MakingPlots')

process.DQMStore = cms.Service("DQMStore")

process.maxEvents = cms.untracked.PSet(            
    input = cms.untracked.int32(0)         
)

process.source = cms.Source("EmptySource")

process.load('Validation.RecoTau.plotterTauTagValidation_cff')

#############################
# Path to be executed
###############################

process.p = cms.Path( process.loadTau 
                     +process.plotPFTauEfficiencies
                     +process.plotPFTauHighEfficiencyEfficiencies
                     +process.plotCaloTauEfficiencies
                     +process.plotPFTauHighEfficiencyEfficienciesLeadingPion )
