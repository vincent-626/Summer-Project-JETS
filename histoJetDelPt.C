#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void histoJetDelPt() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame rdf("matched_jets", "rootfiles/matched_jets.root");

    auto df = rdf.Define("AK4_Delta_pt", "AK4_jet_all_matched_pt - AK2_jet_all_matched_pt")
                    .Define("AK6_Delta_pt", "AK6_jet_all_matched_pt - AK4_jet_all_matched_pt")
                    .Define("AK8_Delta_pt", "AK8_jet_all_matched_pt - AK6_jet_all_matched_pt");

    ROOT::RDF::TH1DModel model_AK4_Delta_pt("h1_AK4_Delta_pt", "", 200, 0., 20.);
    ROOT::RDF::TH1DModel model_AK6_Delta_pt("h1_AK4_Delta_pt", "", 200, 0., 20.);
    ROOT::RDF::TH1DModel model_AK8_Delta_pt("h1_AK4_Delta_pt", "", 200, 0., 20.);

    auto h1_AK4_Delta_pt = df.Histo1D(model_AK4_Delta_pt, "AK4_Delta_pt");
    auto h1_AK6_Delta_pt = df.Histo1D(model_AK6_Delta_pt, "AK6_Delta_pt");
    auto h1_AK8_Delta_pt = df.Histo1D(model_AK8_Delta_pt, "AK8_Delta_pt");

    // AK4 - AK2
    TCanvas *c1 = new TCanvas("c1", "c1");
    c1->cd();
    c1->SetCanvasSize(1200, 1200);

    h1_AK4_Delta_pt->SetStats(0);
    h1_AK4_Delta_pt->SetFillColor(kGreen+1);
    h1_AK4_Delta_pt->SetLineColor(kGreen+1);
    h1_AK4_Delta_pt->SetTitle("");
    h1_AK4_Delta_pt->SetMarkerSize(2);
    h1_AK4_Delta_pt->SetMarkerColor(kGreen+1);

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
    auto xaxis1 = h1_AK4_Delta_pt->GetXaxis();
    xaxis1->SetTitle("#Delta p_{T} (AK2, AK4) (GeV)");
    xaxis1->SetTitleFont(43);
    xaxis1->SetTitleSize(55);
    xaxis1->SetLabelFont(43);
    xaxis1->SetLabelSize(35);

    auto yaxis1 = h1_AK4_Delta_pt->GetYaxis();
    yaxis1->SetTitle("Jets per bin");
    yaxis1->SetTitleFont(43);
    yaxis1->SetTitleSize(55);
    yaxis1->SetLabelFont(43);
    yaxis1->SetLabelSize(35);

    h1_AK4_Delta_pt->Draw("hist");

    c1->cd();
    c1->SaveAs("pdffiles/h1_AK4_Delta_pt.pdf");

    // AK6 - AK4
    TCanvas *c2 = new TCanvas("c2", "c2");
    c2->cd();
    c2->SetCanvasSize(1200, 1200);

    h1_AK6_Delta_pt->SetStats(0);
    h1_AK6_Delta_pt->SetFillColor(kOrange+1);
    h1_AK6_Delta_pt->SetLineColor(kOrange+1);
    h1_AK6_Delta_pt->SetTitle("");
    h1_AK6_Delta_pt->SetMarkerSize(2);
    h1_AK6_Delta_pt->SetMarkerColor(kOrange+1);

    TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 1);
    pad2->SetLeftMargin(0.15);
    pad2->SetRightMargin(0.15);
    pad2->SetBottomMargin(0.15);
    pad2->SetTopMargin(0.15);
    pad2->SetTickx();
    pad2->SetTicky();
    pad2->Draw();
    pad2->cd();

    // Formatting
    auto xaxis2 = h1_AK6_Delta_pt->GetXaxis();
    xaxis2->SetTitle("#Delta p_{T} (AK4, AK6) (GeV)");
    xaxis2->SetTitleFont(43);
    xaxis2->SetTitleSize(55);
    xaxis2->SetLabelFont(43);
    xaxis2->SetLabelSize(35);

    auto yaxis2 = h1_AK6_Delta_pt->GetYaxis();
    yaxis2->SetTitle("Jets per bin");
    yaxis2->SetTitleFont(43);
    yaxis2->SetTitleSize(55);
    yaxis2->SetLabelFont(43);
    yaxis2->SetLabelSize(35);

    h1_AK6_Delta_pt->Draw("hist");

    c2->cd();
    c2->SaveAs("pdffiles/h1_AK6_Delta_pt.pdf");

    // AK8 - AK6
    TCanvas *c3 = new TCanvas("c3", "c3");
    c3->cd();
    c3->SetCanvasSize(1200, 1200);

    h1_AK8_Delta_pt->SetStats(0);
    h1_AK8_Delta_pt->SetFillColor(kRed+1);
    h1_AK8_Delta_pt->SetLineColor(kRed+1);
    h1_AK8_Delta_pt->SetTitle("");
    h1_AK8_Delta_pt->SetMarkerSize(2);
    h1_AK8_Delta_pt->SetMarkerColor(kRed+1);

    TPad *pad3 = new TPad("pad3", "pad3", 0, 0, 1, 1);
    pad3->SetLeftMargin(0.15);
    pad3->SetRightMargin(0.15);
    pad3->SetBottomMargin(0.15);
    pad3->SetTopMargin(0.15);
    pad3->SetTickx();
    pad3->SetTicky();
    pad3->Draw();
    pad3->cd();

    // Formatting
    auto xaxis3 = h1_AK8_Delta_pt->GetXaxis();
    xaxis3->SetTitle("#Delta p_{T} (AK6, AK8) (GeV)");
    xaxis3->SetTitleFont(43);
    xaxis3->SetTitleSize(55);
    xaxis3->SetLabelFont(43);
    xaxis3->SetLabelSize(35);

    auto yaxis3 = h1_AK8_Delta_pt->GetYaxis();
    yaxis3->SetTitle("Jets per bin");
    yaxis3->SetTitleFont(43);
    yaxis3->SetTitleSize(55);
    yaxis3->SetLabelFont(43);
    yaxis3->SetLabelSize(35);

    h1_AK8_Delta_pt->Draw("hist");

    c3->cd();
    c3->SaveAs("pdffiles/h1_AK8_Delta_pt.pdf");
}