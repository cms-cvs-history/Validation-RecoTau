import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_3_1_0_pre10/RelValZEE/GEN-SIM-RECO/STARTUP_31X_v1/0009/EE1D4CDD-0558-DE11-A5BF-001D09F25208.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZEE/GEN-SIM-RECO/STARTUP_31X_v1/0008/6849C50A-7E57-DE11-B8B1-001D09F28EC1.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZEE/GEN-SIM-RECO/STARTUP_31X_v1/0008/5AE82353-8257-DE11-BA64-001D09F23A6B.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZEE/GEN-SIM-RECO/STARTUP_31X_v1/0008/4E13217F-8057-DE11-A5CD-001617DBD5AC.root' ] );


secFiles.extend( [
   ] )


