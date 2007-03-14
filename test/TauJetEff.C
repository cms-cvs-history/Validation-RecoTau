//Author: Konstantinos A. Petridis
//Macro that Collects Iso Eff plots together

//void TauJetEff(TString rootfile,TString jetTagSrc)
void TauJetEff(TString rootfile)
{
  
  TFile f(rootfile);
  f.cd("DQMData/IsolationConeEffConeIsolationForEffValid");
  gDirectory->ls();
  
  TH1F* hIso07;gDirectory->GetObject("EffVsRisoRsig07_130Et150",hIso07); 
  TH1F* hIso107;gDirectory->GetObject("EffVsRisoRsig07_80Et110",hIso107);
  TH1F* hIso207;gDirectory->GetObject("EffVsRisoRsig07_50Et70",hIso207);
  TH1F* hIso307;gDirectory->GetObject("EffVsRisoRsig07_30Et50",hIso307);
  TH1F* hIso04;gDirectory->GetObject("EffVsRisoRsig04_130Et150",hIso04);
  TH1F* hIso104;gDirectory->GetObject("EffVsRisoRsig04_80Et110",hIso104);
  TH1F* hIso204;gDirectory->GetObject("EffVsRisoRsig04_50Et70",hIso204);
  TH1F* hIso304;gDirectory->GetObject("EffVsRisoRsig04_30Et50",hIso304);
 
  hIso07->SetMarkerStyle(20);
  hIso107->SetMarkerStyle(21);
  hIso207->SetMarkerStyle(22);
  hIso307->SetMarkerStyle(23);

  hIso04->SetMarkerStyle(24);
  hIso104->SetMarkerStyle(25);
  hIso204->SetMarkerStyle(26);
  hIso304->SetMarkerStyle(27);
  

  hIso07->SetAxisRange(0.4,1,"Y");
  hIso07->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso07->GetYaxis()->SetTitle("Efficiency");
  hIso107->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso107->GetYaxis()->SetTitle("Efficiency");
  hIso207->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso207->GetYaxis()->SetTitle("Efficiency");
  hIso307->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso307->GetYaxis()->SetTitle("Efficiency");


  hIso04->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso04->GetYaxis()->SetTitle("Efficiency");
  hIso104->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso104->GetYaxis()->SetTitle("Efficiency");
  hIso204->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso204->GetYaxis()->SetTitle("Efficiency");
  hIso304->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso304->GetYaxis()->SetTitle("Efficiency");
  
  TCanvas* c1=new TCanvas("c1","c1");
  c1->Divide(1,1);
  c1->cd(1);

  hIso07->DrawCopy();
  hIso107->DrawCopy("SAME");
  hIso207->DrawCopy("SAME");
  hIso307->DrawCopy("SAME");
  hIso04->DrawCopy("SAME");
  hIso104->DrawCopy("SAME");
  hIso204->DrawCopy("SAME");
  hIso304->DrawCopy("SAME");

  TFile* g=new TFile("IsoEffPlots.root","RECREATE");  
  c1->Write();
  cout<<"Canvas Saved in IsoEffPlots.root"<<endl;
}
