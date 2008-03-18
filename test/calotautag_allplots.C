#include <TString.h>

void calotautag_allplots(TString originalfilename, TString comparisonfilename, TString releaseversion, TString comparison, TString prongs)
{

  gSystem->Load("drawEfficiencyOther_C.so");
  gSystem->Load("drawEfficiencies_C.so");

  cout << endl << " Filename: "<< originalfilename<<endl;
  cout << endl << " comparison: " << comparison << endl;

  TFile f(originalfilename);
  TFile other(comparisonfilename);

  TString Scale("LinearScale");

  //---------------------------------------------------------------------------------------------
  //---------------------------------ORIGINAL FILE ----------------------------------------------
  //---------------------------------------------------------------------------------------------

  TH1F* nMCetaTau=  (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/eta_Tau_GenLevel");
  TH1F* nMCptTau=   (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/pt_Tau_GenLevel");

  // THE FOUR HISTOGRAMS AT GENERATOR LEVEL VISIBLE TAU
  TH1F* nMCetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_etaTauJet");
  TH1F* nMCptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_energyTauJet");
  TH1F* nMCphiTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_phiTauJet");

  // RECONSTRUCTED AS CALOJETS

  TH1F* nCaloJetetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_etaTauJet");
  TH1F* nCaloJetptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_ptTauJet");
  TH1F* nCaloJetenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_energyTauJet");
  TH1F* nCaloJetphiTauJet=     (TH1F*)f.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_phiTauJet");

  // LEADING TRACK FINDING

  TH1F* nCaloJetLTetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_etaTauJet");
  TH1F* nCaloJetLTptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_ptTauJet");
  TH1F* nCaloJetLTenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_energyTauJet");
  TH1F* nCaloJetLTphiTauJet=     (TH1F*)f.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_phiTauJet");
  
  // TRACK ISOLATED CALOJETS

  TH1F* nTrackIsolatedetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_etaTauJet");
  TH1F* nTrackIsolatedptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_ptTauJet");
  TH1F* nTrackIsolatedenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_energyTauJet");
  TH1F* nTrackIsolatedphiTauJet=     (TH1F*)f.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_phiTauJet");
  
  // THE FOUR HISTOGRAMS EM ISOLATION

  TH1F* nEMIsolatedetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_etaTauJet");
  TH1F* nEMIsolatedptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_ptTauJet");
  TH1F* nEMIsolatedenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_energyTauJet");
  TH1F* nEMIsolatedphiTauJet=     (TH1F*)f.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_phiTauJet");


  //---------------------------------------------------------------------------------------------
  //---------------------------------OTHER FILE ----------------------------------------------
  //---------------------------------------------------------------------------------------------


  TH1F* nMCetaTauO=  (TH1F*)other.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/eta_Tau_GenLevel");
  TH1F* nMCptTauO=   (TH1F*)other.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/pt_Tau_GenLevel");

  // THE FOUR HISTOGRAMS AT GENERATOR LEVEL VISIBLE TAU
  TH1F* nMCetaTauJetO =    (TH1F*)other.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_etaTauJet");
  TH1F* nMCptTauJetO =     (TH1F*)other.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJetO = (TH1F*)other.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_energyTauJet");
  TH1F* nMCphiTauJetO =    (TH1F*)other.Get("DQMData/RecoTauV/TausAtGenLevel_CaloTauValidation/nMC_Taus_vs_phiTauJet");

  // RECONSTRUCTED AS CALOJETS

  TH1F* nCaloJetetaTauJetO =    (TH1F*)other.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_etaTauJet");
  TH1F* nCaloJetptTauJetO =     (TH1F*)other.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_ptTauJet");
  TH1F* nCaloJetenergyTauJetO = (TH1F*)other.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_energyTauJet");
  TH1F* nCaloJetphiTauJetO=     (TH1F*)other.Get("DQMData/RecoTauV/CaloJetMatched_CaloTauValidation/CaloJet_vs_phiTauJet");

  // LEADING TRACK FINDING

  TH1F* nCaloJetLTetaTauJetO =    (TH1F*)other.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_etaTauJet");
  TH1F* nCaloJetLTptTauJetO =     (TH1F*)other.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_ptTauJet");
  TH1F* nCaloJetLTenergyTauJetO = (TH1F*)other.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_energyTauJet");
  TH1F* nCaloJetLTphiTauJetO=     (TH1F*)other.Get("DQMData/RecoTauV/LeadingTrackFinding_CaloTauValidation/LeadingTrack_vs_phiTauJet");
  
  // TRACK ISOLATED CALOJETS

  TH1F* nTrackIsolatedetaTauJetO =    (TH1F*)other.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_etaTauJet");
  TH1F* nTrackIsolatedptTauJetO =     (TH1F*)other.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_ptTauJet");
  TH1F* nTrackIsolatedenergyTauJetO = (TH1F*)other.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_energyTauJet");
  TH1F* nTrackIsolatedphiTauJetO=     (TH1F*)other.Get("DQMData/RecoTauV/TrackIsolated_CaloTauValidation/TrackIsolated_vs_phiTauJet");
  
  // THE FOUR HISTOGRAMS EM ISOLATION

  TH1F* nEMIsolatedetaTauJetO =    (TH1F*)other.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_etaTauJet");
  TH1F* nEMIsolatedptTauJetO =     (TH1F*)other.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_ptTauJet");
  TH1F* nEMIsolatedenergyTauJetO = (TH1F*)other.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_energyTauJet");
  TH1F* nEMIsolatedphiTauJetO=     (TH1F*)other.Get("DQMData/RecoTauV/EMIsolated_CaloTauValidation/EMIsolated_vs_phiTauJet");


 //====================================================ETA================================================================= 

  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddText(Form(" P_{T} > %.1f GeV", 5.0));

  TH1F* divisionHisto = (TH1F *) nMCetaTauJetO->Clone();
  divisionHisto->Divide(nCaloJetetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nCaloJetetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyEta",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto2 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto2->Divide(nCaloJetLTetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto2, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto3 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto3->Divide(nTrackIsolatedetaTauJetO, nMCetaTauJetO, 1, 1);
  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto3, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto4 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto4->Divide(nEMIsolatedetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMIsolatedetaTauJet, nMCetaTauJet);
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
  divisionHisto17->Divide(nCaloJetLTetaTauJetO, nCaloJetetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTetaTauJet,nCaloJetetaTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto17, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto18 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto18->Divide(nTrackIsolatedetaTauJetO, nCaloJetLTetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedetaTauJet, nCaloJetLTetaTauJet);
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
  divisionHisto5->Divide(nCaloJetptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nCaloJetptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyPt",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto5, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto6 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto6->Divide(nCaloJetLTptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto6, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto7 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto7->Divide(nTrackIsolatedptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto7, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto8 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto8->Divide(nEMIsolatedptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMIsolatedptTauJet, nMCptTauJet);
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
  divisionHisto19->Divide(nCaloJetLTptTauJetO, nCaloJetptTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTptTauJet,nCaloJetptTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto19, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto20 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto20->Divide(nTrackIsolatedptTauJetO, nCaloJetLTptTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedptTauJet, nCaloJetLTptTauJet);
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
  divisionHisto9->Divide(nCaloJetenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nCaloJetenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto9,"Energy (GeV) (MC Vis. Tau)" , (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto10 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto10->Divide(nCaloJetLTenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto10,"Energy (GeV) (MC Vis. Tau)" , (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto11 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto11->Divide(nTrackIsolatedenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto11, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto12 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto12->Divide(nEMIsolatedenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMIsolatedenergyTauJet, nMCenergyTauJet);
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
  divisionHisto21->Divide(nCaloJetLTenergyTauJetO, nCaloJetenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTenergyTauJet,nCaloJetenergyTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto21, "Energy (GeV/c) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto22 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto22->Divide(nTrackIsolatedenergyTauJetO, nCaloJetLTenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedenergyTauJet, nCaloJetLTenergyTauJet);
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
  divisionHisto13->Divide(nCaloJetphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nCaloJetphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther("Jets(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto13,"#phi (MC Vis. Tau)" , (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto14 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto14->Divide(nCaloJetLTphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTr/MC Visible Tau "+releaseversion, gr1, divisionHisto14,"#phi (MC Vis. Tau)" , (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto15 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto15->Divide(nTrackIsolatedphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","TrackIsolationEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/MC Visible Tau "+releaseversion, gr2, divisionHisto15, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto16 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto16->Divide(nEMIsolatedphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nEMIsolatedphiTauJet, nMCphiTauJet);
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
  divisionHisto23->Divide(nCaloJetLTphiTauJetO, nCaloJetphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetLTphiTauJet,nCaloJetphiTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Jets+LeadTrack/Jets (Matched) "+releaseversion, gr1, divisionHisto23, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto24 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto24->Divide(nTrackIsolatedphiTauJetO, nCaloJetLTphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nTrackIsolatedphiTauJet, nCaloJetLTphiTauJet);
  c4 = new TCanvas("c4","TrackIsolationPartialEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" Track Isolated/Jets+LeadTrack "+releaseversion, gr2, divisionHisto24, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 
  delete gr1;
  delete gr2;


}
