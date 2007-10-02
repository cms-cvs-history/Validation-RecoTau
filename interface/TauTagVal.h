#ifndef TauTagVal_h
#define TauTagVal_h

// -*- C++ -*-
//
// Package:    TauTagVal
// Class:      TauTagVal
// 
/**\class TauTagVal TauTagVal.cc 

 Description: EDAnalyzer to validate the Collections from the ConeIsolation Producer
 It is supposed to be used for Offline Tau Reconstrction, so PrimaryVertex should be used.
 Implementation:

*/
// Original Author:  Simone Gennai
// Modified by Ricardo Vasquez Sierra On August 29, 2007
// user include files

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "HepMC/GenParticle.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/JetTracksAssociation.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/BTauReco/interface/IsolatedTauTagInfo.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"
//#include "DataFormats/TauReco/interface/CaloTau.h"

// Math
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"
#include "TLorentzVector.h"
#include "TH1D.h"
#include "TH1.h"
#include "TH1F.h"
#include <vector>

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Core/interface/MonitorElement.h"


// class declaration    
class TauTagVal : public edm::EDAnalyzer {

public:
  explicit TauTagVal(const edm::ParameterSet&);
  ~TauTagVal() {}

  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  virtual void beginJob();
  virtual void endJob();

  //  Function to get the Daughters of a Generated Particle 

private:
  //------------HELPER FUNCTIONS---------------------------

  std::vector<HepMC::GenParticle*> Daughters(HepMC::GenParticle* p);
  std::vector<TLorentzVector> getVectorOfVisibleTauJets(HepMC::GenEvent *theEvent);

  // ----------- MEMBER DATA--------------------------------
  edm::InputTag jetTagSrc_;
  
  std::string outPutFile_;
  float rSig_,rMatch_,ptLeadTk_, rIso_, minPtIsoRing_;
  int nTracksInIsolationRing_;

  //AGGIUNGERE MC INFO???

  // MonteCarlo Taus -- to see what kind of Taus do we originally have!
  MonitorElement* ptTauMC_;
  MonitorElement* etaTauMC_;
  MonitorElement* phiTauMC_;
  MonitorElement* energyTauMC_;
 
  MonitorElement* nMCTaus_ptTauJet_;
  MonitorElement* nMCTaus_etaTauJet_;
  MonitorElement* nMCTaus_phiTauJet_;
  MonitorElement* nMCTaus_energyTauJet_;

 
  // Leading Track Related Histograms In case the finding of the leading track is a problem
  MonitorElement* deltaRLeadTk_Jet_;
  MonitorElement* ptLeadingTrack_;

  // The following histograms count the number of matched Montecarlo to isolatedTauTagInfoCollection
  MonitorElement* nRecoJet_ptTauJet_;
  MonitorElement* nRecoJet_etaTauJet_;
  MonitorElement* nRecoJet_phiTauJet_;
  MonitorElement* nRecoJet_energyTauJet_;
  MonitorElement* nAssociatedTracks_;   // for recoJets
  MonitorElement* nSelectedTracks_;     // for recoJets

  // The following histograms count  of RecoJets that are matched to MC Tau with a LeadingTrack of 6.0 GeV
  MonitorElement* nRecoJet_LeadingTrack_ptTauJet_;
  MonitorElement* nRecoJet_LeadingTrack_etaTauJet_;
  MonitorElement* nRecoJet_LeadingTrack_phiTauJet_;
  MonitorElement* nRecoJet_LeadingTrack_energyTauJet_;  
  MonitorElement* nSignalTracks_;                     // Signal Tracks in IsolatedTauTagInfo after finding leading track in rMatch=0.1 and pt 1.0

  // The following histograms count the number of isolated isolatedTauTagInfoCollection
  MonitorElement* nIsolatedJet_ptTauJet_;
  MonitorElement* nIsolatedJet_etaTauJet_;
  MonitorElement* nIsolatedJet_phiTauJet_;
  MonitorElement* nIsolatedJet_energyTauJet_;
  MonitorElement* nSignalTracksAfterIsolation_;       // Same as above but after Isolation
  MonitorElement* nIsolatedTausLeadingTrackPt_;
  MonitorElement* nIsolatedTausDeltaR_LTandJet_;
  MonitorElement* nAssociatedTracks_of_IsolatedTaus_;
  MonitorElement* nSelectedTracks_of_IsolatedTaus_;

  // What is the behaviour of cone isolation size on tagging of MC Taus (CONE_MATCHING_CRITERIA) 
  MonitorElement* nTausTotvsConeIsolation_;
  MonitorElement* nTausTaggedvsConeIsolation_;
  MonitorElement* nTausTotvsConeSignal_;
  MonitorElement* nTausTaggedvsConeSignal_;
  MonitorElement* nTausTotvsPtLeadingTrack_;
  MonitorElement* nTausTaggedvsPtLeadingTrack_;
  MonitorElement* nTausTotvsMatchingConeSize_;
  MonitorElement* nTausTaggedvsMatchingConeSize_;
 
  // book-keeping variables
 
  int numEvents_;

};

#endif











