import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_3_1_0_pre8/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0006/D20FF402-DB4D-DE11-99CB-001D09F291D2.root',
   '/store/relval/CMSSW_3_1_0_pre8/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0005/B42C5631-564D-DE11-9A83-001D09F28C1E.root',
   '/store/relval/CMSSW_3_1_0_pre8/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0005/6652E7C2-604D-DE11-9938-001D09F24353.root',
   '/store/relval/CMSSW_3_1_0_pre8/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0005/545467F2-574D-DE11-8CA5-001D09F2AD7F.root' ] );

secFiles.extend( [
               ] )

