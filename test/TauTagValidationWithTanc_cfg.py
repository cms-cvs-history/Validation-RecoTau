import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

MyFileNames = cms.untracked.vstring()
MyReleaseLabel = "CMSSW_3_1_0_pre4"
MyFileLabel = ""

process.load("Validation.RecoTau.TauTagValidationProducer_cff")

ThisIsQCD = False

if ThisIsQCD:
   process.load("Validation.RecoTau.TauTagValidationGenJets_cfi")
   MyFileNames = cms.untracked.vstring(
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/00DD82EE-0616-DE11-ABAD-000423D6B42C.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/1A3FDC02-0916-DE11-9DC7-001617E30D0A.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/1C94B51A-AC16-DE11-8F94-001617C3B76E.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/364F41D9-0516-DE11-BF0A-000423D9853C.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/3E1BCACC-0516-DE11-B6DC-000423D6A6F4.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/5688EBA3-0516-DE11-8170-000423D94AA8.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/6620613C-4F16-DE11-A033-000423D95220.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/6C075A5D-2016-DE11-BB66-000423D6CA72.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/6EA9847C-5A16-DE11-82B8-001617C3B6C6.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/70820DE5-0616-DE11-9A9D-000423D986A8.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/C87CCC26-4F16-DE11-A5E7-000423D98844.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/CC17AAF2-0616-DE11-8C55-000423D6CA42.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/D8DA8359-0616-DE11-8B00-000423D98AF0.root', 
           '/store/relval/CMSSW_3_1_0_pre4/RelValQCD_FlatPt_15_3000/GEN-SIM-DIGI-RECO/IDEAL_30X_FastSim_v1/0003/F668AADD-4F16-DE11-96A4-001617C3B70E.root'  
           )
   MyFileLabel = "QCD"
else:
   process.load("Validation.RecoTau.TauTagValidation_cfi")
   MyFileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/002B1F04-6B16-DE11-9159-003048769CCF.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/02C7C51D-7116-DE11-88AC-003048D42DC8.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/0ABDB25F-6C16-DE11-9AE5-001731A281B1.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/5267F035-6616-DE11-9BD3-00304867920A.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/9C8B64A3-BB16-DE11-B50D-00304875AAED.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0001/CE1EF473-6E16-DE11-9FEC-00304875A9B7.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0002/689971E1-FF16-DE11-90F0-001A92971B04.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0002/B69AAB9F-5C18-DE11-86E8-0018F3D096E8.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0003/462A428D-AB16-DE11-935F-0019DB29C614.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0003/5AC69810-E615-DE11-8919-000423D98634.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0003/A681335C-E915-DE11-86B5-000423D98DC4.root',
        '/store/relval/CMSSW_3_1_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP_30X_v1/0003/EC3834A5-ED15-DE11-81AF-001617DBCF6A.root'
     )
   MyFileLabel = "ZTT"

process.source = cms.Source("PoolSource",
    fileNames = MyFileNames
)

process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(-1)
    input = cms.untracked.int32(5000)
)

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.RelValHistogramEff_cfi")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("RecoTauTag.Configuration.RecoTauTag_FakeConditions_cff")
process.load("FastSimulation.Configuration.CommonInputs_cff")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")


###################################################################################################
#
#    Name of the file that gets all the DQMMonitorElements and saves them, please modify accordingly
#
###################################################################################################

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
  outputFileName = cms.string('%s_%s.root' % (MyReleaseLabel, MyFileLabel))
)
                                 
process.p = cms.Path(
    process.PFTau*
    process.produceShrinkingConeDiscriminationByTauNeuralClassifier+
    process.tauGenJetProducer +
    process.tauTagValidationWithTanc +
    process.TauEfficiencies +
    process.saveTauEff)

process.schedule = cms.Schedule(process.p)
