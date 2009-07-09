import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_3_1_1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V1-v2/0003/DAAF1151-EF6B-DE11-B09A-000423D6A6F4.root',
   '/store/relval/CMSSW_3_1_1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V1-v2/0002/98101275-E36B-DE11-9E7A-001D09F2A465.root',
   '/store/relval/CMSSW_3_1_1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V1-v2/0002/7481E874-E36B-DE11-AEC1-0019B9F72BFF.root',
   '/store/relval/CMSSW_3_1_1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V1-v2/0002/2C6D327D-E36B-DE11-9E9B-000423D98844.root' ] );


secFiles.extend( [
   ] )

