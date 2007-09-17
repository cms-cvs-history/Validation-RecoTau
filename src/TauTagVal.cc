// -*- C++ -*-
//
// Package:    TauTagVal
// Class:      TauTagVal
// 
/**\class TauTagVal TauTagVal.cc RecoTauTag/ConeIsolation/test/TauTagVal.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Simone Gennai/Ricardo Vasquez Sierra
//         Created:  Wed Apr 12 11:12:49 CEST 2006
// $Id: TauTagVal.cc,v 1.10 2007/09/16 12:18:02 vasquez Exp $
//
//
// user include files

#include "Validation/RecoTau/interface/TauTagVal.h"

using namespace edm;
using namespace std;
using namespace reco;

TauTagVal::TauTagVal(const edm::ParameterSet& iConfig)
{
  jetTagSrc_ = iConfig.getParameter<InputTag>("JetTagProd");
  outPutFile_ = iConfig.getParameter<string>("OutPutFile");

  rSig_ = iConfig.getParameter<double>("SignalCone");
  rMatch_ = iConfig.getParameter<double>("MatchingCone");
  rIso_ = iConfig.getParameter<double>("IsolationCone");
  ptLeadTk_ = iConfig.getParameter<double>("MinimumTransverseMomentumLeadingTrack");
  minPtIsoRing_ = iConfig.getParameter<double>("MinimumTransverseMomentumInIsolationRing");
  nTracksInIsolationRing_ = iConfig.getParameter<int>("MaximumNumberOfTracksIsolationRing");
 
  DaqMonitorBEInterface* dbe = &*edm::Service<DaqMonitorBEInterface>();
 
  if(dbe) {

    // What kind of Taus do we originally have!
    dbe->setCurrentFolder("TausAtGenLevel_" + jetTagSrc_.label());    
	
    ptTauMC_    = dbe->book1D("pt_Tau_GenLevel", "pt_Tau_GenLevel", 75, 0., 150.);
    etaTauMC_   = dbe->book1D("eta_Tau_GenLevel", "eta_Tau_GenLevel", 60, -3.0, 3.0 );
    phiTauMC_   = dbe->book1D("phi_Tau_GenLevel", "phi_Tau_GenLevel", 36, -180., 180.);
    energyTauMC_= dbe->book1D("Energy_Tau_GenLevel", "Energy_Tau_GenLevel", 45, 0., 450.0);

    nMCTaus_ptTauJet_ = dbe->book1D("nMC_Taus_vs_ptTauJet", "nMC_Taus_vs_ptTauJet", 75, 0., 150.); 
    nMCTaus_etaTauJet_ = dbe->book1D("nMC_Taus_vs_etaTauJet", "nMC_Taus_vs_etaTauJet", 60, -3.0, 3.0 );
    nMCTaus_phiTauJet_ = dbe->book1D("nMC_Taus_vs_phiTauJet", "nMC_Taus_vs_phiTauJet", 36, -180., 180.);
    nMCTaus_energyTauJet_ = dbe->book1D("nMC_Taus_vs_energyTauJet", "nMC_Taus_vs_energyTauJet", 45, 0., 450.0);

     // Leading Track Related Histograms In case the finding of the leading track is a problem ( with deltaR 0.15 and minimum pt of 1.0 GeV )
    dbe->setCurrentFolder("LeadingTrackPtAndDeltaRStudies_"+jetTagSrc_.label());

    deltaRLeadTk_Jet_ = dbe->book1D("DeltaR_LeadingTrack_in_RecoJet","DeltaR_LeadingTrack_in_RecoJet",30,0.,0.15);    
    ptLeadingTrack_ = dbe->book1D("Leading_track_pt_in_RecoJet", "Leading_track_pt_in_RecoJet", 10, 0., 10.);

    // What are the number of matched IsolatedTauTagInfoCollection with MC jet
    dbe->setCurrentFolder("ReconstructedJet_"+jetTagSrc_.label());

    nRecoJet_ptTauJet_ = dbe->book1D("n_RecoJet_vs_ptTauJet", "n_RecoJet_vs_ptTauJet", 75, 0., 150.);
    nRecoJet_etaTauJet_ = dbe->book1D("n_RecoJet_vs_etaTauJet", "n_RecoJet_vs_etaTauJet",60, -3.0, 3.0 );
    nRecoJet_phiTauJet_ = dbe->book1D("n_RecoJet_vs_phiTauJet", "n_RecoJet_vs_phiTauJet",36, -180.,180.);
    nRecoJet_energyTauJet_ = dbe->book1D("n_RecoJet_vs_energyTauJet", "n_RecoJet_vs_energyTauJet", 45, 0., 450.0);  
    nAssociatedTracks_ = dbe->book1D("Number_Associated_Tracks", "Number_Associated_Tracks", 10, 0., 10.);
    nSelectedTracks_ = dbe->book1D("Number_Selected_Tracks", "Number_Selected_Tracks", 10, 0., 10.);

    // What are the number of RecoJets that are matched to MC Tau with a LeadingTrack of 6.0 GeV
    dbe->setCurrentFolder("ReconstructedJetWithLeadingTrack_"+jetTagSrc_.label());

    nRecoJet_LeadingTrack_ptTauJet_ = dbe->book1D("n_RecoJet+LeadingTrack_vs_ptTauJet", "n_RecoJet+LeadingTrack_vs_ptTauJet", 75, 0., 150.);
    nRecoJet_LeadingTrack_etaTauJet_ = dbe->book1D("n_RecoJet+LeadingTrack_vs_etaTauJet", "n_RecoJet+LeadingTrack_vs_etaTauJet",60, -3.0, 3.0 );
    nRecoJet_LeadingTrack_phiTauJet_ = dbe->book1D("n_RecoJet+LeadingTrack_vs_phiTauJet", "n_RecoJet+LeadingTrack_vs_phiTauJet",36,-180.,180);
    nRecoJet_LeadingTrack_energyTauJet_ = dbe->book1D("n_RecoJet+LeadingTrack_vs_energyTauJet", "n_RecoJet+LeadingTrack_vs_energyTauJet", 45, 0., 450.0); 
    nSignalTracks_ = dbe->book1D("Number_Signal_Tracks", "Number_Signal_Tracks", 10, 0., 10.); 

    // What are the numbers of Tagged and matched IsolatedTauTagInfoCollection with  MC Jet
    dbe->setCurrentFolder("TauTaggedJets_"+jetTagSrc_.label());

    nIsolatedJet_ptTauJet_ =       dbe->book1D("n_IsolatedTauTaggedJets_vs_ptTauJet","n_IsolatedTauTaggedJets_vs_ptTauJet", 75, 0., 150.);
    nIsolatedJet_etaTauJet_ =      dbe->book1D("n_IsolatedTauTaggedJets_vs_etaTauJet","n_IsolatedTauTaggedJets_vs_etaTauJet", 60, -3.0, 3.0 );
    nIsolatedJet_phiTauJet_ =      dbe->book1D("n_IsolatedTauTaggedJets_vs_phiTauJet","n_IsolatedTauTaggedJets_vs_phiTauJets", 36, -180., 180);
    nIsolatedJet_energyTauJet_ =   dbe->book1D("n_IsolatedTauTaggedJets_vs_energyTauJet", "n_IsolatedTauTaggedJets_vs_energyTauJet", 45, 0., 450.0);    
    nSignalTracksAfterIsolation_ = dbe->book1D("Signal_Tks_After_Isolation", "Signal_Tks_After_Isolation", 10, 0., 10.);
    nIsolatedTausLeadingTrackPt_ = dbe->book1D("LeadingTrackPt_After_Isolation", "LeadingTrackPt_After_Isolation",  75, 0., 150.);
    nIsolatedTausDeltaR_LTandJet_= dbe->book1D("DeltaR_LT_and_Jet_After_Isolation","DeltaR_LT_and_Jet_After_Isolation", 22, 0.,0.11);
    nAssociatedTracks_of_IsolatedTaus_ = dbe->book1D("Associated_Tks_After_Isolation","Associated_Tks_After_Isolation", 10, 0., 10.);
    nSelectedTracks_of_IsolatedTaus_ = dbe->book1D("Selected_Tks_After_Isolation","Selected_Tks_After_Isolation", 10, 0., 10.); 

 // What is the behaviour of cone isolation size on tagging of MC Taus (CONE_MATCHING_CRITERIA) 
    dbe->setCurrentFolder("TaggingStudies_"+ jetTagSrc_.label());
  
    nTausTotvsConeIsolation_ = dbe->book1D("nTaus_Tot_vs_coneIsolation", "nTaus_Tot_vs_coneIsolation", 6,0.175,0.475); // six bins centered at 0.2. 0.25. 0.3, 0.35, 0.4. 0.45
    nTausTaggedvsConeIsolation_ = dbe->book1D("nTaus_Tagged_vs_coneIsolation", "nTaus_Tagged_vs_coneIsolation", 6,0.175,0.475);

    nTausTotvsConeSignal_ = dbe->book1D("nTaus_Tot_vs_coneSignal","nTaus_Tot_vs_coneSignal", 6, 0.065, 0.125);
    nTausTaggedvsConeSignal_ = dbe->book1D("nTaus_Tagged_vs_coneSignal","nTaus_Tagged_vs_coneSignal", 6, 0.065, 0.125);  

    nTausTotvsPtLeadingTrack_ = dbe->book1D("nTaus_Tot_vs_PtLeadingTrack","nTaus_Tot_vs_PtLeadingTrack", 6, 1.5, 7.5);
    nTausTaggedvsPtLeadingTrack_ = dbe->book1D("nTaus_Tagged_vs_PtLeadingTrack","nTaus_Tagged_vs_PtLeadingTrack",6, 1.5, 7.5);

    nTausTotvsMatchingConeSize_ = dbe->book1D("nTaus_Tot_vs_MatchingConeSize","nTaus_Tot_vs_MatchingConeSize", 6, 0.065, 0.125);
    nTausTaggedvsMatchingConeSize_ = dbe->book1D("nTaus_Tagged_vs_MatchingConeSize","nTaus_Tagged_vs_MatchingConeSize", 6, 0.065, 0.125);
    TString tversion(edm::getReleaseVersion());
    cout<<endl<<"-----------------------*******************************Version: " << tversion<<endl;
  }
    
  if (outPutFile_.empty ()) {
    LogInfo("OutputInfo") << " TauJet histograms will NOT be saved";
  } else {
    LogInfo("OutputInfo") << " TauJethistograms will be saved to file:" << outPutFile_;
  }

  //---- book-keeping information ---
  numEvents_ = 0 ;
  
}

void TauTagVal::beginJob()
{ 


}

// -- method called to produce fill all the histograms --------------------
void TauTagVal::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace reco;
  numEvents_++;
  //  std::cout << "--------------------------------------------------------------"<<endl;
  //std::cout << " RunNumber: " << iEvent.id().run() << ", EventNumber: " << iEvent.id().event() << std:: endl;
  //std::cout << "Event number: " << ++numEvents_ << endl;
  //std::cout << "--------------------------------------------------------------"<<endl;

  // ------------------------ MC product stuff -------------------------------------------------------------------------
  Handle<HepMCProduct> evt;
  iEvent.getByLabel("source", evt);

  HepMC::GenEvent * myGenEvent = new  HepMC::GenEvent(*(evt->GetEvent()));

  // Get a TLorentzVector with the Visible Taus at Generator level (the momentum of the neutrino is substracted
  vector<TLorentzVector> TauJetsMC=getVectorOfVisibleTauJets(myGenEvent); 
  //---------------------LET's See what this CaloTau has -----------------

  //Handle<CaloTauCollection> theCaloTauHandle;
  //iEvent.getByLabel("caloRecoTauProducer" ,theCaloTauHandle);
  
  //  cout<<"***"<<endl;
  //cout<<"Found "<<theCaloTauHandle->size()<<" had. tau-jet candidates"<<endl;

  //  myGenEvent->print();
  // CaloJets iterativeCone5CaloJets counting stuff-----------------------------------------------------------------------------------------------
  /*  Handle<CaloJetCollection> jetHandle;
  iEvent.getByLabel("iterativeCone5CaloJets", jetHandle);
  CaloJetCollection jetCollection = *(jetHandle.product());
 
  int CaloJetsIterativeCone5 =0;
  CaloJetCollection::const_iterator k = jetCollection.begin();
  
  for(; k!=jetCollection.end(); k++) {
    CaloJetsIterativeCone5++;
  }
  cout<<"-------------------------------------------------------------------------"<<endl;
  cout<<"CaloJetsIterativeCone5: "<<CaloJetsIterativeCone5<<endl;


  // PFJets iterativeCone5PFJets---------------------------------------------------------------------------------------------

  Handle<PFJetCollection> pfjetHandle;
  iEvent.getByLabel("iterativeCone5PFJets", pfjetHandle);
  PFJetCollection pfjetCollection = *(pfjetHandle.product());
  int PFJetsIterativeCone5 = 0;
  
  PFJetCollection::const_iterator l = pfjetCollection.begin();
  for (; l!=pfjetCollection.end(); l++){
    PFJetsIterativeCone5++;
  }
  cout<<"PFJetsIterativeCone5: "<< PFJetsIterativeCone5<<endl;*/
//---------------------------------------- IsolatedTauTagInfoCollection -------------------------------------------------
// ----------------------------------- Matching and filling up histograms -----------------------------------------------
  Handle<IsolatedTauTagInfoCollection> tauTagInfoHandle;
  iEvent.getByLabel(jetTagSrc_, tauTagInfoHandle);
  
  const IsolatedTauTagInfoCollection & tauTagInfo = *(tauTagInfoHandle.product());
  IsolatedTauTagInfoCollection::const_iterator i = tauTagInfo.begin();
  int numTauRecoJets = 0;
  int num_taujet_candidates=0;
  //bool trueTauJet=false;
  
  //  cout <<rMatch_<<" "<< rSig_ << " "<< rIso_ << " "<< ptLeadTk_ << " " << minPtIsoRing_ << " "<< nTracksInIsolationRing_ << endl;
 
  for (; i != tauTagInfo.end(); ++i) {  // Loop over all the IsolatedTauTagInfoCollection
    num_taujet_candidates++;
    TLorentzVector recoTauJet(i->jet()->px(), i->jet()->py(),i->jet()->pz(),i->jet()->energy());
    bool trueTauJet=false;
    std::vector<TLorentzVector>::iterator MCjet;
    for (MCjet = TauJetsMC.begin(); MCjet != TauJetsMC.end(); MCjet++){ 
      if ( MCjet->DeltaR(recoTauJet) < 0.15 ) {
	trueTauJet=true;
	numTauRecoJets++;
        break;
      }
    }

    // If the IsolatedTauTagInfoCollection is matched to a MC Tau then continue
    if (trueTauJet) {

      nRecoJet_ptTauJet_->Fill(MCjet->Perp());  // Fill the histogram with the Pt, Eta, Energy of the Tau Jet at Generator level only for matched Jets
      nRecoJet_etaTauJet_->Fill(MCjet->Eta());  // How many Taus became RecoJets
      nRecoJet_phiTauJet_->Fill(MCjet->Phi()*180.0/TMath::Pi());
      nRecoJet_energyTauJet_->Fill(MCjet->E()); 

      nAssociatedTracks_->Fill(double(i->allTracks().size()));   // Fill histogram with lower kind of tracks quality kind inside of the 0.5 cone around the Jet Momentum
      nSelectedTracks_->Fill(double(i->selectedTracks().size()));// # Tracks of the following quality PixelHits >= 2, TotalHits >= 8, Chi^2/ndf < 100, Transverse IP < 0.03.
      
      if(!(i->leadingSignalTrack(rMatch_, ptLeadTk_))) {} else { // Fill in the histogram if a leading track is found how many Taus that became RecoJets have a leading track
	nRecoJet_LeadingTrack_ptTauJet_->Fill(MCjet->Perp());  // Fill the histogram with the Pt, Eta, Energy of the Tau Jet at Generator level only for matched Jets
	nRecoJet_LeadingTrack_etaTauJet_->Fill(MCjet->Eta());  // How many Tau became RecoJets
        nRecoJet_LeadingTrack_phiTauJet_->Fill(MCjet->Phi()*180.0/TMath::Pi());
	nRecoJet_LeadingTrack_energyTauJet_->Fill(MCjet->E()); 
      }	
      
      if ( i->discriminator(rMatch_, rSig_, rIso_, ptLeadTk_, minPtIsoRing_, nTracksInIsolationRing_)==1) {
	nIsolatedJet_ptTauJet_->Fill(MCjet->Perp());  // Fill the histogram with the Pt, Eta, Energy of the Tau Jet at Generator level only for matched Jets
	nIsolatedJet_etaTauJet_->Fill(MCjet->Eta()); 
        nIsolatedJet_phiTauJet_->Fill(MCjet->Phi()*180./TMath::Pi()); 
	nIsolatedJet_energyTauJet_->Fill(MCjet->E());
        nAssociatedTracks_of_IsolatedTaus_->Fill(double(i->allTracks().size()));
        nSelectedTracks_of_IsolatedTaus_->Fill(double(i->selectedTracks().size()));	
	//	nSignalTracksAfterIsolation->Fill(double (i->tracksInCone(momentum, rSig_,1.)).size()));           // Fill the histograms of the ones that get isolated
      }
      
      // ------------------------------------------------------------------------------------------------------------------------------ 
      // Leading Track of 6 GeV just to find the number of tracks before and after Isolation ------------------------------------------

      const TrackRef leadTk6= (i->leadingSignalTrack(0.10, 6.));  // Get the leading Track for rMatch_ =0.1 and pt greater than 6.0 GeV
      if(!leadTk6)
	{
	   LogInfo("OutputInfo") << " No LeadingTrack" << endl;
	}else{
	math::XYZVector momentum = (*leadTk6).momentum();         // Get the momentum of the leading tack
	
	// Get the number of tracks greater than 1. GeV in cone of 0.07 around the leading track momentum
	nSignalTracks_->Fill(double (i->tracksInCone(momentum, rSig_,  1.).size()));                           // Fill the histogram with this number of tracks
	
	if(i->discriminator(rMatch_,rSig_, rIso_, ptLeadTk_, minPtIsoRing_, nTracksInIsolationRing_) == 1) {//  using rMatch_ = 0.1; rSig_ =0.07; ptLeadTk_ = 6.0, pT_min = 1.0
	  nSignalTracksAfterIsolation_->Fill(double (i->tracksInCone(momentum, rSig_,  1.).size()));           // Fill the histograms of the ones that get isolated
	  nIsolatedTausLeadingTrackPt_->Fill(double (momentum.rho()));
	  math::XYZVector jetMomentum(i->jet()->px(), i->jet()->py(), i->jet()->pz()); 
	  double deltaR = ROOT::Math::VectorUtil::DeltaR(jetMomentum, momentum);         // Calculate the deltaR of the two momenta
          nIsolatedTausDeltaR_LTandJet_->Fill(deltaR);
         
	}
      }
      
      // ------------------------------------------------------------------------------------------------------------------------------ 
      // Now lets study the behaviour of changing cone sizes and Pt of the Leading Track to begin with
      for(int ii=0;ii<6;ii++) {  // Six cone isolation size steps

	double ChangingIsoCone = ii*0.05 + 0.2;    // calculate the size of the Isolation Ring
	if (i->discriminator(rMatch_,rSig_, ChangingIsoCone, ptLeadTk_, minPtIsoRing_, nTracksInIsolationRing_) == 1)
	  nTausTaggedvsConeIsolation_->Fill(ChangingIsoCone);
	
	double ChangingSigCone = ii*0.01+0.07;
	if (i->discriminator(rMatch_,ChangingSigCone, rIso_, ptLeadTk_, minPtIsoRing_, nTracksInIsolationRing_) == 1)
	  nTausTaggedvsConeSignal_->Fill(ChangingSigCone);
	
	int ChangingPtLeadTk = int(ii*1.0 + 2.0);
	if (i->discriminator(rMatch_,rSig_, rIso_, ChangingPtLeadTk, minPtIsoRing_, nTracksInIsolationRing_) == 1)
	  nTausTaggedvsPtLeadingTrack_->Fill(double (ChangingPtLeadTk));

	double ChangingMatchingCone = ii*0.01 + 0.07;
 	if (i->discriminator(ChangingMatchingCone,rSig_, rIso_, ptLeadTk_, minPtIsoRing_, nTracksInIsolationRing_) == 1)
	  nTausTaggedvsMatchingConeSize_->Fill(ChangingMatchingCone);
	  
      }

      // ------------------------------------------------------------------------------------------------------------------------------ 
      // Leading track Finding much more relaxed, just to see how the Leading tracks are behaving!!!!----------------------------------

      const TrackRef leadTk1= (i->leadingSignalTrack(0.10, 1.));  // Get the leading Track for rMatch_ =0.10 and pt greater than 1.0 GeV
      
      if(!leadTk1)
	{
	  LogInfo("OutputInfo") << " No LeadingTrack 2" << endl;
	}else{
	ptLeadingTrack_->Fill((*leadTk1).pt());                    // Fill the ptLeadingTrack histogram with the pt of the leadTrack found
      }


      const TrackRef leadTk2= (i->leadingSignalTrack(0.15,6.0));  //   Get the leading Track for rMatch_ =0.15 and pt greater than 6.0 GeV

      if(!leadTk2)
	{
	  LogInfo("OutputInfo") << " No LeadingTrack 2" << endl;
	}else{	
	math::XYZVector momentum = (*leadTk2).momentum();                           // Get the momentum from the leadingTrack
	math::XYZVector jetMomentum(i->jet()->px(), i->jet()->py(), i->jet()->pz());  // Get the momentum from the Jet
	double deltaR = ROOT::Math::VectorUtil::DeltaR(jetMomentum, momentum);         // Calculate the deltaR of the two momenta
	deltaRLeadTk_Jet_->Fill(deltaR);                                              // Fill the histogram with the value	
	}

    }// end of if (trueTauJet)
  }// end of the IsolatedTauTagInfoCollection loop
  
  //  std::cout<<" Number of Matched Reconstructed Tau Jets: "<<numTauRecoJets_<<endl;
  //std::cout<<"num_taujet_candidates: " <<num_taujet_candidates << endl; 
  delete myGenEvent;  
}

// ---------------------------------------------------------------------------  endJob -----------------------------------------------------------------------

void TauTagVal::endJob(){
  // just fill the denominator histograms for the changing cone sizes

  
  
  double MC_Taus = nMCTaus_etaTauJet_->getEntries();
  double CaloJets_Taus = nRecoJet_etaTauJet_->getEntries();
  double CaloJetsLeadTrack_Taus = nRecoJet_LeadingTrack_etaTauJet_->getEntries();
  double IsolatedTagged_Taus = nIsolatedJet_etaTauJet_->getEntries();
  
  std::streamsize prec = cout.precision();
 
  cout<<setfill('-')<<setw(110)<<"-"<<endl;
  
  cout<<setfill('-')<<setw(55)<<" TAU TAG VALIDATION SUMMARY "<<setw(55)<<"-"<<endl;
  
  cout<<setfill('-')<<setw(92)<<"-"<<setfill(' ')<<setw(9)<<"Rel.Eff."<<setw(9)<<"Tot.Eff."<<endl;
  cout<<setfill('-')<<setw(85)<<left<<" TOTAL NUMBER OF TAUS AT GENERATOR LEVEL: ";
  
  cout<<setfill(' ')<<setw(7) <<right<< nMCTaus_etaTauJet_->getEntries() <<setw(9)<<"--"<<setw(9)<<"--"<< endl;
  
  cout<<setfill('-')<<setw(85)<<left<<" Step 1. TOTAL NUMBER OF ITERATIVE CONE 5 JETS MATCHED TO MC TAUS: ";
  cout<<setfill(' ')<<setw(7) <<right<<nRecoJet_etaTauJet_->getEntries()<<setw(9)<<"--";
  if (MC_Taus > 0) 
    cout<<setw(9)<<setprecision(3)<< CaloJets_Taus/MC_Taus  << setprecision(prec)<<endl;
  else 
    cout<<setw(9)<<"--"<<endl;
  
  cout<<setfill('-')<<setw(85)<<left<<" Step 2. PLUS LEADING TRACK= 6.0 GeV MATCH CONE = 0.1: ";
  cout<<setfill(' ')<<setw(7)<<right<<nRecoJet_LeadingTrack_etaTauJet_->getEntries();
  if (CaloJets_Taus > 0) 
    cout<<setw(9)<<setprecision(3)<< CaloJetsLeadTrack_Taus/CaloJets_Taus <<setprecision(prec);
  else
    cout<<setw(9)<<"--"<<endl;
  
  if (MC_Taus > 0)
    cout<<setw(9)<<setprecision(3)<< CaloJetsLeadTrack_Taus/MC_Taus  << setprecision(prec)<<endl;
  else 
    cout<<setw(9)<<"--"<<endl;

  
 
  cout<<setfill('-')<<setw(85)<<left<<" Step 3. PLUS SIGNAL= 0.07 ISOLATION = 0.45 TRACKS IN ISO = 0 MINIMUM PT = 1.0 GeV: ";
  cout<<setfill(' ')<<setw(7) <<right<<nIsolatedJet_etaTauJet_->getEntries();
  if (CaloJetsLeadTrack_Taus > 0) 
    cout<<setw(9)<<setprecision(3)<< IsolatedTagged_Taus/CaloJetsLeadTrack_Taus <<setprecision(prec);
  else
    cout<<setw(9)<<"--"<<endl;
  
  if (MC_Taus > 0)
    cout<<setw(9)<<setprecision(3)<< IsolatedTagged_Taus/MC_Taus  << setprecision(prec)<<endl;
  else 
    cout<<setw(9)<<"--"<<endl;

  cout<<setfill('-')<<setw(110)<<"-"<<endl;


  if (!outPutFile_.empty() && &*edm::Service<DaqMonitorBEInterface>()) edm::Service<DaqMonitorBEInterface>()->save (outPutFile_);
  
}

// Helper function  

// Get all the daughter particles of a particle
std::vector<HepMC::GenParticle*> TauTagVal::Daughters(HepMC::GenParticle* p)
{
  std::vector<HepMC::GenParticle*>Daughters;
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

//Get a list of visible Tau Jets

std::vector<TLorentzVector> TauTagVal::getVectorOfVisibleTauJets(HepMC::GenEvent *theEvent)
{
  std::vector<TLorentzVector> tempvec;   
  HepMC::GenVertex* TauDecVtx = 0 ;
  int numMCTaus = 0;
  TLorentzVector TauJetMC(0.0,0.0,0.0,0.0);
  for ( HepMC::GenEvent::particle_iterator p = theEvent->particles_begin(); // Loop over all particles
	p != theEvent->particles_end(); ++p ) 
    {
      
      if(abs((*p)->pdg_id())==15 && ((*p)->status()==2))   // Is it a Tau and Decayed?
	{
	  bool FinalTau=true;                           // This looks like a final decayed Tau 
	  TLorentzVector TauNeutrino(0.0,0.0,0.0,0.);   // Neutrino momentum from the Tau decay at GenLevel
	  
	  vector<HepMC::GenParticle*> TauDaught;
          TauDaught=Daughters((*p));
	  
          TauDecVtx = (*p)->end_vertex();
	  
	  if ( TauDecVtx != 0 )
	    {
	      // Loop over Tau Daughter particles and store the Tau neutrino momentum for future use
	      for(vector<HepMC::GenParticle*>::iterator pit=TauDaught.begin();pit!=TauDaught.end();++pit) 
		{
		  if(abs((*pit)->pdg_id())==15) FinalTau=false;
		  if(abs((*pit)->pdg_id())==16) {
		    TauNeutrino=TLorentzVector((*pit)->momentum().px(),(*pit)->momentum().py(),(*pit)->momentum().pz(),(*pit)->momentum().e());
		  }
		}
	    
	      if(FinalTau)   // Meaning: did it find a Neutrino in the list of Daughter particles? Then fill histograms of the original Tau info
		{
		  ptTauMC_->Fill((*p)->momentum().perp());
		  etaTauMC_->Fill((*p)->momentum().eta()); 
                  phiTauMC_->Fill((*p)->momentum().phi()*(180./TMath::Pi()));
		  energyTauMC_->Fill((*p)->momentum().e());		   
                   
                      // Get the Tau Lorentz Vector
		  TLorentzVector theTau((*p)->momentum().x(),(*p)->momentum().y(),(*p)->momentum().z(),(*p)->momentum().e());
		  TauJetMC=theTau-TauNeutrino;      // Substract the Neutrino Lorentz Vector from the Tau
		  if (abs(TauJetMC.Eta())<2.5 && TauJetMC.Perp()>5.0) {
		    nMCTaus_ptTauJet_->Fill(TauJetMC.Perp());  // Fill the histogram with the Pt, Eta, Energy of the Tau Jet at Generator level
		    nMCTaus_etaTauJet_->Fill(TauJetMC.Eta()); 
                    nMCTaus_phiTauJet_->Fill(TauJetMC.Phi()*180./TMath::Pi());
		    nMCTaus_energyTauJet_->Fill(TauJetMC.E());
		    for (int jj =0; jj != 6; jj++){
                      double ChangingIsoCone = jj*0.05 + 0.2;
		      nTausTotvsConeIsolation_->Fill(ChangingIsoCone);
		      double ChangingSigCone = jj*0.01+0.07;
		      nTausTotvsConeSignal_->Fill(ChangingSigCone);
		      int ChangingPtLeadTk = int(jj*1.0 + 2.0);
		      nTausTotvsPtLeadingTrack_->Fill(double (ChangingPtLeadTk));
		      double ChangingMatchingCone = jj*0.01 + 0.07;
		      nTausTotvsMatchingConeSize_->Fill(ChangingMatchingCone);
		    }
		    tempvec.push_back(TauJetMC);
		    ++numMCTaus;
		  }
		}
	    }
	}
  } // closing the loop over the Particles at Generator level

  return tempvec;
  //  cout<<" Number of Taus at Generator Level: "<< numMCTaus << endl; 
}
