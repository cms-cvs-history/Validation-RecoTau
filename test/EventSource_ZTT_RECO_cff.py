import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_3_1_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0004/CE5810FB-C941-DE11-887D-001D09F28D54.root',
   '/store/relval/CMSSW_3_1_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0004/9CA80F94-E641-DE11-BEB0-001D09F231B0.root',
   '/store/relval/CMSSW_3_1_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0004/7CF1F926-CD41-DE11-BC24-001D09F2915A.root',
   '/store/relval/CMSSW_3_1_0_pre7/RelValZTT/GEN-SIM-RECO/STARTUP_31X_v1/0004/348F91A9-BC41-DE11-B7C9-001D09F2910A.root' ] );

secFiles.extend( [
               ] )

