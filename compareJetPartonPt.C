// In this plot the histograms are not normalized

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void compareJetPartonPt() {
    TFile *f = new TFile("rootfiles/Histo_Jet_Parton.root");

    // Make sure all the partons have matched jets!

    auto *h1_parton_pt = f->Get<TH1D>("h1_parton_pt");
    h1_parton_pt->SetFillColor(0);
    h1_parton_pt->SetLineColor(kBlack);
    h1_parton_pt->SetStats(0);
    h1_parton_pt->SetTitle("");
    h1_parton_pt->SetMarkerStyle(kFullCross);
    h1_parton_pt->SetMarkerSize(2);
    h1_parton_pt->SetMarkerColor(kBlack);

    auto *h1_AK2_jet_pt = f->Get<TH1D>("h1_AK2_jet_matched_pt");
    h1_AK2_jet_pt->SetFillColor(0);
    h1_AK2_jet_pt->SetLineColor(kBlue+1);
    h1_AK2_jet_pt->SetStats(0);
    h1_AK2_jet_pt->SetTitle("");
    h1_AK2_jet_pt->SetMarkerStyle(kFullCircle);
    h1_AK2_jet_pt->SetMarkerSize(2);
    h1_AK2_jet_pt->SetMarkerColor(kBlue+1);

    auto *h1_AK4_jet_pt = f->Get<TH1D>("h1_AK4_jet_matched_pt");
    h1_AK4_jet_pt->SetFillColor(0);
    h1_AK4_jet_pt->SetLineColor(kGreen+1);
    h1_AK4_jet_pt->SetStats(0);
    h1_AK4_jet_pt->SetTitle("");
    h1_AK4_jet_pt->SetMarkerStyle(kFullSquare);
    h1_AK4_jet_pt->SetMarkerSize(2);
    h1_AK4_jet_pt->SetMarkerColor(kGreen+1);

    auto *h1_AK6_jet_pt = f->Get<TH1D>("h1_AK6_jet_matched_pt");
    h1_AK6_jet_pt->SetFillColor(0);
    h1_AK6_jet_pt->SetLineColor(kOrange+1);
    h1_AK6_jet_pt->SetStats(0);
    h1_AK6_jet_pt->SetTitle("");
    h1_AK6_jet_pt->SetMarkerStyle(kFullTriangleUp);
    h1_AK6_jet_pt->SetMarkerSize(2);
    h1_AK6_jet_pt->SetMarkerColor(kOrange+1);

    auto *h1_AK8_jet_pt = f->Get<TH1D>("h1_AK8_jet_matched_pt");
    h1_AK8_jet_pt->SetFillColor(0);
    h1_AK8_jet_pt->SetLineColor(kRed+1);
    h1_AK8_jet_pt->SetStats(0);
    h1_AK8_jet_pt->SetTitle("");
    h1_AK8_jet_pt->SetMarkerStyle(kFullTriangleDown);
    h1_AK8_jet_pt->SetMarkerSize(2);
    h1_AK8_jet_pt->SetMarkerColor(kRed+1);

    // Change bin content to 1/nEvent * d2N/dptdeta
    int nBin = h1_AK2_jet_pt->GetNbinsX();
    double dpt = 10.;
    double deta = 4.;
    double nEvent = 10000.;

    for (int i = 0; i < nBin; i++) {
        h1_parton_pt->SetBinContent(i+1, pow(h1_parton_pt->GetBinContent(i+1), 2) / dpt / deta / nEvent);
        h1_AK2_jet_pt->SetBinContent(i+1, pow(h1_AK2_jet_pt->GetBinContent(i+1), 2) / dpt / deta / nEvent);
        h1_AK4_jet_pt->SetBinContent(i+1, pow(h1_AK4_jet_pt->GetBinContent(i+1), 2) / dpt / deta / nEvent);
        h1_AK6_jet_pt->SetBinContent(i+1, pow(h1_AK6_jet_pt->GetBinContent(i+1), 2) / dpt / deta / nEvent);
        h1_AK8_jet_pt->SetBinContent(i+1, pow(h1_AK8_jet_pt->GetBinContent(i+1), 2) / dpt / deta / nEvent);
    }

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

    // Formatting
    h1_parton_pt->SetMaximum(100);
    h1_parton_pt->SetMinimum(1e-6);

    auto yaxis = h1_parton_pt->GetYaxis();
    yaxis->SetTitle("#frac{1}{N_{event}} #frac{d^{2}N}{dp_{T}d#eta}");
    yaxis->SetTitleFont(43);
    yaxis->SetTitleSize(55);
    yaxis->SetTitleOffset(1.7);
    yaxis->SetLabelFont(43);
    yaxis->SetLabelSize(35);
    yaxis->ChangeLabel(1, -1, -1, -1, -1, -1, " ");

    pad1->cd();
    h1_parton_pt->DrawCopy("p");
    h1_AK2_jet_pt->DrawCopy("psame");
    h1_AK4_jet_pt->DrawCopy("psame");
    h1_AK6_jet_pt->DrawCopy("psame");
    h1_AK8_jet_pt->DrawCopy("psame");

    // Legend
    TLegend *leg = new TLegend(0.72, 0.55, 0.86, 0.85);
    leg->SetBorderSize(0);
    leg->AddEntry(h1_parton_pt, "Parton", "pl");
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
    htemp->SetMinimum(-1.5);
    htemp->SetMaximum(3.5);
    htemp->SetStats(0);

    auto xaxis1 = htemp->GetXaxis();
    xaxis1->SetTitle("p_{T} (GeV)");
    xaxis1->SetTitleFont(43);
    xaxis1->SetTitleSize(55);
    xaxis1->SetLabelFont(43);
    xaxis1->SetLabelSize(35);
    xaxis1->SetTitleOffset(2.5);

    auto yaxis1 = htemp->GetYaxis();
    yaxis1->SetTitle("#frac{Jet}{Parton}");
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
    h1_AK2_jet_pt->Divide(h1_parton_pt);
    h1_AK4_jet_pt->Divide(h1_parton_pt);
    h1_AK6_jet_pt->Divide(h1_parton_pt);
    h1_AK8_jet_pt->Divide(h1_parton_pt);

    h1_AK2_jet_pt->Draw("psame");
    h1_AK4_jet_pt->Draw("psame");
    h1_AK6_jet_pt->Draw("psame");
    h1_AK8_jet_pt->Draw("psame");

    c1->cd();
    c1->SaveAs("pdffiles/h1_jet_parton_pt_compare.pdf");
}