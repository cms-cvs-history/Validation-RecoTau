import FWCore.ParameterSet.Config as cms

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
    '/store/relval/CMSSW_4_4_2/RelValZMM/GEN-SIM-RECO/START44_V7-v1/0067/8646C2B8-6605-E111-87E6-002618943879.root',
    '/store/relval/CMSSW_4_4_2/RelValZMM/GEN-SIM-RECO/START44_V7-v1/0060/CC0BE8AF-7802-E111-8970-0018F3D0961E.root',
    '/store/relval/CMSSW_4_4_2/RelValZMM/GEN-SIM-RECO/START44_V7-v1/0060/4618D130-7902-E111-9A07-0018F3D0961E.root',
] );


secFiles.extend( [
   ] )


