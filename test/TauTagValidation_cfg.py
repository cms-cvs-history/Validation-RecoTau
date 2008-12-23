import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

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

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.TauTagValidationProducer_cff")
process.load("Validation.RecoTau.TauTagValidation_cfi")
process.load("Validation.RecoTau.RelValHistogramEff_cfi")
                                 
process.p = cms.Path(
    process.tauGenJetProducer +
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
