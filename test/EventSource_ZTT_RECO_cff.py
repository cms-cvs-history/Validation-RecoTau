import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_2_2_10/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0003/FEB1EC50-033E-DE11-A238-001D09F251B8.root',
   '/store/relval/CMSSW_2_2_10/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0003/8641BD18-033E-DE11-AC0D-001D09F23C73.root',
   '/store/relval/CMSSW_2_2_10/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0003/766B5EE0-023E-DE11-86CB-001D09F251BD.root',
   '/store/relval/CMSSW_2_2_10/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0003/0EC91DF9-073E-DE11-BE0E-001617C3B6C6.root' ] );


secFiles.extend( [
               ] )
