import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)

readFiles.extend( [
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/FAC086A7-820B-E111-A4E9-0018F3D09630.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/C0F9B191-820B-E111-8B07-002618943866.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/BCCBCFC8-820B-E111-8B59-0018F3D09630.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/9E106B98-820B-E111-BD0B-0018F3D09600.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/90257325-7D0B-E111-8853-002618943842.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/8A23B7B6-820B-E111-904A-003048678B72.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/7CD4FFB6-820B-E111-94E9-00304867BFB2.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/7CA59591-820B-E111-AD07-0030486792A8.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/6A2D23B6-820B-E111-9B94-002618FDA248.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/66A00FBF-820B-E111-80B1-0018F3D096C6.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/5EA24198-820B-E111-9B9B-0018F3D0960E.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/54A16A25-7D0B-E111-8B7F-00261894398A.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/4AEA1892-820B-E111-A888-00304867929E.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/44497825-7D0B-E111-B605-002618943914.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/2867D4B7-820B-E111-83B6-00261894386D.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/2086F791-820B-E111-8E1C-0030486792AC.root',
    '/store/relval/CMSSW_5_0_0_pre5/Jet/RECO/GR_R_50_V1_RelVal_jet2011A-v1/0000/14C8DD93-820B-E111-ABC8-0018F3D09604.root',
] )



