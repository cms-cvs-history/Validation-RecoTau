# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("HLTriggerOffline.Tau.Validation.HLTTauReferences_cfi")

process.load("Validation/RecoTau/TauTagValidation_cfi")

# Conditions: fake or frontier
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'IDEAL_V9::All'

process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("RecoTauTag.Configuration.RecoTauTag_cff")

process.DQMStore = cms.Service("DQMStore")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_2_2_0/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v1/0000/10627D20-34B9-DD11-BAD2-000423D986C4.root',
        '/store/relval/CMSSW_2_2_0/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v1/0000/84EC5604-37B9-DD11-B0C4-000423D951D4.root',
        '/store/relval/CMSSW_2_2_0/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v1/0000/B2411152-B5B9-DD11-94D3-000423D6B42C.root',
        '/store/relval/CMSSW_2_2_0/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v1/0000/B623205B-35B9-DD11-A2A7-000423D991F0.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
    ignoreTotal = cms.untracked.int32(1) ## default is one
)

process.load("RecoTauTag.Configuration.RecoTauTag_EventContent_cff")
process.load("Configuration.EventContent.EventContent_cff")

process.load("Validation.RecoTau.RelValHistogramEff_cfi")
                                 
process.p = cms.Path(  process.TauMCProducer
                      *process.CaloTausBothProngs
    		      *process.PFTausBothProngs
                      *process.PFTausHighEfficiencyBothProngs
                      *process.TauEfficiencies
                      *process.saveTauEff)


#process.outpath = cms.EndPath(process.output)
