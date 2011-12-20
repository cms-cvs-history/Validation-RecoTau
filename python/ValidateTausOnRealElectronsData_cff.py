import FWCore.ParameterSet.Config as cms
from Validation.RecoTau.RecoTauValidation_cfi import *
import copy

from RecoJets.Configuration.RecoPFJets_cff import *

selectGoodElectrons = cms.EDFilter(
    'ElectronIdFilter',
    src = cms.InputTag('gsfElectrons'),
    eidsrc = cms.InputTag('eidLoose'),
    eid = cms.int32(13)
    )

kinematicSelectedTauValDenominator = cms.EDFilter( ##FIXME: this should be a filter
   "TauValElectronSelector", #"GenJetSelector"
   src = cms.InputTag("selectGoodElectrons"),
   cut = cms.string(kinematicSelectedTauValDenominatorCut.value()+' && isElectron && (dr04IsolationVariables.tkSumPt + dr04IsolationVariables.ecalRecHitSumEt )/pt < 0.25'),#cms.string('pt > 5. && abs(eta) < 2.5'), #Defined: Validation.RecoTau.RecoTauValidation_cfi 
   filter = cms.bool(False)
)


produceDenominator = cms.Sequence(
    selectGoodElectrons
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
