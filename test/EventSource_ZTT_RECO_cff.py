import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
       '/store/relval/CMSSW_2_2_9/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0001/F09E3EBD-1C32-DE11-A2FE-000423D99B3E.root',
       '/store/relval/CMSSW_2_2_9/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0001/BEE7E6D1-1B32-DE11-A4EE-000423D996C8.root',
       '/store/relval/CMSSW_2_2_9/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0001/22FECC85-4D32-DE11-958C-001617E30CC8.root',
       '/store/relval/CMSSW_2_2_9/RelValZTT/GEN-SIM-RECO/STARTUP_V11_v1/0001/2062EFDD-2032-DE11-B928-000423D6A6F4.root' ] );


secFiles.extend( [
               ] )
