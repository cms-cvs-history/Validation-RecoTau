//Author: Konstantinos A. Petridis
//Macro that Collects Iso Eff plots together

//void TauJetEff(TString rootfile,TString jetTagSrc)
void TauJetEff(TString rootfile)
{
  
  TFile f(rootfile);
  f.cd("DQMData/EfficiencyecalIsolation");
  gDirectory->ls();
  
  TH1F* hIso07;gDirectory->GetObject("EffVsRisoRsig07_130Et150",hIso07); 
  TH1F* hIso107;gDirectory->GetObject("EffVsRisoRsig07_80Et110",hIso107);
  TH1F* hIso207;gDirectory->GetObject("EffVsRisoRsig07_50Et70",hIso207);
  TH1F* hIso307;gDirectory->GetObject("EffVsRisoRsig07_30Et50",hIso307);
 
  hIso07->SetMarkerStyle(23);
  hIso107->SetMarkerStyle(22);
  hIso207->SetMarkerStyle(21);
  hIso307->SetMarkerStyle(20);

  hIso07->SetAxisRange(0.0,1,"Y");
  hIso07->GetXaxis()->SetTitle("P_{iso}^{cut}, GeV");
  hIso07->GetYaxis()->SetTitle("Efficiency");
  hIso107->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso107->GetYaxis()->SetTitle("Efficiency");
  hIso207->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso207->GetYaxis()->SetTitle("Efficiency");
  hIso307->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso307->GetYaxis()->SetTitle("Efficiency");

  TCanvas* c1=new TCanvas("c1","c1");
  c1->Divide(1,1);
  c1->cd(1);
  hIso07->SetMaximum(1.12);
  //  hIso07->GetXaxis()->SetRangeUser(0.2,0.5);
  hIso07->SetTitle("");

  hIso07->DrawCopy();
  hIso107->DrawCopy("SAME");
  hIso207->DrawCopy("SAME");
  hIso307->DrawCopy("SAME");

  TFile* g=new TFile("EMIsoEffPlots.root","RECREATE");  
  c1->Write();
  cout<<"Canvas Saved in IsoEffPlots.root"<<endl;
}
