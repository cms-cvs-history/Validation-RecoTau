# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.DQMStore = cms.Service("DQMStore")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring( 
'/store/relval/2008/7/21/RelVal-RelValZTT-1216579576-STARTUP_V4-2nd/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/CMSSW_2_1_0_pre9-RelVal-1216579576-STARTUP_V4-2nd-unmerged/0000/14459A48-6F57-DD11-B4E3-000423D6BA18.root',        
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.caloTauTagBothProngs = cms.EDAnalyzer("CaloTauTagVal",
    CaloTauProducer = cms.string('caloRecoTauProducer'),
    OutPutFile = cms.string('calotautag.root'), ## This name is modified to reflect releaseversion and histograms stored 
    DataType = cms.string('CALOTAU'),
    OutPutHistograms = cms.string('OneProngAndThreeProng'),
    CaloTauDiscriminatorByIsolationProducer = cms.string('caloRecoTauDiscriminationByIsolation'),
    ExtensionName = cms.InputTag("CaloTauValidation"),
    #    string DataType = "QCD" 
    GenJetProd = cms.InputTag("iterativeCone5GenJets")
)

process.p = cms.Path(process.caloTauTagBothProngs)


