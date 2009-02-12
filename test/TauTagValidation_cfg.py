import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_1_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/260FDDAF-F7F7-DD11-9672-001D09F2538E.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/8ED461AD-F7F7-DD11-B49F-000423D986C4.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/D05D05C6-06F8-DD11-A268-001617C3B6E2.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/F0979216-F7F7-DD11-ADF4-000423D95030.root'
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
  outputFileName = cms.string('CMSSW_3_1_0_pre1_tauGenJets.root')
)
                                 
process.p = cms.Path(
    process.tauGenJetProducer +
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
