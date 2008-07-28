import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")

# The number of events to be processed.
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(5000) )
    
# For valgrind studies
# process.ProfilerService = cms.Service("ProfilerService",
#    lastEvent = cms.untracked.int32(13),
#    firstEvent = cms.untracked.int32(3),
#    paths = cms.untracked.vstring('p1')
#)

# Include the RandomNumberGeneratorService definition
process.load("FastSimulation/Configuration/RandomServiceInitialization_cff")

process.load("FastSimulation/Configuration/ZToTauTau_cfi")

# Famos sequences (Frontier conditions)
process.load("FastSimulation/Configuration/CommonInputsFake_cff")
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
# process.famosSimHits.SimulateMuons = False

process.load("RecoParticleFlow/Configuration/RecoParticleFlow_cff")
process.load("RecoTauTag/Configuration/RecoPFTauTag_cff")

process.DQMStore = cms.Service("DQMStore")

process.pfTauTagHEBothProngs = cms.EDAnalyzer("PFTauTagVal",
    OutPutFile = cms.string('pftautagHEFastSimtest.root'), ## This name is modified to reflect releaseversion and histograms stored
    PFTauProducer = cms.string('pfRecoTauProducerHighEfficiency'),
    DataType = cms.string('PFTAU'),
    OutPutHistograms = cms.string('OneProngAndThreeProng'),
    PFTauDiscriminatorByIsolationProducer = cms.string('pfRecoTauDiscriminationHighEfficiency'),
    ExtensionName = cms.InputTag("PFTauIsolationValidation"),
    PFTauDiscriminatorAgainstElectronProducer = cms.string('pfRecoTauDiscriminationAgainstElectron'),
    PFTauDiscriminatorAgainstMuonProducer = cms.string('pfRecoTauDiscriminationAgainstMuon'),                                    
    #    string DataType = "QCD"
    GenJetProd = cms.InputTag("iterativeCone5GenJets")
)

# Produce PFTauProducts
process.p1 = cms.Path(process.famosWithParticleFlow*process.famosWithPFTauTagging*process.pfTauTagHEBothProngs)



# Keep the logging output to a nice level #
# process.Timing =  cms.Service("Timing")
# process.load("FWCore/MessageService/MessageLogger_cfi")
# process.MessageLogger.destinations = cms.untracked.vstring("pyDetailedInfo.txt")

