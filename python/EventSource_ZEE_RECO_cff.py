import FWCore.ParameterSet.Config as cms

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
    '/store/relval/CMSSW_4_4_2/RelValZEE/GEN-SIM-RECO/START44_V7-v1/0061/A2CAF9A5-DB02-E111-B188-001A92971B3A.root',
    '/store/relval/CMSSW_4_4_2/RelValZEE/GEN-SIM-RECO/START44_V7-v1/0060/52847D86-0E02-E111-93ED-00261894392B.root',
] )


secFiles.extend( [
   ] )

