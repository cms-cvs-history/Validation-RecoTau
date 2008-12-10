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
        '/store/relval/CMSSW_2_2_1/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v2/0002/18AD12CB-9FC4-DD11-8B2A-001D09F2546F.root',
        '/store/relval/CMSSW_2_2_1/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v2/0002/4E4D1ACA-9FC4-DD11-9140-0019B9F72BAA.root',
        '/store/relval/CMSSW_2_2_1/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v2/0002/FA493ED0-9FC4-DD11-B271-001D09F2B2CF.root',
        '/store/relval/CMSSW_2_2_1/RelValZTT/GEN-SIM-RECO/STARTUP_V7_v2/0004/B6F66289-FEC4-DD11-A125-000423D6BA18.root'
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
