{               
  gSystem->Load("drawEfficiency_C.so");
  gSystem->Load("drawEfficiencies_C.so");

  TFile f("calotautag_CMSSW_2_0_0_pre4_OneProngAndThreeProng_CALOTAU.root");

  TString ReleaseVersion("CMSSW_2_0_0_pre2");
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

  //===========================================================Pt=============================================================
  TPaveText* text_etaCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_etaCut->SetBorderSize(0);
  text_etaCut->SetFillColor(0);
  text_etaCut->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetptTauJet,  nMCptTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyPt",35,35,525,525);
  drawEfficiency("Jets(Matched)/MC Visible Taus "+ ReleaseVersion, gr1, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nMCptTauJet->Clone(), c4, text_etaCut, Scale);
  delete c4;
  TGraphAsymmErrors* gr2 = new TGraphAsymmErrors(nCaloJetLTptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","LeadingTrackTotalEfficiencyPt",35,35,525,525);
  drawEfficiency("Leading Track Finding/MC Visible Taus "+ ReleaseVersion, gr2, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nMCptTauJet->Clone(), c4, text_etaCut, Scale);
  delete c4;
  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nTrackIsolatedptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","TrackIsolatedTotalEfficiencyPt",30,30,520,520);
  drawEfficiency("TrackIsolated/MC Visible Tau "+ReleaseVersion, gr3, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut, Scale);
  delete c4;
  TGraphAsymmErrors* gr4 =  new TGraphAsymmErrors(nEMIsolatedptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","EMIsolatedTotalEfficiencyPt",30,30,520,520);
  drawEfficiency("EMIsolated/MC Visible Taus "+ ReleaseVersion, gr4, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut, Scale);
  delete c4;
  c4 = new TCanvas("c4", "EfficienciesStepByStepPt", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ ReleaseVersion,  gr1, gr2, gr3,gr4,  "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nMCptTauJet->Clone(), c4, text_etaCut, "Calo", Scale);  
  delete c4; 
  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nCaloJetLTptTauJet,  nCaloJetptTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyPt",35,35,525,525);
  drawEfficiency("CaloJets+LeadTr/CaloJets(Matched) "+ ReleaseVersion, gr5, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nCaloJetptTauJet->Clone(), c4, text_etaCut, Scale);  
  delete c4;		 
  TGraphAsymmErrors* gr6 =  new TGraphAsymmErrors(nTrackIsolatedptTauJet,  nCaloJetLTptTauJet);
  c4 = new TCanvas("c4","TrackIsolatedPartialEfficiencyPt",35,35,525,525);
  drawEfficiency("TrackIsolated/Jets+LeadTr "+ ReleaseVersion, gr6, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nCaloJetLTptTauJet->Clone(), c4, text_etaCut, Scale); 
  delete c4;
  TGraphAsymmErrors* gr7 =  new TGraphAsymmErrors(nEMIsolatedptTauJet,  nTrackIsolatedptTauJet);
  c4 = new TCanvas("c4","EMIsolatedPartialEfficiencyPt",35,35,525,525);
  drawEfficiency("EMIsolated/TrackIsolated"+ReleaseVersion, gr7, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nTrackIsolatedptTauJet->Clone(), c4, text_etaCut, Scale); 

  delete gr1;
  delete gr2;
  delete gr3;
  delete gr4;
  delete gr5;
  delete gr6;
  delete gr7;
  delete c4;

 //====================================================ETA================================================================= 
  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddText(Form(" P_{T} > %.1f GeV", 5.0));

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetetaTauJet,  nMCetaTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyEta",35,35,525,525);
  drawEfficiency("Jets(Matched)/MC Visible Taus "+ ReleaseVersion, gr1, "#eta (MC Vis. Tau)",(TH1F*)  nMCetaTauJet->Clone(), c4, text_ptCut, Scale);
  delete c4;
  TGraphAsymmErrors* gr2 = new TGraphAsymmErrors(nCaloJetLTetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","LeadingTrackTotalEfficiencyEta",35,35,525,525);
  drawEfficiency("Leading Track Finding/MC Visible Taus "+ ReleaseVersion, gr2, "#eta (MC Vis. Tau)",(TH1F*)  nMCetaTauJet->Clone(), c4, text_ptCut, Scale);
  delete c4;
  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nTrackIsolatedetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","TrackIsolatedTotalEfficiencyEta",30,30,520,520);
  drawEfficiency("TrackIsolated/MC Visible Tau "+ReleaseVersion, gr3, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut, Scale);
  delete c4;
  TGraphAsymmErrors* gr4 =  new TGraphAsymmErrors(nEMIsolatedetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","EMIsolatedTotalEfficiencyEta",30,30,520,520);
  drawEfficiency("EMIsolated/MC Visible Taus "+ ReleaseVersion, gr4, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut, Scale);
  delete c4;
  c4 = new TCanvas("c4", "EfficienciesStepByStepEta", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ ReleaseVersion,  gr1, gr2, gr3,gr4,  "#eta (MC Vis. Tau)",(TH1F*)  nMCetaTauJet->Clone(), c4, text_ptCut, "Calo", Scale);  
  delete c4; 
  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nCaloJetLTetaTauJet,  nCaloJetetaTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyEta",35,35,525,525);
  drawEfficiency("CaloJets+LeadTr/CaloJets(Matched) "+ ReleaseVersion, gr5, "#eta (MC Vis. Tau)",(TH1F*)  nCaloJetetaTauJet->Clone(), c4, text_ptCut, Scale);  
  delete c4;		 
  TGraphAsymmErrors* gr6 =  new TGraphAsymmErrors(nTrackIsolatedetaTauJet,  nCaloJetLTetaTauJet);
  c4 = new TCanvas("c4","TrackIsolatedPartialEfficiencyEta",35,35,525,525);
  drawEfficiency("TrackIsolated/Jets+LeadTr "+ ReleaseVersion, gr6, "#eta (MC Vis. Tau)",(TH1F*)  nCaloJetLTetaTauJet->Clone(), c4, text_ptCut, Scale); 
  delete c4;
  TGraphAsymmErrors* gr7 =  new TGraphAsymmErrors(nEMIsolatedetaTauJet,  nTrackIsolatedetaTauJet);
  c4 = new TCanvas("c4","EMIsolatedPartialEfficiencyEta",35,35,525,525);
  drawEfficiency("EMIsolated/TrackIsolated"+ReleaseVersion, gr7, "#eta (MC Vis. Tau)",(TH1F*)  nTrackIsolatedetaTauJet->Clone(), c4, text_ptCut, Scale);

  delete gr1;
  delete gr2;
  delete gr3;
  delete gr4;
  delete gr5;
  delete gr6;
  delete gr7;
  delete c4;

  //===============================================================Energy========================================================

  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetenergyTauJet,  nMCenergyTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyEnergy",35,35,525,525);
  drawEfficiency("Jets(Matched)/MC Visible Taus "+ ReleaseVersion, gr1, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nMCenergyTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  TGraphAsymmErrors* gr2 = new TGraphAsymmErrors(nCaloJetLTenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","LeadingTrackTotalEfficiencyEnergy",35,35,525,525);
  drawEfficiency("Leading Track Finding/MC Visible Taus "+ ReleaseVersion, gr2, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nMCenergyTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nTrackIsolatedenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","TrackIsolatedTotalEfficiencyEnergy",30,30,520,520);
  drawEfficiency("TrackIsolated/MC Visible Tau "+ReleaseVersion, gr3, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  TGraphAsymmErrors* gr4 =  new TGraphAsymmErrors(nEMIsolatedenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","EMIsolatedTotalEfficiencyEnergy",30,30,520,520);
  drawEfficiency("EMIsolated/MC Visible Taus "+ ReleaseVersion, gr4, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  c4 = new TCanvas("c4", "EfficienciesStepByStepEnergy", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ ReleaseVersion,  gr1, gr2, gr3,gr4,  "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nMCenergyTauJet->Clone(), c4, text_bothCuts, "Calo", Scale);  
  delete c4; 
  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nCaloJetLTenergyTauJet,  nCaloJetenergyTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyEnergy",35,35,525,525);
  drawEfficiency("CaloJets+LeadTr/CaloJets(Matched) "+ ReleaseVersion, gr5, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nCaloJetenergyTauJet->Clone(), c4, text_bothCuts, Scale);  
  delete c4;		 
  TGraphAsymmErrors* gr6 =  new TGraphAsymmErrors(nTrackIsolatedenergyTauJet,  nCaloJetLTenergyTauJet);
  c4 = new TCanvas("c4","TrackIsolatedPartialEfficiencyEnergy",35,35,525,525);
  drawEfficiency("TrackIsolated/Jets+LeadTr "+ ReleaseVersion, gr6, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nCaloJetLTenergyTauJet->Clone(), c4, text_bothCuts, Scale); 
  delete c4;
  TGraphAsymmErrors* gr7 =  new TGraphAsymmErrors(nEMIsolatedenergyTauJet,  nTrackIsolatedenergyTauJet);
  c4 = new TCanvas("c4","EMIsolatedPartialEfficiencyEnergy",35,35,525,525);
  drawEfficiency("EMIsolated/TrackIsolated"+ReleaseVersion, gr7, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nTrackIsolatedenergyTauJet->Clone(), c4, text_bothCuts, Scale);

  delete gr1;
  delete gr2;
  delete gr3;
  delete gr4;
  delete gr5;
  delete gr6;
  delete gr7;
  delete c4;
 
  //===============================================================Phi========================================================

  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nCaloJetphiTauJet,  nMCphiTauJet);
  c4 = new TCanvas("c4","CaloJetTotalEfficiencyPhi",35,35,525,525);
  drawEfficiency("Jets(Matched)/MC Visible Taus "+ ReleaseVersion, gr1, "#phi (MC Vis. Tau)",(TH1F*)  nMCphiTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  TGraphAsymmErrors* gr2 = new TGraphAsymmErrors(nCaloJetLTphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","LeadingTrackTotalEfficiencyPhi",35,35,525,525);
  drawEfficiency("Leading Track Finding/MC Visible Taus "+ ReleaseVersion, gr2, "#phi (MC Vis. Tau)",(TH1F*)  nMCphiTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nTrackIsolatedphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","TrackIsolatedTotalEfficiencyPhi",30,30,520,520);
  drawEfficiency("TrackIsolated/MC Visible Tau "+ReleaseVersion, gr3, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  TGraphAsymmErrors* gr4 =  new TGraphAsymmErrors(nEMIsolatedphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","EMIsolatedTotalEfficiencyPhi",30,30,520,520);
  drawEfficiency("EMIsolated/MC Visible Taus "+ ReleaseVersion, gr4, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts, Scale);
  delete c4;
  c4 = new TCanvas("c4", "EfficienciesStepByStepPhi", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ ReleaseVersion,  gr1, gr2, gr3,gr4,  "#phi (MC Vis. Tau)",(TH1F*)  nMCphiTauJet->Clone(), c4, text_bothCuts, "Calo", Scale);  
  delete c4; 
  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nCaloJetLTphiTauJet,  nCaloJetphiTauJet);
  c4 = new TCanvas("c4","FindingLeadTrackPartialEfficiencyPhi",35,35,525,525);
  drawEfficiency("CaloJets+LeadTr/CaloJets(Matched) "+ ReleaseVersion, gr5, "#phi (MC Vis. Tau)",(TH1F*)  nCaloJetphiTauJet->Clone(), c4, text_bothCuts, Scale);  
  delete c4;		 
  TGraphAsymmErrors* gr6 =  new TGraphAsymmErrors(nTrackIsolatedphiTauJet,  nCaloJetLTphiTauJet);
  c4 = new TCanvas("c4","TrackIsolatedPartialEfficiencyPhi",35,35,525,525);
  drawEfficiency("TrackIsolated/Jets+LeadTr "+ ReleaseVersion, gr6, "#phi (MC Vis. Tau)",(TH1F*)  nCaloJetLTphiTauJet->Clone(), c4, text_bothCuts, Scale); 
  delete c4;
  TGraphAsymmErrors* gr7 =  new TGraphAsymmErrors(nEMIsolatedphiTauJet,  nTrackIsolatedphiTauJet);
  c4 = new TCanvas("c4","EMIsolatedPartialEfficiencyPhi",35,35,525,525);
  drawEfficiency("EMIsolated/TrackIsolated"+ReleaseVersion, gr7, "#phi (MC Vis. Tau)",(TH1F*)  nTrackIsolatedphiTauJet->Clone(), c4, text_bothCuts, Scale);

  delete gr1;
  delete gr2;
  delete gr3;
  delete gr4;
  delete gr5;
  delete gr6;
  delete gr7;
  delete c4;



}
