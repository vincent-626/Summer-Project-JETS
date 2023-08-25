// To plot mean delta R as a function of pt
// Run histoPlotter.C first to get Histo_Jet_Parton.root

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"
#include "TGraphAsymmErrors.h"

void compareMeanDelR() {
    TFile *f = new TFile("rootfiles/Histo_Jet_Parton.root");

    const int pt[6] = {10, 40, 50, 70, 100, 200};
    double mean_AK2[5], mean_AK4[5], mean_AK6[5], mean_AK8[5];
    double rms_AK2[5], rms_AK4[5], rms_AK6[5], rms_AK8[5];

    // Get mean and rms values for every pt bin
    for (int i = 1; i < 6; i++) {
        // AK2
        string title_AK2 = "h1_AK2_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK2 = title_AK2.c_str();
        auto h1_AK2_project = f->Get<TH1D>(c_title_AK2);

        mean_AK2[i-1] = h1_AK2_project->GetMean();
        rms_AK2[i-1] = h1_AK2_project->GetRMS();

        // AK4
        string title_AK4 = "h1_AK4_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK4 = title_AK4.c_str();
        auto h1_AK4_project = f->Get<TH1D>(c_title_AK4);

        mean_AK4[i-1] = h1_AK4_project->GetMean();
        rms_AK4[i-1] = h1_AK4_project->GetRMS();

        // AK6
        string title_AK6 = "h1_AK6_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK6 = title_AK6.c_str();
        auto h1_AK6_project = f->Get<TH1D>(c_title_AK6);

        mean_AK6[i-1] = h1_AK6_project->GetMean();
        rms_AK6[i-1] = h1_AK6_project->GetRMS();

        // AK8
        string title_AK8 = "h1_AK8_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK8 = title_AK8.c_str();
        auto h1_AK8_project = f->Get<TH1D>(c_title_AK8);

        mean_AK8[i-1] = h1_AK8_project->GetMean();
        rms_AK8[i-1] = h1_AK8_project->GetRMS();
    }

    // Plotting
    double x[5] = {1., 2., 3., 4., 5.};
    double err_x[5] = {0., 0., 0., 0., 0.};

    TGraphAsymmErrors *gr_AK2 = new TGraphAsymmErrors(5, x, mean_AK2, err_x, err_x, rms_AK2, rms_AK2);
    TGraphAsymmErrors *gr_AK4 = new TGraphAsymmErrors(5, x, mean_AK4, err_x, err_x, rms_AK4, rms_AK4);
    TGraphAsymmErrors *gr_AK6 = new TGraphAsymmErrors(5, x, mean_AK6, err_x, err_x, rms_AK6, rms_AK6);
    TGraphAsymmErrors *gr_AK8 = new TGraphAsymmErrors(5, x, mean_AK8, err_x, err_x, rms_AK8, rms_AK8);

    // TGraph formatting
    gr_AK2->SetTitle("");
    gr_AK2->SetMarkerColor(kBlue+1);
    gr_AK2->SetMarkerStyle(kFullCircle);
    gr_AK2->SetMarkerSize(3);
    gr_AK2->SetLineColor(kBlue+1);

    gr_AK4->SetTitle("");
    gr_AK4->SetMarkerColor(kGreen+1);
    gr_AK4->SetMarkerStyle(kFullSquare);
    gr_AK4->SetMarkerSize(3);
    gr_AK4->SetLineColor(kGreen+1);

    gr_AK6->SetTitle("");
    gr_AK6->SetMarkerColor(kOrange+1);
    gr_AK6->SetMarkerStyle(kFullTriangleUp);
    gr_AK6->SetMarkerSize(3);
    gr_AK6->SetLineColor(kOrange+1);

    gr_AK8->SetTitle("");
    gr_AK8->SetMarkerColor(kRed+1);
    gr_AK8->SetMarkerStyle(kFullTriangleDown);
    gr_AK8->SetMarkerSize(3);
    gr_AK8->SetLineColor(kRed+1);

    // TH1 as base
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

    TH1I *htemp = new TH1I("", "", 5, 1, 5);
    htemp->SetStats(0);
    htemp->SetMaximum(0.06);
    
    auto xaxis = htemp->GetXaxis();
    xaxis->SetLabelSize(0.04);
    xaxis->SetLimits(0.5, 5.5);
    xaxis->SetNdivisions(5);
    
    for (int i = 1; i < 6; i++) {
        string label = "p_{T} #in [" + std::to_string(pt[i-1]) + ", " + std::to_string(pt[i]) + "] GeV";
        auto c_label = label.c_str();
        xaxis->SetBinLabel(i, c_label);
    }
        
    xaxis->LabelsOption("d");
    xaxis->SetLabelOffset(0.01);

    auto yaxis = htemp->GetYaxis();
    yaxis->SetTitle("#LT#DeltaR#GT");
    yaxis->SetLabelSize(0.03);
    yaxis->SetTitleSize(0.05);
    yaxis->CenterTitle(true);

    // Drawing
    pad1->cd();
    htemp->Draw();
    gr_AK2->Draw("psame");
    gr_AK4->Draw("psame");
    gr_AK6->Draw("psame");
    gr_AK8->Draw("psame");

    // Legend
    TLegend *leg = new TLegend(0.65, 0.6, 0.83, 0.8);
    leg->SetBorderSize(0);
    leg->AddEntry(gr_AK2, "R = 0.2", "pl");
    leg->AddEntry(gr_AK4, "R = 0.4", "pl");
    leg->AddEntry(gr_AK6, "R = 0.6", "pl");
    leg->AddEntry(gr_AK8, "R = 0.8", "pl");
    leg->Draw();

    c1->cd();
    c1->SaveAs("pdffiles/g2_jet_matched_meanDelR.pdf");
}