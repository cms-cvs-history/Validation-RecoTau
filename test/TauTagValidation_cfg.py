import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_0_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0006/0C9E3984-57E8-DD11-B89C-001D09F291D2.root',
        '/store/relval/CMSSW_3_0_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0006/4CBAC9FC-56E8-DD11-90F5-000423D986C4.root',
        '/store/relval/CMSSW_3_0_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0006/B0AF7439-57E8-DD11-BC2D-001617C3B77C.root',
        '/store/relval/CMSSW_3_0_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0006/C6AEDDC0-6AE8-DD11-8381-001D09F231B0.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.TauTagValidationProducer_cff")
process.load("Validation.RecoTau.TauTagValidation_cfi")
process.load("Validation.RecoTau.RelValHistogramEff_cfi")

###################################################################################################
#
#    Name of the file that gets all the DQMMonitorElements and saves them, please modify accordingly
#
###################################################################################################

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
  outputFileName = cms.string('CMSSW_3_0_0_pre7_tauGenJets_TEST.root')
)
                                 
process.p = cms.Path(
    process.tauGenJetProducer +
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
