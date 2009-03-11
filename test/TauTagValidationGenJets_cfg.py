import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
       '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/1AB469A4-520A-DE11-A047-001617E30E28.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/2A091AB5-950A-DE11-B561-000423D9A2AE.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/3EF98F45-770A-DE11-AD4B-000423D944F8.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/9235826C-7D0A-DE11-9762-001617C3B76A.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/C653FC9D-520A-DE11-AF0C-001617C3B6CC.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/D84BEF86-760A-DE11-9FE8-000423D6CA42.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/D84EDCA1-520A-DE11-9159-001617C3B706.root',
        '/store/relval/CMSSW_3_1_0_pre3/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/DC4C12A1-520A-DE11-B96C-001617C3B6DE.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.TauTagValidationGenJets_cfi")
process.load("Validation.RecoTau.RelValHistogramEff_cfi")

###################################################################################################
#
#    Name of the file that gets all the DQMMonitorElements and saves them, please modify accordingly
#
###################################################################################################

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
  outputFileName = cms.string('CMSSW_3_1_0_pre3_RelValQCD_FlatPt_15_3000.root')
)
                                 
process.p = cms.Path(
#    process.tauGenJetProducer +
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
