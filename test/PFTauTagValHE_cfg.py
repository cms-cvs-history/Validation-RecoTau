# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.DQMStore = cms.Service("DQMStore")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/0A8D021D-BD3E-DD11-B07B-000423D6CA6E.root')
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(200)
)
process.pfTauTagHEBothProngs = cms.EDFilter("PFTauTagVal",
    OutPutFile = cms.string('pftautagHE.root'), ## This name is modified to reflect releaseversion and histograms stored

    PFTauProducer = cms.string('pfRecoTauProducerHighEfficiency'),
    DataType = cms.string('PFTAU'),
    OutPutHistograms = cms.string('OneProngAndThreeProng'),
    PFTauDiscriminatorByIsolationProducer = cms.string('pfRecoTauDiscriminationHighEfficiency'),
    ExtensionName = cms.InputTag("PFTauIsolationValidation"),
    #    string DataType = "QCD"
    GenJetProd = cms.InputTag("iterativeCone5GenJets")
)

process.p = cms.Path(process.pfTauTagHEBothProngs)


