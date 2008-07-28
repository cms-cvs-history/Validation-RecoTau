# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("RecoTauTag.RecoTau.PFRecoTauDiscriminationAgainstElectron_cfi")

process.load("RecoTauTag.RecoTau.PFRecoTauDiscriminationAgainstMuon_cfi")

process.DQMStore = cms.Service("DQMStore")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(  '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/14459A48-6F57-DD11-B4E3-000423D6BA18.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/24435CA5-6F57-DD11-A6EC-001617DBD332.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/36ADEB89-7057-DD11-BE2D-000423D94908.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/3C55714D-6F57-DD11-B9AF-000423D991F0.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/542CF7D8-6E57-DD11-84CA-000423D94908.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/56DE4B43-6F57-DD11-BB58-000423D6B358.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/7075E70A-6F57-DD11-B108-000423D60FF6.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/72341589-7057-DD11-A8D2-001617E30D06.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/8062B827-7057-DD11-B170-00161757BF42.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/9E4A7808-6F57-DD11-A13F-000423D98834.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/A457ADFB-6F57-DD11-9CFA-001617E30CD4.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/B4741E9A-6F57-DD11-97EA-000423D991D4.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/B61DD173-6F57-DD11-AA1D-000423D98EA8.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/DE2B1A04-6F57-DD11-9D8F-000423D98800.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/E29CAF03-6F57-DD11-8088-001617E30F56.root',
        '/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/FE73BC71-6F57-DD11-A37B-001617E30CD4.root')

)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
    ignoreTotal = cms.untracked.int32(1) ## default is one

)

process.pfTauTagBothProngs = cms.EDAnalyzer("PFTauTagVal",
    OutPutFile = cms.string('pftautag.root'), ## This name is modified to reflect releaseversion and histograms stored
    PFTauProducer = cms.string('pfRecoTauProducer'),
    DataType = cms.string('PFTAU'),
    OutPutHistograms = cms.string('OneProngAndThreeProng'),
    ExtensionName = cms.InputTag("PFTauIsolationValidation"),
    PFTauDiscriminatorAgainstElectronProducer = cms.string('pfRecoTauDiscriminationAgainstElectron'),
    PFTauDiscriminatorAgainstMuonProducer = cms.string('pfRecoTauDiscriminationAgainstMuon'),
    #    string DataType = "QCD"
    GenJetProd = cms.InputTag("iterativeCone5GenJets")
)

process.p = cms.Path(process.pfTauTagBothProngs)


