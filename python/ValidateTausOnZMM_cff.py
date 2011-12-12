import FWCore.ParameterSet.Config as cms
from Validation.RecoTau.RecoTauValidation_cfi import *
import copy

from PhysicsTools.HepMCCandAlgos.genParticles_cfi import *
from RecoJets.Configuration.RecoGenJets_cff import *
from RecoJets.Configuration.GenJetParticles_cff import *

from SimGeneral.HepPDTESSource.pythiapdt_cfi import *
selectElectrons = cms.EDProducer(
    "GenParticlePruner",
    src = cms.InputTag("genParticles"),
    select = cms.vstring(
    "drop  *  ", # this is the default
    "keep++ pdgId = 13",
    "keep++ pdgId = -13",
    )
)


selectElectronsForGenJets = copy.deepcopy(genParticlesForJets)

selectElectronsForGenJets.src = cms.InputTag("selectElectrons")

objectTypeSelectedTauValDenominatorModule = copy.deepcopy(iterativeCone5GenJets)
objectTypeSelectedTauValDenominatorModule.src = cms.InputTag("selectElectronsForGenJets")

kinematicSelectedTauValDenominator.src = cms.InputTag('objectTypeSelectedTauValDenominatorModule')

produceDenominator = cms.Sequence(
      selectElectrons
      +selectElectronsForGenJets
      +objectTypeSelectedTauValDenominatorModule
      +kinematicSelectedTauValDenominator
      )

runTauValidationBatchMode = cms.Sequence(
      produceDenominator
      +TauValNumeratorAndDenominator
      )

runTauValidation = cms.Sequence(
      runTauValidationBatchMode
      +TauEfficiencies
      )

