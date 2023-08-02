#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void histoCorrPtRatio() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame df("matched_jets", "rootfiles/matched_jets.root");

    // Create TH2s
    ROOT::RDF::TH2DModel model_AK2_AK4_ptRatio("h2_AK2_AK4_ptRatio", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK2_AK6_ptRatio("h2_AK2_AK6_ptRatio", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK2_AK8_ptRatio("h2_AK2_AK8_ptRatio", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK4_AK6_ptRatio("h2_AK4_AK6_ptRatio", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK4_AK8_ptRatio("h2_AK4_AK8_ptRatio", "", 200, 0., 2., 200, 0., 2.);
    ROOT::RDF::TH2DModel model_AK6_AK8_ptRatio("h2_AK6_AK8_ptRatio", "", 200, 0., 2., 200, 0., 2.);

    auto h2_AK2_AK4_ptRatio = df.Histo2D(model_AK2_AK4_ptRatio, "AK2_jet_parton_pt_ratio", "AK4_jet_parton_pt_ratio");
    auto h2_AK2_AK6_ptRatio = df.Histo2D(model_AK2_AK6_ptRatio, "AK2_jet_parton_pt_ratio", "AK6_jet_parton_pt_ratio");
    auto h2_AK2_AK8_ptRatio = df.Histo2D(model_AK2_AK8_ptRatio, "AK2_jet_parton_pt_ratio", "AK8_jet_parton_pt_ratio");
    auto h2_AK4_AK6_ptRatio = df.Histo2D(model_AK4_AK6_ptRatio, "AK4_jet_parton_pt_ratio", "AK6_jet_parton_pt_ratio");
    auto h2_AK4_AK8_ptRatio = df.Histo2D(model_AK4_AK8_ptRatio, "AK4_jet_parton_pt_ratio", "AK8_jet_parton_pt_ratio");
    auto h2_AK6_AK8_ptRatio = df.Histo2D(model_AK6_AK8_ptRatio, "AK6_jet_parton_pt_ratio", "AK8_jet_parton_pt_ratio");

    // Get correlation factors
    double corr[6];

    corr[0] = h2_AK2_AK4_ptRatio->GetCorrelationFactor();
    corr[1] = h2_AK2_AK6_ptRatio->GetCorrelationFactor();
    corr[2] = h2_AK2_AK8_ptRatio->GetCorrelationFactor();
    corr[3] = h2_AK4_AK6_ptRatio->GetCorrelationFactor();
    corr[4] = h2_AK4_AK8_ptRatio->GetCorrelationFactor();
    corr[5] = h2_AK6_AK8_ptRatio->GetCorrelationFactor();

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
    xaxis->ChangeLabel(1, -1, -1, -1, -1, -1, "#frac{p_{T, AK2 Jet}}{p_{T, Parton}}");
    xaxis->ChangeLabel(2, -1, -1, -1, -1, -1, "#frac{p_{T, AK4 Jet}}{p_{T, Parton}}");
    xaxis->ChangeLabel(3, -1, -1, -1, -1, -1, "#frac{p_{T, AK6 Jet}}{p_{T, Parton}}");
    xaxis->ChangeLabel(4, -1, -1, -1, -1, -1, "#frac{p_{T, AK8 Jet}}{p_{T, Parton}}");

    auto yaxis = h2_corr->GetYaxis();
    yaxis->SetNdivisions(4);
    yaxis->CenterLabels();
    yaxis->SetLabelOffset(0.02);
    yaxis->SetLabelSize(0.035);
    yaxis->ChangeLabel(1, -1, -1, -1, -1, -1, "#frac{p_{T, AK2 Jet}}{p_{T, Parton}}");
    yaxis->ChangeLabel(2, -1, -1, -1, -1, -1, "#frac{p_{T, AK4 Jet}}{p_{T, Parton}}");
    yaxis->ChangeLabel(3, -1, -1, -1, -1, -1, "#frac{p_{T, AK6 Jet}}{p_{T, Parton}}");
    yaxis->ChangeLabel(4, -1, -1, -1, -1, -1, "#frac{p_{T, AK8 Jet}}{p_{T, Parton}}");

    TCanvas *c = new TCanvas("c", "c");
    c->cd();
    c->SetCanvasSize(1200, 1200);

    TPad *pad = new TPad("pad", "pad", 0, 0, 1, 1);
    pad->SetLeftMargin(0.15);
    pad->SetRightMargin(0.15);
    pad->SetBottomMargin(0.15);
    pad->SetTopMargin(0.15);
    pad->SetTickx();
    pad->SetTicky();
    pad->Draw();
    pad->cd();

    gStyle->SetPalette(kBlueGreenYellow);
    h2_corr->Draw("colztext");

    c->SaveAs("pdffiles/h2_corrPtRatio.pdf");
}