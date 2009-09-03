import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
      '/store/relval/CMSSW_3_3_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V4-v1/0012/FED16463-E295-DE11-9BBE-000423D94494.root',
      '/store/relval/CMSSW_3_3_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V4-v1/0012/CE1E7DD0-0896-DE11-8133-0019B9F705A3.root',
      '/store/relval/CMSSW_3_3_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V4-v1/0012/BC329B63-DD95-DE11-9656-003048D37456.root',
      '/store/relval/CMSSW_3_3_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V4-v1/0012/7C9552D0-DC95-DE11-AE8C-000423D98634.root',
      '/store/relval/CMSSW_3_3_0_pre1/RelValZTT/GEN-SIM-RECO/STARTUP31X_V4-v1/0012/3E5C88E4-DC95-DE11-8694-000423D9863C.root'

      ] )


secFiles.extend( [
   ] )

