import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/00DD82EE-0616-DE11-ABAD-000423D6B42C.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/1A3FDC02-0916-DE11-9DC7-001617E30D0A.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/1C94B51A-AC16-DE11-8F94-001617C3B76E.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/364F41D9-0516-DE11-BF0A-000423D9853C.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/3E1BCACC-0516-DE11-B6DC-000423D6A6F4.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/5688EBA3-0516-DE11-8170-000423D94AA8.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.DQMStore = cms.Service("DQMStore")

process.load("PhysicsTools.JetMCAlgos.GenJetsSelector_iterativeCone5GenJets_cfi")
process.load("Validation.RecoTau.TauTagValidationGenJets_cfi")
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
  outputFileName = cms.string('CMSSW_3_1_0_pre4_RelValQCD_FlatPt_15_3000_100.root')
)
                                 
process.p = cms.Path(
    process.PFTau+
    process.iterativeCone5GenJetsEta25 +
    process.iterativeCone5GenJetsPt5Cumulative +
    process.tauTagValidation +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
