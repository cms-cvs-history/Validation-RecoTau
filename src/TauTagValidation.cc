// -*- C++ -*-
//
// Package:    TauTagValidation
// Class:      TauTagValidation
// 
/**\class TauTagValidation TauTagValidation.cc

 Description: <one line class summary>
 
 Class used to do the Validation of the TauTag

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Ricardo Vasquez Sierra
//         Created:  October 8, 2008
// $Id: TauTagValidation.cc,v 1.12 2009/12/18 20:45:16 wmtan Exp $
//
//
// user include files

#include "Validation/RecoTau/interface/TauTagValidation.h"

using namespace edm;
using namespace std;
using namespace reco;

TauTagValidation::TauTagValidation(const edm::ParameterSet& iConfig)
{
  // What do we want to use as source Leptons or Jets (the only difference is the matching criteria)
  dataType_ = iConfig.getParameter<string>("DataType");

  // We need different matching criteria if we talk about leptons or jets
  matchDeltaR_Leptons_ = iConfig.getParameter<double>("MatchDeltaR_Leptons");
  matchDeltaR_Jets_    = iConfig.getParameter<double>("MatchDeltaR_Jets");

  // The output histograms can be stored or not
  saveoutputhistograms_ = iConfig.getParameter<bool>("SaveOutputHistograms");

  // Here it can be pretty much anything either a lepton or a jet 
  refCollectionInputTag_ = iConfig.getParameter<InputTag>("RefCollection");
  refCollection_ = refCollectionInputTag_.label();
  
  // The extension name has information about the Reference collection used
  extensionName_ = iConfig.getParameter<string>("ExtensionName");
  
  // Here is the reconstructed product of interest.
  TauProducerInputTag_ = iConfig.getParameter<InputTag>("TauProducer");
  TauProducer_ = TauProducerInputTag_.label();

  // The vector of Tau Discriminators to be monitored
  // TauProducerDiscriminators_ = iConfig.getUntrackedParameter<std::vector<string> >("TauProducerDiscriminators");
  
  // The cut on the Discriminators
  //  TauDiscriminatorCuts_ = iConfig.getUntrackedParameter<std::vector<double> > ("TauDiscriminatorCuts");

  WeightValueMapProducerType_ = ( iConfig.exists("WeightProducerType") ) ? 
    iConfig.getParameter<edm::ParameterSet>("WeightProducerType") : edm::ParameterSet();

  WeightValueMapType_ = ( iConfig.exists("WeightValueMapType") ) ? 
    iConfig.getParameter<edm::ParameterSet>("WeightValueMapType") : edm::ParameterSet();

  WeightValueMapDiscriType_ = ( iConfig.exists("WeightDiscriType") ) ? 
    iConfig.getParameter<edm::ParameterSet>("WeightDiscriType") : edm::ParameterSet();


  // Get the discriminators and their cuts
  discriminators_ = iConfig.getParameter< std::vector<edm::ParameterSet> >( "discriminators" ); 

  //  cout << " RefCollection: " << refCollection_.label() << " "<< refCollection_ << endl;

  eventType_ = iConfig.getParameter<string>("EventType");
  
  tversion = edm::getReleaseVersion();
  //    cout<<endl<<"-----------------------*******************************Version: " << tversion<<endl;
  
  if (!saveoutputhistograms_) {
    LogInfo("OutputInfo") << " TauVisible histograms will NOT be saved";
  } else {
    outPutFile_ = TauProducer_;
    outPutFile_.append("_");    
    tversion.erase(0,1);
    tversion.erase(tversion.size()-1,1);
    outPutFile_.append(tversion);
    outPutFile_.append("_"+ refCollection_);
    if ( ! extensionName_.empty()){
      outPutFile_.append("_"+ extensionName_);
    }
    outPutFile_.append(".root");
    
    //    cout<<endl<< outPutFile_<<endl;
    LogInfo("OutputInfo") << " TauVisiblehistograms will be saved to file:" << outPutFile_;
  }

  //---- book-keeping information ---
  numEvents_ = 0 ;

}

// ------------ method called once each job just before starting event loop  ------------
void TauTagValidation::beginJob()
{ 

  dbeTau = &*edm::Service<DQMStore>();
  
  int nbBinsEta, nbBinsPhi, nbBinsPt, nbBinsEne, nbBinsJW, nbBinsLTPt, maxBins;
  
  if(eventType_ == "RealData"){
    nbBinsEta = 20;
    nbBinsPhi = 18;
    nbBinsPt = 13;
    nbBinsEne = 9;
    nbBinsJW = 9;
    nbBinsLTPt = 9;
    maxBins = 14;
  }else{
    nbBinsEta = 60;
    nbBinsPhi = 36;
    nbBinsPt = 75;
    nbBinsEne = 45;
    nbBinsJW = 50;
    nbBinsLTPt = 50;
    maxBins = 76;
  }
  
  float *binListPt = new float[nbBinsPt+1];
  float *binListEne = new float[nbBinsEne+1];
  float *binListJW = new float[nbBinsJW+1];
  float *binListLTPt = new float[nbBinsLTPt+1];

  if(eventType_ == "RealData"){
    float ListPt[] = {0.,1.,5.,10.,15.,20.,25.,30.,40.,50.,70.,90.,110.,150.};
    float ListEne[] = {0.,25.,50.,75.,100.,150.,200.,300.,400.,500.};
    float ListJW[]  = {0.,0.004,0.008,0.012,0.016,0.02,0.025,0.03,0.04,0.05};
    float ListLTPt[] = {0.,5.,9.,13.,17.,21.,25.,30.,40.,50.};
    for(int i = 0; i != maxBins; i++){
      if(i < nbBinsPt+1)binListPt[i] = ListPt[i];
      if(i < nbBinsEne+1)binListEne[i] = ListEne[i];
      if(i < nbBinsJW+1)binListJW[i] = ListJW[i];
      if(i < nbBinsLTPt+1)binListLTPt[i] = ListLTPt[i];
    }
  }else{
    nbBinsEta = 61;
    nbBinsPhi = 37;
    for(int i = 0; i != maxBins; i++){
      if(i < nbBinsPt+1)binListPt[i] = i*2.;
      if(i < nbBinsEne+1)binListEne[i] = i*10.;
      if(i < nbBinsJW+1)binListJW[i] = i*0.006;
      if(i < nbBinsLTPt+1)binListLTPt[i] = i;
    }
  }

  //Getting the names of value maps we want to use
  /*
  edm::ParameterSet ValueMapProd = WeightValueMapSource_.getParameter<edm::ParameterSet>("WeightProducerType");
  edm::ParameterSet ValueMapType = WeightValueMapSource_.getParameter<edm::ParameterSet>("WeightValueMapType");
  edm::ParameterSet ValueDiscri = WeightValueMapSource_.getParameter<edm::ParameterSet>("WeightDiscriType");
  */

  for(size_t iPType = 0; iPType != WeightValueMapProducerType_.getParameterNamesForType<string>().size(); iPType++){
    PTypes.push_back(WeightValueMapProducerType_.getParameter<string>((WeightValueMapProducerType_.getParameterNamesForType<string>())[iPType]));
  }

  for(size_t iVMType = 0; iVMType != WeightValueMapType_.getParameterNamesForType<string>().size(); iVMType++){
    VMTypes.push_back(WeightValueMapType_.getParameter<string>((WeightValueMapType_.getParameterNamesForType<string>())[iVMType]));
  }

  for(size_t iDType = 0; iDType != WeightValueMapDiscriType_.getParameterNamesForType<string>().size(); iDType++){
    DTypes.push_back(WeightValueMapDiscriType_.getParameter<string>((WeightValueMapDiscriType_.getParameterNamesForType<string>())[iDType]));
  }

  if(dbeTau) {

    MonitorElement * ptTemp,* etaTemp,* phiTemp, *energyTemp, *jetwidthTemp, *leadTrackPtTemp;
    
    // What kind of Taus do we originally have!

    dbeTau->setCurrentFolder("RecoTauV/" + TauProducer_ + extensionName_ + "_ReferenceCollection" );
    
    ptTemp    =  dbeTau->book1D("nRef_Taus_vs_ptTauVisible", "nRef_Taus_vs_ptTauVisible", nbBinsPt, binListPt);
    etaTemp   =  dbeTau->book1D("nRef_Taus_vs_etaTauVisible", "nRef_Taus_vs_etaTauVisible", nbBinsEta, -3.0, 3.0 );
    phiTemp   =  dbeTau->book1D("nRef_Taus_vs_phiTauVisible", "nRef_Taus_vs_phiTauVisible", nbBinsPhi, -180., 180.);
    energyTemp =  dbeTau->book1D("nRef_Taus_vs_energyTauVisible", "nRef_Taus_vs_energyTauVisible", nbBinsEne, binListEne);
    leadTrackPtTemp =  dbeTau->book1D("nRef_Taus_vs_leadTrackPtTauVisible","nRef_Taus_vs_leadTrackPtTauVisible", nbBinsLTPt, binListLTPt);
    jetwidthTemp =  dbeTau->book1D("nRef_Taus_vs_jetwidthTauVisible","nRef_Taus_vs_jetwidthPtTauVisible", nbBinsJW, binListJW);

    ptTauVisibleMap.insert( std::make_pair( refCollection_,ptTemp));
    etaTauVisibleMap.insert( std::make_pair(refCollection_,etaTemp));
    phiTauVisibleMap.insert( std::make_pair(refCollection_,phiTemp));
    energyTauVisibleMap.insert( std::make_pair(refCollection_,energyTemp));
    leadTrackPtTauVisibleMap.insert( std::make_pair(refCollection_,leadTrackPtTemp));
    jetwidthTauVisibleMap.insert( std::make_pair(refCollection_,jetwidthTemp));


    // What kind of preselected Taus do we originally have!

    dbeTau->setCurrentFolder("RecoTauV/" + TauProducer_ + extensionName_ + "_PreselectedReferenceCollection" );
    
    ptTemp    =  dbeTau->book1D("nPreRef_Taus_vs_ptTauVisible", "nPreRef_Taus_vs_ptTauVisible", nbBinsPt, binListPt);
    etaTemp   =  dbeTau->book1D("nPreRef_Taus_vs_etaTauVisible", "nPreRef_Taus_vs_etaTauVisible", nbBinsEta, -3.0, 3.0 );
    phiTemp   =  dbeTau->book1D("nPreRef_Taus_vs_phiTauVisible", "nPreRef_Taus_vs_phiTauVisible", nbBinsPhi, -180., 180.);
    energyTemp =  dbeTau->book1D("nPreRef_Taus_vs_energyTauVisible", "nPreRef_Taus_vs_energyTauVisible", nbBinsEne, binListEne);
    leadTrackPtTemp =  dbeTau->book1D("nPreRef_Taus_vs_leadTrackPtTauVisible","nPreRef_Taus_vs_leadTrackPtTauVisible", nbBinsLTPt, binListLTPt);
    jetwidthTemp =  dbeTau->book1D("nPreRef_Taus_vs_jetwidthTauVisible","nPreRef_Taus_vs_jetwidthPtTauVisible", nbBinsJW, binListJW);

    ptTauVisibleMap.insert( std::make_pair("Preselected"+refCollection_,ptTemp));
    etaTauVisibleMap.insert( std::make_pair("Preselected"+refCollection_,etaTemp));
    phiTauVisibleMap.insert( std::make_pair("Preselected"+refCollection_,phiTemp));
    energyTauVisibleMap.insert( std::make_pair("Preselected"+refCollection_,energyTemp));
    leadTrackPtTauVisibleMap.insert( std::make_pair("Preselected"+refCollection_,leadTrackPtTemp));
    jetwidthTauVisibleMap.insert( std::make_pair("Preselected"+refCollection_,jetwidthTemp));



    // Number of Tau Candidates matched to MC Taus    

    dbeTau->setCurrentFolder("RecoTauV/"+ TauProducer_ + extensionName_ + "_Matched");

    ptTemp    =  dbeTau->book1D(TauProducer_ +"Matched_vs_ptTauVisible", TauProducer_ +"Matched_vs_ptTauVisible", nbBinsPt ,binListPt);
    etaTemp   =  dbeTau->book1D(TauProducer_ +"Matched_vs_etaTauVisible", TauProducer_ +"Matched_vs_etaTauVisible", nbBinsEta, -3.0, 3.0 );
    phiTemp   =  dbeTau->book1D(TauProducer_ +"Matched_vs_phiTauVisible", TauProducer_ +"Matched_vs_phiTauVisible", nbBinsPhi, -180., 180.);
    energyTemp =  dbeTau->book1D(TauProducer_ +"Matched_vs_energyTauVisible", TauProducer_ +"Matched_vs_energyTauVisible", nbBinsEne, binListEne);
    leadTrackPtTemp =  dbeTau->book1D(TauProducer_ +"Matched_vs_leadTrackPtTauVisible", TauProducer_ +"Matched_vs_leadTrackPtTauVisible", nbBinsLTPt, binListLTPt);
    jetwidthTemp =  dbeTau->book1D(TauProducer_ +"Matched_vs_jetwidthTauVisible", TauProducer_ +"Matched_vs_jetwidthTauVisible", nbBinsJW, binListJW);

    ptTauVisibleMap.insert( std::make_pair( TauProducer_+"Matched" ,ptTemp));
    etaTauVisibleMap.insert( std::make_pair(TauProducer_+"Matched" ,etaTemp));
    phiTauVisibleMap.insert( std::make_pair(TauProducer_+"Matched" ,phiTemp));
    energyTauVisibleMap.insert( std::make_pair(TauProducer_+"Matched" ,energyTemp));  
    leadTrackPtTauVisibleMap.insert( std::make_pair(TauProducer_+"Matched" ,leadTrackPtTemp));   
    jetwidthTauVisibleMap.insert( std::make_pair(TauProducer_+"Matched" ,jetwidthTemp));  


      for(std::vector<string>::iterator iDTag = DTypes.begin(); iDTag != DTypes.end(); iDTag++){

	dbeTau->setCurrentFolder("RecoTauV/"+ TauProducer_ + extensionName_ + "_Identified"+(*iDTag));
	
	ptTemp    =  dbeTau->book1D(TauProducer_ +"Identified_vs_ptTauVisible", TauProducer_ +"Identified_vs_ptTauVisible", nbBinsPt ,binListPt);
	etaTemp   =  dbeTau->book1D(TauProducer_ +"Identified_vs_etaTauVisible", TauProducer_ +"Identified_vs_etaTauVisible", nbBinsEta, -3.0, 3.0 );
	phiTemp   =  dbeTau->book1D(TauProducer_ +"Identified_vs_phiTauVisible", TauProducer_ +"Identified_vs_phiTauVisible", nbBinsPhi, -180., 180.);
	energyTemp =  dbeTau->book1D(TauProducer_ +"Identified_vs_energyTauVisible", TauProducer_ +"Identified_vs_energyTauVisible", nbBinsEne, binListEne);
	leadTrackPtTemp =  dbeTau->book1D(TauProducer_ +"Identified_vs_leadTrackPtTauVisible", TauProducer_ +"Identified_vs_leadTrackPtTauVisible", nbBinsLTPt, binListLTPt);
	jetwidthTemp =  dbeTau->book1D(TauProducer_ +"Identified_vs_jetwidthTauVisible", TauProducer_ +"Identified_vs_jetwidthTauVisible", nbBinsJW, binListJW);
	
	ptTauVisibleMap.insert( std::make_pair( TauProducer_+"Identified"+(*iDTag) ,ptTemp));
	etaTauVisibleMap.insert( std::make_pair(TauProducer_+"Identified"+(*iDTag) ,etaTemp));
	phiTauVisibleMap.insert( std::make_pair(TauProducer_+"Identified"+(*iDTag) ,phiTemp));
	energyTauVisibleMap.insert( std::make_pair(TauProducer_+"Identified"+(*iDTag) ,energyTemp));  
	leadTrackPtTauVisibleMap.insert( std::make_pair(TauProducer_+"Identified"+(*iDTag) ,leadTrackPtTemp));     
	jetwidthTauVisibleMap.insert( std::make_pair(TauProducer_+"Identified"+(*iDTag) ,jetwidthTemp)); 
	

	for(std::vector<string>::iterator iVMTag = VMTypes.begin(); iVMTag != VMTypes.end(); iVMTag++){
	  
	  dbeTau->setCurrentFolder("RecoTauV/"+ TauProducer_ + extensionName_ + "_Weighted"+(*iDTag)+(*iVMTag));
	  
	  ptTemp    =  dbeTau->book1D(TauProducer_ +"Weighted_vs_ptTauVisible", TauProducer_ +"Weighted_vs_ptTauVisible", nbBinsPt ,binListPt);
	  etaTemp   =  dbeTau->book1D(TauProducer_ +"Weighted_vs_etaTauVisible", TauProducer_ +"Weighted_vs_etaTauVisible", nbBinsEta, -3.0, 3.0 );
	  phiTemp   =  dbeTau->book1D(TauProducer_ +"Weighted_vs_phiTauVisible", TauProducer_ +"Weighted_vs_phiTauVisible", nbBinsPhi, -180., 180.);
	  energyTemp =  dbeTau->book1D(TauProducer_ +"Weighted_vs_energyTauVisible", TauProducer_ +"Weighted_vs_energyTauVisible", nbBinsEne, binListEne);
	  leadTrackPtTemp =  dbeTau->book1D(TauProducer_ +"Weighted_vs_leadTrackPtTauVisible", TauProducer_ +"Weighted_vs_leadTrackPtTauVisible", nbBinsLTPt, binListLTPt);
	  jetwidthTemp =  dbeTau->book1D(TauProducer_ +"Weighted_vs_jetwidthTauVisible", TauProducer_ +"Weighted_vs_jetwidthTauVisible", nbBinsJW, binListJW);
	  
	  ptTauVisibleMap.insert( std::make_pair( TauProducer_+"Weighted"+(*iDTag)+(*iVMTag) ,ptTemp));
	  etaTauVisibleMap.insert( std::make_pair(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag) ,etaTemp));
	  phiTauVisibleMap.insert( std::make_pair(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag) ,phiTemp));
	  energyTauVisibleMap.insert( std::make_pair(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag) ,energyTemp));  
	  leadTrackPtTauVisibleMap.insert( std::make_pair(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag) ,leadTrackPtTemp)); 
	  jetwidthTauVisibleMap.insert( std::make_pair(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag) ,jetwidthTemp));
	  
	}

      }
      
      


    for ( std::vector< edm::ParameterSet >::iterator it = discriminators_.begin(); it!= discriminators_.end();  it++)
      {
	string DiscriminatorLabel = it->getParameter<string>("discriminator");

	dbeTau->setCurrentFolder("RecoTauV/" +  TauProducer_ + extensionName_ + "_" +  DiscriminatorLabel );
	
	ptTemp    =  dbeTau->book1D(DiscriminatorLabel + "_vs_ptTauVisible", DiscriminatorLabel +"_vs_ptTauVisible", nbBinsPt ,binListPt);
	etaTemp   =  dbeTau->book1D(DiscriminatorLabel + "_vs_etaTauVisible", DiscriminatorLabel + "_vs_etaTauVisible", nbBinsEta, -3.0, 3.0 );
	phiTemp   =  dbeTau->book1D(DiscriminatorLabel + "_vs_phiTauVisible", DiscriminatorLabel + "_vs_phiTauVisible", nbBinsPhi, -180., 180.);
	energyTemp =  dbeTau->book1D(DiscriminatorLabel + "_vs_energyTauVisible", DiscriminatorLabel + "_vs_energyTauVisible", nbBinsEne, binListEne);
	leadTrackPtTemp =  dbeTau->book1D(DiscriminatorLabel + "_vs_leadTrackPtTauVisible", DiscriminatorLabel + "_vs_leadTrackPtTauVisible", nbBinsLTPt, binListLTPt);
	jetwidthTemp =  dbeTau->book1D(DiscriminatorLabel + "_vs_jetwidthTauVisible", DiscriminatorLabel + "_vs_jetwidthTauVisible", nbBinsJW, binListJW);
		
	ptTauVisibleMap.insert( std::make_pair(DiscriminatorLabel,ptTemp));
	etaTauVisibleMap.insert( std::make_pair(DiscriminatorLabel,etaTemp));
	phiTauVisibleMap.insert( std::make_pair(DiscriminatorLabel,phiTemp));
	energyTauVisibleMap.insert( std::make_pair(DiscriminatorLabel,energyTemp));
	leadTrackPtTauVisibleMap.insert( std::make_pair(DiscriminatorLabel,leadTrackPtTemp));
	jetwidthTauVisibleMap.insert( std::make_pair(DiscriminatorLabel,jetwidthTemp));

	//	if ( TauProducer_.find("PFTau") != string::npos) 
	// {
	
	if ( DiscriminatorLabel.find("LeadingTrackPtCut") != string::npos){
	  if ( TauProducer_.find("PFTau") != string::npos)
	    {
	      nPFJet_LeadingChargedHadron_ChargedHadronsSignal_	        =dbeTau->book1D(DiscriminatorLabel + "_ChargedHadronsSignal",DiscriminatorLabel + "_ChargedHadronsSignal", 21, -0.5, 20.5);		 
	      nPFJet_LeadingChargedHadron_ChargedHadronsIsolAnnulus_    =dbeTau->book1D(DiscriminatorLabel + "_ChargedHadronsIsolAnnulus",DiscriminatorLabel + "_ChargedHadronsIsolAnnulus", 21, -0.5, 20.5);	 
	      nPFJet_LeadingChargedHadron_GammasSignal_		        =dbeTau->book1D(DiscriminatorLabel + "_GammasSignal",DiscriminatorLabel + "_GammasSignal",21, -0.5, 20.5);				 
	      nPFJet_LeadingChargedHadron_GammasIsolAnnulus_ 	        =dbeTau->book1D(DiscriminatorLabel + "_GammasIsolAnnulus",DiscriminatorLabel + "_GammasIsolAnnulus",21, -0.5, 20.5);  		 
	      nPFJet_LeadingChargedHadron_NeutralHadronsSignal_	        =dbeTau->book1D(DiscriminatorLabel + "_NeutralHadronsSignal",DiscriminatorLabel + "_NeutralHadronsSignal",21, -0.5, 20.5);		 
	      nPFJet_LeadingChargedHadron_NeutralHadronsIsolAnnulus_	=dbeTau->book1D(DiscriminatorLabel + "_NeutralHadronsIsolAnnulus",DiscriminatorLabel + "_NeutralHadronsIsolAnnulus",21, -0.5, 20.5);   	      
	    }
	  else if (TauProducer_.find("caloRecoTau") != string::npos)
	    {
	      nCaloJet_LeadingTrack_signalTracksInvariantMass_   =dbeTau->book1D(DiscriminatorLabel + "_signalTracksInvariantMass",DiscriminatorLabel + "_signalTracksInvariantMass",  75, 0., 150.); 
	      nCaloJet_LeadingTrack_signalTracks_		 =dbeTau->book1D(DiscriminatorLabel + "_signalTracks", DiscriminatorLabel + "_signalTracks" , 15, -0.5, 14.5);         	     
	      nCaloJet_LeadingTrack_isolationTracks_	    	 =dbeTau->book1D(DiscriminatorLabel + "_isolationTracks", DiscriminatorLabel + "_isolationTracks",  15, -0.5, 14.5);      		 
	      nCaloJet_LeadingTrack_isolationECALhitsEtSum_      =dbeTau->book1D(DiscriminatorLabel + "_isolationECALhitsEtSum", DiscriminatorLabel + "_isolationECALhitsEtSum", 75, 0., 75.);       
	    }
	}
	
	if ( DiscriminatorLabel.find("ByIsolationLater") != string::npos ){
	  if ( TauProducer_.find("PFTau") != string::npos)
	    {
	      nIsolated_NoChargedHadrons_ChargedHadronsSignal_	      =dbeTau->book1D(DiscriminatorLabel + "_ChargedHadronsSignal",DiscriminatorLabel + "_ChargedHadronsSignal", 21, -0.5, 20.5);	 	      
	      nIsolated_NoChargedHadrons_GammasSignal_		      =dbeTau->book1D(DiscriminatorLabel + "_GammasSignal",DiscriminatorLabel + "_GammasSignal",21, -0.5, 20.5);			   
	      nIsolated_NoChargedHadrons_GammasIsolAnnulus_           =dbeTau->book1D(DiscriminatorLabel + "_GammasIsolAnnulus",DiscriminatorLabel + "_GammasIsolAnnulus",21, -0.5, 20.5);  		   
	      nIsolated_NoChargedHadrons_NeutralHadronsSignal_	      =dbeTau->book1D(DiscriminatorLabel + "_NeutralHadronsSignal",DiscriminatorLabel + "_NeutralHadronsSignal",21, -0.5, 20.5);	   
	      nIsolated_NoChargedHadrons_NeutralHadronsIsolAnnulus_   =dbeTau->book1D(DiscriminatorLabel + "_NeutralHadronsIsolAnnulus",DiscriminatorLabel + "_NeutralHadronsIsolAnnulus",21, -0.5, 20.5); 
	    }
	  else if (TauProducer_.find("caloRecoTau") != string::npos)
	    {
	      nTrackIsolated_isolationECALhitsEtSum_      =dbeTau->book1D(DiscriminatorLabel + "_isolationECALhitsEtSum", DiscriminatorLabel + "_isolationECALhitsEtSum", 75, 0., 75.);	  
	      nTrackIsolated_signalTracksInvariantMass_	  =dbeTau->book1D(DiscriminatorLabel + "_signalTracksInvariantMass",DiscriminatorLabel + "_signalTracksInvariantMass", 75, 0., 150.);
	      nTrackIsolated_signalTracks_		  =dbeTau->book1D(DiscriminatorLabel + "_signalTracks",DiscriminatorLabel + "_signalTracks", 15, -0.5, 14.5);                        
	    }
	}

	if ( DiscriminatorLabel.find("ByIsolation") != string::npos ){
	  if ( TauProducer_.find("PFTau") != string::npos)
	    {
	      nIsolated_NoChargedNoGammas_ChargedHadronsSignal_        =dbeTau->book1D(DiscriminatorLabel + "_ChargedHadronsSignal",DiscriminatorLabel + "_ChargedHadronsSignal", 21, -0.5, 20.5);	  
	      nIsolated_NoChargedNoGammas_GammasSignal_                =dbeTau->book1D(DiscriminatorLabel + "_GammasSignal",DiscriminatorLabel + "_GammasSignal",21, -0.5, 20.5);	 
	      nIsolated_NoChargedNoGammas_NeutralHadronsSignal_	       =dbeTau->book1D(DiscriminatorLabel + "_NeutralHadronsSignal",DiscriminatorLabel + "_NeutralHadronsSignal",21, -0.5, 20.5);	   	 
	      nIsolated_NoChargedNoGammas_NeutralHadronsIsolAnnulus_   =dbeTau->book1D(DiscriminatorLabel + "_NeutralHadronsIsolAnnulus",DiscriminatorLabel + "_NeutralHadronsIsolAnnulus",21, -0.5, 20.5); 

	    }
	  else if (TauProducer_.find("caloRecoTau") != string::npos)
	    {
	      nEMIsolated_signalTracksInvariantMass_  =dbeTau->book1D(DiscriminatorLabel+"_signalTracksInvariantMass",DiscriminatorLabel+"_signalTracksInvariantMass", 75, 0., 150.);
	      nEMIsolated_signalTracks_               =dbeTau->book1D(DiscriminatorLabel+"_signalTracks",DiscriminatorLabel+"_signalTracks", 15, -0.5, 14.5);    
	    }
	}

      }
  }

  for ( std::vector< edm::ParameterSet >::iterator it = discriminators_.begin(); it!= discriminators_.end();  it++) 
    {
      cerr<< " "<< it->getParameter<string>("discriminator") << " "<< it->getParameter<double>("selectionCut") << endl;
      
    }
}

// -- method called to produce fill all the histograms --------------------
void TauTagValidation::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
  numEvents_++;
  double matching_criteria = -1.0;

  typedef edm::View<reco::Candidate> genCandidateCollection;
  //  typedef edm::Vector<reco::PFTau> pfCandidateCollection;
  //  typedef edm::Vector<reco::CaloTau> caloCandidateCollection;

  //  std::cout << "--------------------------------------------------------------"<<endl;
  //std::cout << " RunNumber: " << iEvent.id().run() << ", EventNumber: " << iEvent.id().event() << std:: endl;
  //std::cout << "Event number: " << ++numEvents_ << endl;
  //std::cout << "--------------------------------------------------------------"<<endl;

  // ----------------------- Reference product -----------------------------------------------------------------------

  Handle<genCandidateCollection> ReferenceCollection;
  bool isGen = iEvent.getByLabel(refCollectionInputTag_, ReferenceCollection);    // get the product from the event

  if (!isGen) {
    std::cerr << " Reference collection: " << refCollection_ << " not found while running TauTagValidation.cc " << std::endl;
    return;
  }

  if(dataType_ == "Leptons"){
    matching_criteria = matchDeltaR_Leptons_;
  }
  else
  {
    matching_criteria = matchDeltaR_Jets_;
  }

  // ------------------------------ PFTauCollection Matched and other discriminators ---------------------------------------------------------



  
  if ( TauProducer_.find("PFTau") != string::npos)
    {
      Handle<PFTauCollection> thePFTauHandle;
      iEvent.getByLabel(TauProducerInputTag_,thePFTauHandle);
      
      const PFTauCollection  *pfTauProduct;
      pfTauProduct = thePFTauHandle.product();

      edm::Handle<edm::View<reco::BaseTau> > theBaseTauHandle;
      iEvent.getByLabel(TauProducerInputTag_,theBaseTauHandle);

      //This is a test
      Handle<GenJetCollection> theGenJets;
      iEvent.getByLabel(refCollectionInputTag_, theGenJets);


      PFTauCollection::size_type thePFTauClosest;      

      string TauType = "";

      if(TauProducer_ == "fixedConePFTauProducer")TauType = "fixedConePFTau";
      if(TauProducer_ == "shrinkingConePFTauProducer")TauType = "shrinkingConePFTau";
      if(TauProducer_ == "caloRecoTauProducer")TauType = "caloRecoTau";


      Handle<PFTauDiscriminator> byLeadingPion;      
      Handle<PFTauDiscriminator> byLeadingTrack;
      Handle<PFTauDiscriminator> byLeadingTrackPt;
      Handle<PFTauDiscriminator> byTrackIsolation;
      Handle<PFTauDiscriminator> byEcalIsolation;
      Handle<PFTauDiscriminator> againstMuon;      
      Handle<PFTauDiscriminator> againstElectron;
      iEvent.getByLabel(TauType+"DiscriminationByLeadingPionPtCut",byLeadingPion);
      iEvent.getByLabel(TauType+"DiscriminationByLeadingTrackFinding",byLeadingTrack);
      iEvent.getByLabel(TauType+"DiscriminationByLeadingTrackPtCut", byLeadingTrackPt);
      iEvent.getByLabel(TauType+"DiscriminationByTrackIsolation",byTrackIsolation);
      iEvent.getByLabel(TauType+"DiscriminationByECALIsolation",byEcalIsolation);
      iEvent.getByLabel(TauType+"DiscriminationAgainstMuon",againstMuon);
      iEvent.getByLabel(TauType+"DiscriminationAgainstElectron",againstElectron);

      for (genCandidateCollection::const_iterator RefJet= ReferenceCollection->begin() ; RefJet != ReferenceCollection->end(); RefJet++ ){ 	

	thePFTauClosest = pfTauProduct->size();

	const reco::Candidate *gen_particle = &(*RefJet);

	double delta=TMath::Pi();

	for (PFTauCollection::size_type iPFTau=0 ; iPFTau <  pfTauProduct->size() ; iPFTau++) 
	  {		    
	    if (algo_->deltaR(gen_particle, & pfTauProduct->at(iPFTau)) < delta){
	      delta = algo_->deltaR(gen_particle, & pfTauProduct->at(iPFTau));
	      thePFTauClosest = iPFTau;
	    }
	  }
	

	PFTauRef thePFTau(thePFTauHandle, thePFTauClosest);
	Handle<PFTauDiscriminator> currentDiscriminator;

	
	double deltaR = algo_->deltaR(gen_particle, & pfTauProduct->at(thePFTauClosest));

	double jetWidth = sqrt((thePFTau->pfTauTagInfoRef()->pfjetRef()->etaetaMoment()) + (thePFTau->pfTauTagInfoRef()->pfjetRef()->phiphiMoment()));

	ptTauVisibleMap.find(refCollection_)->second->Fill(RefJet->pt());
	etaTauVisibleMap.find(refCollection_)->second->Fill(RefJet->eta());
	phiTauVisibleMap.find(refCollection_)->second->Fill(RefJet->phi()*180.0/TMath::Pi());
	energyTauVisibleMap.find(refCollection_)->second->Fill(RefJet->energy());
	if((*thePFTau).leadPFChargedHadrCand().isNonnull())leadTrackPtTauVisibleMap.find(refCollection_)->second->Fill((*thePFTau).leadPFChargedHadrCand()->pt());
	jetwidthTauVisibleMap.find(refCollection_)->second->Fill(jetWidth);	

	// Skip if there is no reconstructed Tau matching the Reference 
	if (thePFTauClosest == pfTauProduct->size()) continue;
	
	// Skip if the delta R difference is larger than the required criteria
	if (deltaR > matching_criteria && matching_criteria != -1.0) continue;
		
	ptTauVisibleMap.find( TauProducer_+"Matched")->second->Fill(RefJet->pt());
	etaTauVisibleMap.find( TauProducer_+"Matched" )->second->Fill(RefJet->eta());
	phiTauVisibleMap.find( TauProducer_+"Matched" )->second->Fill(RefJet->phi()*180.0/TMath::Pi());
	energyTauVisibleMap.find(  TauProducer_+"Matched")->second->Fill(RefJet->energy());
	if((*thePFTau).leadPFChargedHadrCand().isNonnull())leadTrackPtTauVisibleMap.find(  TauProducer_+"Matched")->second->Fill((*thePFTau).leadPFChargedHadrCand()->pt());
	jetwidthTauVisibleMap.find(  TauProducer_+"Matched")->second->Fill(jetWidth);	



	//std::cout << "Test std muons " <<  (*againstMuons)[thePFTau] << endl;
	

	
	  for ( std::vector< edm::ParameterSet >::iterator it = discriminators_.begin(); it!= discriminators_.end();  it++) 
	    {
	      string currentDiscriminatorLabel = it->getParameter<string>("discriminator");	      
	      iEvent.getByLabel(currentDiscriminatorLabel, currentDiscriminator);
	      
	      if ((*currentDiscriminator)[thePFTau] >= it->getParameter<double>("selectionCut")){
		ptTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill(RefJet->pt());
		etaTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill(RefJet->eta());
		phiTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill(RefJet->phi()*180.0/TMath::Pi());
		energyTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill(RefJet->energy());
		if((*thePFTau).leadPFChargedHadrCand().isNonnull())leadTrackPtTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill((*thePFTau).leadPFChargedHadrCand()->pt());
		jetwidthTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill(jetWidth);
		
		if ( currentDiscriminatorLabel.find("LeadingTrackPtCut") != string::npos){
		  nPFJet_LeadingChargedHadron_ChargedHadronsSignal_->Fill((*thePFTau).signalPFChargedHadrCands().size());
		  nPFJet_LeadingChargedHadron_ChargedHadronsIsolAnnulus_->Fill((*thePFTau).isolationPFChargedHadrCands().size());
		  nPFJet_LeadingChargedHadron_GammasSignal_->Fill((*thePFTau).signalPFGammaCands().size());		 
		  nPFJet_LeadingChargedHadron_GammasIsolAnnulus_->Fill((*thePFTau).isolationPFGammaCands().size()); 
		  nPFJet_LeadingChargedHadron_NeutralHadronsSignal_->Fill((*thePFTau).signalPFNeutrHadrCands().size());	 
		  nPFJet_LeadingChargedHadron_NeutralHadronsIsolAnnulus_->Fill((*thePFTau).isolationPFNeutrHadrCands().size());
		}	      
		else if ( currentDiscriminatorLabel.find("ByIsolation") != string::npos ){
		  nIsolated_NoChargedNoGammas_ChargedHadronsSignal_->Fill((*thePFTau).signalPFChargedHadrCands().size());	 
		  nIsolated_NoChargedNoGammas_GammasSignal_->Fill((*thePFTau).signalPFGammaCands().size());		 
		  nIsolated_NoChargedNoGammas_NeutralHadronsSignal_->Fill((*thePFTau).signalPFNeutrHadrCands().size());	 
		  nIsolated_NoChargedNoGammas_NeutralHadronsIsolAnnulus_->Fill((*thePFTau).isolationPFNeutrHadrCands().size());		  
		}
	      }
	      else {
		break; 
	      }
	    }
	
	//Tau candidate must pass preselection
	if(abs((*thePFTau).p4().eta())   > 2.1 ||
	   (*thePFTau).p4().Pt()         < 20. ||
	   (*byLeadingTrack)[thePFTau]   < 0.5 ||
	   (*byLeadingTrackPt)[thePFTau] < 0.5 ||
	   (*againstMuon)[thePFTau]      < 0.5 ||
	   (*againstElectron)[thePFTau]  < 0.5
           )continue;

	//Filling preselected for control plots
	ptTauVisibleMap.find("Preselected"+refCollection_)->second->Fill(RefJet->pt());
	etaTauVisibleMap.find("Preselected"+refCollection_)->second->Fill(RefJet->eta());
	phiTauVisibleMap.find("Preselected"+refCollection_)->second->Fill(RefJet->phi()*180.0/TMath::Pi());
	energyTauVisibleMap.find("Preselected"+refCollection_)->second->Fill(RefJet->energy());
	if((*thePFTau).leadPFChargedHadrCand().isNonnull())leadTrackPtTauVisibleMap.find("Preselected"+refCollection_)->second->Fill((*thePFTau).leadPFChargedHadrCand()->pt());
	jetwidthTauVisibleMap.find("Preselected"+refCollection_)->second->Fill(jetWidth);

	
	//Loop for using of multiple efficiency-fakerate tables
	for(std::vector<string>::iterator iPTag = PTypes.begin(); iPTag != PTypes.end(); iPTag++){
	  for(std::vector<string>::iterator iDTag = DTypes.begin(); iDTag != DTypes.end(); iDTag++){
	  
	      bool FillOK = false;

	  
	      if((*iDTag) == "ByCharge" && abs((*thePFTau).charge()) == 1)FillOK = true;
	      
	      if((*iDTag) == "ByNumTracks"  &&
		 (((*thePFTau).signalPFChargedHadrCands().size() == 1) || 
		  ((*thePFTau).signalPFChargedHadrCands().size() == 3)))
		FillOK = true;
	      
	      if((*iDTag) == "ByLeadPion"  &&
		 (*byLeadingPion)[thePFTau] > 0.5)
		FillOK = true;    
	      
	      if((*iDTag) == "ByLeadingTrack"  &&
		 (*byLeadingTrack)[thePFTau] > 0.5)
		FillOK = true;
	      
	      if((*iDTag) == "ByChargeAndTracks"  &&
		 abs((*thePFTau).charge()) == 1 && 
		 (((*thePFTau).signalPFChargedHadrCands().size() == 1) || 
		  ((*thePFTau).signalPFChargedHadrCands().size() == 3)))
		FillOK = true;
	      
	      if((*iDTag) == "ByIsolation"       &&	     
		 (*byTrackIsolation)[thePFTau] > 0.5 && 
		 (*byEcalIsolation)[thePFTau] > 0.5)
		FillOK = true;	 
	      
	      if((*iDTag) == "AgainstElectron"  &&
		 (*againstElectron)[thePFTau] > 0.5)
		FillOK = true;
	      
	      if((*iDTag) == "AgainstMuon"  &&
		 (*againstMuon)[thePFTau] > 0.5)
		FillOK = true;
	      
	      if((*iDTag) == "ByStandardChain"   &&
		 (*byTrackIsolation)[thePFTau] > 0.5 && 
		 (*byEcalIsolation)[thePFTau] > 0.5  &&
		 abs((*thePFTau).charge()) == 1      && 
		 (((*thePFTau).signalPFChargedHadrCands().size() == 1) || ((*thePFTau).signalPFChargedHadrCands().size() == 3)))
		FillOK = true;
	      
	      
	      if((*iDTag) == "ByStandardChainNoMu" &&
		 (*byTrackIsolation)[thePFTau] > 0.5   && 
		 (*byEcalIsolation)[thePFTau] > 0.5    &&
		 (*againstElectron)[thePFTau] > 0.5    &&
		 abs((*thePFTau).charge()) == 1        && 
		 (((*thePFTau).signalPFChargedHadrCands().size() == 1) || ((*thePFTau).signalPFChargedHadrCands().size() == 3)))
		FillOK = true;
	      
	      
	      if((*iDTag) == "ByStandardChainNoE" &&
		 (*byTrackIsolation)[thePFTau] > 0.5    && 
		 (*byEcalIsolation)[thePFTau] > 0.5     &&
		 (*againstMuon)[thePFTau] > 0.5         &&
		 abs((*thePFTau).charge()) == 1         && 
		 (((*thePFTau).signalPFChargedHadrCands().size() == 1) || ((*thePFTau).signalPFChargedHadrCands().size() == 3)))
		FillOK = true;
	      
	      
	      //Filling plots following discriminators
	      if(FillOK){
		ptTauVisibleMap.find( TauProducer_+"Identified"+(*iDTag))->second->Fill(RefJet->pt());
		etaTauVisibleMap.find( TauProducer_+"Identified"+(*iDTag))->second->Fill(RefJet->eta());
		phiTauVisibleMap.find( TauProducer_+"Identified"+(*iDTag))->second->Fill(RefJet->phi()*180.0/TMath::Pi());
		energyTauVisibleMap.find(  TauProducer_+"Identified"+(*iDTag))->second->Fill(RefJet->energy());
		if((*thePFTau).leadPFChargedHadrCand().isNonnull())leadTrackPtTauVisibleMap.find(  TauProducer_+"Identified"+(*iDTag))->second->Fill((*thePFTau).leadPFChargedHadrCand()->pt());
		jetwidthTauVisibleMap.find(  TauProducer_+"Identified"+(*iDTag))->second->Fill(jetWidth);
	      }

	      for(std::vector<string>::iterator iVMTag = VMTypes.begin(); iVMTag != VMTypes.end(); iVMTag++){

		string EffORFr; 
		if((eventType_ == "QCD") | (eventType_ == "RealData"))EffORFr = "fr";
		if(eventType_ == "ZTT")EffORFr = "eff";

		string ExtraTag = "";
		if((*iVMTag) == "MuEnrichedQCD")ExtraTag = "Associator";
		if((*iVMTag) == "ZTT")	ExtraTag = "EffSimAssociator";

		edm::InputTag valuemap;
		valuemap = edm::InputTag((*iPTag)+(*iVMTag)+ExtraTag,EffORFr+(*iDTag)+(*iVMTag)+"sim");
		

		edm::RefToBase<reco::BaseTau> myTau = theBaseTauHandle->refAt(thePFTauClosest);

		edm::Handle<EfficiencyMap> WeightValueMap;
		iEvent.getByLabel(valuemap, WeightValueMap);
		
		ptTauVisibleMap.find(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag))->second->Fill(RefJet->pt(),(*WeightValueMap)[myTau].value());
		etaTauVisibleMap.find(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag))->second->Fill(RefJet->eta(),(*WeightValueMap)[myTau].value());
		phiTauVisibleMap.find(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag))->second->Fill(RefJet->phi()*180.0/TMath::Pi(),(*WeightValueMap)[myTau].value());
		energyTauVisibleMap.find(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag))->second->Fill(RefJet->energy(),(*WeightValueMap)[myTau].value());
		if((*thePFTau).leadPFChargedHadrCand().isNonnull())leadTrackPtTauVisibleMap.find(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag))->second->Fill((*thePFTau).leadPFChargedHadrCand()->pt(),(*WeightValueMap)[myTau].value());
	      jetwidthTauVisibleMap.find(TauProducer_+"Weighted"+(*iDTag)+(*iVMTag))->second->Fill(jetWidth,(*WeightValueMap)[myTau].value());
	      
	      }
	      
	  }
	}
      }
    }

  // ------------------------------ CaloTauCollection Matched and other discriminators ---------------------------------------------------------
  else if (TauProducer_.find("caloRecoTau") != string::npos)
    {
      
      Handle<CaloTauCollection> theCaloTauHandle;
      iEvent.getByLabel(TauProducer_,theCaloTauHandle);
      
      const CaloTauCollection *caloTauProduct;
      caloTauProduct = theCaloTauHandle.product();
      
      for (genCandidateCollection::const_iterator RefJet= ReferenceCollection->begin() ; RefJet != ReferenceCollection->end(); RefJet++ ){ 

	const reco::Candidate *gen_particle = &(*RefJet);

	bool trueCaloTau = false;
	double delta=TMath::Pi();
	CaloTauCollection::size_type  theCaloTauClosest=caloTauProduct->size();
	
	for (CaloTauCollection::size_type iCaloTau=0 ; iCaloTau <  caloTauProduct->size() ; iCaloTau++) 
	  {	
	    
	    if (algo_->deltaR(gen_particle, & caloTauProduct->at(iCaloTau)) < delta){
	      delta = algo_->deltaR(gen_particle, & caloTauProduct->at(iCaloTau));
	      theCaloTauClosest = iCaloTau;
	    }
	    if ( delta <  matching_criteria ) {
	      trueCaloTau=true;
	    }
	  }

	// Skip if there is no reconstructed Tau matching the Reference 
	if (theCaloTauClosest == caloTauProduct->size()) continue;

	CaloTauRef theCaloTau(theCaloTauHandle,theCaloTauClosest);
	Handle<CaloTauDiscriminator> currentDiscriminator;
	
	double jetWidth = sqrt((theCaloTau->caloTauTagInfoRef()->calojetRef()->etaetaMoment())*(theCaloTau->caloTauTagInfoRef()->calojetRef()->etaetaMoment()) + (theCaloTau->caloTauTagInfoRef()->calojetRef()->phiphiMoment())*(theCaloTau->caloTauTagInfoRef()->calojetRef()->phiphiMoment()));

	
	ptTauVisibleMap.find(refCollection_)->second->Fill(RefJet->pt());
	etaTauVisibleMap.find(refCollection_)->second->Fill(RefJet->eta());
	phiTauVisibleMap.find(refCollection_)->second->Fill(RefJet->phi()*180.0/TMath::Pi());
	energyTauVisibleMap.find(refCollection_)->second->Fill(RefJet->energy());
	if(theCaloTau->leadTrack().isNonnull())leadTrackPtTauVisibleMap.find(refCollection_)->second->Fill(theCaloTau->leadTrack()->pt());
	jetwidthTauVisibleMap.find(refCollection_)->second->Fill(jetWidth);



	double deltaR = algo_->deltaR(gen_particle, & caloTauProduct->at(theCaloTauClosest));
	
	// Skip if the delta R difference is larger than the required criteria
	if (deltaR > matching_criteria && matching_criteria != -1.0) continue;


	
	ptTauVisibleMap.find( TauProducer_+"Matched")->second->Fill(RefJet->pt());
	etaTauVisibleMap.find( TauProducer_+"Matched" )->second->Fill(RefJet->eta());
	phiTauVisibleMap.find( TauProducer_+"Matched" )->second->Fill(RefJet->phi()*180.0/TMath::Pi());
	energyTauVisibleMap.find(  TauProducer_+"Matched")->second->Fill(RefJet->energy());
	if(theCaloTau->leadTrack().isNonnull())leadTrackPtTauVisibleMap.find(  TauProducer_+"Matched")->second->Fill(theCaloTau->leadTrack()->pt());
	jetwidthTauVisibleMap.find(  TauProducer_+"Matched")->second->Fill(jetWidth);
	

	
	for (  std::vector< edm::ParameterSet >::iterator it = discriminators_.begin(); it!= discriminators_.end();  it++)
	  {
	    
	    string currentDiscriminatorLabel = it->getParameter<string>("discriminator");
	    iEvent.getByLabel(currentDiscriminatorLabel, currentDiscriminator);	      
	    
	    if((*currentDiscriminator)[theCaloTau] >= it->getParameter<double>("selectionCut") )
	      {
		ptTauVisibleMap.find( currentDiscriminatorLabel)->second->Fill(RefJet->pt());
		etaTauVisibleMap.find( currentDiscriminatorLabel )->second->Fill(RefJet->eta());
		phiTauVisibleMap.find( currentDiscriminatorLabel )->second->Fill(RefJet->phi()*180.0/TMath::Pi());
		energyTauVisibleMap.find( currentDiscriminatorLabel )->second->Fill(RefJet->energy());
		if(theCaloTau->leadTrack().isNonnull())leadTrackPtTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill(theCaloTau->leadTrack()->pt());
		jetwidthTauVisibleMap.find(  currentDiscriminatorLabel )->second->Fill(jetWidth);
		
		if ( currentDiscriminatorLabel.find("LeadingTrackPtCut") != string::npos){
		  nCaloJet_LeadingTrack_signalTracksInvariantMass_->Fill((*theCaloTau).signalTracksInvariantMass());
		  nCaloJet_LeadingTrack_signalTracks_->Fill((*theCaloTau).signalTracks().size()); 
		  nCaloJet_LeadingTrack_isolationTracks_->Fill((*theCaloTau).isolationTracks().size());
		  nCaloJet_LeadingTrack_isolationECALhitsEtSum_->Fill((*theCaloTau).isolationECALhitsEtSum());
		}
		
		else if ( currentDiscriminatorLabel.find("ByIsolation") != string::npos ){
		  nEMIsolated_signalTracksInvariantMass_->Fill((*theCaloTau).signalTracksInvariantMass());
		  nEMIsolated_signalTracks_->Fill((*theCaloTau).signalTracks().size());     
		}
	      }
	    else {
	      break; 
	    }
	  }	
      }
    }    
}


 

// ---------------------------------------------------------------------------  endJob -----------------------------------------------------------------------

void TauTagValidation::endJob(){
  // just fill the denominator histograms for the changing cone sizes
  /*  
  double Denominator_Taus = nRefTaus_etaTauVisible_->getEntries();
  double First_Taus = nPFJet_etaTauVisible_->getEntries();
  double Second_Taus = nPFJet_LeadingChargedHadron_etaTauVisible_->getEntries();
  double Third_Taus = nIsolated_NoChargedHadrons_etaTauVisible_->getEntries();
  double Forth_Taus = nIsolated_NoChargedNoGammas_etaTauVisible_->getEntries();
   
  std::streamsize prec = cout.precision();
 
  cout<<setfill('-')<<setw(110)<<"-"<<endl;
  
  cout<<setfill('-')<<setw(55)<<" TAU TAG VALIDATION SUMMARY "<<setw(55)<<"-"<<endl;
  
  cout<<setfill('-')<<setw(92)<<"-"<<setfill(' ')<<setw(9)<<"Rel.Eff."<<setw(9)<<"Tot.Eff."<<endl;
  cout<<setfill('-')<<setw(85)<<left<<" TOTAL NUMBER OF REF OBJECTS LEVEL: ";
  
  cout<<setfill(' ')<<setw(7) <<right<< Denominator_Taus <<setw(9)<<"--"<<setw(9)<<"--"<< endl;
  
  cout<<setfill('-')<<setw(85)<<left<<" Step 1. TOTAL NUMBER OF PFJETS MATCHED TO REF COLLECTION: ";
  cout<<setfill(' ')<<setw(7) <<right<< First_Taus <<setw(9)<<"--";
  if (Denominator_Taus > 0) 
    cout<<setw(9)<<setprecision(3)<< First_Taus/Denominator_Taus  << setprecision(prec)<<endl;
  else 
    cout<<setw(9)<<"--"<<endl;
  
  cout<<setfill('-')<<setw(85)<<left<<" Step 2. PLUS LEADING CHARGED HADRON= 5.0 GeV: ";
  cout<<setfill(' ')<<setw(7)<<right<<Second_Taus;
  if (First_Taus > 0) 
    cout<<setw(9)<<setprecision(3)<< Second_Taus/First_Taus <<setprecision(prec);
  else
    cout<<setw(9)<<"--"<<endl;
  
  if (Denominator_Taus > 0)
    cout<<setw(9)<<setprecision(3)<< Second_Taus/Denominator_Taus  << setprecision(prec)<<endl;
  else 
    cout<<setw(9)<<"--"<<endl;

  
 
  cout<<setfill('-')<<setw(85)<<left<<" Step 3. PLUS CHARGED HADRON ISOLATION: ";
  cout<<setfill(' ')<<setw(7) <<right<<Third_Taus;
  if (Second_Taus > 0) 
    cout<<setw(9)<<setprecision(3)<< Third_Taus/Second_Taus <<setprecision(prec);
  else
    cout<<setw(9)<<"--"<<endl;
  
  if (Denominator_Taus > 0)
    cout<<setw(9)<<setprecision(3)<< Third_Taus/Denominator_Taus  << setprecision(prec)<<endl;
  else 
    cout<<setw(9)<<"--"<<endl;

  //  cout<<setfill('-')<<setw(110)<<"-"<<endl;

  cout<<setfill('-')<<setw(85)<<left<<" Step 4. PLUS GAMMA ISOLATION: ";
  cout<<setfill(' ')<<setw(7) <<right<<Forth_Taus;
  if (Third_Taus > 0) 
    cout<<setw(9)<<setprecision(3)<< Forth_Taus/Third_Taus <<setprecision(prec);
  else
    cout<<setw(9)<<"--"<<endl;
  
  if (Denominator_Taus > 0)
    cout<<setw(9)<<setprecision(3)<< Forth_Taus/Denominator_Taus  << setprecision(prec)<<endl;
  else 
    cout<<setw(9)<<"--"<<endl;

    cout<<setfill('-')<<setw(110)<<"-"<<endl; 
  */

  if (!outPutFile_.empty() && &*edm::Service<DQMStore>() && saveoutputhistograms_) dbeTau->save (outPutFile_);
  
}


