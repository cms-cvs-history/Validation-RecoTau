# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.DQMStore = cms.Service("DQMStore")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/0A8D021D-BD3E-DD11-B07B-000423D6CA6E.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/1075CAB6-B83E-DD11-8511-000423D98E54.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/160523FF-B83E-DD11-AA36-001617DBCF90.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/1C0F0B63-B73E-DD11-965A-000423D98A44.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/28EB4F12-B83E-DD11-9C2D-000423D98A44.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/2CA709F1-BE3E-DD11-AC34-000423D6BA18.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/363A0954-BA3E-DD11-A084-001617DBCF6A.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/5CC2112E-B63E-DD11-BF56-000423D98A44.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/64DE5D68-BB3E-DD11-BBB2-001617DC1F70.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/6C31B8CB-B63E-DD11-B129-000423D9997E.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/7E4FAA78-BA3E-DD11-B4BE-0019DB29C614.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/828AC38C-BC3E-DD11-AD22-001617DBD224.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/9894270C-B93E-DD11-B27C-000423D98804.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/9E4D4C57-B73E-DD11-BB40-000423D6CAF2.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/C0D36912-B93E-DD11-8CA7-001617DF785A.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/C6B16DE3-B93E-DD11-9423-000423D6CAF2.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/C8A0E252-B73E-DD11-A4E6-000423D99AAA.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/EE1BF32B-B93E-DD11-AB3B-001617C3B79A.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/F0B1EB65-B73E-DD11-B38C-001617C3B5E4.root', 
        '/store/relval/2008/6/20/RelVal-RelValZTT-1213921089-STARTUP_V1-2nd/0000/F6165ED7-B83E-DD11-A606-0019DB2F3F9B.root')
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.caloTauTagBothProngs = cms.EDAnalyzer("CaloTauTagVal",
    CaloTauProducer = cms.string('caloRecoTauProducer'),
    OutPutFile = cms.string('calotautagTEST.root'), ## This name is modified to reflect releaseversion and histograms stored 
    DataType = cms.string('CALOTAU'),
    OutPutHistograms = cms.string('OneProngAndThreeProng'),
    CaloTauDiscriminatorByIsolationProducer = cms.string('caloRecoTauDiscriminationByIsolation'),
    ExtensionName = cms.InputTag("CaloTauValidation"),
    #    string DataType = "QCD" 
    GenJetProd = cms.InputTag("iterativeCone5GenJets")
)

process.p = cms.Path(process.caloTauTagBothProngs)


