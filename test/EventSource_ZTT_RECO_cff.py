import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
      '/store/relval/CMSSW_3_3_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0015/C8E94ACD-799F-DE11-9822-001D09F28E80.root',
      '/store/relval/CMSSW_3_3_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0015/927779ED-5F9F-DE11-AC7C-000423D6B48C.root',
      '/store/relval/CMSSW_3_3_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0015/34755BD3-619F-DE11-8E43-001D09F24691.root',
      '/store/relval/CMSSW_3_3_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP31X_V7-v1/0015/000857CA-609F-DE11-93DC-000423D992A4.root'

      ] )


secFiles.extend( [
   ] )

