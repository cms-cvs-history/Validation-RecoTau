import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)

readFiles.extend( [
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0069/BE834382-6B22-E111-B099-0026189438C1.root',
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0068/00D44C1F-1A22-E111-8CC6-00248C0BE013.root',
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0000/B433B2D1-FD21-E111-8C19-001A928116C4.root',
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0000/9E47A4C3-FD21-E111-9ED3-003048678E80.root',
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0000/6A4771D0-FD21-E111-A115-001A928116B8.root',
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0000/3E9922D1-FD21-E111-B801-001BFCDBD130.root',
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0000/16CAD2C7-FD21-E111-98A2-0018F3D09664.root',
    '/store/relval/CMSSW_5_0_0_pre7/Electron/RECO/GR_R_50_V5_RelVal_electron2010B-v1/0000/041878C3-FD21-E111-ACE3-003048B95B30.root',
] )



