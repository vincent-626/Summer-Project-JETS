#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void compareJetDelR() {
    TFile *f = new TFile("rootfiles/Histo_Jet_Parton.root");

    auto *h1_AK2_jet_matched_delR = f->Get<TH1D>("h1_AK2_jet_matched_delR");
    h1_AK2_jet_matched_delR->Scale(1/h1_AK2_jet_matched_delR->Integral());
    h1_AK2_jet_matched_delR->SetFillColorAlpha(kBlue+1, 0.25);
    h1_AK2_jet_matched_delR->SetLineColor(kBlue+1);
    h1_AK2_jet_matched_delR->SetStats(0);
    h1_AK2_jet_matched_delR->SetTitle("");

    auto *h1_AK4_jet_matched_delR = f->Get<TH1D>("h1_AK4_jet_matched_delR");
    h1_AK4_jet_matched_delR->Scale(1/h1_AK4_jet_matched_delR->Integral());
    h1_AK4_jet_matched_delR->SetFillColorAlpha(kGreen+1, 0.25);
    h1_AK4_jet_matched_delR->SetLineColor(kGreen+1);
    h1_AK4_jet_matched_delR->SetStats(0);
    h1_AK4_jet_matched_delR->SetTitle("");

    auto *h1_AK6_jet_matched_delR = f->Get<TH1D>("h1_AK6_jet_matched_delR");
    h1_AK6_jet_matched_delR->Scale(1/h1_AK6_jet_matched_delR->Integral());
    h1_AK6_jet_matched_delR->SetFillColorAlpha(kOrange+1, 0.25);
    h1_AK6_jet_matched_delR->SetLineColor(kOrange+1);
    h1_AK6_jet_matched_delR->SetStats(0);
    h1_AK6_jet_matched_delR->SetTitle("");

    auto *h1_AK8_jet_matched_delR = f->Get<TH1D>("h1_AK8_jet_matched_delR");
    h1_AK8_jet_matched_delR->Scale(1/h1_AK8_jet_matched_delR->Integral());
    h1_AK8_jet_matched_delR->SetFillColorAlpha(kRed+1, 0.25);
    h1_AK8_jet_matched_delR->SetLineColor(kRed+1);
    h1_AK8_jet_matched_delR->SetStats(0);
    h1_AK8_jet_matched_delR->SetTitle("");

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
    h1_AK8_jet_matched_delR->SetMaximum(0.12);

    auto xaxis = h1_AK8_jet_matched_delR->GetXaxis();
    xaxis->SetTitle("#DeltaR");
    xaxis->SetTitleFont(43);
    xaxis->SetTitleSize(55);
    xaxis->SetLabelFont(43);
    xaxis->SetLabelSize(35);

    auto yaxis = h1_AK8_jet_matched_delR->GetYaxis();
    yaxis->SetTitle("Normalised jets per bin");
    yaxis->SetTitleFont(43);
    yaxis->SetTitleSize(55);
    yaxis->SetLabelFont(43);
    yaxis->SetLabelSize(35);

    h1_AK8_jet_matched_delR->Draw("hist");
    h1_AK6_jet_matched_delR->Draw("histsame");
    h1_AK4_jet_matched_delR->Draw("histsame");
    h1_AK2_jet_matched_delR->Draw("histsame");

    // Legend
    TLegend *leg = new TLegend(0.6, 0.6, 0.8, 0.8);
    leg->SetBorderSize(0);
    leg->AddEntry(h1_AK2_jet_matched_delR, "R = 0.2", "f");
    leg->AddEntry(h1_AK4_jet_matched_delR, "R = 0.4", "f");
    leg->AddEntry(h1_AK6_jet_matched_delR, "R = 0.6", "f");
    leg->AddEntry(h1_AK8_jet_matched_delR, "R = 0.8", "f");
    leg->Draw();

    c1->cd();
    c1->SaveAs("pdffiles/h1_jet_matched_delR_compare.pdf");
}