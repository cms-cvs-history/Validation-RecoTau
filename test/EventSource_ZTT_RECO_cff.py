import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_3_1_0_pre11/RelValZTT/GEN-SIM-RECO/STARTUP31X_V1-v1/0000/6C9BEF7F-AD64-DE11-AE61-001D09F23A6B.root',
   '/store/relval/CMSSW_3_1_0_pre11/RelValZTT/GEN-SIM-RECO/STARTUP31X_V1-v1/0000/62DD9EFC-7164-DE11-B38D-0019B9F72BFF.root',
   '/store/relval/CMSSW_3_1_0_pre11/RelValZTT/GEN-SIM-RECO/STARTUP31X_V1-v1/0000/5E611C51-9864-DE11-A276-001D09F24DA8.root' ] );

secFiles.extend( [
   ] )

