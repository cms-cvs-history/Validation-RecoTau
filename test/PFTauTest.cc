#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/TauReco/interface/PFTauDiscriminatorByIsolation.h"
#include "DataFormats/TauReco/interface/PFTauDiscriminator.h"
#include "DataFormats/TauReco/interface/PFTauTagInfo.h"

#include "RecoTauTag/TauTagTools/interface/PFTauElementsOperators.h"
#include "RecoTauTag/TauTagTools/interface/TauTagTools.h"

//#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"

#include <memory>
#include <string>
#include <iostream>

#include <TROOT.h>
#include <TSystem.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TDirectory.h>

#include "FWCore/ServiceRegistry/interface/Service.h" // Framework services
#include "PhysicsTools/UtilAlgos/interface/TFileService.h" // Framework service for histograms
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
//#include <Math/GenVector/VectorUtil.h>

// get rid of this damn TLorentzVector!
#include "DataFormats/Candidate/interface/Particle.h"
#include "DataFormats/Math/interface/deltaR.h"
//#include "TLorentzVector.h"

using namespace edm;
using namespace reco; 
using namespace std;

typedef Particle::LorentzVector LorentzVector;

class PFTauTest : public EDAnalyzer {
public:
  explicit PFTauTest(const ParameterSet&);
  ~PFTauTest() {}
  virtual void analyze(const Event& iEvent,const EventSetup& iSetup);
  virtual void beginJob();
  virtual void endJob();
private:

  DeltaR<LorentzVector> deltaRComputer_;

  string PFTauProducer_;
  string PFTauDiscriminatorByIsolationProducer_;
  string PFTauDiscriminatorAgainstElectronProducer_;
  string PFTauDiscriminatorAgainstMuonProducer_;
  string GenParticles_;

  
  int nEvent;
  int nTauMatchPFTau;
  int nElecMatchPFTau;
  int nTauElecPreID;
  int nElecElecPreID;
  int nTauNonElecPreID;
  int nElecNonElecPreID;

  // files
  std::string _fileName;
  TFile *_file;
  TDirectory *_dir;

  
  TH2F* h_ElecEff_eid1_HvsEoP;
};

PFTauTest::PFTauTest(const ParameterSet& iConfig){
  PFTauProducer_                         = iConfig.getParameter<string>("PFTauProducer");
 
  nEvent=0;

  nTauMatchPFTau=0;
  nElecMatchPFTau=0;
  nTauElecPreID=0;
  nElecElecPreID=0;
  nTauNonElecPreID=0;
  nElecNonElecPreID=0;

 
}

void PFTauTest::beginJob(){
}

void PFTauTest::analyze(const Event& iEvent, const EventSetup& iSetup){
  //cout<<"********"<<endl;
  //cout<<"Event number "<<nEvent++<<endl;



  ////////////////////////////////////////////////////////  

 
   
  Handle<PFTauCollection> thePFTauHandle;
  iEvent.getByLabel(PFTauProducer_,thePFTauHandle);
 

  //int n = 0;
  // Tau Loop
  for (PFTauCollection::size_type iPFTau=0;iPFTau<thePFTauHandle->size();iPFTau++) 
    { 
      PFTauRef thePFTau(thePFTauHandle,iPFTau); 
      //  PFTauElementsOperators myPFTauElementsOperators(*thePFTau);      
      //      PFCandidateRef myleadPFCand=myPFTauElementsOperators.leadPFChargedHadrCand("DR",0.1,5.0);
      if((*thePFTau).pt()< 5 ) continue;
	cout << "Et "<< (*thePFTau).pt()<<" Eta "<<(*thePFTau).eta() <<" Phi "<< (*thePFTau).phi()<<endl;
	
	PFCandidateRefVector myPFCands = thePFTau->signalPFCands();
	for(int i =0; i<myPFCands.size(); i++)
	  {
	    cout <<"Pt "<<myPFCands[i]->pt() << " Eta "<< myPFCands[i]->eta()  <<" Phi "<< myPFCands[i]->phi() <<" PDG ID "<<myPFCands[i]->pdgId()<<endl;
	  }


      if(thePFTau->leadPFCand().isNonnull()){
	cout<<"****************************"<<endl;
	cout << "Leading PF  (eta/phi/pt)"<<thePFTau->leadPFCand()->eta() <<" "<<thePFTau->leadPFCand()->phi() <<" "<<thePFTau->leadPFCand()->pt()<<endl;
	if(thePFTau->leadTrack().isNonnull()){
	  cout <<"Leading Track (eta/phi/pt)"<<thePFTau->leadTrack()->eta() <<" "<<thePFTau->leadTrack()->phi() <<" "<<thePFTau->leadTrack()->pt()<<endl;
	}else{
	cout <<"No lead track associated "<<endl;
	}
      } 
    }
}
void PFTauTest::endJob(){
  /*
  cout<<"**********************************"<<endl;
  cout<<"Electron rejection efficiencies"<<endl;
  cout<<"**********************************"<<endl;
  if (nTauMatchPFTau>0) {
    cout<<"Taus ("<<nTauMatchPFTau<<"):"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"  Passed: "<< (float)nTauNonElecPreID/(float)nTauMatchPFTau <<endl;
    cout<<"Rejected: "<< (float)nTauElecPreID/(float)nTauMatchPFTau <<endl;
  }
  if (nElecMatchPFTau>0) {
    cout<<"\nElectrons ("<<nElecMatchPFTau<<"):"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"  Passed: "<< (float)nElecNonElecPreID/(float)nElecMatchPFTau <<endl;
    cout<<"Rejected: "<< (float)nElecElecPreID/(float)nElecMatchPFTau <<endl;
  }
  */
}

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(PFTauTest);
