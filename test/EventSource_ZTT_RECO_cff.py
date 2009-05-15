import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
       '/store/relval/CMSSW_3_1_0_pre6/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0002/FE76B34E-8F32-DE11-8208-000423D9853C.root',
       '/store/relval/CMSSW_3_1_0_pre6/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0002/C4077B7A-1733-DE11-84AA-001617C3B77C.root',
       '/store/relval/CMSSW_3_1_0_pre6/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0002/B4C86624-8B32-DE11-A2B3-000423D98B6C.root',
       '/store/relval/CMSSW_3_1_0_pre6/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0002/4AB04CA2-9032-DE11-AD66-000423D992DC.root' ] );


secFiles.extend( [
               ] )

