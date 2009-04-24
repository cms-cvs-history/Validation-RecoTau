import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing

process = cms.Process("TEST")

options = VarParsing.VarParsing ('standard')

options.register( 'isSignal',
                  1,
                  VarParsing.VarParsing.multiplicity.singleton,
                  VarParsing.VarParsing.varType.int,
                  "If true, generate and validate Z-TauTau (hadronic only) events. Otherwise, generate QCD FlatPt 15-3000 events."
                 )
options.register( 'Label',
                  "TauValidation",
                  VarParsing.VarParsing.multiplicity.singleton,
                  VarParsing.VarParsing.varType.string,
                  "Label to append to file name.  e.g. CMSSW_3_1_0"
                 )

options.register( 'batchNumber',
                  -1,
                  VarParsing.VarParsing.multiplicity.singleton,
                  VarParsing.VarParsing.varType.int,
                  "If batchNumer >= 0, the number will be appended to the file name, and the efficiencies will not computed (only the numerator/denominators). \n \
                   Additionally, the batch number will be used to create a new RandomSeed."
               )

options.register( 'writeEDMFile',
                  "",
                  VarParsing.VarParsing.multiplicity.singleton,
                  VarParsing.VarParsing.varType.string,
                  "Specify an (optional) output file.  Don't use the default output file flag. Event content will PFTau RECO content along with genParticles"
               )


options.maxEvents = 500
options.isSignal  = 1
options.Label     = "TauValidation"
options.writeEDMFile    = ""

options.parseArguments()

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(options.maxEvents)
)

process.load("Validation.RecoTau.TauTagValidationProducer_cff")
process.load("FastSimulation.Configuration.RandomServiceInitialization_cff")

MyFileLabel = ""

if options.isSignal:
   MyFileLabel = "ZTT"
   process.load("Configuration.Generator.ZTT_Tauola_All_hadronic_cfi")
   process.load("Validation.RecoTau.TauTagValidation_cfi")
else:
   MyFileLabel = "QCD"
   process.load("Configuration.Generator.QCDForPF_cfi")
   process.load("Validation.RecoTau.TauTagValidationGenJets_cfi")

options.writeEDMFile = options.writeEDMFile.replace(".root", "_%s.root" % MyFileLabel)

if options.batchNumber >= 0:
   MyFileLabel += "_%i" % options.batchNumber
   newSeed = process.RandomNumberGeneratorService.theSource.initialSeed.value() + options.batchNumber 
   process.RandomNumberGeneratorService.theSource.initialSeed = cms.untracked.uint32(newSeed)
   process.RandomNumberGeneratorService.generator.initialSeed = cms.untracked.uint32(newSeed)
   print options.writeEDMFile
   options.writeEDMFile = options.writeEDMFile.replace(".root", "_%i.root" % options.batchNumber)
   print "I'm setting the random seed to ", newSeed, " output file: ", options.writeEDMFile

process.DQMStore = cms.Service("DQMStore")

process.load("Validation.RecoTau.RelValHistogramEff_cfi")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("RecoTauTag.Configuration.RecoTauTag_EventContent_cff")
process.load("FastSimulation.Configuration.CommonInputs_cff")

process.load("FastSimulation.Configuration.FamosSequences_cff")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")

process.saveTauEff = cms.EDAnalyzer("DQMSimpleFileSaver",
  outputFileName = cms.string('%s_%s.root' % (options.Label, MyFileLabel))
)

if options.batchNumber >= 0:
   process.runDQMFileActions = cms.Sequence(process.saveTauEff)
else:
   # Only run the efficiency computation if this is a one-off job
   process.runDQMFileActions = cms.Sequence(process.TauEfficiencies*process.saveTauEff)

                                 
process.p = cms.Path(
    process.ProductionFilterSequence*
    process.genParticles*
#    process.famosWithTauTagging*
    process.famosWithElectrons*
    process.famosWithPFTauTagging+
    process.famosWithTauTagging+
#    process.famosWithEverything*
    process.tauGenJetProducer +
    process.tauTagValidationWithTanc +
    process.runDQMFileActions
    )

TauTagValOutputCommands = cms.PSet(
      outputCommands = cms.untracked.vstring('drop *',
         'keep recoPFCandidates_*_*_*',
         'keep *_genParticles_*_*',
         'keep *_tauGenJets_*_*',
         'keep *_selectedGenTauDecays*_*_*'
         )
      )

TauTagValOutputCommands.outputCommands.extend(process.RecoTauTagRECO.outputCommands)

# talk to output module
if options.writeEDMFile != "":
   process.out = cms.OutputModule("PoolOutputModule",
         TauTagValOutputCommands,
         verbose = cms.untracked.bool(False),
         fileName = cms.untracked.string (options.writeEDMFile)
   )
   process.out_step = cms.EndPath(process.out)
else:
   process.out_step = cms.EndPath()

process.schedule = cms.Schedule(process.p,process.out_step)

