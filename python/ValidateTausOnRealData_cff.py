import FWCore.ParameterSet.Config as cms
from Validation.RecoTau.RecoTauValidation_cfi import *
import copy

from RecoJets.Configuration.RecoPFJets_cff import *
from RecoJets.Configuration.GenJetParticles_cff import *

kinematicSelectedTauValDenominator.src = cms.InputTag("ak5PFJets") ##FIXME: this should be a filter

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
