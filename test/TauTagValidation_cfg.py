# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("HLTriggerOffline.Tau.Validation.HLTTauReferences_cfi")

process.load("Validation/RecoTau/TauTagValidation_cfi")

process.load("Configuration.StandardSequences.GeometryPilot2_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")

# Conditions: fake or frontier
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'IDEAL_V9::All'

process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("RecoTauTag.Configuration.RecoTauTag_cff")

process.DQMStore = cms.Service("DQMStore")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
     '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/08129034-FD99-DD11-BEED-000423D8F63C.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/3E09F7AB-A699-DD11-B642-000423D94C68.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/4A07D9D9-AA99-DD11-B646-000423D98DD4.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/54FE0387-A999-DD11-8ACE-000423D998BA.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/58EFF32A-A899-DD11-BBD1-000423D991F0.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/647A6A85-A999-DD11-8159-000423D6CA6E.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/66A0F94F-AA99-DD11-8DAB-000423D94E1C.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/74AD18D5-A499-DD11-AE7C-000423D996C8.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/880BA685-A999-DD11-B3E2-001617DBD472.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/8A4147D3-AA99-DD11-8F6F-000423D99996.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/9CB09C57-AA99-DD11-B17B-001617C3B64C.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/A49D4C86-A999-DD11-BF99-001617C3B5F4.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/CE142AD1-A899-DD11-81F9-000423D98C20.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/D2BE4560-AA99-DD11-A6A3-001617C3B5F4.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/DE79C186-AA99-DD11-A31B-001617C3B6FE.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/E63DE9B5-AA99-DD11-8464-000423D98750.root',
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/EC09555F-A599-DD11-99C5-001617C3B5F4.root'
)
)



process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(300)
)

process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
    ignoreTotal = cms.untracked.int32(1) ## default is one
)

process.load("RecoTauTag.Configuration.RecoTauTag_EventContent_cff")
process.load("Configuration.EventContent.EventContent_cff")

#process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
#
#process.printList = cms.EDFilter("ParticleListDrawer",
#                                 src = cms.InputTag("genParticles"),
#                                 maxEventsToPrint = cms.untracked.int32(-1)
#                                 )
#
#process.printTree = cms.EDFilter("ParticleTreeDrawer",
#                                 src = cms.InputTag("genParticles"),
#                                 printP4 = cms.untracked.bool(False),
#                                 printPtEtaPhi = cms.untracked.bool(False),
#                                 printVertex = cms.untracked.bool(False),
#                                 printStatus = cms.untracked.bool(False),
#                                 printIndex = cms.untracked.bool(False),
#                                 status = cms.untracked.vint32(3)
#)

process.output = cms.OutputModule("PoolOutputModule",
                                   fileName = cms.untracked.string('letssee.root'),
                                   outputCommands = cms.untracked.vstring('drop *',
                                   'keep *_caloRecoTau*_*_*'
                                   )
                                  )
                                 
process.p = cms.Path( process.PFTau
                      *process.PFTauHighEfficiency
                      *process.tautagging
                      *process.TauMCProducer
#                      *process.output
#                      *process.CaloTausBothProngs)
 		      *process.CaloTausBothProngs
    		      *process.PFTausBothProngs
                      *process.PFTausHighEfficiencyBothProngs) 

#process.outpath = cms.EndPath(process.output)
