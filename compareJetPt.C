#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void compareJetPt() {
    TFile *f = new TFile("rootfiles/Histo_Jet_PtEtaPhi.root");

    auto *h1_AK2_jet_pt = f->Get<TH1D>("h1_AK2_jet_pt");
    h1_AK2_jet_pt->SetFillColor(0);
    h1_AK2_jet_pt->SetLineColor(kBlue+1);
    h1_AK2_jet_pt->SetStats(0);
    h1_AK2_jet_pt->SetTitle("");
    h1_AK2_jet_pt->SetMarkerSize(2);
    h1_AK2_jet_pt->SetMarkerColor(kBlue+1);
    h1_AK2_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

    auto *h1_AK4_jet_pt = f->Get<TH1D>("h1_AK4_jet_pt");
    h1_AK4_jet_pt->SetFillColor(0);
    h1_AK4_jet_pt->SetLineColor(kGreen+1);
    h1_AK4_jet_pt->SetStats(0);
    h1_AK4_jet_pt->SetTitle("");
    h1_AK4_jet_pt->SetMarkerSize(2);
    h1_AK4_jet_pt->SetMarkerColor(kGreen+1);
    h1_AK4_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

    auto *h1_AK6_jet_pt = f->Get<TH1D>("h1_AK6_jet_pt");
    h1_AK6_jet_pt->SetFillColor(0);
    h1_AK6_jet_pt->SetLineColor(kOrange+1);
    h1_AK6_jet_pt->SetStats(0);
    h1_AK6_jet_pt->SetTitle("");
    h1_AK6_jet_pt->SetMarkerSize(2);
    h1_AK6_jet_pt->SetMarkerColor(kOrange+1);
    h1_AK6_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

    auto *h1_AK8_jet_pt = f->Get<TH1D>("h1_AK8_jet_pt");
    h1_AK8_jet_pt->SetFillColor(0);
    h1_AK8_jet_pt->SetLineColor(kRed+1);
    h1_AK8_jet_pt->SetStats(0);
    h1_AK8_jet_pt->SetTitle("");
    h1_AK8_jet_pt->SetMarkerSize(2);
    h1_AK8_jet_pt->SetMarkerColor(kRed+1);
    h1_AK8_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

    TCanvas *c1 = new TCanvas("c1", "c1");
    c1->cd();
    c1->SetCanvasSize(1200, 1200);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0, 1, 1);
    pad1->SetLeftMargin(0.15);
    pad1->SetRightMargin(0.15);
    pad1->SetBottomMargin(0.15);
    pad1->SetTopMargin(0.15);
    pad1->SetTickx();
    pad1->SetTicky();
    pad1->Draw();
    pad1->cd();

    // Formatting
    auto xaxis = h1_AK2_jet_pt->GetXaxis();
    xaxis->SetTitle("p_{T}^{Jet} (GeV)");
    xaxis->SetTitleFont(43);
    xaxis->SetTitleSize(55);
    xaxis->SetLabelFont(43);
    xaxis->SetLabelSize(35);

    auto yaxis = h1_AK2_jet_pt->GetYaxis();
    yaxis->SetTitle("Events per bin");
    yaxis->SetTitleFont(43);
    yaxis->SetTitleSize(55);
    yaxis->SetLabelFont(43);
    yaxis->SetLabelSize(35);

    h1_AK2_jet_pt->Draw("hist");
    h1_AK4_jet_pt->Draw("histsame");
    h1_AK6_jet_pt->Draw("histsame");
    h1_AK8_jet_pt->Draw("histsame");

    // Legend
    TLegend *leg = new TLegend(0.6, 0.6, 0.8, 0.8);
    leg->SetBorderSize(0);
    leg->AddEntry(h1_AK2_jet_pt, "R = 0.2", "f");
    leg->AddEntry(h1_AK4_jet_pt, "R = 0.4", "f");
    leg->AddEntry(h1_AK6_jet_pt, "R = 0.6", "f");
    leg->AddEntry(h1_AK8_jet_pt, "R = 0.8", "f");
    leg->Draw();

    c1->cd();
    c1->SaveAs("pdffiles/h1_jet_pt_compare.pdf");
}