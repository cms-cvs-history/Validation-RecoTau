import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_1_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/102A7D74-300A-DE11-B318-000423D6006E.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/C6345BA8-300A-DE11-A5F2-000423D6CA42.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/E4F6CB66-300A-DE11-BAF4-000423D60FF6.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/FE324A2E-800A-DE11-A3A3-000423D99A8E.root'
)
)

process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(-1)
    input = cms.untracked.int32(100)
)

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.TauTagValidationProducer_cff")
process.load("Validation.RecoTau.TauTagValidation_cfi")
process.load("Validation.RecoTau.RelValHistogramEff_cfi")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("FastSimulation.Configuration.CommonInputs_cff")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")


###################################################################################################
#
#    Name of the file that gets all the DQMMonitorElements and saves them, please modify accordingly
#
###################################################################################################

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
  outputFileName = cms.string('CMSSW_3_1_0_pre3_tauGenJets.root')
)
                                 
process.p = cms.Path(
    process.PFTau+
    process.tauGenJetProducer +
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
