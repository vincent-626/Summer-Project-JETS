// To plot correlation matrix of jet width
// Run TTreeMaker_JetPartonPt.C first to get matched_jets.root (contains only all matched jets)

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void histoCorrJetWidth() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame df("matched_jets", "rootfiles/matched_jets.root");

    // Create TH2s
    ROOT::RDF::TH2DModel model_AK2_AK4_lambda11("h2_AK2_AK4_lambda11", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK2_AK6_lambda11("h2_AK2_AK6_lambda11", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK2_AK8_lambda11("h2_AK2_AK8_lambda11", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK4_AK6_lambda11("h2_AK4_AK6_lambda11", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK4_AK8_lambda11("h2_AK4_AK8_lambda11", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK6_AK8_lambda11("h2_AK6_AK8_lambda11", "", 200, 0., 2., 200, 0., 2.);

    auto h2_AK2_AK4_lambda11 = df.Histo2D(model_AK2_AK4_lambda11, "AK2_jet_all_matched_lambda11", "AK4_jet_all_matched_lambda11");
    auto h2_AK2_AK6_lambda11 = df.Histo2D(model_AK2_AK6_lambda11, "AK2_jet_all_matched_lambda11", "AK6_jet_all_matched_lambda11");
    auto h2_AK2_AK8_lambda11 = df.Histo2D(model_AK2_AK8_lambda11, "AK2_jet_all_matched_lambda11", "AK8_jet_all_matched_lambda11");
    auto h2_AK4_AK6_lambda11 = df.Histo2D(model_AK4_AK6_lambda11, "AK4_jet_all_matched_lambda11", "AK6_jet_all_matched_lambda11");
    auto h2_AK4_AK8_lambda11 = df.Histo2D(model_AK4_AK8_lambda11, "AK4_jet_all_matched_lambda11", "AK8_jet_all_matched_lambda11");
    auto h2_AK6_AK8_lambda11 = df.Histo2D(model_AK6_AK8_lambda11, "AK6_jet_all_matched_lambda11", "AK8_jet_all_matched_lambda11");

    // Get correlation factors
    double corr[6];

    corr[0] = h2_AK2_AK4_lambda11->GetCorrelationFactor();
    corr[1] = h2_AK2_AK6_lambda11->GetCorrelationFactor();
    corr[2] = h2_AK2_AK8_lambda11->GetCorrelationFactor();
    corr[3] = h2_AK4_AK6_lambda11->GetCorrelationFactor();
    corr[4] = h2_AK4_AK8_lambda11->GetCorrelationFactor();
    corr[5] = h2_AK6_AK8_lambda11->GetCorrelationFactor();

    for (int i = 0; i < 6; i++) {
        std::cout << corr[i] << std::endl;
    }

    // Plot correlation matrix
    TH2D *h2_corr = new TH2D("h2_corr", "", 4, 0, 4, 4, 0, 4);

    h2_corr->SetBinContent(1, 1, 1.);
    h2_corr->SetBinContent(1, 2, corr[0]);
    h2_corr->SetBinContent(2, 1, corr[0]);
    h2_corr->SetBinContent(1, 3, corr[1]);
    h2_corr->SetBinContent(3, 1, corr[1]);
    h2_corr->SetBinContent(1, 3, corr[1]);
    h2_corr->SetBinContent(1, 4, corr[2]);
    h2_corr->SetBinContent(4, 1, corr[2]);

    h2_corr->SetBinContent(2, 2, 1);
    h2_corr->SetBinContent(2, 3, corr[3]);
    h2_corr->SetBinContent(3, 2, corr[3]);
    h2_corr->SetBinContent(2, 4, corr[4]);
    h2_corr->SetBinContent(4, 2, corr[4]);

    h2_corr->SetBinContent(3, 3, 1);
    h2_corr->SetBinContent(3, 4, corr[5]);
    h2_corr->SetBinContent(4, 3, corr[5]);

    h2_corr->SetBinContent(4, 4, 1);

    h2_corr->SetStats(0);
    h2_corr->SetMinimum(0.);
    h2_corr->SetMaximum(1.);

    auto xaxis = h2_corr->GetXaxis();
    xaxis->SetNdivisions(4);
    xaxis->CenterLabels();
    xaxis->SetLabelOffset(0.04);
    xaxis->SetLabelSize(0.035);
    xaxis->ChangeLabel(1, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK2}");
    xaxis->ChangeLabel(2, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK4}");
    xaxis->ChangeLabel(3, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK6}");
    xaxis->ChangeLabel(4, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK8}");

    auto yaxis = h2_corr->GetYaxis();
    yaxis->SetNdivisions(4);
    yaxis->CenterLabels();
    yaxis->SetLabelOffset(0.02);
    yaxis->SetLabelSize(0.035);
    yaxis->ChangeLabel(1, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK2}");
    yaxis->ChangeLabel(2, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK4}");
    yaxis->ChangeLabel(3, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK6}");
    yaxis->ChangeLabel(4, -1, -1, -1, -1, -1, "#lambda^{1}_{1, AK8}");

    auto zaxis = h2_corr->GetZaxis();
    zaxis->SetTitle("Correlation factor");
    zaxis->SetTitleOffset(1.5);

    TCanvas *c = new TCanvas("c", "c");
    c->cd();
    c->SetCanvasSize(1200, 1200);

    TPad *pad = new TPad("pad", "pad", 0, 0, 1, 1);
    pad->SetLeftMargin(0.18);
    pad->SetRightMargin(0.18);
    pad->SetBottomMargin(0.18);
    pad->SetTopMargin(0.18);
    pad->SetTickx();
    pad->SetTicky();
    pad->Draw();
    pad->cd();

    gStyle->SetPalette(kBlueGreenYellow);
    h2_corr->Draw("colztext");

    c->SaveAs("pdffiles/h2_corrJetWidth.pdf");
}