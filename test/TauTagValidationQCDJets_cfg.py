import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/02DFC48D-FEF7-DD11-9CD2-000423D98DB4.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/2C1C30CC-FCF7-DD11-B1D6-001617E30F56.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/32B15D35-FDF7-DD11-82EF-000423D98DB4.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/4CB750CD-FCF7-DD11-A372-000423D99658.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/785B595C-FEF7-DD11-A5ED-000423D6CA6E.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/820357D1-FCF7-DD11-9BD2-000423D98B28.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/906CE33B-FDF7-DD11-8D5C-001617C3B710.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/9680FBCD-FCF7-DD11-9229-000423D985B0.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/98B8D2DA-06F8-DD11-BFE5-000423D98DC4.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/A8BCF5D0-FCF7-DD11-9488-001617E30E2C.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/B21A8731-FDF7-DD11-837E-001617DBD5AC.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/DEDB07A6-FCF7-DD11-A70E-000423D6B48C.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/EE88D3CC-FCF7-DD11-862E-001617DBD316.root',
        '/store/relval/CMSSW_3_1_0_pre1/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/FEAA80D9-FCF7-DD11-A08F-000423D6CA6E.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.TauTagValidationQCDJets_cfi")
process.load("Validation.RecoTau.RelValHistogramEff_cfi")

###################################################################################################
#
#    Name of the file that gets all the DQMMonitorElements and saves them, please modify accordingly
#
###################################################################################################

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
  outputFileName = cms.string('CMSSW_3_1_0_pre1_RelValQCD_FlatPt_15_3000_test.root')
)
                                 
process.p = cms.Path(
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
