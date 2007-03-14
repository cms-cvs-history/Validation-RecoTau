#ifndef TauTagVal_EMIso_h
#define TauTagVal_EMIso_h

// -*- C++ -*-
//
// Package:    TauTagVal_EMIso
// Class:      TauTagVal_EMIso
// 
/**\class TauTagVal_EMIso TauTagVal_EMIso.cc 

 Description: EDAnalyzer to validate the Collections from the ConeIsolation Producer
 It is supposed to be used for Offline Tau Reconstrction, so PrimaryVertex should be used.
 Implementation:
  
*/
//
// Original Author:  Simone Gennai
//
//



// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/BTauReco/interface/JetTracksAssociation.h"
#include "DataFormats/BTauReco/interface/EMIsolatedTauTagInfo.h"
#include "DataFormats/BTauReco/interface/IsolatedTauTagInfo.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"

// Math
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"
#include "TLorentzVector.h"
#include "TH1D.h"
#include <vector>

class MonitorElement;

//
// class decleration
//

    
class TauTagVal_EMIso : public edm::EDAnalyzer {
public:



  explicit TauTagVal_EMIso(const edm::ParameterSet&);
  ~TauTagVal_EMIso() {}

  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  virtual void beginJob();
  virtual void endJob();
  
  vector<HepMC::GenParticle*> DaughtersVec(vector<HepMC::GenParticle*> pvec)
  {
    vector<HepMC::GenParticle*>Daughters;
    HepMC::GenVertex* end_vertex;

    for(vector<HepMC::GenParticle*>::iterator pvecit=pvec.begin();pvecit!=pvec.end();pvecit++)
      {
	end_vertex = (*pvecit)->end_vertex();
	if(end_vertex){
	  HepMC::GenVertex::particles_out_const_iterator outp;
	  for(outp=end_vertex->particles_out_const_begin();outp!=end_vertex->particles_out_const_end();++outp)
	    {
	      Daughters.push_back((*outp));
	    }
	}
      }
    return Daughters;
  }
  vector<HepMC::GenParticle*> Daughters(HepMC::GenParticle* p)
  {
    vector<HepMC::GenParticle*>Daughters;
    HepMC::GenVertex* end_vertex;
    end_vertex = p->end_vertex();
    if(end_vertex)
      {
	HepMC::GenVertex::particles_out_const_iterator outp;
	for(outp=end_vertex->particles_out_const_begin();outp!=end_vertex->particles_out_const_end();++outp)
	  {
	    Daughters.push_back((*outp));
	  }
      }
    return Daughters;
  }  

  double dR(TLorentzVector* v1,TLorentzVector* v2)
  {
    double DR;
    double dphi=fabs(v1->Phi()-v2->Phi());
    if(dphi>acos(-1.0))dphi=2*acos(-1.0)-dphi;
    double deta=fabs(v1->Eta()-v2->Eta());
    DR=sqrt(dphi*dphi+deta*deta);
    return DR;
  }

  double Vec3dR(TVector3* v1,TVector3* v2)
  {
    double DR;
    double dphi=fabs(v1->Phi()-v2->Phi());
    if(dphi>acos(-1.0))dphi=2*acos(-1.0)-dphi;
    double deta=fabs(v1->Eta()-v2->Eta());
    DR=sqrt(dphi*dphi+deta*deta);
    return DR;
  }

private:
  int nEvent;
  int nRuns;
  vector<float> nEventsUsed;
  edm::InputTag jetTagSrc;
  vector<float> nEventsRiso;
  vector<float> nEventsEnergyUsed;
  vector<float> nEventsEnergy;
  vector<float> energyBins;
  
  vector<double>nEventsUsed07;
  vector<double>nEventsRiso07;

  vector<double>nEventsUsed107;
  vector<double>nEventsRiso107;


  vector<double>nEventsUsed207;
  vector<double>nEventsRiso207;

  vector<double>nEventsUsed307;
  vector<double>nEventsRiso307;



  TH1D* hRatio;
  TH1D* hRatioEta;
  vector<TH1D*> ratio;
  vector<TH1D*> ratioEta;
  vector<double> etbin;
  
  std::string outPutFile;
  float rSig,rMatch,ptLeadTk, rIso;
  MonitorElement* effVsRiso07;
  MonitorElement* effVsRiso107;
  MonitorElement* effVsRiso207;
  MonitorElement* effVsRiso307;


   

};

#endif










