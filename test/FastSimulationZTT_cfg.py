import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")

# The number of events to be processed.
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )
    
# For valgrind studies
# process.ProfilerService = cms.Service("ProfilerService",
#    lastEvent = cms.untracked.int32(13),
#    firstEvent = cms.untracked.int32(3),
#    paths = cms.untracked.vstring('p1')
#)

# Include the RandomNumberGeneratorService definition
process.load("FastSimulation/Configuration/RandomServiceInitialization_cff")

process.load("FastSimulation/Configuration/ZToTauTau_cfi")
#process.load("GeneratorInterface/Pythia6Interface/test/Ztautau2_cfg")

# Famos sequences (Frontier conditions)
process.load("FastSimulation/Configuration/CommonInputs_cff")
process.load("FastSimulation/Configuration/FamosSequences_cff")

# Parametrized magnetic field (new mapping, 4.0 and 3.8T)
#process.load("Configuration.StandardSequences.MagneticField_40T_cff")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.VolumeBasedMagneticFieldESProducer.useParametrizedTrackerField = True

# If you want to turn on/off pile-up
process.famosPileUp.PileUpSimulator.averageNumber = 0.0    
# You may not want to simulate everything for your study
process.famosSimHits.SimulateCalorimetry = True
process.famosSimHits.SimulateTracking = True

# Get frontier conditions    - not applied in the HCAL, see below
# Values for globaltag are "STARTUP_V5::All", "1PB::All", "10PB::All", "IDEAL_V5::All"
process.GlobalTag.globaltag = "STARTUP_V5::All"

# Apply ECAL miscalibration
process.caloRecHits.RecHitsFactory.doMiscalib = False

# Apply Tracker misalignment
process.famosSimHits.ApplyAlignment = False
process.misalignedTrackerGeometry.applyAlignment = False

# Apply HCAL miscalibration (not ideal in that case) . Choose between hcalmiscalib_startup.xml , hcalmiscalib_1pb.xml , hcalmiscalib_10pb.xml (startup is the default)
process.caloRecHits.RecHitsFactory.HCAL.Refactor = 1.0
process.caloRecHits.RecHitsFactory.HCAL.Refactor_mean = 1.0


# process.famosSimHits.SimulateMuons = False

process.load("RecoTauTag.RecoTau.PFRecoTauDiscriminationAgainstElectron_cfi")
process.load("RecoTauTag.RecoTau.PFRecoTauDiscriminationAgainstMuon_cfi")
process.load("RecoParticleFlow.Configuration.RecoParticleFlow_cff")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")

process.DQMStore = cms.Service("DQMStore")

process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("HLTriggerOffline.Tau.Validation.HLTTauReferences_cfi")

process.load("Validation/RecoTau/TauTagValidation_cfi")

process.load("Validation.RecoTau.RelValHistogramEff_cfi")

# Conditions: fake or frontier

process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")

process.load("RecoTauTag.Configuration.RecoTauTag_EventContent_cff")

# Produce PFTauProducts
process.p1 = cms.Path(process.famosWithEverything
                      *process.PFTau
                      *process.PFTauHighEfficiency
                      *process.tautagging
                      *process.TauMCProducer
                      *process.CaloTausBothProngs
    		      *process.PFTausBothProngs
                      *process.PFTausHighEfficiencyBothProngs
                      *process.TauEfficiencies
                      *process.saveTauEffFast)
