 
{               
  gSystem->Load("drawEfficiency_C.so");

  TFile f("tautag_IsoEffValid.root");

  TH1F* nMCetaTau=  (TH1F*)f.Get("DQMData/TausAtGenLevel_ConeIsolationForValidation/eta_Tau_GenLevel");
  TH1F* nMCptTau=   (TH1F*)f.Get("DQMData/TausAtGenLevel_ConeIsolationForValidation/pt_Tau_GenLevel");

  TH1F* nMCetaTauJet =    (TH1F*)f.Get("DQMData/TausAtGenLevel_ConeIsolationForValidation/nMC_Taus_vs_etaTauJet");
  TH1F* nMCptTauJet =     (TH1F*)f.Get("DQMData/TausAtGenLevel_ConeIsolationForValidation/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJet = (TH1F*)f.Get("DQMData/TausAtGenLevel_ConeIsolationForValidation/nMC_Taus_vs_energyTauJet");

  TH1F* nRecoJetetaTauJet =    (TH1F*)f.Get("DQMData/ReconstructedJet_ConeIsolationForValidation/n_RecoJet_vs_etaTauJet");
  TH1F* nRecoJetptTauJet =     (TH1F*)f.Get("DQMData/ReconstructedJet_ConeIsolationForValidation/n_RecoJet_vs_ptTauJet");
  TH1F* nRecoJetenergyTauJet = (TH1F*)f.Get("DQMData/ReconstructedJet_ConeIsolationForValidation/n_RecoJet_vs_energyTauJet");
  TH1F* nAssociatedTracks =    (TH1F*)f.Get("DQMData/ReconstructedJet_ConeIsolationForValidation/Number_Associated_Tracks");
  TH1F* nSelectedTracks =      (TH1F*)f.Get("DQMData/ReconstructedJet_ConeIsolationForValidation/Number_Selected_Tracks");

  TH1F* nRecoJetLTetaTauJet =    (TH1F*)f.Get("DQMData/ReconstructedJetWithLeadingTrack_ConeIsolationForValidation/n_RecoJet+LeadingTrack_vs_etaTauJet");
  TH1F* nRecoJetLTptTauJet =     (TH1F*)f.Get("DQMData/ReconstructedJetWithLeadingTrack_ConeIsolationForValidation/n_RecoJet+LeadingTrack_vs_ptTauJet");
  TH1F* nRecoJetLTenergyTauJet = (TH1F*)f.Get("DQMData/ReconstructedJetWithLeadingTrack_ConeIsolationForValidation/n_RecoJet+LeadingTrack_vs_energyTauJet");

  TH1F* nTaggedJetsetaTauJet =    (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/n_IsolatedTauTaggedJets_vs_etaTauJet");
  TH1F* nTaggedJetsptTauJet =     (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/n_IsolatedTauTaggedJets_vs_ptTauJet");
  TH1F* nTaggedJetsenergyTauJet = (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/n_IsolatedTauTaggedJets_vs_energyTauJet");

  gStyle->SetOptStat("ie");

  cout << endl<< " entries "<< nMCetaTauJet->Integral()<<endl;

  c21 = new TCanvas("c21","", 10, 10, 500, 410);
  nMCetaTauJet->SetTitle("# MC Taus (Visible Energy)");
  nMCetaTauJet->GetXaxis()->SetTitle("eta");
  nMCetaTauJet->DrawNormalized();
  c21->Print(TString("MCetaTauJets.eps"),"eps");


  c22 = new TCanvas("c22","", 10,10,500,410);
  nMCptTauJet->SetTitle("# MC Taus (Visible Energy)");
  nMCptTauJet->GetXaxis()->SetTitle("Pt (GeV)");
  nMCptTauJet->DrawNormalized();
  c22->Print(TString("MCPtTauJets.eps"),"eps");	    
  
  c23 = new TCanvas("c23","", 10,10,500,410);
  nMCenergyTauJet->SetTitle("# MC Taus (Visible Energy)");
  nMCenergyTauJet->GetXaxis()->SetTitle("Energy (GeV)");
  nMCenergyTauJet->DrawNormalized();
  c23->Print(TString("MCEnergyTauJets.eps"),"eps");

  c24 = new TCanvas("c24","", 10,10,500,410);
  nMCetaTau->SetTitle("# MC Taus");
  nMCetaTau->GetXaxis()->SetTitle("eta");
  nMCetaTau->DrawNormalized(); 
  c24->Print(TString("MCetaTau.eps"),"eps");

  c25 = new TCanvas("c25","", 10,10,500,410);
  nMCptTau->SetTitle("# MC Taus");
  nMCptTau->GetXaxis()->SetTitle("Pt (GeV)");
  nMCptTau->DrawNormalized();
  c25->Print(TString("MCPtTau.eps"),"eps");	 

  c26 = new TCanvas("c26","", 10,10,500,410);
  nAssociatedTracks->SetTitle("Associated Tracks Matched Reconstructed Jet ");
  nAssociatedTracks->GetXaxis()->SetTitle("# Associated Tracks");
  nAssociatedTracks->DrawNormalized();
  c26->Print(TString("AssociatedTracks.eps"),"eps");	 
  
  c27 = new TCanvas("c27","", 10,10,500,410);
  nSelectedTracks->SetTitle("Selected Tracks Matched Reconstructed Jet ");
  nSelectedTracks->GetXaxis()->SetTitle("# Selected Tracks");
  nSelectedTracks->DrawNormalized();
  c27->Print(TString("SelectedTracks.eps"),"eps");	 

  /*
  c2 = new TCanvas("c2","",15,15,505,1205);
  
  c2->Divide(1,3);

  c2_1->cd();
  nRecoJetetaTauJet->Draw();
  c2_2->cd();
  nRecoJetptTauJet->Draw();
  c2_3->cd();
  nRecoJetenergyTauJet->Draw();

  c3 = new TCanvas("c3","",20,20,510,1210);

  c3->Divide(1,3);
  
  c3_1->cd();
  nRecoJetLTetaTauJet->Draw();
  c3_2->cd();
  nRecoJetLTptTauJet->Draw();
  c3_3->cd();
  nRecoJetLTenergyTauJet->Draw();  

  c4 = new TCanvas("c4","",25,25,515,1215);

  c4->Divide(1,3);
  
  c4_1->cd();
  nTaggedJetsetaTauJet->Draw();
  c4_2->cd();
  nTaggedJetsptTauJet->Draw();
  c4_3->cd();
  nTaggedJetsenergyTauJet->Draw(); 
  */
  //*****************************************************************************************************

  TH1F* deltaRLeadingTrackJetP =        (TH1F *)f.Get("DQMData/LeadingTrackPtAndDeltaRStudies_ConeIsolationForValidation/DeltaR_LeadingTrack_in_RecoJet");
  TH1F* leadingTrackPtJet      =        (TH1F *)f.Get("DQMData/LeadingTrackPtAndDeltaRStudies_ConeIsolationForValidation/Leading_track_pt_in_RecoJet");

  c21 = new TCanvas("c21","",125,125,615,615);
  deltaRLeadingTrackJetP->Draw();
  c22 = new TCanvas("c22","",150,150,640,640);
  leadingTrackPtJet->Draw();
  
  //========================================================================================================================= 
  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddText(Form(" %.1f  < P_{T} < %.1f GeV", 10.0, 100.0));

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nTaggedJetsetaTauJet, nMCetaTauJet);
  c5 = new TCanvas("c5","TotalEfficiencyEta",30,30,520,520);
  drawEfficiency("N_Isolated/N_Total Generated", gr1, "eta (MC Tau Jet)", (TH1F*) nMCetaTauJet->Clone(), c5, text_ptCut);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nRecoJetetaTauJet,  nMCetaTauJet);
  c6 = new TCanvas("c6","CaloJetTotalEfficiencyEta",35,35,525,525);
  drawEfficiency("N_CaloJets(Matched)/N_Total MC Generated", gr2, "eta (MC Tau Jet)",(TH1F*)  nMCetaTauJet->Clone(), c6, text_ptCut);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nRecoJetLTetaTauJet,  nRecoJetetaTauJet);
  c7 = new TCanvas("c7","FindingLeadTrackPartialEfficiencyEta",35,35,525,525);
  drawEfficiency("N_CaloJets+LeadTr/N_CaloJets(Matched)", gr3, "eta (MC Tau Jet)",(TH1F*)  nRecoJetetaTauJet->Clone(), c7, text_ptCut);  
  		 
  TGraphAsymmErrors* gr4 =  new TGraphAsymmErrors(nTaggedJetsetaTauJet,  nRecoJetLTetaTauJet);
  c8 = new TCanvas("c8","IsolationPartialEfficencyEta",35,35,525,525);
  drawEfficiency("N_Isolated/N_CaloJets+LeadTr", gr4, "eta (MC Tau Jet)",(TH1F*)  nRecoJetetaTauJet->Clone(), c8, text_ptCut); 

  //==========================================================================================================================
  TPaveText* text_etaCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_etaCut->SetBorderSize(0);
  text_etaCut->SetFillColor(0);
  text_etaCut->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nTaggedJetsptTauJet, nMCptTauJet);
  c9 = new TCanvas("c5","TotalEfficiencyPt",30,30,520,520);
  drawEfficiency("N_Isolated/N_Total Generated", gr5, "Pt (GeV) (MC Tau Jet)", (TH1F*) nMCptTauJet->Clone(), c9, text_etaCut);
  
  TGraphAsymmErrors* gr6 =  new TGraphAsymmErrors(nRecoJetptTauJet,  nMCptTauJet);
  c10 = new TCanvas("c10","CaloJetTotalEfficiencyPt",35,35,525,525);
  drawEfficiency("N_CaloJets(Matched)/N_Total MC Generated", gr6, "Pt (GeV) (MC Tau Jet)",(TH1F*)  nMCptTauJet->Clone(), c10, text_etaCut);

  TGraphAsymmErrors* gr7 =  new TGraphAsymmErrors(nRecoJetLTptTauJet,  nRecoJetptTauJet);
  c11 = new TCanvas("c11","FindingLeadTrackPartialEfficiencyPt",35,35,525,525);
  drawEfficiency("N_CaloJets+LeadTr/N_CaloJets(Matched)", gr7, "Pt (GeV) (MC Tau Jet)",(TH1F*)  nRecoJetptTauJet->Clone(), c11, text_etaCut);  
  		 
  TGraphAsymmErrors* gr8 =  new TGraphAsymmErrors(nTaggedJetsptTauJet,  nRecoJetLTptTauJet);
  c12 = new TCanvas("c12","IsolationPartialEfficencyPt",35,35,525,525);
  drawEfficiency("N_Isolated/N_CaloJets+LeadTr", gr8, "Pt (GeV) (MC Tau Jet)",(TH1F*)  nRecoJetptTauJet->Clone(), c12, text_etaCut); 

  //==========================================================================================================================

  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" %.1f  < P_{T} < %.1f GeV", 10.0, 100.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr9 =  new TGraphAsymmErrors(nTaggedJetsenergyTauJet, nMCenergyTauJet);
  c13 = new TCanvas("c13","TotalEfficiencyEnergy",30,30,520,520);
  drawEfficiency("N_Isolated/N_Total Generated", gr9, "Energy (GeV) (MC Tau Jet)", (TH1F*) nMCenergyTauJet->Clone(), c13, text_bothCuts);
  
  TGraphAsymmErrors* gr10 =  new TGraphAsymmErrors(nRecoJetenergyTauJet,  nMCenergyTauJet);
  c14 = new TCanvas("c14","CaloJetTotalEfficiencyEnergy",35,35,525,525);
  drawEfficiency("N_CaloJets(Matched)/N_Total MC Generated", gr10, "Energy (GeV) (MC Tau Jet)",(TH1F*)  nMCenergyTauJet->Clone(), c14, text_bothCuts);

  TGraphAsymmErrors* gr11 =  new TGraphAsymmErrors(nRecoJetLTenergyTauJet,  nRecoJetenergyTauJet);
  c15 = new TCanvas("c15","FindingLeadTrackPartialEfficiencyEnergy",35,35,525,525);
  drawEfficiency("N_CaloJets+LeadTr/N_CaloJets(Matched)", gr11, "Energy (GeV) (MC Tau Jet)",(TH1F*)  nRecoJetenergyTauJet->Clone(), c15, text_bothCuts);  
  		 
  TGraphAsymmErrors* gr12 =  new TGraphAsymmErrors(nTaggedJetsenergyTauJet,  nRecoJetLTenergyTauJet);
  c16 = new TCanvas("c16","IsolationPartialEfficencyEnergy",35,35,525,525);
  drawEfficiency("N_Isolated/N_CaloJets+LeadTr", gr12, "Energy (GeV) (MC Tau Jet)",(TH1F*)  nRecoJetenergyTauJet->Clone(), c16, text_bothCuts); 

  TH1F* nTausTaggedvsMatchingConeSize = (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tagged_vs_MatchingConeSize");
  TH1F* nTausTotvsMatchingConeSize =    (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tot_vs_MatchingConeSize");
  TH1F* nTausTaggedvsPtLeadingTrack =   (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tagged_vs_PtLeadingTrack");
  TH1F* nTausTotvsPtLeadingTrack=       (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tot_vs_PtLeadingTrack");
  TH1F* nTausTaggedvsConeIsolation=     (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tagged_vs_coneIsolation");
  TH1F* nTausTotvsConeIsolation=        (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tot_vs_coneIsolation");
  TH1F* nTausTaggedvsConeSignal=        (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tagged_vs_coneSignal");
  TH1F* nTausTotvsConeSignal=           (TH1F *)f.Get("DQMData/TaggingStudies_ConeIsolationForValidation/nTaus_Tot_vs_coneSignal");

  TGraphAsymmErrors* gr13 =  new TGraphAsymmErrors(nTausTaggedvsMatchingConeSize,nTausTotvsMatchingConeSize );
  c17 = new TCanvas("c17","EfficiencyKeepingEverythingEqualMatchingCone",35,35,525,525);
  drawEfficiency("N_Isolated/N_CaloJets(Matched)", gr13, "Matching Cone Size",(TH1F*)  nTausTotvsMatchingConeSize->Clone(), c17, text_bothCuts); 

  TGraphAsymmErrors* gr14 =  new TGraphAsymmErrors(nTausTaggedvsPtLeadingTrack, nTausTotvsPtLeadingTrack);
  c18 = new TCanvas("c18","EfficiencyKeepingEverythingEqualPtLeadTr",35,35,525,525);
  drawEfficiency("N_Isolated/CaloJets(Matched)", gr14, "Pt Leading Track",(TH1F*)  nTausTotvsPtLeadingTrack->Clone(), c18, text_bothCuts); 

  TGraphAsymmErrors* gr15 =  new TGraphAsymmErrors(nTausTaggedvsConeIsolation,nTausTotvsConeIsolation );
  c19 = new TCanvas("c19","EfficiencyKeepingEverythingEqualIsolationCone",35,35,525,525);
  drawEfficiency("N_Isolated/CaloJets(Matched)", gr15, "Cone Isolation Size",(TH1F*)  nTausTotvsConeIsolation->Clone(), c19, text_bothCuts);

  TGraphAsymmErrors* gr16 =  new TGraphAsymmErrors(nTausTaggedvsConeSignal, nTausTotvsConeSignal );
  c20 = new TCanvas("c20","EfficiencyKeepingEverythingEqualSignalCone",35,35,525,525);
  drawEfficiency("N_Isolated/CaloJets(Matched)", gr16, "Cone Signal Size",(TH1F*) nTausTotvsConeSignal->Clone(), c20, text_bothCuts);
  
}


