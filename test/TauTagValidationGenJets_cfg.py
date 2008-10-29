# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

#process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("HLTriggerOffline.Tau.Validation.HLTTauReferences_cfi")

process.load("Validation.RecoTau.TauTagValidationGenJets_cfi")

process.load("Validation.RecoTau.GenJetRefProducer_cfi")

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
        '/store/relval/CMSSW_2_1_10/RelValZTT/GEN-SIM-DIGI-RAW-HLTDEBUG-RECO/IDEAL_V9_v2/0000/A49D4C86-A999-DD11-BF99-001617C3B5F4.root'
    )
)

process.maxEvents = cms.untracked.PSet( 
    input = cms.untracked.int32(200)
)

process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
    ignoreTotal = cms.untracked.int32(1) ## default is one
)

process.p = cms.Path(process.PFTauHighEfficiency*
                     process.GenJetProducer*
                     process.generatorLevelJets)

#process.p1 = cms.EndPath(process.out)

