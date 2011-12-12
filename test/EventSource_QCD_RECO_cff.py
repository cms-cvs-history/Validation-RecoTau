import FWCore.ParameterSet.Config as cms

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
                   #'rfio:/castor/cern.ch/user/f/friis/CMSSW_4_1_x/skims/QCD/QCD_PU/QCD_PU_10_1_Z95.root',
                   #    'rfio:/castor/cern.ch/user/f/friis/CMSSW_4_1_x/skims/QCD/QCD_PU/QCD_PU_1_1_NzT.root',
                   'file:///disk1/perchalla/data/relval/CMSSW_4_2_8/RelValQCD_Pt_80_120/GEN-SIM-RECO/START42_V12-v1/0030/0E9DB677-B5BB-E011-829C-0026189438EF.root'
] )



secFiles.extend( [
   ] )

