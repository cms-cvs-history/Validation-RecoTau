//Author: Konstantinos A. Petridis
//Macro that Collects Iso Eff plots together

//void TauJetEff(TString rootfile,TString jetTagSrc)
void TauJetEff(TString rootfile)
{
  TFile f(rootfile);
  f.cd("DQMData/IsolationConeEffConeIsolationForEffValid");
  gDirectory->ls();
  
  

  TH1F* hSelIso07;gDirectory->GetObject("NSelVsRisoRsig07_130Et150",hSelIso07); 
  TH1F* hSelIso107;gDirectory->GetObject("NSelVsRisoRsig07_80Et110",hSelIso107);
  TH1F* hSelIso207;gDirectory->GetObject("NSelVsRisoRsig07_50Et70",hSelIso207);
  TH1F* hSelIso307;gDirectory->GetObject("NSelVsRisoRsig07_30Et50",hSelIso307);


  TH1F* hSelIso04;gDirectory->GetObject("NSelVsRisoRsig04_130Et150",hSelIso04); 
  TH1F* hSelIso104;gDirectory->GetObject("NSelVsRisoRsig04_80Et110",hSelIso104);
  TH1F* hSelIso204;gDirectory->GetObject("NSelVsRisoRsig04_50Et70",hSelIso204);
  TH1F* hSelIso304;gDirectory->GetObject("NSelVsRisoRsig04_30Et50",hSelIso304);


  TH1F* hTotIso07;gDirectory->GetObject("NTotVsRisoRsig07_130Et150",hTotIso07); 
  TH1F* hTotIso107;gDirectory->GetObject("NTotVsRisoRsig07_80Et110",hTotIso107);
  TH1F* hTotIso207;gDirectory->GetObject("NTotVsRisoRsig07_50Et70",hTotIso207);
  TH1F* hTotIso307;gDirectory->GetObject("NTotVsRisoRsig07_30Et50",hTotIso307);



 

  TH1F* hIso07 = hSelIso07;
  hIso07->Divide(hTotIso07);
  TH1F* hIso107 = hSelIso107;
  hIso107->Divide(hTotIso107);
  TH1F* hIso207 = hSelIso207;
  hIso207->Divide(hTotIso207);
  TH1F* hIso307 = hSelIso307;
  hIso307->Divide(hTotIso307);

  TH1F* hIso04 = hSelIso04;
  hIso04->Divide(hTotIso07);
  TH1F* hIso104 = hSelIso104;
  hIso104->Divide(hTotIso107);
  TH1F* hIso204 = hSelIso204;
  hIso204->Divide(hTotIso207);
  TH1F* hIso304 = hSelIso304;
  hIso304->Divide(hTotIso307);


  
  hIso07->SetMarkerStyle(20);
  hIso107->SetMarkerStyle(21);
  hIso207->SetMarkerStyle(22);
  hIso307->SetMarkerStyle(23);


  hIso04->SetMarkerStyle(24);
  hIso104->SetMarkerStyle(25);
  hIso204->SetMarkerStyle(26);
  hIso304->SetMarkerStyle(27);
  
  for(int i=1;i<21;i++)
    {
      double eff07 = hIso07->GetBinContent(i);
      double eff04 = hIso04->GetBinContent(i);
      double nTot = hTotIso07->GetBinContent(i);
      double effEff=0.;
      if(nTot > 0){
	effErr = sqrt(eff07*(1-eff07)/nTot);
	hSelIso07->SetBinError(i,effErr);
	effErr = sqrt(eff04*(1-eff04)/nTot);
	hSelIso04->SetBinError(i,effErr);

      }
      eff07 = hIso107->GetBinContent(i);
      eff04 = hIso104->GetBinContent(i);
      nTot = hTotIso107->GetBinContent(i);
      if(nTot > 0)
	{
	  effErr = sqrt(eff07*(1-eff07)/nTot);

	  hSelIso107->SetBinError(i,effErr);
	  effErr = sqrt(eff04*(1-eff04)/nTot);
	  hSelIso104->SetBinError(i,effErr);
	}


      eff07 = hIso207->GetBinContent(i);
      eff04 = hIso204->GetBinContent(i);
      nTot = hTotIso207->GetBinContent(i);
      if(nTot > 0)
	{
	  effErr = sqrt(eff07*(1-eff07)/nTot);

	  hSelIso207->SetBinError(i,effErr);
	  effErr = sqrt(eff04*(1-eff04)/nTot);
	  hSelIso204->SetBinError(i,effErr);
	}
      
      eff07 = hIso307->GetBinContent(i);
      eff04 = hIso304->GetBinContent(i);
      nTot = hTotIso307->GetBinContent(i);
      if(nTot > 0)
	{
	  effErr = sqrt(eff07*(1-eff07)/nTot);

	  hSelIso307->SetBinError(i,effErr);
	  effErr = sqrt(eff04*(1-eff04)/nTot);
	  hSelIso304->SetBinError(i,effErr);
	}


    }

   


  hIso07->SetAxisRange(0.,0.12,"Y");
  hIso07->GetXaxis()->SetTitle("Isolation Cone R_{iso}");
  hIso07->GetYaxis()->SetTitle("Efficiency");
  
  
  hIso07->GetXaxis()->SetRangeUser(0.2,0.5);
  hIso07->SetTitle("");
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

}
