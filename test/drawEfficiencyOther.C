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

void drawEfficiencyOther(TString histogramTitle, TGraphAsymmErrors* graph, TH1F* comparison, TString xAxisTitle,  TH1F* hDummy, TCanvas* canvas, TPaveText* Text,TString version, TString comparedto, TString loglinearscale="LinearScale", double Minimum=0.)
{ 

  hDummy->SetStats(false);
  hDummy->SetTitle(histogramTitle);
  hDummy->SetMinimum(Minimum);
  hDummy->SetMaximum(1.2);
  hDummy->GetXaxis()->SetTitle(xAxisTitle);
  hDummy->GetYaxis()->CenterTitle();
  hDummy->GetYaxis()->SetTitle("Efficiency");
  hDummy->Reset();
  if ( loglinearscale.CompareTo("LogScale")==0) {
    if (Minimum<0.00001) Minimum = 0.001;
    hDummy->SetMinimum(Minimum);
    hDummy->SetMaximum(3.0);
    canvas->SetLogy();
  }
  hDummy->Draw("p");
  comparison->SetFillColor(41);
  comparison->Draw("HISTO SAME"); 
  hDummy->Draw("sameaxis");
  graph->SetMarkerStyle(20);
  graph->SetMarkerSize(1);
  graph->SetMarkerColor(4);
  if ( Text ) Text->Draw();
  canvas->Update();
 
  graph->Draw("p SAME");

  TLegend* legend;
  legend = new TLegend(0.1, 0.84, 0.5, 0.94);

  legend->AddEntry(graph, version, "P");
  legend->AddEntry(comparison, comparedto, "F");
 
  legend->Draw();

  canvas->Update();
  canvas->Print(TString(canvas->GetTitle()).Append(".png"),"png");

}
