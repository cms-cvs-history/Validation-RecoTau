import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_3_1_0_pre10/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0009/0EC0E0FE-0558-DE11-986D-001D09F29146.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0008/969D21C1-E857-DE11-A00D-001D09F23D04.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0008/840866A4-EA57-DE11-8A75-001D09F28EC1.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0008/70EDDE9C-E957-DE11-A16D-000423D98868.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0001/CCE6F244-1458-DE11-A5E5-001A92971B5E.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0001/C4E56D8D-075A-DE11-B5E7-001A92971B54.root',
   '/store/relval/CMSSW_3_1_0_pre10/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0001/16E3E391-7059-DE11-9887-001A928116F4.root' ] );



secFiles.extend( [
   ] )

