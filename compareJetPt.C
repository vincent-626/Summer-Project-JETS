// To plot jet spectra
// Run histoPlotter.C first to get Histo_Jet_Parton.root

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void compareJetPt() {
    TFile *f = new TFile("rootfiles/Histo_Jet_Parton.root");

    // ---------
    // All jets
    // ---------

    auto *h1_AK2_jet_pt = f->Get<TH1D>("h1_AK2_jet_pt");
    auto *h1_AK4_jet_pt = f->Get<TH1D>("h1_AK4_jet_pt");
    auto *h1_AK6_jet_pt = f->Get<TH1D>("h1_AK6_jet_pt");
    auto *h1_AK8_jet_pt = f->Get<TH1D>("h1_AK8_jet_pt");

    h1_AK2_jet_pt->SetFillColor(0);
    h1_AK2_jet_pt->SetLineColor(kBlue+1);
    h1_AK2_jet_pt->SetStats(0);
    h1_AK2_jet_pt->SetTitle("");
    h1_AK2_jet_pt->SetMarkerStyle(kFullCircle);
    h1_AK2_jet_pt->SetMarkerSize(2);
    h1_AK2_jet_pt->SetMarkerColor(kBlue+1);

    h1_AK4_jet_pt->SetFillColor(0);
    h1_AK4_jet_pt->SetLineColor(kGreen+1);
    h1_AK4_jet_pt->SetStats(0);
    h1_AK4_jet_pt->SetTitle("");
    h1_AK4_jet_pt->SetMarkerStyle(kFullSquare);
    h1_AK4_jet_pt->SetMarkerSize(2);
    h1_AK4_jet_pt->SetMarkerColor(kGreen+1);

    h1_AK6_jet_pt->SetFillColor(0);
    h1_AK6_jet_pt->SetLineColor(kOrange+1);
    h1_AK6_jet_pt->SetStats(0);
    h1_AK6_jet_pt->SetTitle("");
    h1_AK6_jet_pt->SetMarkerStyle(kFullTriangleUp);
    h1_AK6_jet_pt->SetMarkerSize(2);
    h1_AK6_jet_pt->SetMarkerColor(kOrange+1);

    h1_AK8_jet_pt->SetFillColor(0);
    h1_AK8_jet_pt->SetLineColor(kRed+1);
    h1_AK8_jet_pt->SetStats(0);
    h1_AK8_jet_pt->SetTitle("");
    h1_AK8_jet_pt->SetMarkerStyle(kFullTriangleDown);
    h1_AK8_jet_pt->SetMarkerSize(2);
    h1_AK8_jet_pt->SetMarkerColor(kRed+1);

    // Scale bins to 1/nEvent * d2N/dptdeta
    int nBin = h1_AK2_jet_pt->GetNbinsX();
    double nEvent = 500000.;
    double dpt = 5.;
    double deta_AK2 = 3.6;
    double deta_AK4 = 3.2;
    double deta_AK6 = 2.8;
    double deta_AK8 = 2.4;
    double normFactor_AK2 = 1 / dpt / deta_AK2 / nEvent;
    double normFactor_AK4 = 1 / dpt / deta_AK4 / nEvent;
    double normFactor_AK6 = 1 / dpt / deta_AK6 / nEvent;
    double normFactor_AK8 = 1 / dpt / deta_AK8 / nEvent;

    h1_AK2_jet_pt->Scale(normFactor_AK2);
    h1_AK4_jet_pt->Scale(normFactor_AK4);
    h1_AK6_jet_pt->Scale(normFactor_AK6);
    h1_AK8_jet_pt->Scale(normFactor_AK8);

    TCanvas *c1 = new TCanvas("c1", "c1");
    c1->cd();
    c1->SetCanvasSize(1200, 1200);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.36, 1, 1);
    pad1->SetLeftMargin(0.2);
    pad1->SetRightMargin(0.1);
    pad1->SetBottomMargin(0.);
    pad1->SetTopMargin(0.1);
    pad1->SetTickx();
    pad1->SetTicky();
    pad1->SetLogy();
    pad1->Draw();
    pad1->cd();

    auto yaxis = h1_AK8_jet_pt->GetYaxis();
    yaxis->SetTitle("#frac{1}{N_{event}} #frac{d^{2}N}{dp_{T, Jet}d#eta_{Jet}}");
    yaxis->SetTitleFont(43);
    yaxis->SetTitleSize(55);
    yaxis->SetTitleOffset(1.7);
    yaxis->SetLabelFont(43);
    yaxis->SetLabelSize(35);

    h1_AK8_jet_pt->SetMaximum(10);
    h1_AK8_jet_pt->SetMinimum(1.1e-9);

    pad1->cd();
    h1_AK8_jet_pt->DrawCopy("ep");
    h1_AK6_jet_pt->DrawCopy("epsame");
    h1_AK4_jet_pt->DrawCopy("epsame");
    h1_AK2_jet_pt->DrawCopy("epsame");

    // Legend
    TLegend *leg = new TLegend(0.72, 0.6, 0.86, 0.85);
    leg->SetBorderSize(0);
    leg->AddEntry(h1_AK2_jet_pt, "R = 0.2", "pl");
    leg->AddEntry(h1_AK4_jet_pt, "R = 0.4", "pl");
    leg->AddEntry(h1_AK6_jet_pt, "R = 0.6", "pl");
    leg->AddEntry(h1_AK8_jet_pt, "R = 0.8", "pl");
    leg->Draw();

    // Ratio plot
    c1->cd();
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 0.35);
    pad2->SetLeftMargin(0.2);
    pad2->SetRightMargin(0.1);
    pad2->SetBottomMargin(0.3);
    pad2->SetTopMargin(0);
    pad2->SetTickx();
    pad2->SetTicky();
    pad2->Draw();
    pad2->cd();

    // TH1 as base
    TH1D *htemp = new TH1D("", "", 40, 0., 200.);
    htemp->SetMinimum(0.);
    htemp->SetMaximum(20.);
    htemp->SetStats(0);

    auto xaxis1 = htemp->GetXaxis();
    xaxis1->SetTitle("p_{T, Jet} (GeV)");
    xaxis1->SetTitleFont(43);
    xaxis1->SetTitleSize(55);
    xaxis1->SetLabelFont(43);
    xaxis1->SetLabelSize(35);
    xaxis1->SetTitleOffset(2.5);

    auto yaxis1 = htemp->GetYaxis();
    yaxis1->SetTitle("#frac{R = x}{R = 0.2}");
    yaxis1->SetTitleFont(43);
    yaxis1->SetTitleSize(55);
    yaxis1->SetTitleOffset(1.7);
    yaxis1->SetLabelFont(43);
    yaxis1->SetLabelSize(35);
    yaxis1->CenterTitle(true);
    yaxis1->ChangeLabel(1, -1, -1, -1, -1, -1, " ");
    yaxis1->ChangeLabel(3, -1, -1, -1, -1, -1, " ");
    yaxis1->ChangeLabel(5, -1, -1, -1, -1, -1, " ");
    yaxis1->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
    yaxis1->ChangeLabel(9, -1, -1, -1, -1, -1, " ");
    yaxis1->ChangeLabel(11, -1, -1, -1, -1, -1, " ");

    htemp->Draw("0");

    // Draw middle line
    TLine *line = new TLine(0., 1., 200., 1.);
    line->SetLineColor(kBlack);
    line->SetLineStyle(7);
    line->Draw("same");

    // Draw histos
    h1_AK8_jet_pt->Divide(h1_AK8_jet_pt, h1_AK2_jet_pt, 1., 1., "B");
    h1_AK6_jet_pt->Divide(h1_AK6_jet_pt, h1_AK2_jet_pt, 1., 1., "B");
    h1_AK4_jet_pt->Divide(h1_AK4_jet_pt, h1_AK2_jet_pt, 1., 1., "B");
    
    h1_AK8_jet_pt->DrawCopy("epsame");
    h1_AK6_jet_pt->DrawCopy("epsame");
    h1_AK4_jet_pt->DrawCopy("epsame");

    c1->cd();
    c1->SaveAs("pdffiles/h1_jet_pt_compare.pdf");



    // -------------
    // Matched jets
    // -------------

    auto *h1_AK2_jet_matched_pt = f->Get<TH1D>("h1_AK2_jet_matched_pt");
    auto *h1_AK4_jet_matched_pt = f->Get<TH1D>("h1_AK4_jet_matched_pt");
    auto *h1_AK6_jet_matched_pt = f->Get<TH1D>("h1_AK6_jet_matched_pt");
    auto *h1_AK8_jet_matched_pt = f->Get<TH1D>("h1_AK8_jet_matched_pt");

    h1_AK2_jet_matched_pt->SetFillColor(0);
    h1_AK2_jet_matched_pt->SetLineColor(kBlue+1);
    h1_AK2_jet_matched_pt->SetStats(0);
    h1_AK2_jet_matched_pt->SetTitle("");
    h1_AK2_jet_matched_pt->SetMarkerStyle(kFullCircle);
    h1_AK2_jet_matched_pt->SetMarkerSize(2);
    h1_AK2_jet_matched_pt->SetMarkerColor(kBlue+1);

    h1_AK4_jet_matched_pt->SetFillColor(0);
    h1_AK4_jet_matched_pt->SetLineColor(kGreen+1);
    h1_AK4_jet_matched_pt->SetStats(0);
    h1_AK4_jet_matched_pt->SetTitle("");
    h1_AK4_jet_matched_pt->SetMarkerStyle(kFullSquare);
    h1_AK4_jet_matched_pt->SetMarkerSize(2);
    h1_AK4_jet_matched_pt->SetMarkerColor(kGreen+1);

    h1_AK6_jet_matched_pt->SetFillColor(0);
    h1_AK6_jet_matched_pt->SetLineColor(kOrange+1);
    h1_AK6_jet_matched_pt->SetStats(0);
    h1_AK6_jet_matched_pt->SetTitle("");
    h1_AK6_jet_matched_pt->SetMarkerStyle(kFullTriangleUp);
    h1_AK6_jet_matched_pt->SetMarkerSize(2);
    h1_AK6_jet_matched_pt->SetMarkerColor(kOrange+1);

    h1_AK8_jet_matched_pt->SetFillColor(0);
    h1_AK8_jet_matched_pt->SetLineColor(kRed+1);
    h1_AK8_jet_matched_pt->SetStats(0);
    h1_AK8_jet_matched_pt->SetTitle("");
    h1_AK8_jet_matched_pt->SetMarkerStyle(kFullTriangleDown);
    h1_AK8_jet_matched_pt->SetMarkerSize(2);
    h1_AK8_jet_matched_pt->SetMarkerColor(kRed+1);

    h1_AK2_jet_matched_pt->Scale(normFactor_AK2);
    h1_AK4_jet_matched_pt->Scale(normFactor_AK4);
    h1_AK6_jet_matched_pt->Scale(normFactor_AK6);
    h1_AK8_jet_matched_pt->Scale(normFactor_AK8);

    TCanvas *c2 = new TCanvas("c2", "c2");
    c2->cd();
    c2->SetCanvasSize(1200, 1200);

    TPad *pad3 = new TPad("pad1", "pad1", 0, 0.36, 1, 1);
    pad3->SetLeftMargin(0.2);
    pad3->SetRightMargin(0.1);
    pad3->SetBottomMargin(0.);
    pad3->SetTopMargin(0.1);
    pad3->SetTickx();
    pad3->SetTicky();
    pad3->SetLogy();
    pad3->Draw();
    pad3->cd();

    auto yaxis2 = h1_AK8_jet_matched_pt->GetYaxis();
    yaxis2->SetTitle("#frac{1}{N_{event}} #frac{d^{2}N}{dp_{T, Jet}d#eta_{Jet}}");
    yaxis2->SetTitleFont(43);
    yaxis2->SetTitleSize(55);
    yaxis2->SetTitleOffset(1.7);
    yaxis2->SetLabelFont(43);
    yaxis2->SetLabelSize(35);

    h1_AK8_jet_matched_pt->SetMaximum(10);
    h1_AK8_jet_matched_pt->SetMinimum(1.1e-9);

    pad3->cd();
    h1_AK8_jet_matched_pt->DrawCopy("ep");
    h1_AK6_jet_matched_pt->DrawCopy("epsame");
    h1_AK4_jet_matched_pt->DrawCopy("epsame");
    h1_AK2_jet_matched_pt->DrawCopy("epsame");

    // Legend
    TLegend *leg2 = new TLegend(0.72, 0.6, 0.86, 0.85);
    leg2->SetBorderSize(0);
    leg2->AddEntry(h1_AK2_jet_matched_pt, "R = 0.2", "pl");
    leg2->AddEntry(h1_AK4_jet_matched_pt, "R = 0.4", "pl");
    leg2->AddEntry(h1_AK6_jet_matched_pt, "R = 0.6", "pl");
    leg2->AddEntry(h1_AK8_jet_matched_pt, "R = 0.8", "pl");
    leg2->Draw();

    // Ratio plot
    c2->cd();
    TPad *pad4 = new TPad("pad2", "pad2", 0, 0, 1, 0.35);
    pad4->SetLeftMargin(0.2);
    pad4->SetRightMargin(0.1);
    pad4->SetBottomMargin(0.3);
    pad4->SetTopMargin(0);
    pad4->SetTickx();
    pad4->SetTicky();
    pad4->Draw();
    pad4->cd();

    // TH1 as base
    TH1D *htemp2 = new TH1D("", "", 40, 0., 200.);
    htemp2->SetMinimum(0.);
    htemp2->SetMaximum(20.);
    htemp2->SetStats(0);

    auto xaxis3 = htemp2->GetXaxis();
    xaxis3->SetTitle("p_{T, Jet} (GeV)");
    xaxis3->SetTitleFont(43);
    xaxis3->SetTitleSize(55);
    xaxis3->SetLabelFont(43);
    xaxis3->SetLabelSize(35);
    xaxis3->SetTitleOffset(2.5);

    auto yaxis3 = htemp2->GetYaxis();
    yaxis3->SetTitle("#frac{R = x}{R = 0.2}");
    yaxis3->SetTitleFont(43);
    yaxis3->SetTitleSize(55);
    yaxis3->SetTitleOffset(1.7);
    yaxis3->SetLabelFont(43);
    yaxis3->SetLabelSize(35);
    yaxis3->CenterTitle(true);
    yaxis3->ChangeLabel(1, -1, -1, -1, -1, -1, " ");
    yaxis3->ChangeLabel(3, -1, -1, -1, -1, -1, " ");
    yaxis3->ChangeLabel(5, -1, -1, -1, -1, -1, " ");
    yaxis3->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
    yaxis3->ChangeLabel(9, -1, -1, -1, -1, -1, " ");
    yaxis3->ChangeLabel(11, -1, -1, -1, -1, -1, " ");

    htemp2->Draw("0");

    // Draw middle line
    TLine *line2 = new TLine(0., 1., 200., 1.);
    line2->SetLineColor(kBlack);
    line2->SetLineStyle(7);
    line2->Draw("same");

    // Draw histos
    h1_AK8_jet_matched_pt->Divide(h1_AK8_jet_matched_pt, h1_AK2_jet_matched_pt, 1., 1., "B");
    h1_AK6_jet_matched_pt->Divide(h1_AK6_jet_matched_pt, h1_AK2_jet_matched_pt, 1., 1., "B");
    h1_AK4_jet_matched_pt->Divide(h1_AK4_jet_matched_pt, h1_AK2_jet_matched_pt, 1., 1., "B");
    
    h1_AK8_jet_matched_pt->DrawCopy("epsame");
    h1_AK6_jet_matched_pt->DrawCopy("epsame");
    h1_AK4_jet_matched_pt->DrawCopy("epsame");

    c2->cd();
    c2->SaveAs("pdffiles/h1_jet_matched_pt_compare.pdf");
}