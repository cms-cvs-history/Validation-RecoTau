# The following comments couldn't be translated into the new config version:

#module execution use first line for Z->TauTau sample and the second for QCD sample changing accordingly the DataType on the PFTauTagVal module above

import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("HLTriggerOffline.Tau.Validation.HLTTauReferences_cfi")

process.load("Validation/RecoTau/TauTagValidation_cfi")

# Conditions: fake or frontier
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'IDEAL_V9::All'

process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("RecoTauTag.Configuration.RecoTauTag_cff")

process.DQMStore = cms.Service("DQMStore")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_0.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_1.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_10.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_2.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_3.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_4.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_5.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_6.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_7.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_8.root',
'rfio:/castor/cern.ch/user/b/beaudett/grid/CMSSW_2_2_1/iteration-5/ZTT_Tauola_cfi_GEN_FASTSIM_IDEAL_9.root'
)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
    ignoreTotal = cms.untracked.int32(1) ## default is one
)

process.load("RecoTauTag.Configuration.RecoTauTag_EventContent_cff")
process.load("Configuration.EventContent.EventContent_cff")

process.load("Validation.RecoTau.RelValHistogramEff_cfi")
                                 
process.p = cms.Path(  process.TauMCProducer
                      *process.CaloTausBothProngs
    		      *process.PFTausBothProngs
                      *process.PFTausHighEfficiencyBothProngs
                      *process.TauEfficiencies
                      *process.saveTauEffFast)


#process.outpath = cms.EndPath(process.output)
