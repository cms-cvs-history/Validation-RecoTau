import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       '/store/relval/CMSSW_2_2_8/RelValZTT/GEN-SIM-RECO/STARTUP_V9_v1/0001/C8F823C3-1D2D-DE11-ABC5-000423D174FE.root',
       '/store/relval/CMSSW_2_2_8/RelValZTT/GEN-SIM-RECO/STARTUP_V9_v1/0001/5047CDE9-EF2C-DE11-B7C3-000423D9890C.root',
       '/store/relval/CMSSW_2_2_8/RelValZTT/GEN-SIM-RECO/STARTUP_V9_v1/0000/FAD4ADC9-B12C-DE11-9BFE-001617C3B6FE.root',
       '/store/relval/CMSSW_2_2_8/RelValZTT/GEN-SIM-RECO/STARTUP_V9_v1/0000/B6726994-E52C-DE11-82E1-000423D95220.root',
       '/store/relval/CMSSW_2_2_8/RelValZTT/GEN-SIM-RECO/STARTUP_V9_v1/0000/28060A61-AA2C-DE11-85CD-000423D999CA.root'


)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
#    input = cms.untracked.int32(100)
)

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.TauTagValidationProducer_cff")
process.load("Validation.RecoTau.TauTagValidation_cfi")
process.load("Validation.RecoTau.RelValHistogramEff_cfi")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("RecoTauTag.Configuration.RecoTauTag_FakeConditions_cff")
process.load("FastSimulation.Configuration.CommonInputsFake_cff")
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
    process.tauTagValidationWithTanc +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
