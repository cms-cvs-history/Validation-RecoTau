// -*- C++ -*-
//
// Package:    TauTagVal_BKG
// Class:      TauTagVal_BKG
// 
/**\class TauTagVal_BKG TauTagVal_BKG.cc RecoTauTag/ConeIsolation/test/TauTagVal_BKG.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Simone Gennai
//         Created:  Wed Apr 12 11:12:49 CEST 2006
// $Id: TauTagVal_BKG.cc,v 1.4 2007/03/05 18:23:34 gennai Exp $
//
//


// user include files
#include "Validation/RecoTau/interface/TauTagVal_BKG.h"
#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"
#include "TLorentzVector.h"
#include "TH1D.h"
#include "TF1.h"
#include "TClonesArray.h"
#include <vector>


using namespace edm;
using namespace std;
using namespace reco;



TauTagVal_BKG::TauTagVal_BKG(const edm::ParameterSet& iConfig)
{
  nEvent = 0;
  jetTagSrc = iConfig.getParameter<InputTag>("JetTagProd");
  genJetSrc = iConfig.getParameter<InputTag>("GenJets");
  outPutFile = iConfig.getParameter<string>("OutPutFile");
  rSig = iConfig.getParameter<double>("SignalCone");
  rMatch = iConfig.getParameter<double>("MatchingCone");
  rIso = iConfig.getParameter<double>("IsolationCone");
  ptLeadTk = iConfig.getParameter<double>("MinimumTransverseMomentumLeadingTrack");

  nEventsRiso.reserve(6);
  nEventsUsed.reserve(6);
  nEventsEnergy.reserve(6);
  nEventsEnergyUsed.reserve(6);
  for(int i=0;i<6;i++)
    {    
      nEventsRiso[i]=0;
      nEventsUsed[i]=0;
      nEventsEnergy[i]=0;
      nEventsEnergyUsed[i]=0;
    }

  nEventsUsed07.reserve(20);
  nEventsRiso07.reserve(20);
  nEventsUsed04.reserve(20);
  nEventsRiso04.reserve(20);

  nEventsUsed107.reserve(20);
  nEventsRiso107.reserve(20);
  nEventsUsed104.reserve(20);
  nEventsRiso104.reserve(20);

  nEventsUsed207.reserve(20);
  nEventsRiso207.reserve(20);
  nEventsUsed204.reserve(20);
  nEventsRiso204.reserve(20);

  nEventsUsed307.reserve(20);
  nEventsRiso307.reserve(20);
  nEventsUsed304.reserve(20);
  nEventsRiso304.reserve(20);

  for(int i=0;i<20;i++)
    {
      nEventsRiso07[i]=0.;
      nEventsUsed07[i]=0.;
      nEventsRiso04[i]=0.;
      nEventsUsed04[i]=0.;

      nEventsRiso107[i]=0.;
      nEventsUsed107[i]=0.;
      nEventsRiso104[i]=0.;
      nEventsUsed104[i]=0.;

      nEventsRiso207[i]=0.;
      nEventsUsed207[i]=0.;
      nEventsRiso204[i]=0.;
      nEventsUsed204[i]=0.;

      nEventsRiso307[i]=0.;
      nEventsUsed307[i]=0.;
      nEventsRiso304[i]=0.;
      nEventsUsed304[i]=0.;


    }


  ratio.reserve(100);
  ratioEta.reserve(100);
  etbin.reserve(100);
  nRuns=11;
  TString s="s";
  TString rationame="r";
  TString rationameEta="rEta";
  for(int i=0;i<20;i++)
    {
      rationame+=s;
      rationameEta+=s;
      hRatio=new TH1D(rationame,rationame,100,0,2);
      hRatioEta=new TH1D(rationameEta,rationameEta,100,0,2);
      ratio[i]=hRatio;
      ratioEta[i]=hRatioEta;
    }


  
  
DaqMonitorBEInterface* dbe = &*edm::Service<DaqMonitorBEInterface>();
  if(dbe) {
    dbe->setCurrentFolder("TauJetTask_" + jetTagSrc.label());    
    ptLeadingTrack = dbe->book1D("PtLeadTk", "Pt LeadTk", 30, 0., 300.);
    ptJet  = dbe->book1D("PtJet", "Pt Jet", 30, 0., 300.);
    nSignalTracks = dbe->book1D("NSigTks", "NSigTks", 10, 0., 10.);
    nSignalTracksAfterIsolation = dbe->book1D("NSigTksAI", "NSigTksAI", 10, 0., 10.);
    nAssociatedTracks = dbe->book1D("NAssTks", "NAssTks", 10, 0., 10.);
    nSelectedTracks = dbe->book1D("NSelTks", "NSelTks", 10, 0., 10.);

    effVsRiso = dbe->book1D("EffIsol","EffIsol",6,0.2,0.5);
    EventseffVsRiso = dbe->book1D("EventsIsol","EvEffIsol",6,0.2,0.5);
    EventsToteffVsRiso = dbe->book1D("EventsTotIsol","EvTotEffIsol",6,0.2,0.5);
    effVsEt = dbe->book1D("EffVsEtJet","EffVsEtJet",6,0.,300.);
    EventseffVsEt = dbe->book1D("EventsEffVsEtJet","EvEffVsEtJet",6,0.,300.);
    EventsToteffVsEt = dbe->book1D("EventsTotEffVsEtJet","EvTotEffVsEtJet",6,0.,300.);
    effFindLeadTk =dbe->book1D("EffLeadTk","EffLeadTk",2,0.,2.);
   
    deltaRLeadTk_Jet = dbe->book1D("DeltaR_LT_Jet","DeltaR",20,0.,0.2);
    hDRRecLdgTrTauJet=dbe->book1D("DeltaRJetLtr40<Et<60","DeltaRJetLtr40<Et<60",16,0,0.16);
    hDRRecLdgTrTauJet1=dbe->book1D("DeltaRJetLtr200<Et<250","DeltaRJetLtr200<Et<250",16,0,0.16);;
    
    dbe->setCurrentFolder("IsolationConeEff"+jetTagSrc.label());
    nSelVsRiso07=dbe->book1D("NSelVsRisoRsig07_130Et150","NSelVsRisoRsig07_130Et150",20,0,1);
    nSelVsRiso107=dbe->book1D("NSelVsRisoRsig07_80Et110","NSelVsRisoRsig07_80Et110",20,0,1);
    nSelVsRiso207=dbe->book1D("NSelVsRisoRsig07_50Et70","NSelVsRisoRsig07_50Et70",20,0,1);
    nSelVsRiso307=dbe->book1D("NSelVsRisoRsig07_30Et50","NSelVsRisoRsig07_30Et50",20,0,1);
    nSelVsRiso04=dbe->book1D("NSelVsRisoRsig04_130Et150","NSelVsRisoRsig04_130Et150",20,0,1);
    nSelVsRiso104=dbe->book1D("NSelVsRisoRsig04_80Et110","NSelVsRisoRsig04_80Et110",20,0,1);
    nSelVsRiso204=dbe->book1D("NSelVsRisoRsig04_50Et70","NSelVsRisoRsig04_50Et70",20,0,1);
    nSelVsRiso304=dbe->book1D("NSelVsRisoRsig04_30Et50","NSelVsRisoRsig04_30Et50",20,0,1);

    nTotVsRiso07=dbe->book1D("NTotVsRisoRsig07_130Et150","NTotVsRisoRsig07_130Et150",20,0,1);
    nTotVsRiso107=dbe->book1D("NTotVsRisoRsig07_80Et110","NTotVsRisoRsig07_80Et110",20,0,1);
    nTotVsRiso207=dbe->book1D("NTotVsRisoRsig07_50Et70","NTotVsRisoRsig07_50Et70",20,0,1);
    nTotVsRiso307=dbe->book1D("NTotVsRisoRsig07_30Et50","NTotVsRisoRsig07_30Et50",20,0,1);
    
    dbe->setCurrentFolder("TauJetResponsePlots"+jetTagSrc.label());
    hEtmean=dbe->book1D("EtmeanResp","EtmeanResp",nRuns,0,420);
    hEtamean=dbe->book1D("EtameanResp","EtameanResp",nRuns,0,2.2);
    hTauJets=dbe->book1D("hTauJets","hTauJets",200,0,450);

}

    
  if (outPutFile.empty ()) {
    LogInfo("OutputInfo") << " TauJet histograms will NOT be saved";
  } else {
    LogInfo("OutputInfo") << " TauJethistograms will be saved to file:" << outPutFile;
  }
  
}

void TauTagVal_BKG::beginJob(){ 

}

void TauTagVal_BKG::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace reco;

  edm::Handle< GenJetCollection > genJets ;
  iEvent.getByLabel( genJetSrc, genJets ) ;


  TClonesArray* TauJets=new TClonesArray("TLorentzVector");
  TLorentzVector TauJetMC(0.0,0.0,0.0,0.0);

  int jjj=0;
  GenJetCollection::const_iterator jetItr = genJets->begin();
  if(jetItr != genJets->end() )
    {
      math::XYZTLorentzVector p4 = jetItr->p4() ;
      TLorentzVector TauJetMC(p4.x(),p4.y(),p4.z(),p4.e());
      if(jjj<2) new((*TauJets)[jjj])TLorentzVector(TauJetMC);
      jjj++;
    }
  
  for(int j=0;j<TauJets->GetEntriesFast();j++)
    {
      TLorentzVector* theTauJet=(TLorentzVector*)TauJets->At(j);
      hTauJets->Fill(theTauJet->Et());
    }

  
  Handle<IsolatedTauTagInfoCollection> tauTagInfoHandle;
  iEvent.getByLabel(jetTagSrc, tauTagInfoHandle);
  
  const IsolatedTauTagInfoCollection & tauTagInfo = *(tauTagInfoHandle.product());
  
  IsolatedTauTagInfoCollection::const_iterator i = tauTagInfo.begin();
  int it=0,it1=0;
  for (; i != tauTagInfo.end(); ++i) {

    //Take only the first jet waiting for a jet selector
    //    if(it == 0) {
      for(int ii=0;ii<6;ii++)
	{
	  nEventsUsed[ii]++;
	  float Riso = ii*0.05 + 0.2;
	  float Etmin = ii*50.;
	  float Etmax  = Etmin+50;
	  float Rmatch = rMatch;
	  float Rsig = rSig;
	  float pT_LT = ptLeadTk;
	  float pT_min =1.;
	  if( i->discriminator(Rmatch,Rsig,Riso,pT_LT,pT_min) > 0) {
	    nEventsRiso[ii]++;
	  }
	  if(i->jet()->pt() > Etmin && i->jet()->pt()<Etmax)
	    {
	      nEventsEnergyUsed[ii]++;
	      if( i->discriminator(Rmatch,Rsig,rIso,pT_LT,pT_min) > 0) nEventsEnergy[ii]++;
	    }
	  if(!(i->leadingSignalTrack(rMatch, ptLeadTk)))
	    {
	      effFindLeadTk->Fill(0.);
	    }else{
	      effFindLeadTk->Fill(1.);
	    }
	  const TrackRef leadTkTmp= (i->leadingSignalTrack(0.5, 1.));
	  if(!leadTkTmp){
	  }else{
	    math::XYZVector momentum = (*leadTkTmp).momentum();
	    math::XYZVector jetMomentum(i->jet()->px(), i->jet()->py(), i->jet()->pz());
	    float deltaR = ROOT::Math::VectorUtil::DeltaR(jetMomentum, momentum);
	    deltaRLeadTk_Jet->Fill(deltaR);
	  }
	  
	  const TrackRef leadTk= (i->leadingSignalTrack(rMatch, 1.));
	  if(!leadTk){
	    LogInfo("LeadingTrack") << " No LeadingTrack";
	  }else{
	    ptLeadingTrack->Fill((*leadTk).pt());
	    ptJet->Fill((i->jet())->pt());
	    math::XYZVector momentum = (*leadTk).momentum();
	    float nsigtks = (i->tracksInCone(momentum, rSig,  1.)).size();
	    nSignalTracks->Fill(nsigtks);
	    if(i->discriminator(rMatch,rSig,rIso,ptLeadTk,1.) == 1)
	      nSignalTracksAfterIsolation->Fill(nsigtks);
	  }
	  float allTracks = i->allTracks().size();
	  nAssociatedTracks->Fill(allTracks);
	  float selectedTracks = i->selectedTracks().size();
	  nSelectedTracks->Fill(selectedTracks);
	}	      
    
    
      //Added By Konstantinos A. Petridis
      if(i->discriminator(0.1,0.07,0.4,6.,1.,0,0.2)){

	
	TLorentzVector recoTauJet(i->jet()->px(),i->jet()->py(),i->jet()->pz(),i->jet()->energy());
	bool trueTauJet=false;
	TLorentzVector* mcTauJetMatched=0;
	for(int m=0;m<TauJets->GetEntriesFast();m++)
	  {
	    TLorentzVector* trueTauJets=(TLorentzVector*)TauJets->At(m);
	    if(dR(trueTauJets,&recoTauJet)<0.2)
	      {
		trueTauJet=true;
		mcTauJetMatched=trueTauJets;
	      }
	  }
    
	if(trueTauJet)
	  {
	    double binSize=420.0/(1.0*nRuns);
	    double binSizeEta=2.2/(1.0*nRuns);
	    int EtBin=(mcTauJetMatched->Et())/binSize;
	    int EtaBin=(fabs(mcTauJetMatched->Eta()))/binSizeEta;
	    if(fabs(mcTauJetMatched->Eta())<2.2)
	      {
		ratio[EtBin]->Fill(recoTauJet.Et()/mcTauJetMatched->Et());
		if(mcTauJetMatched->Et()>30)ratioEta[EtaBin]->Fill(recoTauJet.Et()/mcTauJetMatched->Et());
	      }
	    
	    const TrackRef LeadingTrack3GeV=(i->leadingSignalTrack(0.1,3.0));
	    if(!LeadingTrack3GeV)cout<<"NO LEADING TRACK PASSES CRITERIA::"<<endl;
	    else
	      {
		math::XYZVector LeadingTrackMom=(*LeadingTrack3GeV).momentum();
		TVector3 LdgTrackMom3GeV(LeadingTrackMom.X(),LeadingTrackMom.Y(),LeadingTrackMom.Z());
		TVector3 RecoTauJetTight3GeV(i->jet()->px(),i->jet()->py(),i->jet()->pz());
		double LdgTrTauJetDR = Vec3dR(&LdgTrackMom3GeV,&RecoTauJetTight3GeV);
		if(mcTauJetMatched->Et()>40.0&&mcTauJetMatched->Et()<60)hDRRecLdgTrTauJet->Fill(LdgTrTauJetDR);
		if(mcTauJetMatched->Et()>200&&mcTauJetMatched->Et()<250)hDRRecLdgTrTauJet1->Fill(LdgTrTauJetDR);
	      }
	    
	  }
      }
      
      TLorentzVector recTauJet(i->jet()->px(),i->jet()->py(),i->jet()->pz(),i->jet()->energy());
      bool mtchdTauJet=false;
      TLorentzVector* mcTauJetMtchd=0;
      for(int l=0;l<TauJets->GetEntriesFast();l++)
	{
	  TLorentzVector* trTauJets=(TLorentzVector*)TauJets->At(l);
	  if(dR(trTauJets,&recTauJet)<0.2)
	    {
	      mtchdTauJet=true;
	      mcTauJetMtchd=trTauJets;
	    }
	}
      
      if(mtchdTauJet)
	{
	  if(mcTauJetMtchd->Et()>130.0&&mcTauJetMtchd->Et()<150.0)
	    {
	      for(int ii=0;ii<20;ii++){
		nEventsUsed07[ii]++;
		double riso=ii*0.05;
		if(i->discriminator(0.1,0.07,riso,6.0,1.0,0,0.2)){
		  nEventsRiso07[ii]++;
		}
		if(i->discriminator(0.1,0.04,riso,6.0,1.0,0,0.2)){
		  nEventsRiso04[ii]++;
		}
	      }
	    }
	  if(mcTauJetMtchd->Et()>80.0&&mcTauJetMtchd->Et()<110.0)
	    {
	      for(int ii=0;ii<20;ii++){
		nEventsUsed107[ii]++;
		double riso=ii*0.05;
		if(i->discriminator(0.1,0.07,riso,6.0,1.0,0,0.2)){
		  nEventsRiso107[ii]++;
		}
		if(i->discriminator(0.1,0.04,riso,6.0,1.0,0,0.2)){
		  nEventsRiso104[ii]++;
		}
	      }
	    }
	  if(mcTauJetMtchd->Et()>50.0&&mcTauJetMtchd->Et()<70.0)
	    {
	      for(int ii=0;ii<20;ii++){
		nEventsUsed207[ii]++;
		double riso=ii*0.05;
		if(i->discriminator(0.1,0.07,riso,6.0,1.0,0,0.2)){
		  nEventsRiso207[ii]++;
		}
		if(i->discriminator(0.1,0.04,riso,6.0,1.0,0,0.2)){
		  nEventsRiso204[ii]++;
		}
	      }
	    }
	  if(mcTauJetMtchd->Et()>30.0&&mcTauJetMtchd->Et()<50.0)
	    {
	      for(int ii=0;ii<20;ii++){
		nEventsUsed307[ii]++;
		double riso=ii*0.05;
		if(i->discriminator(0.1,0.07,riso,6.0,1.0,0,0.2)){
		  nEventsRiso307[ii]++;
		}
		if(i->discriminator(0.1,0.04,riso,6.0,1.0,0,0.2)){
		  nEventsRiso304[ii]++;
		}
	      }
	    }
	}
      //    }
      it1++;
      it++;
  }
  delete TauJets;

}
  
void TauTagVal_BKG::endJob(){
  int ibin;
  for(int ii=0; ii<6; ii++){
    if(nEventsUsed[ii] > 0.)
      {
	ibin= ii+1;
	float eff= nEventsRiso[ii]/nEventsUsed[ii];
	effVsRiso->setBinContent(ibin,eff);
	float nEvents = 1.*nEventsRiso[ii];
	float nEventsTot = 1.*nEventsUsed[ii];
	EventseffVsRiso->setBinContent(ibin, nEvents);
	EventsToteffVsRiso->setBinContent(ibin, nEventsTot);
      }
    if(nEventsEnergyUsed[ii] > 0.)
      {
	ibin= ii+1;
	float eff= nEventsEnergy[ii]/nEventsEnergyUsed[ii];
	effVsEt->setBinContent(ibin,eff);
	float nEvents = 1.*nEventsEnergy[ii];
	float nEventsTot = 1.*nEventsEnergyUsed[ii];
	EventseffVsEt->setBinContent(ibin,nEvents);
	EventsToteffVsEt->setBinContent(ibin,nEventsTot);
      }
  }


  //Added By Konstantinos A. Petridis
  
  int ibin07=0;
  
  for(int ii=0; ii<20; ii++){
    
    ibin07= ii+1;
  
    if(nEventsUsed07[ii])
      {
	nSelVsRiso07->setBinContent(ibin07,1.*nEventsRiso07[ii]);
	nTotVsRiso07->setBinContent(ibin07,1.*nEventsUsed07[ii]);

	nSelVsRiso04->setBinContent(ibin07,1.*nEventsRiso04[ii]);
      }

    if(nEventsUsed107[ii])
      {   
	nSelVsRiso107->setBinContent(ibin07,1.*nEventsRiso107[ii]);
	nTotVsRiso107->setBinContent(ibin07,1.*nEventsUsed107[ii]);
	nSelVsRiso104->setBinContent(ibin07,1.*nEventsRiso104[ii]);
      }

    if(nEventsUsed207[ii])
      {
	nSelVsRiso207->setBinContent(ibin07,1.*nEventsRiso207[ii]);
	nTotVsRiso207->setBinContent(ibin07,1.*nEventsUsed207[ii]);
	nSelVsRiso204->setBinContent(ibin07,1.*nEventsRiso204[ii]);

      }	

    if(nEventsUsed307[ii])
      {
	nSelVsRiso207->setBinContent(ibin07,1.*nEventsRiso307[ii]);
	nTotVsRiso207->setBinContent(ibin07,1.*nEventsUsed307[ii]);
	nSelVsRiso204->setBinContent(ibin07,1.*nEventsRiso304[ii]);

      }
  }

  double piEtmean[20];
  double piEtpar[100];
  double piEtmeanEr[20];
  double piEtamean[20];
  double piEtapar[100];
  double piEtameanEr[20];
  double etbinmean[20];
  double etbinerr[20];
  double etabinmean[20];
  double etabinerr[20];

  for(int i=0;i<nRuns;i++)
    {
      TF1 piEt("piEt","gaus");
      TF1 piEta("piEta","gaus");
      ratio[i]->Fit("piEt");
      ratioEta[i]->Fit("piEta");
      piEt.GetParameters(&piEtpar[0]);
      piEtmean[i]=piEtpar[1];
      piEtmeanEr[i]=piEt.GetParError(1);
      piEta.GetParameters(&piEtapar[0]);
      piEtamean[i]=piEtapar[1];
      piEtameanEr[i]=piEta.GetParError(1);
      etbinmean[i]=420/(nRuns*1.0)*i+420/(nRuns*2.0);
      etbinerr[i]=420/(nRuns*2.0);
      etabinmean[i]=2.2/(nRuns*1.0)*i+2.2/(nRuns*2.0);
      etabinerr[i]=2.2/(nRuns*2.0);
      hEtmean->setBinContent(i+1,piEtmean[i]);
      hEtmean->setBinError(i,piEtmeanEr[i]);
      hEtamean->setBinContent(i+1,piEtamean[i]);
      hEtamean->setBinError(i+1,piEtmeanEr[i]);
    }

  /*
  effVsRiso07->setAxisRange(0.4,1.0,2);
  effVsRiso107->setAxisRange(0.4,1.0,2);
  effVsRiso207->setAxisRange(0.4,1.0,2);
  effVsRiso307->setAxisRange(0.4,1.0,2);
  effVsRiso04->setAxisRange(0.4,1.0,2);
  effVsRiso104->setAxisRange(0.4,1.0,2);
  effVsRiso204->setAxisRange(0.4,1.0,2);
  effVsRiso304->setAxisRange(0.4,1.0,2);
  */
  hEtmean->setAxisRange(0.7,1.2,2);
  hEtmean->setAxisRange(0.7,1.2,2);


/*  
  effVsRiso07->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso07->GetYaxis()->SetTitle( "Efficiency" );
  effVsRiso107->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso107->GetYaxis()->SetTitle( "Efficiency" );
  effVsRiso207->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso207->GetYaxis()->SetTitle( "Efficiency" );
  effVsRiso307->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso307->GetYaxis()->SetTitle( "Efficiency" );

  effVsRiso04->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso04->GetYaxis()->SetTitle( "Efficiency" );
  effVsRiso104->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso104->GetYaxis()->SetTitle( "Efficiency" );
  effVsRiso204->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso204->GetYaxis()->SetTitle( "Efficiency" );
  effVsRiso304->GetXaxis()->SetTitle( "Isolation Cone" );
  effVsRiso304->GetYaxis()->SetTitle( "Efficiency" );
  */

  if (!outPutFile.empty() && &*edm::Service<DaqMonitorBEInterface>()) edm::Service<DaqMonitorBEInterface>()->save (outPutFile);
  
}
