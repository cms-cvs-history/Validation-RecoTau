import FWCore.ParameterSet.Config as cms
from Validation.RecoTau.RecoTauValidation_cfi import *
import copy

from RecoJets.Configuration.RecoPFJets_cff import *

kinematicSelectedTauValDenominator = cms.EDFilter( ##FIXME: this should be a filter
   "TauValMuonSelector", #"GenJetSelector"
   src = cms.InputTag("muons"),
   cut = cms.string(kinematicSelectedTauValDenominatorCut.value()+' && isGlobalMuon && isTrackerMuon && isPFIsolationValid && (pfIsolationR04.sumChargedParticlePt + max(pfIsolationR04.sumPhotonEt + pfIsolationR04.sumNeutralHadronEt - 0.0729*pfIsolationR04.sumPUPt,0.0) )/pt < 0.25'),#cms.string('pt > 5. && abs(eta) < 2.5'), #Defined: Validation.RecoTau.RecoTauValidation_cfi 
   filter = cms.bool(False)
)


produceDenominator = cms.Sequence(
      kinematicSelectedTauValDenominator
      )

runTauValidationBatchMode = cms.Sequence(
      produceDenominator
      +TauValNumeratorAndDenominator
      )

runTauValidation = cms.Sequence(
      runTauValidationBatchMode
      +TauEfficiencies
      )
