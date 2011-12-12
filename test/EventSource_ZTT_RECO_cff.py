import FWCore.ParameterSet.Config as cms

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
                   #   '/store/relval/CMSSW_4_2_0_pre6/RelValZTT/GEN-SIM-RECO/START42_V4-v1/0023/267CF021-A645-E011-A05B-00261894391D.root',
                   #   '/store/relval/CMSSW_4_2_0_pre6/RelValZTT/GEN-SIM-RECO/START42_V4-v1/0020/52137829-5945-E011-B764-00261894383F.root',
                   #   '/store/relval/CMSSW_4_2_0_pre6/RelValZTT/GEN-SIM-RECO/START42_V4-v1/0020/24E484D7-5A45-E011-8B00-00261894394B.root'
                   #'file:///disk1/perchalla/store/relval/CMSSW_4_2_8/RelValZTT/GEN-SIM-RECO/START42_V12-v1/0026/609087DF-8CBB-E011-AF17-001A92971B08.root'
                   'file:///disk1/perchalla/store/relval/CMSSW_4_4_0/RelValZTT/GEN-SIM-RECO/START44_V5-v2/0047/220DB039-0FE6-E011-A72C-001A92811720.root'
                   'file:///disk1/perchalla/store/relval/CMSSW_4_4_0/RelValZTT/GEN-SIM-RECO/START44_V5-v2/0047/5AE7DF69-BFE6-E011-8AF2-0030486790B0.root'
                   'file:///disk1/perchalla/store/relval/CMSSW_4_4_0/RelValZTT/GEN-SIM-RECO/START44_V5-v2/0047/8699ED0C-09E6-E011-B925-003048D15E02.root'
] )


secFiles.extend( [
   ] )
