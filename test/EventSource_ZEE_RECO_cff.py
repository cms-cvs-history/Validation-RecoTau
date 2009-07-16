import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
   '/store/relval/CMSSW_3_1_1/RelValZEE/GEN-SIM-RECO/STARTUP31X_V1-v2/0003/D85971AE-F36B-DE11-89BC-000423D6AF24.root',
   '/store/relval/CMSSW_3_1_1/RelValZEE/GEN-SIM-RECO/STARTUP31X_V1-v2/0003/C27DE241-F06B-DE11-A0F4-0030487C6090.root',
   '/store/relval/CMSSW_3_1_1/RelValZEE/GEN-SIM-RECO/STARTUP31X_V1-v2/0003/5E478E7C-EF6B-DE11-83BE-001D09F2960F.root',
   '/store/relval/CMSSW_3_1_1/RelValZEE/GEN-SIM-RECO/STARTUP31X_V1-v2/0003/2CE5C24E-FF6B-DE11-B50F-000423D992A4.root',
   '/store/relval/CMSSW_3_1_1/RelValZEE/GEN-SIM-RECO/STARTUP31X_V1-v2/0003/0E9B0F91-F66B-DE11-8373-000423D6AF24.root',
   '/store/relval/CMSSW_3_1_1/RelValZEE/GEN-SIM-RECO/STARTUP31X_V1-v2/0003/00D20C62-F56B-DE11-9E3E-001D09F2438A.root' ] );

secFiles.extend( [
   ] )


