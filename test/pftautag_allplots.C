#include <TString.h>

void pftautag_allplots(TString originalfilename, TString comparisonName, TString releaseversion, TString comparison, TString prongs)
{

  gSystem->Load("drawEfficiencyOther_C.so");
  gSystem->Load("drawEfficiencies_C.so");
  gSystem->Load("drawHistograms_C.so");

  cout << endl << " Filename: "<< originalfilename<<endl;
  cout << endl << " comparison: " << comparison << endl;
  
  TFile f(originalfilename);
  TFile other(comparisonName);

  TString Scale("LinearScale");
  
  //---------------------------------------------------------------------------------------------
  //---------------------------------ORIGINAL FILE ----------------------------------------------
  //---------------------------------------------------------------------------------------------  

  TH1F* nMCetaTau=  (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/eta_Tau_GenLevel");
  TH1F* nMCptTau=   (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/pt_Tau_GenLevel");

  // THE FOUR HISTOGRAMS AT GENERATOR LEVEL VISIBLE TAU
  TH1F* nMCetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_etaTauJet");
  TH1F* nMCptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_energyTauJet");
  TH1F* nMCphiTauJet = (TH1F*)f.Get("DQMData/RecoTauV/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_phiTauJet");

  // RECONSTRUCTED AS PFTAUCANDIDATES
  TH1F* nPFTauCandetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_etaTauJet");
  TH1F* nPFTauCandptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_ptTauJet");
  TH1F* nPFTauCandenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_energyTauJet");
  TH1F* nPFTauCandphiTauJet=     (TH1F*)f.Get("DQMData/RecoTauV/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_phiTauJet");  

  // WITH A LEADING CHARGED HADRON
  TH1F* nPFTauCandLCHetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_etaTauJet");
  TH1F* nPFTauCandLCHptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_ptTauJet");
  TH1F* nPFTauCandLCHenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_energyTauJet");
  TH1F* nPFTauCandLCHphiTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_phiTauJet");

  // WITH NO CHARGED HADRONS IN THE ISOLATION ANNULUS
  TH1F* nIsolNoChargedHadronsetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_etaTauJet");
  TH1F* nIsolNoChargedHadronsptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_ptTauJet");
  TH1F* nIsolNoChargedHadronsenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_energyTauJet");
  TH1F* nIsolNoChargedHadronsphiTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_phiTauJet");

  // WITH NO GAMMAS (AND NO CHARGED HADRONS) IN THE ISOLATION ANNULUS
  TH1F* nIsolNoChargedNoGammasetaTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_etaTauJet");
  TH1F* nIsolNoChargedNoGammasptTauJet =     (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_ptTauJet");
  TH1F* nIsolNoChargedNoGammasenergyTauJet = (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_energyTauJet");
  TH1F* nIsolNoChargedNoGammasphiTauJet =    (TH1F*)f.Get("DQMData/RecoTauV/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_phiTauJet");  

  //---------------------------------------------------------------------------------------------
  //---------------------------------THE OTHER FILE ----------------------------------------------
  //---------------------------------------------------------------------------------------------  

  TH1F* nMCetaTauO=  (TH1F*)other.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/eta_Tau_GenLevel");
  TH1F* nMCptTauO=   (TH1F*)other.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/pt_Tau_GenLevel");

  // THE FOUR HISTOGRAMS AT GENERATOR LEVEL VISIBLE TAU
  TH1F* nMCetaTauJetO =    (TH1F*)other.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_etaTauJet");
  TH1F* nMCptTauJetO =     (TH1F*)other.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_ptTauJet");
  TH1F* nMCenergyTauJetO = (TH1F*)other.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_energyTauJet");
  TH1F* nMCphiTauJetO = (TH1F*)other.Get("DQMData/TausAtGenLevel_PFTauIsolationValidation/nMC_Taus_vs_phiTauJet");

  // RECONSTRUCTED AS PFTAUCANDIDATES
  TH1F* nPFTauCandetaTauJetO =    (TH1F*)other.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_etaTauJet");
  TH1F* nPFTauCandptTauJetO =     (TH1F*)other.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_ptTauJet");
  TH1F* nPFTauCandenergyTauJetO = (TH1F*)other.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_energyTauJet");
  TH1F* nPFTauCandphiTauJetO=     (TH1F*)other.Get("DQMData/PFTauCandidatesMatched_PFTauIsolationValidation/n_PFTauCand_vs_phiTauJet");  

  // WITH A LEADING CHARGED HADRON
  TH1F* nPFTauCandLCHetaTauJetO =    (TH1F*)other.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_etaTauJet");
  TH1F* nPFTauCandLCHptTauJetO =     (TH1F*)other.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_ptTauJet");
  TH1F* nPFTauCandLCHenergyTauJetO = (TH1F*)other.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_energyTauJet");
  TH1F* nPFTauCandLCHphiTauJetO =    (TH1F*)other.Get("DQMData/PFTauPlusLeadingChargedHadron_PFTauIsolationValidation/n_PFTau_LeadingChargedHadron_vs_phiTauJet");

  // WITH NO CHARGED HADRONS IN THE ISOLATION ANNULUS
  TH1F* nIsolNoChargedHadronsetaTauJetO =    (TH1F*)other.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_etaTauJet");
  TH1F* nIsolNoChargedHadronsptTauJetO =     (TH1F*)other.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_ptTauJet");
  TH1F* nIsolNoChargedHadronsenergyTauJetO = (TH1F*)other.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_energyTauJet");
  TH1F* nIsolNoChargedHadronsphiTauJetO =    (TH1F*)other.Get("DQMData/Isolated_NoChargedHadrons_PFTauIsolationValidation/n_Isolated_NoChargedHadrons_vs_phiTauJet");

  // WITH NO GAMMAS (AND NO CHARGED HADRONS) IN THE ISOLATION ANNULUS
  TH1F* nIsolNoChargedNoGammasetaTauJetO =    (TH1F*)other.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_etaTauJet");
  TH1F* nIsolNoChargedNoGammasptTauJetO =     (TH1F*)other.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_ptTauJet");
  TH1F* nIsolNoChargedNoGammasenergyTauJetO = (TH1F*)other.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_energyTauJet");
  TH1F* nIsolNoChargedNoGammasphiTauJetO =    (TH1F*)other.Get("DQMData/Isolated_NoChargedNoGammas_PFTauIsolationValidation/n_Isolated_NoChargedNoGammas_vs_phiTauJet");  


  cout << endl<< " entriesO "<< nMCetaTauJetO->Integral()<<endl;

 //====================================================ETA================================================================= 

  TPaveText* text_ptCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_ptCut->SetBorderSize(0);
  text_ptCut->SetFillColor(0);
  text_ptCut->AddText(Form(" P_{T} > %.1f GeV", 5.0));

  c4 = new TCanvas("c4", "VisibleTauMCEtadistributions", 30, 30, 520, 520);
  drawHistograms("Visible MC Tau", nMCetaTauJet, nMCetaTauJetO, "#eta", c4, text_ptCut, releaseversion, comparison, Scale);

  delete c4;

  TH1F* divisionHisto = (TH1F *) nMCetaTauJetO->Clone();
  divisionHisto->Divide(nPFTauCandetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","PFTauCandTotalEfficiencyEta",30,30,520,520);
  drawEfficiencyOther("PFTauCand(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto2 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto2->Divide(nPFTauCandLCHetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nPFTauCandLCHetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargeHadronEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargeHadron/MC Visible Tau "+releaseversion, gr1, divisionHisto2, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto3 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto3->Divide(nIsolNoChargedHadronsetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nIsolNoChargedHadronsetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/MC Visible Tau "+releaseversion, gr2, divisionHisto3, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto4 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto4->Divide(nIsolNoChargedNoGammasetaTauJetO, nMCetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasetaTauJet, nMCetaTauJet);
  c4 = new TCanvas("c4","NoChargedNoGammasEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" NoChargedNoGammas/MC Visible Tau "+releaseversion, gr3, divisionHisto4, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepEta", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3,  "#eta (MC Vis. Tau)",(TH1F*)  nMCetaTauJet->Clone(), c4, text_ptCut,"PFTaus", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3; 

  TH1F* divisionHisto5 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto5->Divide(nPFTauCandLCHetaTauJetO, nPFTauCandetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandLCHetaTauJet, nPFTauCandetaTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargedHadronPartialEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargedHadron/ PFTauCand(Matched) "+releaseversion, gr0, divisionHisto5, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4;

  TH1F* divisionHisto6 = (TH1F *)  nMCetaTauJetO->Clone();
  divisionHisto6->Divide(nIsolNoChargedHadronsetaTauJetO, nPFTauCandLCHetaTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nIsolNoChargedHadronsetaTauJet, nPFTauCandLCHetaTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsPartialEfficiencyEta",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/FindingLeadingChargedHadron "+releaseversion, gr1, divisionHisto6, "#eta (MC Vis. Tau)", (TH1F*) nMCetaTauJet->Clone(), c4, text_ptCut,releaseversion, comparison, Scale ); 

  delete c4;
  delete gr0;
  delete gr1;

 //====================================================Pt================================================================= 

  TPaveText* text_etaCut = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_etaCut->SetBorderSize(0);
  text_etaCut->SetFillColor(0);
  text_etaCut->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  c4 = new TCanvas("c4", "VisibleTauMCPtdistributions", 30, 30, 520, 520);
  drawHistograms("Visible MC Tau", nMCptTauJet, nMCptTauJetO, " P_{T} (GeV/c) ", c4, text_etaCut, releaseversion, comparison, Scale);

  delete c4;


  TH1F* divisionHisto7 = (TH1F *) nMCptTauJetO->Clone();
  divisionHisto7->Divide(nPFTauCandptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","PFTauCandTotalEfficiencyPt",30,30,520,520);
  drawEfficiencyOther("PFTauCand(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto7, " P_{T} (GeV/c)(MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto8 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto8->Divide(nPFTauCandLCHptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nPFTauCandLCHptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargeHadronEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargeHadron/MC Visible Tau "+releaseversion, gr1, divisionHisto8, " P_{T} (GeV/c)(MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto9 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto9->Divide(nIsolNoChargedHadronsptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nIsolNoChargedHadronsptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/MC Visible Tau "+releaseversion, gr2, divisionHisto9, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto10 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto10->Divide(nIsolNoChargedNoGammasptTauJetO, nMCptTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasptTauJet, nMCptTauJet);
  c4 = new TCanvas("c4","NoChargedNoGammasEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" NoChargedNoGammas/MC Visible Tau "+releaseversion, gr3, divisionHisto10, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepPt", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3,  "P_{T} (GeV/c)(MC Vis. Tau)",(TH1F*)  nMCptTauJet->Clone(), c4, text_etaCut,"PFTaus", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3; 

  TH1F* divisionHisto11 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto11->Divide(nPFTauCandLCHptTauJetO, nPFTauCandptTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandLCHptTauJet, nPFTauCandptTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargedHadronPartialEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargedHadron/ PFTauCand(Matched) "+releaseversion, gr0, divisionHisto11, "P_{T} (GeV/c) (MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4;

  TH1F* divisionHisto12 = (TH1F *)  nMCptTauJetO->Clone();
  divisionHisto12->Divide(nIsolNoChargedHadronsptTauJetO, nPFTauCandLCHptTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nIsolNoChargedHadronsptTauJet, nPFTauCandLCHptTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsPartialEfficiencyPt",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/FindingLeadingChargedHadron "+releaseversion, gr1, divisionHisto12, "P_{T} (GeV/c)(MC Vis. Tau)", (TH1F*) nMCptTauJet->Clone(), c4, text_etaCut,releaseversion, comparison, Scale ); 

  delete c4;
  delete gr0;
  delete gr1;

 //====================================================Energy ================================================================= 

  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  c4 = new TCanvas("c4", "VisibleTauMCEnergydistributions", 30, 30, 520, 520);
  drawHistograms("Visible MC Tau", nMCenergyTauJet, nMCenergyTauJetO, " Energy (GeV) ", c4, text_bothCuts, releaseversion, comparison, Scale);

  delete c4;

  TH1F* divisionHisto13 = (TH1F *) nMCenergyTauJetO->Clone();
  divisionHisto13->Divide(nPFTauCandenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","PFTauCandTotalEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther("PFTauCand(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto13, " Energy (GeV)(MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto14 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto14->Divide(nPFTauCandLCHenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nPFTauCandLCHenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargeHadronEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargeHadron/MC Visible Tau "+releaseversion, gr1, divisionHisto14, " Energy (GeV)(MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto15 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto15->Divide(nIsolNoChargedHadronsenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nIsolNoChargedHadronsenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/MC Visible Tau "+releaseversion, gr2, divisionHisto15, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto16 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto16->Divide(nIsolNoChargedNoGammasenergyTauJetO, nMCenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasenergyTauJet, nMCenergyTauJet);
  c4 = new TCanvas("c4","NoChargedNoGammasEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" NoChargedNoGammas/MC Visible Tau "+releaseversion, gr3, divisionHisto16, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepEnergy", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3,  "Energy (GeV)(MC Vis. Tau)",(TH1F*)  nMCenergyTauJet->Clone(), c4, text_bothCuts,"PFTaus", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3; 

  TH1F* divisionHisto17 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto17->Divide(nPFTauCandLCHenergyTauJetO, nPFTauCandenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandLCHenergyTauJet, nPFTauCandenergyTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargedHadronPartialEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargedHadron/ PFTauCand(Matched) "+releaseversion, gr0, divisionHisto17, "Energy (GeV) (MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4;

  TH1F* divisionHisto18 = (TH1F *)  nMCenergyTauJetO->Clone();
  divisionHisto18->Divide(nIsolNoChargedHadronsenergyTauJetO, nPFTauCandLCHenergyTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nIsolNoChargedHadronsenergyTauJet, nPFTauCandLCHenergyTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsPartialEfficiencyEnergy",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/FindingLeadingChargedHadron "+releaseversion, gr1, divisionHisto18, " Energy (GeV)(MC Vis. Tau)", (TH1F*) nMCenergyTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4;
  delete gr0;
  delete gr1;

 //==================================================== Phi ================================================================= 

  TPaveText* text_bothCuts = new TPaveText(0.66, 0.82, 0.92, 0.92, "brNDC");
  text_bothCuts->SetBorderSize(0);
  text_bothCuts->SetFillColor(0);
  text_bothCuts->AddText(Form(" P_{T} > %.1f GeV", 5.0));
  text_bothCuts->AddText(Form(" %.1f  < #eta < %.1f ", -2.5, 2.5));

  c4 = new TCanvas("c4", "VisibleTauMCPhidistributions", 30, 30, 520, 520);
  drawHistograms("Visible MC Tau", nMCphiTauJet, nMCphiTauJetO, " #phi ", c4, text_bothCuts, releaseversion, comparison, Scale);

  delete c4;

  TH1F* divisionHisto19 = (TH1F *) nMCphiTauJetO->Clone();
  divisionHisto19->Divide(nPFTauCandphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","PFTauCandTotalEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther("PFTauCand(Matched)/MC Visible Tau "+releaseversion, gr0, divisionHisto19, " #phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale );  

  delete c4; 

  TH1F* divisionHisto20 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto20->Divide(nPFTauCandLCHphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nPFTauCandLCHphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargeHadronEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargeHadron/MC Visible Tau "+releaseversion, gr1, divisionHisto20, " #phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto21 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto21->Divide(nIsolNoChargedHadronsphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr2 =  new TGraphAsymmErrors(nIsolNoChargedHadronsphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/MC Visible Tau "+releaseversion, gr2, divisionHisto21, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  TH1F* divisionHisto22 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto22->Divide(nIsolNoChargedNoGammasphiTauJetO, nMCphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr3 =  new TGraphAsymmErrors(nIsolNoChargedNoGammasphiTauJet, nMCphiTauJet);
  c4 = new TCanvas("c4","NoChargedNoGammasEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" NoChargedNoGammas/MC Visible Tau "+releaseversion, gr3, divisionHisto22, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4; 

  c4 = new TCanvas("c4", "EfficienciesStepByStepPhi", 230, 230, 720, 720);
  drawEfficiencies("Different Steps/MC Visible Taus "+releaseversion, gr0, gr1, gr2,gr3,  "#phi (MC Vis. Tau)",(TH1F*)  nMCphiTauJet->Clone(), c4, text_bothCuts,"PFTaus", Scale);

  delete c4;
  delete gr0;
  delete gr1;
  delete gr2;
  delete gr3; 

  TH1F* divisionHisto23 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto23->Divide(nPFTauCandLCHphiTauJetO, nPFTauCandphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr0 =  new TGraphAsymmErrors(nPFTauCandLCHphiTauJet, nPFTauCandphiTauJet);
  c4 = new TCanvas("c4","FindingLeadingChargedHadronPartialEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" FindingLeadingChargedHadron/ PFTauCand(Matched) "+releaseversion, gr0, divisionHisto23, "#phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4;

  TH1F* divisionHisto24 = (TH1F *)  nMCphiTauJetO->Clone();
  divisionHisto24->Divide(nIsolNoChargedHadronsphiTauJetO, nPFTauCandLCHphiTauJetO, 1, 1);

  TGraphAsymmErrors* gr1 =  new TGraphAsymmErrors(nIsolNoChargedHadronsphiTauJet, nPFTauCandLCHphiTauJet);
  c4 = new TCanvas("c4","NoChargedHadronsPartialEfficiencyPhi",30,30,520,520);
  drawEfficiencyOther(" NoChargedHadrons/FindingLeadingChargedHadron "+releaseversion, gr1, divisionHisto24, " #phi (MC Vis. Tau)", (TH1F*) nMCphiTauJet->Clone(), c4, text_bothCuts,releaseversion, comparison, Scale ); 

  delete c4;
  delete gr0;
  delete gr1;

}
