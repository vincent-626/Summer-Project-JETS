// To plot the matching efficiency
// This definition of efficiency might not be useful (Need to implement a new way to define matched and unmatched)

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"

void histoNMatchedJet() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame df("tree", "rootfiles/events.root");

    auto AK2_nMatched = df.Sum("AK2_nMatchedJet");
    auto AK2_nUnmatched = df.Sum("AK2_nUnmatchedJet");
    
    auto AK4_nMatched = df.Sum("AK4_nMatchedJet");
    auto AK4_nUnmatched = df.Sum("AK4_nUnmatchedJet");

    auto AK6_nMatched = df.Sum("AK6_nMatchedJet");
    auto AK6_nUnmatched = df.Sum("AK6_nUnmatchedJet");

    auto AK8_nMatched = df.Sum("AK8_nMatchedJet");
    auto AK8_nUnmatched = df.Sum("AK8_nUnmatchedJet");

    auto nMatchedParton = df.Sum("nMatchedParton");
    auto nUnmatchedParton = df.Sum("nUnmatchedParton");

    std::cout << *AK2_nMatched << std::endl;
    std::cout << *AK2_nUnmatched << std::endl;
    std::cout << *AK4_nMatched << std::endl;
    std::cout << *AK4_nUnmatched << std::endl;
    std::cout << *AK6_nMatched << std::endl;
    std::cout << *AK6_nUnmatched << std::endl;
    std::cout << *AK8_nMatched << std::endl;
    std::cout << *AK8_nUnmatched << std::endl;
    std::cout << *nMatchedParton << std::endl;
    std::cout << *nUnmatchedParton << std::endl;

    // AK2
    TH1I *h1_AK2_nMatched =new TH1I("h1_AK2_nMatched", "", 2, 0, 1);

    h1_AK2_nMatched->SetBinContent(1, *AK2_nUnmatched);
    h1_AK2_nMatched->SetBinContent(2, *AK2_nMatched);

    h1_AK2_nMatched->Scale(100./h1_AK2_nMatched->Integral());

    h1_AK2_nMatched->SetFillColor(kBlue+1);
    h1_AK2_nMatched->SetLineColor(kBlue+1);
    h1_AK2_nMatched->SetStats(0);
    h1_AK2_nMatched->SetTitle("");
    h1_AK2_nMatched->SetMarkerSize(2);
    h1_AK2_nMatched->SetMarkerColor(kBlue+1);
    h1_AK2_nMatched->SetMinimum(0);
    h1_AK2_nMatched->SetMaximum(100);

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
    auto xaxis1 = h1_AK2_nMatched->GetXaxis();
    xaxis1->SetTitle("");
    xaxis1->SetTitleFont(43);
    xaxis1->SetTitleSize(55);
    xaxis1->SetLabelFont(43);
    xaxis1->SetLabelSize(35);
    xaxis1->SetBinLabel(1, "Unmatched");
    xaxis1->SetBinLabel(2, "Matched");

    auto yaxis1 = h1_AK2_nMatched->GetYaxis();
    yaxis1->SetTitle("AK2 Jet Percentage (\%)");
    yaxis1->SetTitleFont(43);
    yaxis1->SetTitleSize(55);
    yaxis1->SetLabelFont(43);
    yaxis1->SetLabelSize(35);

    h1_AK2_nMatched->Draw("hist");

    c1->cd();
    c1->SaveAs("pdffiles/h1_AK2_nMatchedJet.pdf");

    // AK4
    TH1I *h1_AK4_nMatched =new TH1I("h1_AK4_nMatched", "", 2, 0, 1);

    h1_AK4_nMatched->SetBinContent(1, *AK4_nUnmatched);
    h1_AK4_nMatched->SetBinContent(2, *AK4_nMatched);

    h1_AK4_nMatched->Scale(100./h1_AK4_nMatched->Integral());

    h1_AK4_nMatched->SetFillColor(kGreen+1);
    h1_AK4_nMatched->SetLineColor(kGreen+1);
    h1_AK4_nMatched->SetStats(0);
    h1_AK4_nMatched->SetTitle("");
    h1_AK4_nMatched->SetMarkerSize(2);
    h1_AK4_nMatched->SetMarkerColor(kGreen+1);
    h1_AK4_nMatched->SetMinimum(0);
    h1_AK4_nMatched->SetMaximum(100);

    TCanvas *c2 = new TCanvas("c2", "c2");
    c2->cd();
    c2->SetCanvasSize(1200, 1200);

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
    auto xaxis2 = h1_AK4_nMatched->GetXaxis();
    xaxis2->SetTitle("");
    xaxis2->SetTitleFont(43);
    xaxis2->SetTitleSize(55);
    xaxis2->SetLabelFont(43);
    xaxis2->SetLabelSize(35);
    xaxis2->SetBinLabel(1, "Unmatched");
    xaxis2->SetBinLabel(2, "Matched");

    auto yaxis2 = h1_AK4_nMatched->GetYaxis();
    yaxis2->SetTitle("AK4 Jet Percentage (\%)");
    yaxis2->SetTitleFont(43);
    yaxis2->SetTitleSize(55);
    yaxis2->SetLabelFont(43);
    yaxis2->SetLabelSize(35);

    h1_AK4_nMatched->Draw("hist");

    c2->cd();
    c2->SaveAs("pdffiles/h1_AK4_nMatchedJet.pdf");

    // AK6
    TH1I *h1_AK6_nMatched =new TH1I("h1_AK6_nMatched", "", 2, 0, 1);

    h1_AK6_nMatched->SetBinContent(1, *AK6_nUnmatched);
    h1_AK6_nMatched->SetBinContent(2, *AK6_nMatched);

    h1_AK6_nMatched->Scale(100./h1_AK6_nMatched->Integral());

    h1_AK6_nMatched->SetFillColor(kOrange+1);
    h1_AK6_nMatched->SetLineColor(kOrange+1);
    h1_AK6_nMatched->SetStats(0);
    h1_AK6_nMatched->SetTitle("");
    h1_AK6_nMatched->SetMarkerSize(2);
    h1_AK6_nMatched->SetMarkerColor(kOrange+1);
    h1_AK6_nMatched->SetMinimum(0);
    h1_AK6_nMatched->SetMaximum(100);

    TCanvas *c3 = new TCanvas("c3", "c3");
    c3->cd();
    c3->SetCanvasSize(1200, 1200);

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
    auto xaxis3 = h1_AK6_nMatched->GetXaxis();
    xaxis3->SetTitle("");
    xaxis3->SetTitleFont(43);
    xaxis3->SetTitleSize(55);
    xaxis3->SetLabelFont(43);
    xaxis3->SetLabelSize(35);
    xaxis3->SetBinLabel(1, "Unmatched");
    xaxis3->SetBinLabel(2, "Matched");

    auto yaxis3 = h1_AK6_nMatched->GetYaxis();
    yaxis3->SetTitle("AK6 Jet Percentage (\%)");
    yaxis3->SetTitleFont(43);
    yaxis3->SetTitleSize(55);
    yaxis3->SetLabelFont(43);
    yaxis3->SetLabelSize(35);

    h1_AK6_nMatched->Draw("hist");

    c3->cd();
    c3->SaveAs("pdffiles/h1_AK6_nMatchedJet.pdf");

    // AK8
    TH1I *h1_AK8_nMatched =new TH1I("h1_AK8_nMatched", "", 2, 0, 1);

    h1_AK8_nMatched->SetBinContent(1, *AK8_nUnmatched);
    h1_AK8_nMatched->SetBinContent(2, *AK8_nMatched);

    h1_AK8_nMatched->Scale(100./h1_AK8_nMatched->Integral());

    h1_AK8_nMatched->SetFillColor(kRed+1);
    h1_AK8_nMatched->SetLineColor(kRed+1);
    h1_AK8_nMatched->SetStats(0);
    h1_AK8_nMatched->SetTitle("");
    h1_AK8_nMatched->SetMarkerSize(2);
    h1_AK8_nMatched->SetMarkerColor(kRed+1);
    h1_AK8_nMatched->SetMinimum(0);
    h1_AK8_nMatched->SetMaximum(100);

    TCanvas *c4 = new TCanvas("c4", "c4");
    c4->cd();
    c4->SetCanvasSize(1200, 1200);

    TPad *pad4 = new TPad("pad4", "pad4", 0, 0, 1, 1);
    pad4->SetLeftMargin(0.15);
    pad4->SetRightMargin(0.15);
    pad4->SetBottomMargin(0.15);
    pad4->SetTopMargin(0.15);
    pad4->SetTickx();
    pad4->SetTicky();
    pad4->Draw();
    pad4->cd();

    // Formatting
    auto xaxis4 = h1_AK8_nMatched->GetXaxis();
    xaxis4->SetTitle("");
    xaxis4->SetTitleFont(43);
    xaxis4->SetTitleSize(55);
    xaxis4->SetLabelFont(43);
    xaxis4->SetLabelSize(35);
    xaxis4->SetBinLabel(1, "Unmatched");
    xaxis4->SetBinLabel(2, "Matched");

    auto yaxis4 = h1_AK8_nMatched->GetYaxis();
    yaxis4->SetTitle("AK8 Jet Percentage (\%)");
    yaxis4->SetTitleFont(43);
    yaxis4->SetTitleSize(55);
    yaxis4->SetLabelFont(43);
    yaxis4->SetLabelSize(35);

    h1_AK8_nMatched->Draw("hist");

    c4->cd();
    c4->SaveAs("pdffiles/h1_AK8_nMatchedJet.pdf");

    // Parton
    TH1I *h1_Parton_nMatched =new TH1I("h1_Parton_nMatched", "", 2, 0, 1);

    h1_Parton_nMatched->SetBinContent(1, *nUnmatchedParton);
    h1_Parton_nMatched->SetBinContent(2, *nMatchedParton);

    h1_Parton_nMatched->Scale(100./h1_Parton_nMatched->Integral());

    h1_Parton_nMatched->SetFillColor(kCyan+1);
    h1_Parton_nMatched->SetLineColor(kCyan+1);
    h1_Parton_nMatched->SetStats(0);
    h1_Parton_nMatched->SetTitle("");
    h1_Parton_nMatched->SetMarkerSize(2);
    h1_Parton_nMatched->SetMarkerColor(kCyan+1);
    h1_Parton_nMatched->SetMinimum(0);
    h1_Parton_nMatched->SetMaximum(100);

    TCanvas *c5 = new TCanvas("c5", "c5");
    c5->cd();
    c5->SetCanvasSize(1200, 1200);

    TPad *pad5 = new TPad("pad5", "pad5", 0, 0, 1, 1);
    pad5->SetLeftMargin(0.15);
    pad5->SetRightMargin(0.15);
    pad5->SetBottomMargin(0.15);
    pad5->SetTopMargin(0.15);
    pad5->SetTickx();
    pad5->SetTicky();
    pad5->Draw();
    pad5->cd();

    // Formatting
    auto xaxis5 = h1_Parton_nMatched->GetXaxis();
    xaxis5->SetTitle("");
    xaxis5->SetTitleFont(43);
    xaxis5->SetTitleSize(55);
    xaxis5->SetLabelFont(43);
    xaxis5->SetLabelSize(35);
    xaxis5->SetBinLabel(1, "Unmatched");
    xaxis5->SetBinLabel(2, "Matched");

    auto yaxis5 = h1_Parton_nMatched->GetYaxis();
    yaxis5->SetTitle("All Matched Parton Percentage (\%)");
    yaxis5->SetTitleFont(43);
    yaxis5->SetTitleSize(55);
    yaxis5->SetLabelFont(43);
    yaxis5->SetLabelSize(35);

    h1_Parton_nMatched->Draw("hist");

    c5->cd();
    c5->SaveAs("pdffiles/h1_nMatchedParton.pdf");


    // Plot matching efficiency
    double x[4] = {0.2, 0.4, 0.6, 0.8};
    double y[4] = {h1_AK2_nMatched->GetBinContent(2), h1_AK4_nMatched->GetBinContent(2), h1_AK6_nMatched->GetBinContent(2), h1_AK8_nMatched->GetBinContent(2)};
    double err_x[4] = {0., 0., 0., 0.};
    double err_y[4] = {0., 0., 0., 0.};

    for (int i = 0; i < 4; i++) {
        std::cout << y[i] << std::endl;
    }

    TGraphAsymmErrors *gr = new TGraphAsymmErrors(4, x, y, err_x, err_x, err_y, err_y);

    gr->SetTitle("");
    gr->SetMarkerStyle(kFullCircle);
    gr->SetMarkerSize(3);
    gr->SetMarkerColor(kBlue+2);
    gr->SetLineWidth(2);
    gr->SetLineColor(kBlue+1);

    TCanvas *c6 = new TCanvas("c6", "c6");
    c6->cd();
    c6->SetCanvasSize(1200, 1200);

    TPad *pad6 = new TPad("pad1", "pad1", 0, 0, 1, 1);
    pad6->SetLeftMargin(0.15);
    pad6->SetRightMargin(0.15);
    pad6->SetBottomMargin(0.15);
    pad6->SetTopMargin(0.15);
    pad6->SetTickx();
    pad6->SetTicky();
    pad6->Draw();
    pad6->cd();

    TH1D *htemp = new TH1D("", "", 5, 0, 1);
    htemp->SetStats(0);
    htemp->SetMaximum(100);
    htemp->SetMinimum(95);

    auto xaxis6 = htemp->GetXaxis();
    xaxis6->SetTitle("R");
    xaxis6->SetLabelSize(0.03);
    xaxis6->SetTitleSize(0.05);
    xaxis6->SetNdivisions(5);
    xaxis6->SetTickLength(0.01);

    auto yaxis6 = htemp->GetYaxis();
    yaxis6->SetTitle("Jet matching efficiency (\%)");
    yaxis6->SetLabelSize(0.03);
    yaxis6->SetTitleSize(0.05);

    pad6->cd();
    htemp->Draw();
    gr->Draw("lpsame");

    c6->cd();
    c6->SaveAs("pdffiles/g2_jet_matching_eff.pdf");
}