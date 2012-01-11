import FWCore.ParameterSet.Config as cms
from Validation.RecoTau.RecoTauValidation_cfi import *
import copy

from PhysicsTools.HepMCCandAlgos.genParticles_cfi import *
from RecoJets.Configuration.RecoGenJets_cff import *
from RecoJets.Configuration.GenJetParticles_cff import *

kinematicSelectedTauValDenominator = cms.EDFilter(
   "GenJetSelector", #"GenJetSelector"
   src = cms.InputTag('iterativeCone5GenJets'),
   cut = kinematicSelectedTauValDenominatorCut,#cms.string('pt > 5. && abs(eta) < 2.5'), #Defined: Validation.RecoTau.RecoTauValidation_cfi 
   filter = cms.bool(False)
)


produceDenominator = cms.Sequence(
    genParticlesForJets
    *kinematicSelectedTauValDenominator
    )

runTauValidationBatchMode = cms.Sequence(
    produceDenominator
    +TauValNumeratorAndDenominator
    )

runTauValidation = cms.Sequence(
    runTauValidationBatchMode
    +TauEfficiencies
    )
