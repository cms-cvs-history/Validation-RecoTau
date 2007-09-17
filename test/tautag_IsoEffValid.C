 
{               
  gSystem->Load("drawEfficiency_C.so");
  gSystem->Load("drawEfficiencies_C.so");

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

  TH1F* LeadingTrackPt_TaggedTau =   (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/LeadingTrackPt_After_Isolation");
  TH1F* DeltaR_LTandJet_TaggedTau =  (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/DeltaR_LT_and_Jet_After_Isolation");
  TH1F* SignalTracks_TaggedTau =     (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/Signal_Tks_After_Isolation");
  TH1F* SelectedTracks_TaggedTau =   (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/Selected_Tks_After_Isolation");
  TH1F* AssociatedTracks_TaggedTau = (TH1F*)f.Get("DQMData/TauTaggedJets_ConeIsolationForValidation/Associated_Tks_After_Isolation");

  gStyle->SetOptStat("ie");

  cout << endl<< " entries "<< nMCetaTauJet->Integral()<<endl;

  c21 = new TCanvas("c21","", 10, 10, 500, 410);
  nMCetaTauJet->SetTitle("# MC Taus (Visible Energy)");
  nMCetaTauJet->GetXaxis()->SetTitle("eta");
  nMCetaTauJet->DrawNormalized();
  c21->Print(TString("MCetaTauJets.gif"),"gif");


  c22 = new TCanvas("c22","", 10,10,500,410);
  nMCptTauJet->SetTitle("# MC Taus (Visible Energy)");
  nMCptTauJet->GetXaxis()->SetTitle("Pt (GeV)");
  nMCptTauJet->DrawNormalized();
  c22->Print(TString("MCPtTauJets.gif"),"gif");	    
  
  c23 = new TCanvas("c23","", 10,10,500,410);
  nMCenergyTauJet->SetTitle("# MC Taus (Visible Energy)");
  nMCenergyTauJet->GetXaxis()->SetTitle("Energy (GeV)");
  nMCenergyTauJet->DrawNormalized();
  c23->Print(TString("MCEnergyTauJets.gif"),"gif");

  c24 = new TCanvas("c24","", 10,10,500,410);
  nMCetaTau->SetTitle("# MC Taus");
  nMCetaTau->GetXaxis()->SetTitle("eta");
  nMCetaTau->DrawNormalized(); 
  c24->Print(TString("MCetaTau.gif"),"gif");

  c25 = new TCanvas("c25","", 10,10,500,410);
  nMCptTau->SetTitle("# MC Taus");
  nMCptTau->GetXaxis()->SetTitle("Pt (GeV)");
  nMCptTau->DrawNormalized();
  c25->Print(TString("MCPtTau.gif"),"gif");	 

  c26 = new TCanvas("c26","", 10,10,500,410);
  nAssociatedTracks->SetTitle("Associated Tracks Matched Reconstructed Jet ");
  nAssociatedTracks->GetXaxis()->SetTitle("# Associated Tracks");
  nAssociatedTracks->Draw();
  c26->Print(TString("AssociatedTracks.gif"),"gif");	 
  
  c27 = new TCanvas("c27","", 10,10,500,410);
  nSelectedTracks->SetTitle("Selected Tracks Matched Reconstructed Jet ");
  nSelectedTracks->GetXaxis()->SetTitle("# Selected Tracks");
  nSelectedTracks->Draw();
  c27->Print(TString("SelectedTracks.gif"),"gif");	 
  

  //Tau Tagged Jets Characteristics
  
  c28 = new TCanvas("c28","", 110, 110, 600, 510);
  LeadingTrackPt_TaggedTau->SetTitle("Leading Track Pt Tagged Taus");
  LeadingTrackPt_TaggedTau->GetXaxis()->SetTitle("Leading Track Pt (GeV)");
  LeadingTrackPt_TaggedTau->Draw();
  c28->Print(TString("LeadingTrackPt_TaggedTaus.gif"),"gif");
  
  c29 = new TCanvas("c29","", 110, 110, 600, 510);
  DeltaR_LTandJet_TaggedTau->SetTitle("DeltaR(LeadingTrack, JetMomentum) Tagged Taus");
  DeltaR_LTandJet_TaggedTau->GetXaxis()->SetTitle("DeltaR(LeadingTrack, JetMomentum)");
  DeltaR_LTandJet_TaggedTau->Draw();
  c29->Print(TString("DeltaR_LT_Jet_TaggedTaus.gif"),"gif");

  c30 = new TCanvas("c30","",110,110,600,510);
  SignalTracks_TaggedTau->SetTitle("# Tracks inside Signal cone Tagged Taus > 1.0 GeV");
  SignalTracks_TaggedTau->GetXaxis()->SetTitle("# Signal Tracks");
  SignalTracks_TaggedTau->Draw();
  c30->Print(TString("SignalTracks_TaggedTaus.gif"),"gif");

  c31 = new TCanvas("c31","",110,110,600,510);
  SelectedTracks_TaggedTau->SetTitle("# Selected Tracks Tagged Taus");
  SelectedTracks_TaggedTau->GetXaxis()->SetTitle("# Selected Tracks");
  SelectedTracks_TaggedTau->Draw();
  c31->Print(TString("SelectedTracks_TaggedTaus.gif"),"gif");

  c32 = new TCanvas("c32","",110,110,600,510);
  AssociatedTracks_TaggedTau->SetTitle("# Associated Tracks Tagged Taus");
  AssociatedTracks_TaggedTau->GetXaxis()->SetTitle("# Associated Tracks");
  AssociatedTracks_TaggedTau->Draw();
  c32->Print(TString("AssociatedTracks_TaggedTaus.gif"),"gif");


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
  
  //====================================================ETA================================================================= 
  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddText(Form(" %.1f  < P_{T} < %.1f GeV", 10.0, 100.0));

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nTaggedJetsetaTauJet, nMCetaTauJet);
  c5 = new TCanvas("c5","TotalEfficiencyEta",30,30,520,520);
  drawEfficiency("N_Isolated/N_Total Generated", gr1, "MC Vis. Tau #eta", (TH1F*) nMCetaTauJet->Clone(), c5, text_ptCut);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nRecoJetetaTauJet,  nMCetaTauJet);
  c6 = new TCanvas("c6","CaloJetTotalEfficiencyEta",35,35,525,525);
  drawEfficiency("N_CaloJets(Matched)/N_Total MC Generated", gr2, "MC Vis. Tau #eta",(TH1F*)  nMCetaTauJet->Clone(), c6, text_ptCut);

  TGraphAsymmErrors* gr100 = new TGraphAsymmErrors(nRecoJetLTetaTauJet, nMCetaTauJet);
  c100 = new TCanvas("c100", "EfficienciesStepByStepEta", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/N_Total MC Generated", gr1, gr2, gr100,  "MC Vis. Tau #eta",(TH1F*)  nMCetaTauJet->Clone(), c100, text_ptCut);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nRecoJetLTetaTauJet,  nRecoJetetaTauJet);
  c7 = new TCanvas("c7","FindingLeadTrackPartialEfficiencyEta",35,35,525,525);
  drawEfficiency("N_CaloJets+LeadTr/N_CaloJets(Matched)", gr3, "MC Vis. Tau #eta",(TH1F*)  nRecoJetetaTauJet->Clone(), c7, text_ptCut);  
  		 
  TGraphAsymmErrors* gr4 =  new TGraphAsymmErrors(nTaggedJetsetaTauJet,  nRecoJetLTetaTauJet);
  c8 = new TCanvas("c8","IsolationPartialEfficencyEta",35,35,525,525);
  drawEfficiency("N_Isolated/N_CaloJets+LeadTr", gr4, "MC Vis. Tau #eta",(TH1F*)  nRecoJetetaTauJet->Clone(), c8, text_ptCut); 

  //===========================================================Pt=============================================================
  TPaveText* text_etaCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_etaCut->SetBorderSize(0);
  text_etaCut->SetFillColor(0);
  text_etaCut->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nTaggedJetsptTauJet, nMCptTauJet);
  c9 = new TCanvas("c5","TotalEfficiencyPt",30,30,520,520);
  drawEfficiency("N_Isolated/N_Total Generated", gr5, "MC Vis. Tau P_{T} (GeV)", (TH1F*) nMCptTauJet->Clone(), c9, text_etaCut);
  
  TGraphAsymmErrors* gr6 =  new TGraphAsymmErrors(nRecoJetptTauJet,  nMCptTauJet);
  c10 = new TCanvas("c10","CaloJetTotalEfficiencyPt",35,35,525,525);
  drawEfficiency("N_CaloJets(Matched)/N_Total MC Generated", gr6, "MC Vis. Tau P_{T} (GeV)",(TH1F*)  nMCptTauJet->Clone(), c10, text_etaCut);
  
  TGraphAsymmErrors* gr101 = new TGraphAsymmErrors(nRecoJetLTptTauJet, nMCptTauJet);
  c101 = new TCanvas("c101", "EfficienciesStepByStepPt", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/N_Total MC Generated", gr5, gr6, gr101,  "MC Vis. Tau P_{T} (GeV)",(TH1F*)  nMCptTauJet->Clone(), c101, text_etaCut);  

  TGraphAsymmErrors* gr7 =  new TGraphAsymmErrors(nRecoJetLTptTauJet,  nRecoJetptTauJet);
  c11 = new TCanvas("c11","FindingLeadTrackPartialEfficiencyPt",35,35,525,525);
  drawEfficiency("N_CaloJets+LeadTr/N_CaloJets(Matched)", gr7, "MC Vis. Tau P_{T} (GeV)",(TH1F*)  nRecoJetptTauJet->Clone(), c11, text_etaCut);  
  		 
  TGraphAsymmErrors* gr8 =  new TGraphAsymmErrors(nTaggedJetsptTauJet,  nRecoJetLTptTauJet);
  c12 = new TCanvas("c12","IsolationPartialEfficencyPt",35,35,525,525);
  drawEfficiency("N_Isolated/N_CaloJets+LeadTr", gr8, "MC Vis. Tau P_{T} (GeV)",(TH1F*)  nRecoJetptTauJet->Clone(), c12, text_etaCut); 

  //===============================================================Energy========================================================

  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" %.1f  < P_{T} < %.1f GeV", 10.0, 100.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr9 =  new TGraphAsymmErrors(nTaggedJetsenergyTauJet, nMCenergyTauJet);
  c13 = new TCanvas("c13","TotalEfficiencyEnergy",30,30,520,520);
  drawEfficiency("N_Isolated/N_Total Generated", gr9, "MC Vis. Tau Energy (GeV)", (TH1F*) nMCenergyTauJet->Clone(), c13, text_bothCuts);
  
  TGraphAsymmErrors* gr10 =  new TGraphAsymmErrors(nRecoJetenergyTauJet,  nMCenergyTauJet);
  c14 = new TCanvas("c14","CaloJetTotalEfficiencyEnergy",35,35,525,525);
  drawEfficiency("N_CaloJets(Matched)/N_Total MC Generated", gr10, "MC Vis. Tau Energy (GeV)",(TH1F*)  nMCenergyTauJet->Clone(), c14, text_bothCuts);

  TGraphAsymmErrors* gr102 = new TGraphAsymmErrors(nRecoJetLTenergyTauJet, nMCenergyTauJet);
  c102 = new TCanvas("c102", "EfficienciesStepByStepEnergy", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/N_Total MC Generated", gr9, gr10, gr102,  "MC Vis. Tau Energy (GeV)",(TH1F*)  nMCenergyTauJet->Clone(), c102, text_bothCuts);

  TGraphAsymmErrors* gr11 =  new TGraphAsymmErrors(nRecoJetLTenergyTauJet,  nRecoJetenergyTauJet);
  c15 = new TCanvas("c15","FindingLeadTrackPartialEfficiencyEnergy",35,35,525,525);
  drawEfficiency("N_CaloJets+LeadTr/N_CaloJets(Matched)", gr11, "MC Vis. Tau Energy (GeV)",(TH1F*)  nRecoJetenergyTauJet->Clone(), c15, text_bothCuts);  
  		 
  TGraphAsymmErrors* gr12 =  new TGraphAsymmErrors(nTaggedJetsenergyTauJet,  nRecoJetLTenergyTauJet);
  c16 = new TCanvas("c16","IsolationPartialEfficencyEnergy",35,35,525,525);
  drawEfficiency("N_Isolated/N_CaloJets+LeadTr", gr12, "MC Vis. Tau Energy (GeV)",(TH1F*)  nRecoJetenergyTauJet->Clone(), c16, text_bothCuts); 

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


