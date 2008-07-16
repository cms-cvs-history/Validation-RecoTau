# The following comments couldn't be translated into the new config version:

# replace famosSimHits.SimulateMuons = false
# The digis are needed for the L1 simulation
# replace caloRecHits.RecHitsFactory.doDigis=true
# service = Timing { }

import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")
# Include the RandomNumberGeneratorService definition
process.load("FastSimulation.Configuration.RandomServiceInitialization_cff")

process.load("FastSimulation.Configuration.ZToTauTau_cfi")

# Famos sequences (Frontier conditions)
process.load("FastSimulation.Configuration.CommonInputsFake_cff")

process.load("FastSimulation.Configuration.FamosSequences_cff")

process.load("Configuration.StandardSequences.MagneticField_40T_cff")

process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("RecoParticleFlow.Configuration.RecoParticleFlow_cff")

process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10000)
)
process.DQMStore = cms.Service("DQMStore")

process.pfTauTagHEBothProngs = cms.EDFilter("PFTauTagVal",
    OutPutFile = cms.string('pftautagHEFastSimtest.root'), ## This name is modified to reflect releaseversion and histograms stored

    PFTauProducer = cms.string('pfRecoTauProducerHighEfficiency'),
    DataType = cms.string('PFTAU'),
    OutPutHistograms = cms.string('OneProngAndThreeProng'),
    PFTauDiscriminatorByIsolationProducer = cms.string('pfRecoTauDiscriminationHighEfficiency'),
    ExtensionName = cms.InputTag("PFTauIsolationValidation"),
    #    string DataType = "QCD"
    GenJetProd = cms.InputTag("iterativeCone5GenJets")
)

process.p1 = cms.Path(process.famosWithPFTauTagging*process.pfTauTagHEBothProngs)
process.famosPileUp.PileUpSimulator.averageNumber = 0.0
process.VolumeBasedMagneticFieldESProducer.useParametrizedTrackerField = True
process.famosSimHits.SimulateCalorimetry = True
process.famosSimHits.SimulateTracking = True


