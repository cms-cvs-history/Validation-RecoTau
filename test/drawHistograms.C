#include <TH1F.h>
#include <TGraphAsymmErrors.h>
#include <TMath.h>
#include <TMatrixD.h>
#include <TVectorD.h>
#include <TArrayD.h>
#include <TString.h>
#include <TCanvas.h>
#include <TPostScript.h>
#include <TPaveText.h>
#include <iostream>
#include <TLegend.h>

void drawHistograms(TString histogramTitle, TH1F* original, TH1F* comparison, TString xAxisTitle, TCanvas* canvas, TPaveText* Text,TString version, TString comparedto, TString loglinearscale="LinearScale", double Minimum=0.)
{ 
  comparison->Sumw2();
  original->Sumw2();
  comparison->SetStats(false);
  comparison->SetTitle(histogramTitle);
  comparison->SetMinimum(Minimum);
  comparison->GetXaxis()->SetTitle(xAxisTitle);
  comparison->GetYaxis()->CenterTitle();
  comparison->GetYaxis()->SetTitle("Normalized");
  if ( loglinearscale.CompareTo("LogScale")==0) {
    if (Minimum<0.00001) Minimum = 0.001;
    comparison->SetMinimum(Minimum);
    comparison->SetMaximum(3.0);
    canvas->SetLogy();
  }
  comparison->SetFillColor(41);
  comparison->DrawNormalized("Histo");

  original->SetMarkerStyle(20);
  original->SetMarkerSize(1);
  original->SetMarkerColor(4);
  original->DrawNormalized("p SAME"); 

  if ( Text ) Text->Draw();
  canvas->Update();

  TLegend* legend;
  legend = new TLegend(0.55, 0.91,  .99, 0.99);

  legend->AddEntry(original, version, "P");
  legend->AddEntry(comparison, comparedto, "F");
 
  legend->Draw();

  canvas->Update();
  canvas->Print(TString(canvas->GetTitle()).Append(".png"),"png");

}
