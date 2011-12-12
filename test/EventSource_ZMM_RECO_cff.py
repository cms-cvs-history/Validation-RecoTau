import FWCore.ParameterSet.Config as cms

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
                   'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZMM/GEN-SIM-RECO/START42_V12-v1/0026/40B00842-9ABB-E011-A9D5-003048679000.root',
                   'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZMM/GEN-SIM-RECO/START42_V12-v1/0024/FA374077-D3BA-E011-B079-003048678D78.root',
                   'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZMM/GEN-SIM-RECO/START42_V12-v1/0024/AE0B00F7-D4BA-E011-9AA4-001A928116C6.root',
                   'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZMM/GEN-SIM-RECO/START42_V12-v1/0024/8276ABDD-D6BA-E011-8066-00304867C136.root'                                                         
                   ]);


secFiles.extend( [
   ] )


