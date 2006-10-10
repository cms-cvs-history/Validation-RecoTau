{
gROOT->Reset();
TFile f("tautag_Vertex.root");
TFile g("tautag_NoVertex.root");
TFile h("tautag_PxlVertex.root");
TH1F* EffIsolPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/EffIsol");
TH1F* EffEnergyPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/EffVsEtJet");
TH1F* NSigTksPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/NSigTks");
TH1F* NSigTksAIPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/NSigTksAI");
TH1F* NSelTksPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/NSelTks");
TH1F* EffLeadTkPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/EffLeadTk");
TH1F* DeltaR_LT_JetPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/DeltaR_LT_Jet");
TH1F* PtJetPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/PtJet");
TH1F* PtLeadTkPxl = (TH1F*)h.Get("DQMData/TauJetTask_coneIsolationWithPxlVertex/PtLeadTk");


TH1F* EffIsolNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/EffIsol");
TH1F* EffEnergyNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/EffVsEtJet");
TH1F* NSigTksNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/NSigTks");
TH1F* NSigTksAINoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/NSigTksAI");
TH1F* NSelTksNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/NSelTks");
TH1F* EffLeadTkNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/EffLeadTk");
TH1F* DeltaR_LT_JetNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/DeltaR_LT_Jet");
TH1F* PtJetNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/PtJet");
TH1F* PtLeadTkNoVertex = (TH1F*)g.Get("DQMData/TauJetTask_coneIsolationWithoutVertex/PtLeadTk");

TH1F* EffIsolVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/EffIsol");
TH1F* EffEnergyVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/EffVsEtJet");
TH1F* NSigTksVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/NSigTks");
TH1F* NSigTksAIVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/NSigTksAI");
TH1F* NSelTksVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/NSelTks");
TH1F* EffLeadTkVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/EffLeadTk");
TH1F* DeltaR_LT_JetVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/DeltaR_LT_Jet");
TH1F* PtJetVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/PtJet");
TH1F* PtLeadTkVertex = (TH1F*)f.Get("DQMData/TauJetTask_coneIsolationWithVertex/PtLeadTk");

c1 = new TCanvas("c1","",10,10,500,1200);
c1->Divide(1,3);

c1_1->cd();
TH1F* dummy1 = new TH1F("","EffLeadTk",1,1.,2.);
dummy1->SetMaximum(1.);
dummy1->DrawCopy();
EffLeadTkPxl->SetMinimum(0.);	
EffLeadTkPxl->SetMaximum(2.);	
EffLeadTkPxl->SetLineColor(2);
EffLeadTkPxl->DrawNormalized("same");
EffLeadTkNoVertex->SetLineColor(1);
EffLeadTkNoVertex->DrawNormalized("same");
EffLeadTkVertex->SetLineColor(4);
EffLeadTkVertex->DrawNormalized("same");
TLegend t1(0.25,0.55,0.45,0.8,"","brNDC");
t1.SetBorderSize(0);
t1.SetFillColor(0);
t1.AddEntry(EffLeadTkPxl,"Pxl Vertex","lpf");
t1.AddEntry(EffLeadTkNoVertex,"No Vertex","lpf");
t1.AddEntry(EffLeadTkVertex,"offline Vertex","lpf");
t1.Draw();

c1_2->cd();
TH1F* dummy = new TH1F("","Signal Tracks",10,0.,10.);
dummy->SetMaximum(1.);
dummy->DrawCopy();
NSigTksPxl->SetLineColor(2);
NSigTksPxl->DrawNormalized("same");
NSigTksNoVertex->SetLineColor(1);
NSigTksNoVertex->DrawNormalized("same");
NSigTksVertex->SetLineColor(4);
NSigTksVertex->DrawNormalized("same");

c1_3->cd();
dummy->SetTitle("Selected Tracks");
dummy->DrawCopy();
NSelTksPxl->SetLineColor(2);
NSelTksPxl->DrawNormalized("same");
NSelTksNoVertex->SetLineColor(1);
NSelTksNoVertex->DrawNormalized("same");
NSelTksVertex->SetLineColor(4);
NSelTksVertex->DrawNormalized("same");

c2 = new TCanvas("c2","",10,10,1200,1200);
c2->Divide(2,2);

c2_1->cd();
dummy->SetMaximum(1.);
dummy->DrawCopy();
NSigTksAIPxl->SetLineColor(2);
NSigTksAIPxl->DrawNormalized("same");
NSigTksAINoVertex->SetLineColor(1);
NSigTksAINoVertex->DrawNormalized("same");
NSigTksAIVertex->SetLineColor(4);
NSigTksAIVertex->DrawNormalized("same");
TLegend t2(0.45,0.45,0.65,0.8,"","brNDC");
t2.SetBorderSize(0);
t2.SetFillColor(0);
t2.AddEntry(NSigTksAIPxl,"Pxl Vertex","lpf");
t2.AddEntry(NSigTksAINoVertex,"No Vertex","lpf");
t2.AddEntry(NSigTksAIVertex,"offline Vertex","lpf");
t2.Draw();
c2_2->cd();
DeltaR_LT_JetPxl->SetLineColor(2);
DeltaR_LT_JetPxl->DrawNormalized();
DeltaR_LT_JetNoVertex->SetLineColor(1);
DeltaR_LT_JetNoVertex->DrawNormalized("same");
DeltaR_LT_JetVertex->SetLineColor(4);
DeltaR_LT_JetVertex->DrawNormalized("same");

c2_3->cd();
TH1F* dummy3 = new TH1F("","Pt LeadTk",30,0.,300.);
dummy3->SetMaximum(.3);
dummy3->DrawCopy();
PtLeadTkPxl->SetLineColor(2);
PtLeadTkPxl->DrawNormalized("same");
PtLeadTkNoVertex->SetLineColor(1);
PtLeadTkNoVertex->DrawNormalized("same");
PtLeadTkVertex->SetLineColor(4);
PtLeadTkVertex->DrawNormalized("same");

c2_4->cd();
TH1F* dummy2 = new TH1F("","Pt Jet",30,0.,300.);
dummy2->SetMaximum(.12);
dummy2->DrawCopy();
PtJetPxl->SetLineColor(2);
PtJetPxl->DrawNormalized("same");
PtJetNoVertex->SetLineColor(1);
PtJetNoVertex->DrawNormalized("same");
PtJetVertex->SetLineColor(4);
PtJetVertex->DrawNormalized("same");

c3 = new TCanvas("c3","",10,10,1200,500);
c3->Divide(2,1);
c3_1->cd();
EffIsolPxl->SetMinimum(0.);	
EffIsolPxl->SetMaximum(2.);	
EffIsolPxl->SetLineColor(2);
EffIsolPxl->DrawCopy();
EffIsolNoVertex->SetLineColor(1);
EffIsolNoVertex->DrawCopy("same");
EffIsolVertex->SetLineColor(4);
EffIsolVertex->DrawCopy("same");
TLegend t(0.25,0.65,0.55,0.8,"","brNDC");
t.SetBorderSize(0);
t.SetFillColor(0);
t.AddEntry(EffIsolPxl,"Pxl Vertex","lpf");
t.AddEntry(EffIsolNoVertex,"No Vertex","lpf");
t.AddEntry(EffIsolVertex,"offline Vertex","lpf");
t.Draw();
c3_2->cd();
EffEnergyPxl->SetMinimum(0.);	
EffEnergyPxl->SetMaximum(2.);	
EffEnergyPxl->SetLineColor(2);
EffEnergyPxl->DrawCopy();
EffEnergyNoVertex->SetLineColor(1);
EffEnergyNoVertex->DrawCopy("same");
EffEnergyVertex->SetLineColor(4);
EffEnergyVertex->DrawCopy("same");


}
