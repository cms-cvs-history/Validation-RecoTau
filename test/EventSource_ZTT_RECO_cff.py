import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
    '/store/relval/CMSSW_3_5_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP3X_V15-v2/0006/90B313B3-B405-DF11-A7F9-0030487CD77E.root',
    '/store/relval/CMSSW_3_5_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP3X_V15-v2/0006/8C203505-E304-DF11-BC45-00304879EDEA.root',
    '/store/relval/CMSSW_3_5_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP3X_V15-v2/0006/86F0855B-E004-DF11-B3FD-0030487CAEAC.root',
    '/store/relval/CMSSW_3_5_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP3X_V15-v2/0006/22E2607D-E204-DF11-83F3-003048D2BC30.root',
    '/store/relval/CMSSW_3_5_0_pre3/RelValZTT/GEN-SIM-RECO/STARTUP3X_V15-v2/0006/06FAD7DF-DF04-DF11-9D79-003048D3750A.root' 
] )



secFiles.extend( [
   ] )

