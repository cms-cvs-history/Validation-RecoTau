import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)

readFiles.extend( [
    '/store/relval/CMSSW_5_0_0_pre7/Mu/RECO/GR_R_50_V5_RelVal_mu2010B-v1/0068/F082701B-1A22-E111-9238-00304867C1BA.root',
    '/store/relval/CMSSW_5_0_0_pre7/Mu/RECO/GR_R_50_V5_RelVal_mu2010B-v1/0000/F25CCACA-FD21-E111-BD1C-003048FFCBA8.root',
    '/store/relval/CMSSW_5_0_0_pre7/Mu/RECO/GR_R_50_V5_RelVal_mu2010B-v1/0000/E4987CBD-FD21-E111-A4A0-003048679044.root',
    '/store/relval/CMSSW_5_0_0_pre7/Mu/RECO/GR_R_50_V5_RelVal_mu2010B-v1/0000/E26C39C0-FD21-E111-96D4-001BFCDBD160.root',
    '/store/relval/CMSSW_5_0_0_pre7/Mu/RECO/GR_R_50_V5_RelVal_mu2010B-v1/0000/B28A76B8-FD21-E111-BC3E-00304867C034.root',
    '/store/relval/CMSSW_5_0_0_pre7/Mu/RECO/GR_R_50_V5_RelVal_mu2010B-v1/0000/A40713C6-FD21-E111-8CF8-001A92810AE4.root',
    '/store/relval/CMSSW_5_0_0_pre7/Mu/RECO/GR_R_50_V5_RelVal_mu2010B-v1/0000/8C0ED6C8-FD21-E111-947C-003048FF9AC6.root',
] )



