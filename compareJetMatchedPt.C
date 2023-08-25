// To compare jet spectra of all jets and matched jets (by having a ratio plot between them)
// Run histoPlotter.C first to get Histo_Jet_Parton.root

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void compareJetMatchedPt() {
    TFile *f = new TFile("rootfiles/Histo_Jet_Parton.root");

    auto *h1_AK2_jet_pt = f->Get<TH1D>("h1_AK2_jet_pt");
    auto *h1_AK4_jet_pt = f->Get<TH1D>("h1_AK4_jet_pt");
    auto *h1_AK6_jet_pt = f->Get<TH1D>("h1_AK6_jet_pt");
    auto *h1_AK8_jet_pt = f->Get<TH1D>("h1_AK8_jet_pt");

    auto *h1_AK2_jet_matched_pt = f->Get<TH1D>("h1_AK2_jet_matched_pt");
    auto *h1_AK4_jet_matched_pt = f->Get<TH1D>("h1_AK4_jet_matched_pt");
    auto *h1_AK6_jet_matched_pt = f->Get<TH1D>("h1_AK6_jet_matched_pt");
    auto *h1_AK8_jet_matched_pt = f->Get<TH1D>("h1_AK8_jet_matched_pt");

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

    h1_AK2_jet_matched_pt->SetFillColor(0);
    h1_AK2_jet_matched_pt->SetLineColor(kBlue+3);
    h1_AK2_jet_matched_pt->SetStats(0);
    h1_AK2_jet_matched_pt->SetTitle("");
    h1_AK2_jet_matched_pt->SetMarkerStyle(kFullSquare);
    h1_AK2_jet_matched_pt->SetMarkerSize(2);
    h1_AK2_jet_matched_pt->SetMarkerColor(kBlue+3);

    h1_AK4_jet_matched_pt->SetFillColor(0);
    h1_AK4_jet_matched_pt->SetLineColor(kGreen+3);
    h1_AK4_jet_matched_pt->SetStats(0);
    h1_AK4_jet_matched_pt->SetTitle("");
    h1_AK4_jet_matched_pt->SetMarkerStyle(kFullTriangleUp);
    h1_AK4_jet_matched_pt->SetMarkerSize(2);
    h1_AK4_jet_matched_pt->SetMarkerColor(kGreen+3);

    h1_AK6_jet_matched_pt->SetFillColor(0);
    h1_AK6_jet_matched_pt->SetLineColor(kOrange+3);
    h1_AK6_jet_matched_pt->SetStats(0);
    h1_AK6_jet_matched_pt->SetTitle("");
    h1_AK6_jet_matched_pt->SetMarkerStyle(kFullTriangleDown);
    h1_AK6_jet_matched_pt->SetMarkerSize(2);
    h1_AK6_jet_matched_pt->SetMarkerColor(kOrange+3);

    h1_AK8_jet_matched_pt->SetFillColor(0);
    h1_AK8_jet_matched_pt->SetLineColor(kRed+3);
    h1_AK8_jet_matched_pt->SetStats(0);
    h1_AK8_jet_matched_pt->SetTitle("");
    h1_AK8_jet_matched_pt->SetMarkerStyle(kFullCircle);
    h1_AK8_jet_matched_pt->SetMarkerSize(2);
    h1_AK8_jet_matched_pt->SetMarkerColor(kRed+3);

    // Scale bins to 1/nEvent * d2N/dptdeta
    double nEvent = 50000.;
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

    h1_AK2_jet_matched_pt->Scale(normFactor_AK2);
    h1_AK4_jet_matched_pt->Scale(normFactor_AK4);
    h1_AK6_jet_matched_pt->Scale(normFactor_AK6);
    h1_AK8_jet_matched_pt->Scale(normFactor_AK8);

    // AK2
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

    h1_AK2_jet_pt->SetMaximum(1.);
    h1_AK2_jet_pt->SetMinimum(1.1e-6);

    pad1->cd();
    h1_AK2_jet_pt->DrawCopy("ep");
    h1_AK2_jet_matched_pt->DrawCopy("epsame");

    // Legend
    TLegend *leg = new TLegend(0.66, 0.7, 0.86, 0.85);
    leg->SetBorderSize(0);
    leg->AddEntry(h1_AK2_jet_pt, "All jets", "pl");
    leg->AddEntry(h1_AK2_jet_matched_pt, "Matched jets", "pl");
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
    htemp->SetMinimum(0.8);
    htemp->SetMaximum(1.2);
    htemp->SetStats(0);

    auto xaxis1 = htemp->GetXaxis();
    xaxis1->SetTitle("p_{T, Jet} (GeV)");
    xaxis1->SetTitleFont(43);
    xaxis1->SetTitleSize(55);
    xaxis1->SetLabelFont(43);
    xaxis1->SetLabelSize(35);
    xaxis1->SetTitleOffset(2.5);

    auto yaxis1 = htemp->GetYaxis();
    yaxis1->SetTitle("#frac{All jets}{Matched jets}");
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
    h1_AK2_jet_pt->Divide(h1_AK2_jet_pt, h1_AK2_jet_matched_pt, 1., 1., "B");
    h1_AK2_jet_pt->Draw("epsame");

    c1->cd();
    c1->SaveAs("pdffiles/h1_AK2_jet_pt_matched_ratio.pdf");

    // AK4
    TCanvas *c3 = new TCanvas("c3", "c3");
    c3->cd();
    c3->SetCanvasSize(1200, 1200);

    TPad *pad3 = new TPad("pad3", "pad3", 0, 0.36, 1, 1);
    pad3->SetLeftMargin(0.2);
    pad3->SetRightMargin(0.1);
    pad3->SetBottomMargin(0.);
    pad3->SetTopMargin(0.1);
    pad3->SetTickx();
    pad3->SetTicky();
    pad3->SetLogy();
    pad3->Draw();
    pad3->cd();

    auto yaxis3 = h1_AK4_jet_pt->GetYaxis();
    yaxis3->SetTitle("#frac{1}{N_{event}} #frac{d^{2}N}{dp_{T, Jet}d#eta_{Jet}}");
    yaxis3->SetTitleFont(43);
    yaxis3->SetTitleSize(55);
    yaxis3->SetTitleOffset(1.7);
    yaxis3->SetLabelFont(43);
    yaxis3->SetLabelSize(35);

    h1_AK4_jet_pt->SetMaximum(10.);
    h1_AK4_jet_pt->SetMinimum(1.1e-9);

    pad3->cd();
    h1_AK4_jet_pt->DrawCopy("ep");
    h1_AK4_jet_matched_pt->DrawCopy("epsame");

    // Legend
    TLegend *leg3 = new TLegend(0.66, 0.7, 0.86, 0.85);
    leg3->SetBorderSize(0);
    leg3->AddEntry(h1_AK4_jet_pt, "All jets", "pl");
    leg3->AddEntry(h1_AK4_jet_matched_pt, "Matched jets", "pl");
    leg3->Draw();

    // Ratio plot
    c3->cd();
    TPad *pad4 = new TPad("pad4", "pad4", 0, 0, 1, 0.35);
    pad4->SetLeftMargin(0.2);
    pad4->SetRightMargin(0.1);
    pad4->SetBottomMargin(0.3);
    pad4->SetTopMargin(0);
    pad4->SetTickx();
    pad4->SetTicky();
    pad4->Draw();
    pad4->cd();

    // TH1 as base
    TH1D *htemp3 = new TH1D("", "", 20, 0., 200.);
    htemp3->SetMinimum(0.);
    htemp3->SetMaximum(12.);
    htemp3->SetStats(0);

    auto xaxis4 = htemp3->GetXaxis();
    xaxis4->SetTitle("p_{T, Jet} (GeV)");
    xaxis4->SetTitleFont(43);
    xaxis4->SetTitleSize(55);
    xaxis4->SetLabelFont(43);
    xaxis4->SetLabelSize(35);
    xaxis4->SetTitleOffset(2.5);

    auto yaxis4 = htemp3->GetYaxis();
    yaxis4->SetTitle("#frac{All jets}{Matched jets}");
    yaxis4->SetTitleFont(43);
    yaxis4->SetTitleSize(55);
    yaxis4->SetTitleOffset(1.7);
    yaxis4->SetLabelFont(43);
    yaxis4->SetLabelSize(35);
    yaxis4->CenterTitle(true);
    yaxis4->ChangeLabel(1, -1, -1, -1, -1, -1, " ");
    yaxis4->ChangeLabel(3, -1, -1, -1, -1, -1, " ");
    yaxis4->ChangeLabel(5, -1, -1, -1, -1, -1, " ");
    yaxis4->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
    yaxis4->ChangeLabel(9, -1, -1, -1, -1, -1, " ");
    yaxis4->ChangeLabel(11, -1, -1, -1, -1, -1, " ");

    htemp3->Draw("0");

    // Draw middle line
    TLine *line3 = new TLine(0., 1., 200., 1.);
    line3->SetLineColor(kBlack);
    line3->SetLineStyle(7);
    line3->Draw("same");

    // Draw histos
    h1_AK4_jet_pt->Divide(h1_AK4_jet_matched_pt);
    h1_AK4_jet_pt->Draw("epsame");

    c3->cd();
    c3->SaveAs("pdffiles/h1_AK4_jet_pt_matched_ratio.pdf");

    // AK6
    TCanvas *c5 = new TCanvas("c5", "c5");
    c5->cd();
    c5->SetCanvasSize(1200, 1200);

    TPad *pad5 = new TPad("pad5", "pad5", 0, 0.36, 1, 1);
    pad5->SetLeftMargin(0.2);
    pad5->SetRightMargin(0.1);
    pad5->SetBottomMargin(0.);
    pad5->SetTopMargin(0.1);
    pad5->SetTickx();
    pad5->SetTicky();
    pad5->SetLogy();
    pad5->Draw();
    pad5->cd();

    auto yaxis5 = h1_AK6_jet_pt->GetYaxis();
    yaxis5->SetTitle("#frac{1}{N_{event}} #frac{d^{2}N}{dp_{T, Jet}d#eta_{Jet}}");
    yaxis5->SetTitleFont(43);
    yaxis5->SetTitleSize(55);
    yaxis5->SetTitleOffset(1.7);
    yaxis5->SetLabelFont(43);
    yaxis5->SetLabelSize(35);

    h1_AK6_jet_pt->SetMaximum(1.);
    h1_AK6_jet_pt->SetMinimum(1.1e-6);

    pad5->cd();
    h1_AK6_jet_pt->DrawCopy("ep");
    h1_AK6_jet_matched_pt->DrawCopy("epsame");

    // Legend
    TLegend *leg5 = new TLegend(0.66, 0.7, 0.86, 0.85);
    leg5->SetBorderSize(0);
    leg5->AddEntry(h1_AK6_jet_pt, "All jets", "pl");
    leg5->AddEntry(h1_AK6_jet_matched_pt, "Matched jets", "pl");
    leg5->Draw();

    // Ratio plot
    c5->cd();
    TPad *pad6 = new TPad("pad6", "pad6", 0, 0, 1, 0.35);
    pad6->SetLeftMargin(0.2);
    pad6->SetRightMargin(0.1);
    pad6->SetBottomMargin(0.3);
    pad6->SetTopMargin(0);
    pad6->SetTickx();
    pad6->SetTicky();
    pad6->Draw();
    pad6->cd();

    // TH1 as base
    TH1D *htemp6 = new TH1D("", "", 20, 0., 200.);
    htemp6->SetMinimum(0.8);
    htemp6->SetMaximum(1.2);
    htemp6->SetStats(0);

    auto xaxis6 = htemp6->GetXaxis();
    xaxis6->SetTitle("p_{T, Jet} (GeV)");
    xaxis6->SetTitleFont(43);
    xaxis6->SetTitleSize(55);
    xaxis6->SetLabelFont(43);
    xaxis6->SetLabelSize(35);
    xaxis6->SetTitleOffset(2.5);

    auto yaxis6 = htemp6->GetYaxis();
    yaxis6->SetTitle("#frac{All jets}{Matched jets}");
    yaxis6->SetTitleFont(43);
    yaxis6->SetTitleSize(55);
    yaxis6->SetTitleOffset(1.7);
    yaxis6->SetLabelFont(43);
    yaxis6->SetLabelSize(35);
    yaxis6->CenterTitle(true);
    yaxis6->ChangeLabel(1, -1, -1, -1, -1, -1, " ");
    yaxis6->ChangeLabel(3, -1, -1, -1, -1, -1, " ");
    yaxis6->ChangeLabel(5, -1, -1, -1, -1, -1, " ");
    yaxis6->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
    yaxis6->ChangeLabel(9, -1, -1, -1, -1, -1, " ");
    yaxis6->ChangeLabel(11, -1, -1, -1, -1, -1, " ");

    htemp6->Draw("0");

    // Draw middle line
    TLine *line6 = new TLine(0., 1., 200., 1.);
    line6->SetLineColor(kBlack);
    line6->SetLineStyle(7);
    line6->Draw("same");

    // Draw histos
    h1_AK6_jet_pt->Divide(h1_AK6_jet_matched_pt);
    h1_AK6_jet_pt->Draw("epsame");

    c5->cd();
    c5->SaveAs("pdffiles/h1_AK6_jet_pt_matched_ratio.pdf");

    // AK8
    TCanvas *c7 = new TCanvas("c7", "c7");
    c7->cd();
    c7->SetCanvasSize(1200, 1200);

    TPad *pad7 = new TPad("pad5", "pad5", 0, 0.36, 1, 1);
    pad7->SetLeftMargin(0.2);
    pad7->SetRightMargin(0.1);
    pad7->SetBottomMargin(0.);
    pad7->SetTopMargin(0.1);
    pad7->SetTickx();
    pad7->SetTicky();
    pad7->SetLogy();
    pad7->Draw();
    pad7->cd();

    auto yaxis7 = h1_AK8_jet_pt->GetYaxis();
    yaxis7->SetTitle("#frac{1}{N_{event}} #frac{d^{2}N}{dp_{T, Jet}d#eta_{Jet}}");
    yaxis7->SetTitleFont(43);
    yaxis7->SetTitleSize(55);
    yaxis7->SetTitleOffset(1.7);
    yaxis7->SetLabelFont(43);
    yaxis7->SetLabelSize(35);

    h1_AK8_jet_pt->SetMaximum(1.);
    h1_AK8_jet_pt->SetMinimum(1.1e-6);

    pad7->cd();
    h1_AK8_jet_pt->DrawCopy("ep");
    h1_AK8_jet_matched_pt->DrawCopy("epsame");

    // Legend
    TLegend *leg7 = new TLegend(0.66, 0.7, 0.86, 0.85);
    leg7->SetBorderSize(0);
    leg7->AddEntry(h1_AK8_jet_pt, "All jets", "pl");
    leg7->AddEntry(h1_AK8_jet_matched_pt, "Matched jets", "pl");
    leg7->Draw();

    // Ratio plot
    c7->cd();
    TPad *pad8 = new TPad("pad8", "pad8", 0, 0, 1, 0.35);
    pad8->SetLeftMargin(0.2);
    pad8->SetRightMargin(0.1);
    pad8->SetBottomMargin(0.3);
    pad8->SetTopMargin(0);
    pad8->SetTickx();
    pad8->SetTicky();
    pad8->Draw();
    pad8->cd();

    // TH1 as base
    TH1D *htemp8 = new TH1D("", "", 20, 0., 200.);
    htemp8->SetMinimum(0.8);
    htemp8->SetMaximum(1.2);
    htemp8->SetStats(0);

    auto xaxis8 = htemp8->GetXaxis();
    xaxis8->SetTitle("p_{T, Jet} (GeV)");
    xaxis8->SetTitleFont(43);
    xaxis8->SetTitleSize(55);
    xaxis8->SetLabelFont(43);
    xaxis8->SetLabelSize(35);
    xaxis8->SetTitleOffset(2.5);

    auto yaxis8 = htemp8->GetYaxis();
    yaxis8->SetTitle("#frac{All jets}{Matched jets}");
    yaxis8->SetTitleFont(43);
    yaxis8->SetTitleSize(55);
    yaxis8->SetTitleOffset(1.7);
    yaxis8->SetLabelFont(43);
    yaxis8->SetLabelSize(35);
    yaxis8->CenterTitle(true);
    yaxis8->ChangeLabel(1, -1, -1, -1, -1, -1, " ");
    yaxis8->ChangeLabel(3, -1, -1, -1, -1, -1, " ");
    yaxis8->ChangeLabel(5, -1, -1, -1, -1, -1, " ");
    yaxis8->ChangeLabel(7, -1, -1, -1, -1, -1, " ");
    yaxis8->ChangeLabel(9, -1, -1, -1, -1, -1, " ");
    yaxis8->ChangeLabel(11, -1, -1, -1, -1, -1, " ");

    htemp8->Draw("0");

    // Draw middle line
    TLine *line8 = new TLine(0., 1., 200., 1.);
    line8->SetLineColor(kBlack);
    line8->SetLineStyle(7);
    line8->Draw("same");

    // Draw histos
    h1_AK8_jet_pt->Divide(h1_AK8_jet_matched_pt);
    h1_AK8_jet_pt->Draw("epsame");

    c7->cd();
    c7->SaveAs("pdffiles/h1_AK8_jet_pt_matched_ratio.pdf");
}