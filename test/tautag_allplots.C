#include <TString.h>

void tautag_allplots(TString originalfilename, TString comparisonName, TString releaseversion, TString comparison, TString prongs)
{

  gSystem->Load("drawEfficiencyOther_C.so");
  gSystem->Load("drawEfficiencies_C.so");

  cout << endl << " Filename: "<< originalfilename<<endl;
  cout << endl << " comparison: " << comparison << endl;
  
  TFile f(originalfilename);
  TFile other(comparisonName);

  TString Scale("LinearScale");
  
  //---------------------------------------------------------------------------------------------
  //---------------------------------ORIGINAL FILE ----------------------------------------------
  //---------------------------------------------------------------------------------------------  
  TH1F* nMCetaTau=  (TH1F*)f.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/eta_Tau_GenLevel");
  TH1F* nMCptTau=   (TH1F*)f.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/pt_Tau_GenLevel");
  // THE FOUR HISTOGRAMS AT GENERATOR LEVEL
  TH1F* nMCptTauJet =     (TH1F*)f.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJet = (TH1F*)f.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_energyTauJet");
  TH1F* nMCetaTauJet =    (TH1F*)f.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_etaTauJet");
  TH1F* nMCphiTauJet =    (TH1F*)f.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_phiTauJet");

  // THE FOUR HISTOGRAMS RECONSTRUCTED AS JETS
  TH1F* nRecoJetptTauJet =     (TH1F*)f.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_ptTauJet");
  TH1F* nRecoJetenergyTauJet = (TH1F*)f.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_energyTauJet");
  TH1F* nRecoJetetaTauJet =    (TH1F*)f.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_etaTauJet");
  TH1F* nRecoJetphiTauJet = (TH1F*)f.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_phiTauJet");

  // THIS ONES I DON'T KNOW YET 
  TH1F* nAssociatedTracks =    (TH1F*)f.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/Number_Associated_Tracks");
  TH1F* nSelectedTracks =      (TH1F*)f.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/Number_Selected_Tracks");

  // THE FOUR HISTOGRAMS JETS + LEADING TRACK
  TH1F* nRecoJetLTptTauJet =     (TH1F*)f.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_ptTauJet");
  TH1F* nRecoJetLTenergyTauJet = (TH1F*)f.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_energyTauJet");
  TH1F* nRecoJetLTetaTauJet =    (TH1F*)f.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_etaTauJet");
  TH1F* nRecoJetLTphiTauJet =    (TH1F*)f.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_phiTauJet");
 
  // THE FOUR HISTOGRAMS TRACK ISOLATION
  TH1F* nTaggedJetsptTauJet =     (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_ptTauJet");
  TH1F* nTaggedJetsenergyTauJet = (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_energyTauJet");
  TH1F* nTaggedJetsetaTauJet =    (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_etaTauJet");
  TH1F* nTaggedJetsphiTauJet =    (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_phiTauJet");

  // THE FOUR HISTOGRAMS EM ISOLATION
  TH1F* nEMTaggedJetsptTauJet =     (TH1F*)f.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_ptTauJet");
  TH1F* nEMTaggedJetsenergyTauJet = (TH1F*)f.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_energyTauJet");
  TH1F* nEMTaggedJetsetaTauJet =    (TH1F*)f.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_etaTauJet");
  TH1F* nEMTaggedJetsphiTauJet =    (TH1F*)f.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_phiTauJet");

  // I DON'T KNOW WHAT TO DO WITH THESE HISTOGRAMS
  TH1F* LeadingTrackPt_TaggedTau =   (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/LeadingTrackPt_After_Isolation");
  TH1F* DeltaR_LTandJet_TaggedTau =  (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/DeltaR_LT_and_Jet_After_Isolation");
  TH1F* SignalTracks_TaggedTau =     (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/Signal_Tks_After_Isolation");
  TH1F* SelectedTracks_TaggedTau =   (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/Selected_Tks_After_Isolation");
  TH1F* AssociatedTracks_TaggedTau = (TH1F*)f.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/Associated_Tks_After_Isolation");

  gStyle->SetOptStat("ie");

  cout << endl<< " entries "<< nMCetaTauJet->Integral()<<endl;

  //---------------------------------------------------------------------------------------------
  //---------------------------------ORIGINAL FILE ----------------------------------------------
  //---------------------------------------------------------------------------------------------  

  TH1F* nMCetaTauO=  (TH1F*)other.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/eta_Tau_GenLevel");
  TH1F* nMCptTauO=   (TH1F*)other.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/pt_Tau_GenLevel");
  // THE FOUR HISTOGRAMS AT GENERATOR LEVEL
  TH1F* nMCptTauJetO =     (TH1F*)other.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJetO = (TH1F*)other.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_energyTauJet");
  TH1F* nMCetaTauJetO =    (TH1F*)other.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_etaTauJet");
  TH1F* nMCphiTauJetO =    (TH1F*)other.Get("DQMData/TausAtGenLevel_coneIsolationTauJetTags/nMC_Taus_vs_phiTauJet");

  // THE FOUR HISTOGRAMS RECONSTRUCTED AS JETS
  TH1F* nRecoJetptTauJetO =     (TH1F*)other.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_ptTauJet");
  TH1F* nRecoJetenergyTauJetO = (TH1F*)other.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_energyTauJet");
  TH1F* nRecoJetetaTauJetO =    (TH1F*)other.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_etaTauJet");
  TH1F* nRecoJetphiTauJetO = (TH1F*)other.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/n_RecoJet_vs_phiTauJet");

  // THIS ONES I DON'T KNOW YET 
  TH1F* nAssociatedTracksO =    (TH1F*)other.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/Number_Associated_Tracks");
  TH1F* nSelectedTracksO =      (TH1F*)other.Get("DQMData/ReconstructedJet_coneIsolationTauJetTags/Number_Selected_Tracks");

  // THE FOUR HISTOGRAMS JETS + LEADING TRACK
  TH1F* nRecoJetLTptTauJetO =     (TH1F*)other.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_ptTauJet");
  TH1F* nRecoJetLTenergyTauJetO = (TH1F*)other.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_energyTauJet");
  TH1F* nRecoJetLTetaTauJetO =    (TH1F*)other.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_etaTauJet");
  TH1F* nRecoJetLTphiTauJetO =    (TH1F*)other.Get("DQMData/ReconstructedJetWithLeadingTrack_coneIsolationTauJetTags/n_RecoJet+LeadingTrack_vs_phiTauJet");
 
  // THE FOUR HISTOGRAMS TRACK ISOLATION
  TH1F* nTaggedJetsptTauJetO =     (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_ptTauJet");
  TH1F* nTaggedJetsenergyTauJetO = (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_energyTauJet");
  TH1F* nTaggedJetsetaTauJetO =    (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_etaTauJet");
  TH1F* nTaggedJetsphiTauJetO =    (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/n_IsolatedTauTaggedJets_vs_phiTauJet");

  // THE FOUR HISTOGRAMS EM ISOLATION
  TH1F* nEMTaggedJetsptTauJetO =     (TH1F*)other.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_ptTauJet");
  TH1F* nEMTaggedJetsenergyTauJetO = (TH1F*)other.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_energyTauJet");
  TH1F* nEMTaggedJetsetaTauJetO =    (TH1F*)other.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_etaTauJet");
  TH1F* nEMTaggedJetsphiTauJetO =    (TH1F*)other.Get("DQMData/TauEMTaggedJets_ecalIsolation/n_EMIsolatedTauTaggedJets_vs_phiTauJet");

  // I DON'T KNOW WHAT TO DO WITH THESE HISTOGRAMS
  TH1F* LeadingTrackPt_TaggedTauO =   (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/LeadingTrackPt_After_Isolation");
  TH1F* DeltaR_LTandJet_TaggedTauO =  (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/DeltaR_LT_and_Jet_After_Isolation");
  TH1F* SignalTracks_TaggedTauO =     (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/Signal_Tks_After_Isolation");
  TH1F* SelectedTracks_TaggedTauO =   (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/Selected_Tks_After_Isolation");
  TH1F* AssociatedTracks_TaggedTauO = (TH1F*)other.Get("DQMData/TauTaggedJets_coneIsolationTauJetTags/Associated_Tks_After_Isolation");

  cout << endl<< " entriesO "<< nMCetaTauJetO->Integral()<<endl;

 //====================================================ETA================================================================= 

  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddText(Form(" P_{T} > %.1f GeV", 5.0));

  TH1F* divisionHisto = (TH1F *) nMCetaTauJetO->Clone();
  divisionHisto->Divide(nRecoJetetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nRecoJetetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyEta",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto2 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto2->Divide(nRecoJetLTetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto2, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto3 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto3->Divide(nTaggedJetsetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto3, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto4 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto4->Divide(nEMTaggedJetsetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMTaggedJetsetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","EMIsolationEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" EM Isolated/MC Visible Tau "+releaseversion, gr3, divisionHisto4, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepEta", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3,  "#eta (MC Vis. Tau)",(TH1F*)  nMCetaTauJet->Clone(), c4, text_ptCut,"Calo", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3;

  TH1F* divisionHisto17 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto17->Divide(nRecoJetLTetaTauJetO, nRecoJetetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTetaTauJet,nRecoJetetaTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto17, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto18 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto18->Divide(nTaggedJetsetaTauJetO, nRecoJetLTetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsetaTauJet, nRecoJetLTetaTauJet);
  c4 = new TCanvas("c4","TrackIsolationPartialEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/Jets+LeadTrack "+releaseversion, gr2, divisionHisto18, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 
  delete gr1;
  delete gr2;


 //====================================================Pt================================================================= 

  TPaveText* text_etaCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_etaCut->SetBorderSize(0);
  text_etaCut->SetFillColor(0);
  text_etaCut->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TH1F* divisionHisto5 = (TH1F *) nMCptTauJetO->Clone();
  divisionHisto5->Divide(nRecoJetptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nRecoJetptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyPt",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto5, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto6 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto6->Divide(nRecoJetLTptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto6, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto7 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto7->Divide(nTaggedJetsptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto7, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto8 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto8->Divide(nEMTaggedJetsptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMTaggedJetsptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","EMIsolationEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" EM Isolated/MC Visible Tau "+releaseversion, gr3, divisionHisto8, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepPt", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nMCptTauJet->Clone(), c4, text_etaCut,"Calo", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3;

  TH1F* divisionHisto19 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto19->Divide(nRecoJetLTptTauJetO, nRecoJetptTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTptTauJet,nRecoJetptTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto19, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto20 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto20->Divide(nTaggedJetsptTauJetO, nRecoJetLTptTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsptTauJet, nRecoJetLTptTauJet);
  c4 = new TCanvas("c4","TrackIsolationPartialEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/Jets+LeadTrack "+releaseversion, gr2, divisionHisto20, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 
  delete gr1;
  delete gr2;


 //==================================================== Energy ================================================================= 
 
  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TH1F* divisionHisto9 = (TH1F *) nMCenergyTauJetO->Clone();
  divisionHisto9->Divide(nRecoJetenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nRecoJetenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto9,"Energy (GeV) (MC Vis. Tau)" , (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto10 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto10->Divide(nRecoJetLTenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto10,"Energy (GeV) (MC Vis. Tau)" , (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto11 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto11->Divide(nTaggedJetsenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto11, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto12 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto12->Divide(nEMTaggedJetsenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMTaggedJetsenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","EMIsolationEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" EM Isolated/MC Visible Tau "+releaseversion, gr3, divisionHisto12, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepEnergy", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nMCenergyTauJet->Clone(), c4, text_bothCuts,"Calo", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3;

  TH1F* divisionHisto21 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto21->Divide(nRecoJetLTenergyTauJetO, nRecoJetenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTenergyTauJet,nRecoJetenergyTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto21, "Energy (GeV/c) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto22 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto22->Divide(nTaggedJetsenergyTauJetO, nRecoJetLTenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsenergyTauJet, nRecoJetLTenergyTauJet);
  c4 = new TCanvas("c4","TrackIsolationPartialEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/Jets+LeadTrack "+releaseversion, gr2, divisionHisto22, "Energy (GeV/c) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 
  delete gr1;
  delete gr2;

 //==================================================== Phi ================================================================= 
 
  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TH1F* divisionHisto13 = (TH1F *) nMCphiTauJetO->Clone();
  divisionHisto13->Divide(nRecoJetphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nRecoJetphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto13,"#phi (MC Vis. Tau)" , (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto14 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto14->Divide(nRecoJetLTphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto14,"#phi (MC Vis. Tau)" , (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto15 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto15->Divide(nTaggedJetsphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto15, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto16 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto16->Divide(nEMTaggedJetsphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMTaggedJetsphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","EMIsolationEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" EM Isolated/MC Visible Tau "+releaseversion, gr3, divisionHisto16, "#phi (MC Vis. Tau)" , (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepPhi", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3, "#phi (MC Vis. Tau)",(TH1F*)  nMCphiTauJet->Clone(), c4, text_bothCuts,"Calo", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3;

  TH1F* divisionHisto23 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto23->Divide(nRecoJetLTphiTauJetO, nRecoJetphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nRecoJetLTphiTauJet,nRecoJetphiTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto23, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto24 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto24->Divide(nTaggedJetsphiTauJetO, nRecoJetLTphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTaggedJetsphiTauJet, nRecoJetLTphiTauJet);
  c4 = new TCanvas("c4","TrackIsolationPartialEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/Jets+LeadTrack "+releaseversion, gr2, divisionHisto24, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 
  delete gr1;
  delete gr2;

}
