import FWCore.ParameterSet.Config as cms

process = cms.Process('EWKTauMuon')

process.load('Validation.RecoTau.plotterTauTagValidationFastSim_cff')

process.DQMStore = cms.Service("DQMStore")

process.maxEvents = cms.untracked.PSet(            
    input = cms.untracked.int32(0)         
)

process.source = cms.Source("EmptySource")

process.p = cms.Path( process.loadTau
                     +process.plotPFTauEfficiencies
                     +process.plotPFTauHighEfficiencyEfficiencies
                     +process.plotCaloTauEfficiencies)
