 
{               
  gSystem->Load("drawEfficiency_C.so");
  gSystem->Load("drawEfficiencies_C.so");

  TFile f("test.root");

  TString ReleaseVersion("CMSSW210pre2");
  TString Scale("LinearScale");

  TH1F* nMCetaTau=  (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/eta_Tau_GenLevel");
  TH1F* nMCptTau=   (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/pt_Tau_GenLevel");

  TH1F* nMCetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_etaTauJet");
  TH1F* nMCptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_energyTauJet");
  TH1F* nMCphiTauJet = (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_phiTauJet");

  TH1F* nPFTauCandetaTauJet =    (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_etaTauJet");
  TH1F* nPFTauCandptTauJet =     (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_ptTauJet");
  TH1F* nPFTauCandenergyTauJet = (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_energyTauJet");
  TH1F* nPFTauCandphiTauJet=     (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_phiTauJet");

  TH1F* nPFTauCandChargedHadronsSignal =      (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/nPFTauCand_ChargedHadronsSignal");
  TH1F* nPFTauCandChargedHadronsIsolAnnulus = (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/nPFTauCand_ChargedHadronsIsolAnnulus");
  TH1F* nPFTauCandGammasSignal =              (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/nPFTauCand_GammasSignal");
  TH1F* nPFTauCandGammasIsolAnnulus =         (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/nPFTauCand_GammasIsolAnnulus");
  TH1F* nPFTauCandNeutralHadronsSignal =      (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/nPFTauCand_NeutralHadronsSignal");
  TH1F* nPFTauCandNeutralHadronsIsolAnnulus=  (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/nPFTauCand_NeutralHadronsIsolAnnulus");

  TH1F* nPFTauCandLCHetaTauJet =    (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_etaTauJet");
  TH1F* nPFTauCandLCHptTauJet =     (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_ptTauJet");
  TH1F* nPFTauCandLCHenergyTauJet = (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_energyTauJet");
  TH1F* nPFTauCandLCHphiTauJet =    (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_phiTauJet");

  TH1F* nPFTauCandLCHChargedHadronsSignal =      (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/nPFTau_LeadingChargedHadron_ChargedHadronsSignal");
  TH1F* nPFTauCandLCHChargedHadronsIsolAnnulus = (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/nPFTau_LeadingChargedHadron_ChargedHadronsIsolAnnulus");
  TH1F* nPFTauCandLCHGammasSignal =              (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/nPFTau_LeadingChargedHadron_GammasSignal");
  TH1F* nPFTauCandLCHGammasIsolAnnulus =         (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/nPFTau_LeadingChargedHadron_GammasIsolAnnulus");
  TH1F* nPFTauCandLCHNeutralHadronsSignal =      (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/nPFTau_LeadingChargedHadron_NeutralHadronsSignal");
  TH1F* nPFTauCandLCHNeutralHadronsIsolAnnulus=  (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/nPFTau_LeadingChargedHadron_NeutralHadronsIsolAnnulus");

  TH1F* nIsolNoChargedHadronsetaTauJet =    (TH1F*)f.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_etaTauJet");
  TH1F* nIsolNoChargedHadronsptTauJet =     (TH1F*)f.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_ptTauJet");
  TH1F* nIsolNoChargedHadronsenergyTauJet = (TH1F*)f.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_energyTauJet");
  TH1F* nIsolNoChargedHadronsphiTauJet =    (TH1F*)f.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_phiTauJet");

  TH1F* nIsolNoChargedNoGammasetaTauJet =    (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_etaTauJet");
  TH1F* nIsolNoChargedNoGammasptTauJet =     (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_ptTauJet");
  TH1F* nIsolNoChargedNoGammasenergyTauJet = (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_energyTauJet");
  TH1F* nIsolNoChargedNoGammasphiTauJet =    (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_phiTauJet");  

  TH1F* nIsolNoChargedNoGammasNeutralHadronsSignal=     (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/nIsolated_NoChargedNoGammas_NeutralHadronsSignal");
  TH1F* nIsolNoChargedNoGammasNeutralHadronsIsolAnnulus=     (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/nIsolated_NoChargedNoGammas_NeutralHadronsIsolAnnulus");


  // PF Candidates in signal cone after all isolation is applied plus the N-1 plots in signal cone +isolation annulus

  TH1F* n_1_ChargedHadronsSignalCone_isolated = (TH1F*)f.Get("DQMData/PFCandidates_in_SignalOrIsolationAnnulus_PFTauIsolationValidation/nChargedHadronsSignalCone_isolated");
  TH1F* n_1_GammasSignalCone_isolated =         (TH1F*)f.Get("DQMData/PFCandidates_in_SignalOrIsolationAnnulus_PFTauIsolationValidation/nGammasSignalCone_isolated");
  TH1F* n_1_NeutralHadronsSignalCone_isolated = (TH1F*)f.Get("DQMData/PFCandidates_in_SignalOrIsolationAnnulus_PFTauIsolationValidation/nNeutralHadronsSignalCone_isolated");

  gStyle->SetOptStat("ie");

  cout << endl<< " entries "<< nMCetaTauJet->Integral()<<endl;
  
  c21 = new TCanvas("c21","", 10, 10, 500, 410);
  nMCetaTauJet->SetTitle("# MC Visible Taus (Visible Energy) "+ReleaseVersion);
  nMCetaTauJet->GetXaxis()->SetTitle("eta");
  nMCetaTauJet->DrawNormalized();
  c21->Print(TString("MCetaTauJets.gif"),"gif");

  c22 = new TCanvas("c22","", 10,10,500,410);
  nMCptTauJet->SetTitle("# MC Visible Taus (Visible Eneryg) "+ReleaseVersion);
  nMCptTauJet->GetXaxis()->SetTitle("Pt (GeV)");
  nMCptTauJet->DrawNormalized();
  c22->Print(TString("MCPtTauJets.gif"),"gif");	    
  
  c23 = new TCanvas("c23","", 10,10,500,410);
  nMCenergyTauJet->SetTitle("# MC Visible Taus (Visible Energy) "+ReleaseVersion);
  nMCenergyTauJet->GetXaxis()->SetTitle("Energy (GeV)");
  nMCenergyTauJet->DrawNormalized();
  c23->Print(TString("MCEnergyTauJets.gif"),"gif");
  
  c24 = new TCanvas("c24","", 10,10,500,410);
  nMCetaTau->SetTitle("# MC Taus "+ReleaseVersion);
  nMCetaTau->GetXaxis()->SetTitle("#eta");
  nMCetaTau->DrawNormalized(); 
  c24->Print(TString("MCetaTau.gif"),"gif");

  c25 = new TCanvas("c25","", 10,10,500,410);
  nMCptTau->SetTitle("# MC Taus "+ReleaseVersion);
  nMCptTau->GetXaxis()->SetTitle("Pt (GeV)");
  nMCptTau->DrawNormalized();
  c25->Print(TString("MCPtTau.gif"),"gif");	 
 
// Number of PF Candidates in signal cone and isolation annulus after PFTau matching

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandChargedHadronsSignal->SetTitle("PFCharged Hadrons in Signal Cone after PFTau matching "+ReleaseVersion);
  nPFTauCandChargedHadronsSignal->GetXaxis()->SetTitle("# Charged Hadrons in Signal Cone");
  nPFTauCandChargedHadronsSignal->Draw();
  c23->Print(TString("PFTauMatching_ChargedHadronsSignal.gif"),"gif");
  
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandChargedHadronsIsolAnnulus->SetTitle("PFCharged Hadrons in Isolation Annulus after PFTau matching "+ReleaseVersion);
  nPFTauCandChargedHadronsIsolAnnulus->GetXaxis()->SetTitle("# Charged Hadrons in Isolation Annulus");
  nPFTauCandChargedHadronsIsolAnnulus->Draw();
  c23->Print(TString("PFTauMatching_ChargedHadronsIsolAnnulus.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandGammasSignal->SetTitle("PFGammas in Signal Cone after PFTau matching "+ReleaseVersion);
  nPFTauCandGammasSignal->GetXaxis()->SetTitle("# Gammas in Signal Cone");
  nPFTauCandGammasSignal->Draw();
  c23->Print(TString("PFTauMatching_GammasSignal.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandGammasIsolAnnulus->SetTitle("PFGammas in Isolation Annulus after PFTau matching "+ReleaseVersion);
  nPFTauCandGammasIsolAnnulus->GetXaxis()->SetTitle("# Gammas in Isolation Annulus");
  nPFTauCandGammasIsolAnnulus->Draw();
  c23->Print(TString("PFTauMatching_GammasIsolAnnulus.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandNeutralHadronsSignal->SetTitle("PFNeutral Hadrons in Signal Cone after PFTau matching "+ReleaseVersion);
  nPFTauCandNeutralHadronsSignal->GetXaxis()->SetTitle("# Neutral Hadrons in Signal Cone");
  nPFTauCandNeutralHadronsSignal->Draw();
  c23->Print(TString("PFTauMatching_NeutralHadronsSignal.gif"),"gif");

  
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandNeutralHadronsIsolAnnulus->SetTitle("PFNeutral Hadrons in Isolation Annulus after PFTau matching "+ReleaseVersion);
  nPFTauCandNeutralHadronsIsolAnnulus->GetXaxis()->SetTitle("# Neutral Hadrons in Isolation Annulus");
  nPFTauCandNeutralHadronsIsolAnnulus->Draw();
  c23->Print(TString("PFTauMatching_NeutralHadronsIsolAnnulus.gif"),"gif");


  // Number of PF Candidates in signal cone and isolation annulus after PFTau matching plus Leading Charged Hadron
 
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandLCHChargedHadronsSignal->SetTitle("PFCharged Hadrons in Signal Cone after finding Leading Hadron "+ReleaseVersion);
  nPFTauCandLCHChargedHadronsSignal->GetXaxis()->SetTitle("# Charged Hadrons in Signal Cone");
  nPFTauCandLCHChargedHadronsSignal->Draw();
  c23->Print(TString("PFTauMatchingLCH_ChargedHadronsSignal.gif"),"gif");
 
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandLCHChargedHadronsIsolAnnulus->SetTitle("PFCharged Hadrons in Isolation Annulus after finding Leading Hadron "+ReleaseVersion);
  nPFTauCandLCHChargedHadronsIsolAnnulus->GetXaxis()->SetTitle("# Charged Hadrons in Isolation Annulus");
  nPFTauCandLCHChargedHadronsIsolAnnulus->Draw();
  c23->Print(TString("PFTauMatchingLCH_ChargedHadronsIsolAnnulus.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandLCHGammasSignal->SetTitle("PFGammas in Signal Cone after finding Leading Hadron "+ReleaseVersion);
  nPFTauCandLCHGammasSignal->GetXaxis()->SetTitle("# Gammas in Signal Cone");
  nPFTauCandLCHGammasSignal->Draw();
  c23->Print(TString("PFTauMatchingLCH_GammasSignal.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandLCHGammasIsolAnnulus->SetTitle("PFGammas in Isolation Annulus after finding Leading Hadron "+ReleaseVersion);
  nPFTauCandLCHGammasIsolAnnulus->GetXaxis()->SetTitle("# Gammas in Isolation Annulus");
  nPFTauCandLCHGammasIsolAnnulus->Draw();
  c23->Print(TString("PFTauMatchingLCH_GammasIsolAnnulus.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandLCHNeutralHadronsSignal->SetTitle("PFNeutral Hadrons in Signal Cone after finding Leading Hadron "+ReleaseVersion);
  nPFTauCandLCHNeutralHadronsSignal->GetXaxis()->SetTitle("# Neutral Hadrons in Signal Cone");
  nPFTauCandLCHNeutralHadronsSignal->Draw();
  c23->Print(TString("PFTauMatchingLCH_NeutralHadronsSignal.gif"),"gif");

  
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nPFTauCandNeutralHadronsIsolAnnulus->SetTitle("PFNeutral Hadrons in Isolation Annulus after finding Leading Hadron "+ReleaseVersion);
  nPFTauCandNeutralHadronsIsolAnnulus->GetXaxis()->SetTitle("# Neutral Hadrons in Isolation Annulus");
  nPFTauCandNeutralHadronsIsolAnnulus->Draw();
  c23->Print(TString("PFTauMatchingLCH_NeutralHadronsIsolAnnulus.gif"),"gif");

  // PFNeutral Hadrons 
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nIsolNoChargedNoGammasNeutralHadronsIsolAnnulus->SetTitle("PFNeutral Hadrons in Isolation Annulus after Isolation"+ ReleaseVersion);
  nIsolNoChargedNoGammasNeutralHadronsIsolAnnulus->GetXaxis()->SetTitle("# Neutral Hadrons in Isolation Annulus");
  nIsolNoChargedNoGammasNeutralHadronsIsolAnnulus->Draw();
  c23->Print(TString("PFTauSemiIsolated_NeutralHadronsIsolAnnulus.gif"),"gif");
  
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  nIsolNoChargedNoGammasNeutralHadronsSignal->SetTitle("PFNeutral Hadrons in Signal Cone"+ReleaseVersion);
  nIsolNoChargedNoGammasNeutralHadronsSignal->GetXaxis()->SetTitle("# Neutral Hadrons in Signal Cone");
  nIsolNoChargedNoGammasNeutralHadronsSignal->Draw();
  c23->Print(TString("PFTauSemiIsolated_NeutralHadronsSignal.gif"),"gif");

  // PF Candidates in signal cone after all isolation is applied plus the N-1 plots in signal cone +isolation annulus
  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  n_1_ChargedHadronsSignalCone_isolated->SetTitle("PFCharged Hadrons in Signal Cone after total isolation "+ReleaseVersion);
  n_1_ChargedHadronsSignalCone_isolated->GetXaxis()->SetTitle("# Charged Hadrons in Signal Cone");
  n_1_ChargedHadronsSignalCone_isolated->Draw();
  c23->Print(TString("PFTauIsolated_ChargedHadronsSignalCone.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  n_1_GammasSignalCone_isolated->SetTitle("PFGammas in Signal Cone after total isolation "+ReleaseVersion); 
  n_1_GammasSignalCone_isolated->GetXaxis()->SetTitle("# Gammas in Signal Cone");
  n_1_GammasSignalCone_isolated ->Draw();
  c23->Print(TString("PFTauIsolated_GammasSignalCone.gif"),"gif");

  delete c23;
  c23 = new TCanvas("c23","", 10,10,500,410);
  n_1_NeutralHadronsSignalCone_isolated->SetTitle("PFNeutral Hadrons in Signal Cone after total isolation"+ReleaseVersion);
  n_1_NeutralHadronsSignalCone_isolated->GetXaxis()->SetTitle("# Neutral Hadrons in Signal Cone");
  n_1_NeutralHadronsSignalCone_isolated->Draw();
  c23->Print(TString("PFTauIsolated_NeutralHadronsSignalCone.gif"),"gif");

    

  //====================================================ETA================================================================= 
  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddTex t(Form(" P_{T} > %.1f GeV", 5.0));

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nIsolNoChargedHadronsetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","IsolationNoChargedHadronsEta",30,30,520,520);
  drawEfficiency("Isolated_NoChargedHadrons/MC Visible Tau "+ReleaseVersion, gr0, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,Scale );

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasetaTauJet, nMCetaTauJet);
  c5 = new TCanvas("c5","TotalEfficiencyEta",30,30,520,520);
  drawEfficiency("Isolated_NoChargedNoGammas/MC Visible Tau "+ReleaseVersion, gr1, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c5, text_ptCut, Scale);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nPFTauCandetaTauJet, nMCetaTauJet);
  c6 = new TCanvas("c6","PFTauCandTotalEfficiencyEta",35,35,525,525);
  drawEfficiency("PFTauCand(Matched)/MC Visible Taus "+ReleaseVersion, gr2, "#eta (MC Vis. Tau)",(TH1F*)  nMCetaTauJet->Clone(), c6, text_ptCut, Scale);

  TGraphAsymmErrors* gr100 = new TGraphAsymmErrors(nPFTauCandLCHetaTauJet, nMCetaTauJet);
  c100 = new TCanvas("c100", "EfficienciesStepByStepEta", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ReleaseVersion, gr2, gr100, gr0,gr1,  "#eta (MC Vis. Tau)",(TH1F*)  nMCetaTauJet->Clone(), c100, text_ptCut,"PFTaus", Scale);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nPFTauCandLCHetaTauJet,  nPFTauCandetaTauJet);
  c7 = new TCanvas("c7","FindingLeadingChargeHadronPartialEfficiencyEta",35,35,525,525);
  drawEfficiency("PFTau+LeadChargeHadron/PFTau(Matched) "+ReleaseVersion, gr3, "#eta (MC Vis. Tau)",(TH1F*)  nPFTauCandetaTauJet->Clone(), c7, text_ptCut, Scale);  
  		 
  TGraphAsymmErrors* gr4 =  new TGraphAsymmErrors(nIsolNoChargedHadronsetaTauJet,  nPFTauCandLCHetaTauJet);
  c8 = new TCanvas("c8","IsolationNoChargedHadronsPartialEfficencyEta",35,35,525,525);
  drawEfficiency("IsolatedNoChargeHadrons/PFTau+LCH "+ReleaseVersion, gr4, "#eta (MC Vis. Tau)",(TH1F*)  nPFTauCandLCHetaTauJet->Clone(), c8, text_ptCut, Scale); 

  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasetaTauJet,  nIsolNoChargedHadronsetaTauJet);
  c9 = new TCanvas("c9","IsolationNoChargedNoGammasPartialEfficencyEta",35,35,525,525);
  drawEfficiency("NoChargedNoGammas/NoCharged "+ReleaseVersion, gr5, "#eta (MC Vis. Tau)",(TH1F*)  nIsolNoChargedHadronsetaTauJet->Clone(), c9, text_ptCut, Scale); 

  
  //===========================================================Pt=============================================================
  TPaveText* text_etaCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_etaCut->SetBorderSize(0);
  text_etaCut->SetFillColor(0);
  text_etaCut->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr50 =  new TGraphAsymmErrors(nIsolNoChargedHadronsptTauJet, nMCptTauJet);
  c40 = new TCanvas("c40","IsolationNoChargedHadronsEfficiencyPt",30,30,520,520);
  drawEfficiency("Isolated_NoChargedHadrons/MC Visible Tau"+ReleaseVersion, gr50, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c40, text_etaCut, Scale);
  
  TGraphAsymmErrors* gr5 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasptTauJet, nMCptTauJet);
  c9 = new TCanvas("c5","TotalEfficiencyPt",30,30,520,520);
  drawEfficiency("Isolated_NoChargedNoGammas/MC Visible Taus "+ ReleaseVersion, gr5, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c9, text_etaCut, Scale);

  TGraphAsymmErrors* gr6 =  new TGraphAsymmErrors(nPFTauCandptTauJet,  nMCptTauJet);
  c10 = new TCanvas("c10","PFTauCandTotalEfficiencyPt",35,35,525,525);
  drawEfficiency("PFTauCand(Matched)/MC Visible Taus "+ ReleaseVersion,gr6, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nMCptTauJet->Clone(), c10, text_etaCut, Scale);
  
  TGraphAsymmErrors* gr101 = new TGraphAsymmErrors(nPFTauCandLCHptTauJet, nMCptTauJet);
  c101 = new TCanvas("c101", "EfficienciesStepByStepPt", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ ReleaseVersion,gr6, gr101, gr50,gr5,"P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*) nMCptTauJet->Clone(),c101,text_etaCut,"PFTaus", Scale);  
  TGraphAsymmErrors* gr7 =  new TGraphAsymmErrors(nPFTauCandLCHptTauJet,  nPFTauCandptTauJet);
  c11 = new TCanvas("c11","FindingLeadingChargeHadronPartialEfficiencyPt",35,35,525,525);
  drawEfficiency(" PFTau+LeadChargeHadron/PFTau(Matched)"+ ReleaseVersion, gr7, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nPFTauCandptTauJet->Clone(), c11, text_etaCut, Scale);  
  		 
  TGraphAsymmErrors* gr8 =  new TGraphAsymmErrors(nIsolNoChargedHadronsptTauJet,  nPFTauCandLCHptTauJet);
  c12 = new TCanvas("c12","IsolationNoChargedHadronsPartialEfficencyPt",35,35,525,525);
  drawEfficiency("IsolatedNoChargeHadrons/PFTau+LCH "+ ReleaseVersion, gr8, "P_{T} (GeV/c) (MC Vis. Tau)",(TH1F*)  nPFTauCandLCHptTauJet->Clone(), c12, text_etaCut, Scale); 

 TGraphAsymmErrors* gr9 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasptTauJet,  nIsolNoChargedHadronsptTauJet);
  c13 = new TCanvas("c13","IsolationNoChargedNoGammasPartialEfficencyPt",35,35,525,525);
  drawEfficiency("NoChargedNoGammas/NoCharged"+ReleaseVersion, gr9, "P_{T} (Gev/c) (MC Vis. Tau)",(TH1F*)  nIsolNoChargedHadronsptTauJet->Clone(), c13, text_etaCut, Scale); 

  //===============================================================Energy========================================================
  
  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr90 =  new TGraphAsymmErrors(nIsolNoChargedHadronsphiTauJet, nMCphiTauJet);
  c90 = new TCanvas("c90","IsolationNoChargedHadronsEfficiencyPhi",30,30,520,520);
  drawEfficiency("Isolated_NoChargedHadrons/MC Visible Tau "+ReleaseVersion, gr90, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c90, text_bothCuts, Scale);

  TGraphAsymmErrors* gr9 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasphiTauJet, nMCphiTauJet);
  c13 = new TCanvas("c13","TotalEfficiencyPhi",30,30,520,520);
  drawEfficiency("Isolated_NoChargedNoGammas/MC Visible Taus "+ ReleaseVersion, gr9, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c13, text_bothCuts, Scale);
  
  TGraphAsymmErrors* gr10 =  new TGraphAsymmErrors(nPFTauCandphiTauJet,  nMCphiTauJet);
  c14 = new TCanvas("c14","PFTauCandTotalEfficiencyPhi",35,35,525,525);
  drawEfficiency("PFTauCand(Matched)/MC Visible Taus "+ ReleaseVersion, gr10, "#phi (MC Vis. Tau)",(TH1F*)  nMCphiTauJet->Clone(), c14, text_bothCuts, Scale);

  TGraphAsymmErrors* gr102 = new TGraphAsymmErrors(nPFTauCandLCHphiTauJet, nMCphiTauJet);
  c102 = new TCanvas("c102", "EfficienciesStepByStepPhi", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ ReleaseVersion, gr10, gr102, gr90, gr9,  "#phi (MC Vis. Tau)",(TH1F*)  nMCphiTauJet->Clone(), c102, text_bothCuts, "PFTaus", Scale);

  TGraphAsymmErrors* gr11 =  new TGraphAsymmErrors(nPFTauCandLCHphiTauJet,  nPFTauCandphiTauJet);
  c15 = new TCanvas("c15","FindingLeadingChargeHadronPartialEfficiencyPhi",35,35,525,525);
  drawEfficiency(" PFTau+LeadChargeHadron/PFTau(Matched) "+ReleaseVersion, gr11, "#phi (MC Vis. Tau)",(TH1F*)  nPFTauCandphiTauJet->Clone(), c15, text_bothCuts, Scale);  
  		 
  TGraphAsymmErrors* gr12 =  new TGraphAsymmErrors(nIsolNoChargedHadronsphiTauJet,  nPFTauCandLCHphiTauJet);
  c16 = new TCanvas("c16","IsolationNoChargedHadronsPartialEfficencyPhi",35,35,525,525);
  drawEfficiency(" IsolatedNoChargeHadrons/PFTau+LCH" +ReleaseVersion, gr12, "#phi (MC Vis. Tau)",(TH1F*)  nPFTauCandLCHphiTauJet->Clone(), c16, text_bothCuts, Scale); 

  TGraphAsymmErrors* gr13 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasphiTauJet, nIsolNoChargedHadronsphiTauJet);
  c170 = new TCanvas("c170","IsolationNoChargedNoGammasPartialEfficencyPhi",35,35,525,525);
  drawEfficiency("NoChargedNoGammas/NoCharged " +ReleaseVersion, gr13, "#phi (MC Vis. Tau)",(TH1F*)  nIsolNoChargedHadronsphiTauJet->Clone(), c170, text_bothCuts, Scale);

  //=============================================================== Phi ========================================================
  
  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  TGraphAsymmErrors* gr90 =  new TGraphAsymmErrors(nIsolNoChargedHadronsenergyTauJet, nMCenergyTauJet);
  c90 = new TCanvas("c90","IsolationNoChargedHadronsEfficiencyEnergy",30,30,520,520);
  drawEfficiency("Isolated_NoChargedHadrons/MC Visible Tau "+ReleaseVersion, gr90, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c90, text_bothCuts, Scale);

  TGraphAsymmErrors* gr9 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasenergyTauJet, nMCenergyTauJet);
  c13 = new TCanvas("c13","TotalEfficiencyEnergy",30,30,520,520);
  drawEfficiency("Isolated_NoChargedNoGammas/MC Visible Taus "+ ReleaseVersion, gr9, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c13, text_bothCuts, Scale);
  
  TGraphAsymmErrors* gr10 =  new TGraphAsymmErrors(nPFTauCandenergyTauJet,  nMCenergyTauJet);
  c14 = new TCanvas("c14","PFTauCandTotalEfficiencyEnergy",35,35,525,525);
  drawEfficiency("PFTauCand(Matched)/MC Visible Taus "+ ReleaseVersion, gr10, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nMCenergyTauJet->Clone(), c14, text_bothCuts, Scale);

  TGraphAsymmErrors* gr102 = new TGraphAsymmErrors(nPFTauCandLCHenergyTauJet, nMCenergyTauJet);
  c102 = new TCanvas("c102", "EfficienciesStepByStepEnergy", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+ ReleaseVersion, gr10, gr102, gr90, gr9,  "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nMCenergyTauJet->Clone(), c102, text_bothCuts, "PFTaus", Scale);

  TGraphAsymmErrors* gr11 =  new TGraphAsymmErrors(nPFTauCandLCHenergyTauJet,  nPFTauCandenergyTauJet);
  c15 = new TCanvas("c15","FindingLeadingChargeHadronPartialEfficiencyEnergy",35,35,525,525);
  drawEfficiency(" PFTau+LeadChargeHadron/PFTau(Matched) "+ReleaseVersion, gr11, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nPFTauCandenergyTauJet->Clone(), c15, text_bothCuts, Scale);  
  		 
  TGraphAsymmErrors* gr12 =  new TGraphAsymmErrors(nIsolNoChargedHadronsenergyTauJet,  nPFTauCandLCHenergyTauJet);
  c16 = new TCanvas("c16","IsolationNoChargedHadronsPartialEfficencyEnergy",35,35,525,525);
  drawEfficiency(" IsolatedNoChargeHadrons/PFTau+LCH" +ReleaseVersion, gr12, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nPFTauCandLCHenergyTauJet->Clone(), c16, text_bothCuts, Scale); 

  TGraphAsymmErrors* gr13 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasenergyTauJet, nIsolNoChargedHadronsenergyTauJet);
  c170 = new TCanvas("c170","IsolationNoChargedNoGammasPartialEfficencyEnergy",35,35,525,525);
  drawEfficiency("NoChargedNoGammas/NoCharged " +ReleaseVersion, gr13, "Energy (GeV) (MC Vis. Tau)",(TH1F*)  nIsolNoChargedHadronsenergyTauJet->Clone(), c170, text_bothCuts, Scale);

  
}


                                                 
