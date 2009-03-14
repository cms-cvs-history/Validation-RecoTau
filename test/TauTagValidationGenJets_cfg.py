import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/147F4EAF-AE03-DE11-B98A-000423D6006E.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/24A7D1A3-AE03-DE11-8CFC-000423D99B3E.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/268E6CE8-AE03-DE11-8C29-001D09F231B0.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/3400D4B5-AE03-DE11-8D98-000423D98920.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/568DC4AC-AE03-DE11-9577-000423D8FA38.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/581EB8AD-AE03-DE11-A558-001617E30D52.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/6CDAA1AD-AE03-DE11-85FF-000423D985B0.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/80C385D6-AE03-DE11-8E09-000423D99614.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/982811D3-AE03-DE11-8372-000423D98FBC.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/A81028D8-AE03-DE11-8808-001D09F28EA3.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/B69F9776-DB03-DE11-9E22-000423D98DC4.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/C21A76B1-AE03-DE11-BE6B-001617C3B6DE.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/C679ADB2-AE03-DE11-BF43-001617E30D38.root',
        '/store/relval/CMSSW_3_1_0_pre2/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0001/FCA230D0-AE03-DE11-8999-001617C3B654.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

process.DQMStore = cms.Service("DQMStore")

process.load("PhysicsTools.JetMCAlgos.GenJetsSelector_iterativeCone5GenJets_cfi")
process.load("Validation.RecoTau.TauTagValidationGenJets_cfi")
process.load("Validation.RecoTau.RelValHistogramEff_cfi")

###################################################################################################
#
#    Name of the file that gets all the DQMMonitorElements and saves them, please modify accordingly
#
###################################################################################################

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
  outputFileName = cms.string('CMSSW_3_1_0_pre2_RelValQCD_FlatPt_15_3000_100.root')
)
                                 
process.p = cms.Path(
    process.iterativeCone5GenJetsEta25 +
    process.iterativeCone5GenJetsPt5Cumulative +
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
