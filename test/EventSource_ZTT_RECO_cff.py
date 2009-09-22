import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
       '/store/relval/CMSSW_3_3_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0000/E68941F3-28A7-DE11-AC46-001D09F29524.root',
       '/store/relval/CMSSW_3_3_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0000/DA3F0BA0-71A7-DE11-A6FF-000423D99B3E.root',
       '/store/relval/CMSSW_3_3_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0000/CE11F712-2AA7-DE11-A079-001D09F252DA.root',
       '/store/relval/CMSSW_3_3_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0000/66BB1A85-7AA7-DE11-94EC-001D09F2924F.root',
       '/store/relval/CMSSW_3_3_0_pre4/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0000/048EDD3D-2AA7-DE11-92D3-001D09F251E0.root'
      ] )


secFiles.extend( [
   ] )

