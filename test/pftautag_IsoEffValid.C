 
{               
  gSystem->Load("drawEfficiency_C.so");
  gSystem->Load("drawEfficiencies_C.so");

  TFile f("pftautag_IsoEffValid.root");

  TString ReleaseVersion("CMSSW160");
  TString Scale("LinearScale");

  TH1F* nMCetaTau=  (TH1F*)f.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/eta_Tau_GenLevel");
  TH1F* nMCptTau=   (TH1F*)f.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/pt_Tau_GenLevel");

  TH1F* nMCetaTauJet =    (TH1F*)f.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_etaTauJet");
  TH1F* nMCptTauJet =     (TH1F*)f.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJet = (TH1F*)f.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_energyTauJet");

  TH1F* nPFTauCandetaTauJet =    (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_etaTauJet");
  TH1F* nPFTauCandptTauJet =     (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_ptTauJet");
  TH1F* nPFTauCandenergyTauJet = (TH1F*)f.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_energyTauJet");

  TH1F* nPFTauCandLCHetaTauJet =    (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_etaTauJet");
  TH1F* nPFTauCandLCHptTauJet =     (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_ptTauJet");
  TH1F* nPFTauCandLCHenergyTauJet = (TH1F*)f.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_energyTauJet");

  TH1F* nIsolNoChargedHadronsetaTauJet =    (TH1F*)f.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_etaTauJet");
  TH1F* nIsolNoChargedHadronsptTauJet =     (TH1F*)f.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_ptTauJet");
  TH1F* nIsolNoChargedHadronsenergyTauJet = (TH1F*)f.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_energyTauJet");

  TH1F* nIsolNoChargedNoGammasetaTauJet =    (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_etaTauJet");
  TH1F* nIsolNoChargedNoGammasptTauJet =     (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_ptTauJet");
  TH1F* nIsolNoChargedNoGammasenergyTauJet = (TH1F*)f.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_energyTauJet");

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
  /*
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
  */

  //====================================================ETA================================================================= 
  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddText(Form(" P_{T} > %.1f GeV", 5.0));

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


