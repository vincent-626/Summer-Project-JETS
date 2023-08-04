#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void compareJetPt() {
    TFile *f = new TFile("rootfiles/Histo_Jet_Parton.root");

    auto *h1_AK2_jet_pt = f->Get<TH1D>("h1_AK2_jet_all_matched_pt");
    h1_AK2_jet_pt->SetFillColor(0);
    h1_AK2_jet_pt->SetLineColor(kBlue+1);
    h1_AK2_jet_pt->SetStats(0);
    h1_AK2_jet_pt->SetTitle("");
    h1_AK2_jet_pt->SetMarkerStyle(kFullCircle);
    h1_AK2_jet_pt->SetMarkerSize(2);
    h1_AK2_jet_pt->SetMarkerColor(kBlue+1);

    auto *h1_AK4_jet_pt = f->Get<TH1D>("h1_AK4_jet_all_matched_pt");
    h1_AK4_jet_pt->SetFillColor(0);
    h1_AK4_jet_pt->SetLineColor(kGreen+1);
    h1_AK4_jet_pt->SetStats(0);
    h1_AK4_jet_pt->SetTitle("");
    h1_AK4_jet_pt->SetMarkerStyle(kFullSquare);
    h1_AK4_jet_pt->SetMarkerSize(2);
    h1_AK4_jet_pt->SetMarkerColor(kGreen+1);

    auto *h1_AK6_jet_pt = f->Get<TH1D>("h1_AK6_jet_all_matched_pt");
    h1_AK6_jet_pt->SetFillColor(0);
    h1_AK6_jet_pt->SetLineColor(kOrange+1);
    h1_AK6_jet_pt->SetStats(0);
    h1_AK6_jet_pt->SetTitle("");
    h1_AK6_jet_pt->SetMarkerStyle(kFullTriangleUp);
    h1_AK6_jet_pt->SetMarkerSize(2);
    h1_AK6_jet_pt->SetMarkerColor(kOrange+1);

    auto *h1_AK8_jet_pt = f->Get<TH1D>("h1_AK8_jet_all_matched_pt");
    h1_AK8_jet_pt->SetFillColor(0);
    h1_AK8_jet_pt->SetLineColor(kRed+1);
    h1_AK8_jet_pt->SetStats(0);
    h1_AK8_jet_pt->SetTitle("");
    h1_AK8_jet_pt->SetMarkerStyle(kFullTriangleDown);
    h1_AK8_jet_pt->SetMarkerSize(2);
    h1_AK8_jet_pt->SetMarkerColor(kRed+1);

    // Scale bins to 1/nEvent * d2N/dptdeta
    int nBin = h1_AK2_jet_pt->GetNbinsX();
    double dpt = 10.;
    double deta = 4.;
    double nEvent = 10000.;
    double normFactor = 1 / dpt / deta / nEvent;

    h1_AK2_jet_pt->Scale(normFactor);
    h1_AK4_jet_pt->Scale(normFactor);
    h1_AK6_jet_pt->Scale(normFactor);
    h1_AK8_jet_pt->Scale(normFactor);

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

    auto yaxis = h1_AK2_jet_pt->GetYaxis();
    yaxis->SetTitle("#frac{1}{N_{event}} #frac{d^{2}N}{dp_{T, Jet}d#eta_{Jet}}");
    yaxis->SetTitleFont(43);
    yaxis->SetTitleSize(55);
    yaxis->SetTitleOffset(1.7);
    yaxis->SetLabelFont(43);
    yaxis->SetLabelSize(35);

    pad1->cd();
    h1_AK2_jet_pt->DrawCopy("ep");
    h1_AK4_jet_pt->DrawCopy("epsame");
    h1_AK6_jet_pt->DrawCopy("epsame");
    h1_AK8_jet_pt->DrawCopy("epsame");

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
    TH1D *htemp = new TH1D("", "", 20, 0., 200.);
    htemp->SetMinimum(0.);
    htemp->SetMaximum(2.);
    htemp->SetStats(0);

    auto xaxis1 = htemp->GetXaxis();
    xaxis1->SetTitle("p_{T, Jet} (GeV)");
    xaxis1->SetTitleFont(43);
    xaxis1->SetTitleSize(55);
    xaxis1->SetLabelFont(43);
    xaxis1->SetLabelSize(35);
    xaxis1->SetTitleOffset(2.5);

    auto yaxis1 = htemp->GetYaxis();
    yaxis1->SetTitle("#frac{R = x}{R = x-0.2}");
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
    h1_AK8_jet_pt->Divide(h1_AK6_jet_pt);
    h1_AK6_jet_pt->Divide(h1_AK4_jet_pt);
    h1_AK4_jet_pt->Divide(h1_AK2_jet_pt);
    
    h1_AK4_jet_pt->Draw("epsame");
    h1_AK6_jet_pt->Draw("epsame");
    h1_AK8_jet_pt->Draw("epsame");

    c1->cd();
    c1->SaveAs("pdffiles/h1_jet_matched_pt_compare.pdf");
}