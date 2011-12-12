import FWCore.ParameterSet.Config as cms

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
                   'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZEE/GEN-SIM-RECO/START42_V12-v1/0028/66C13220-A1BB-E011-A16A-001A92971B36.root',
                   'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZEE/GEN-SIM-RECO/START42_V12-v1/0025/C4A1AC08-06BB-E011-84BA-001A92971ACE.root',
                   'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZEE/GEN-SIM-RECO/START42_V12-v1/0025/529A2B04-05BB-E011-837A-001A92811708.root'
                   ] )


secFiles.extend( [
   ] )

