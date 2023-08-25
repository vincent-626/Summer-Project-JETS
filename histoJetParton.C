// To make the plots of different quantities

#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void histoJetParton() {
    TFile *f = new TFile("rootfiles/Histo_Jet_Parton.root");

    // -----
    // pt
    // -----

    // AK2
    auto *h1_AK2_jet_pt = f->Get<TH1D>("h1_AK2_jet_pt");
    h1_AK2_jet_pt->SetFillColor(kBlue+1);
    h1_AK2_jet_pt->SetLineColor(kBlue+1);
    h1_AK2_jet_pt->SetStats(0);
    h1_AK2_jet_pt->SetTitle("");
    h1_AK2_jet_pt->SetMarkerSize(2);
    h1_AK2_jet_pt->SetMarkerColor(kBlue+1);

    TCanvas *c1 = new TCanvas("c1", "c1");
    c1->cd();
    c1->SetCanvasSize(1200, 1200);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0, 1, 1);
    pad1->SetLeftMargin(0.15);
    pad1->SetRightMargin(0.15);
    pad1->SetBottomMargin(0.15);
    pad1->SetTopMargin(0.15);
    pad1->SetLogy();
    pad1->SetTickx();
    pad1->SetTicky();
    pad1->Draw();
    pad1->cd();

    // Formatting
    auto xaxis1 = h1_AK2_jet_pt->GetXaxis();
    xaxis1->SetTitle("p_{T}^{AK2 Jet} (GeV)");
    xaxis1->SetTitleFont(43);
    xaxis1->SetTitleSize(55);
    xaxis1->SetLabelFont(43);
    xaxis1->SetLabelSize(35);

    auto yaxis1 = h1_AK2_jet_pt->GetYaxis();
    yaxis1->SetTitle("Events per bin");
    yaxis1->SetTitleFont(43);
    yaxis1->SetTitleSize(55);
    yaxis1->SetLabelFont(43);
    yaxis1->SetLabelSize(35);

    h1_AK2_jet_pt->Draw("hist");

    c1->cd();
    c1->SaveAs("pdffiles/h1_AK2_jet_pt.pdf");

    // AK4
    auto *h1_AK4_jet_pt = f->Get<TH1D>("h1_AK4_jet_pt");
    h1_AK4_jet_pt->SetFillColor(kGreen+1);
    h1_AK4_jet_pt->SetLineColor(kGreen+1);
    h1_AK4_jet_pt->SetStats(0);
    h1_AK4_jet_pt->SetTitle("");
    h1_AK4_jet_pt->SetMarkerSize(2);
    h1_AK4_jet_pt->SetMarkerColor(kGreen+1);

    TCanvas *c2 = new TCanvas("c2", "c2");
    c2->cd();
    c2->SetCanvasSize(1200, 1200);

    TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 1);
    pad2->SetLeftMargin(0.15);
    pad2->SetRightMargin(0.15);
    pad2->SetBottomMargin(0.15);
    pad2->SetTopMargin(0.15);
    pad2->SetLogy();
    pad2->SetTickx();
    pad2->SetTicky();
    pad2->Draw();
    pad2->cd();

    // Formatting
    auto xaxis2 = h1_AK4_jet_pt->GetXaxis();
    xaxis2->SetTitle("p_{T}^{AK4 Jet} (GeV)");
    xaxis2->SetTitleFont(43);
    xaxis2->SetTitleSize(55);
    xaxis2->SetLabelFont(43);
    xaxis2->SetLabelSize(35);

    auto yaxis2 = h1_AK4_jet_pt->GetYaxis();
    yaxis2->SetTitle("Events per bin");
    yaxis2->SetTitleFont(43);
    yaxis2->SetTitleSize(55);
    yaxis2->SetLabelFont(43);
    yaxis2->SetLabelSize(35);

    h1_AK4_jet_pt->Draw("hist");

    c2->cd();
    c2->SaveAs("pdffiles/h1_AK4_jet_pt.pdf");

    // AK6
    auto *h1_AK6_jet_pt = f->Get<TH1D>("h1_AK6_jet_pt");
    h1_AK6_jet_pt->SetFillColor(kOrange+1);
    h1_AK6_jet_pt->SetLineColor(kOrange+1);
    h1_AK6_jet_pt->SetStats(0);
    h1_AK6_jet_pt->SetTitle("");
    h1_AK6_jet_pt->SetMarkerSize(2);
    h1_AK6_jet_pt->SetMarkerColor(kOrange+1);

    TCanvas *c3 = new TCanvas("c3", "c3");
    c3->cd();
    c3->SetCanvasSize(1200, 1200);

    TPad *pad3 = new TPad("pad3", "pad3", 0, 0, 1, 1);
    pad3->SetLeftMargin(0.15);
    pad3->SetRightMargin(0.15);
    pad3->SetBottomMargin(0.15);
    pad3->SetTopMargin(0.15);
    pad3->SetLogy();
    pad3->SetTickx();
    pad3->SetTicky();
    pad3->Draw();
    pad3->cd();

    // Formatting
    auto xaxis3 = h1_AK6_jet_pt->GetXaxis();
    xaxis3->SetTitle("p_{T}^{AK6 Jet} (GeV)");
    xaxis3->SetTitleFont(43);
    xaxis3->SetTitleSize(55);
    xaxis3->SetLabelFont(43);
    xaxis3->SetLabelSize(35);

    auto yaxis3 = h1_AK6_jet_pt->GetYaxis();
    yaxis3->SetTitle("Events per bin");
    yaxis3->SetTitleFont(43);
    yaxis3->SetTitleSize(55);
    yaxis3->SetLabelFont(43);
    yaxis3->SetLabelSize(35);

    h1_AK6_jet_pt->Draw("hist");

    c3->cd();
    c3->SaveAs("pdffiles/h1_AK6_jet_pt.pdf");

    // AK8
    auto *h1_AK8_jet_pt = f->Get<TH1D>("h1_AK8_jet_pt");
    h1_AK8_jet_pt->SetFillColor(kRed+1);
    h1_AK8_jet_pt->SetLineColor(kRed+1);
    h1_AK8_jet_pt->SetStats(0);
    h1_AK8_jet_pt->SetTitle("");
    h1_AK8_jet_pt->SetMarkerSize(2);
    h1_AK8_jet_pt->SetMarkerColor(kRed+1);

    TCanvas *c4 = new TCanvas("c4", "c4");
    c4->cd();
    c4->SetCanvasSize(1200, 1200);

    TPad *pad4 = new TPad("pad4", "pad4", 0, 0, 1, 1);
    pad4->SetLeftMargin(0.15);
    pad4->SetRightMargin(0.15);
    pad4->SetBottomMargin(0.15);
    pad4->SetTopMargin(0.15);
    pad4->SetLogy();
    pad4->SetTickx();
    pad4->SetTicky();
    pad4->Draw();
    pad4->cd();

    // Formatting
    auto xaxis4 = h1_AK8_jet_pt->GetXaxis();
    xaxis4->SetTitle("p_{T}^{AK8 Jet} (GeV)");
    xaxis4->SetTitleFont(43);
    xaxis4->SetTitleSize(55);
    xaxis4->SetLabelFont(43);
    xaxis4->SetLabelSize(35);

    auto yaxis4 = h1_AK8_jet_pt->GetYaxis();
    yaxis4->SetTitle("Events per bin");
    yaxis4->SetTitleFont(43);
    yaxis4->SetTitleSize(55);
    yaxis4->SetLabelFont(43);
    yaxis4->SetLabelSize(35);

    h1_AK8_jet_pt->Draw("hist");

    c4->cd();
    c4->SaveAs("pdffiles/h1_AK8_jet_pt.pdf");

    // -----
    // eta
    // -----

    // AK2
    auto *h1_AK2_jet_eta = f->Get<TH1D>("h1_AK2_jet_eta");
    h1_AK2_jet_eta->SetFillColor(kBlue+1);
    h1_AK2_jet_eta->SetLineColor(kBlue+1);
    h1_AK2_jet_eta->SetStats(0);
    h1_AK2_jet_eta->SetTitle("");
    h1_AK2_jet_eta->SetMarkerSize(2);
    h1_AK2_jet_eta->SetMarkerColor(kBlue+1);
    h1_AK2_jet_eta->SetMinimum(0);

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
    auto xaxis5 = h1_AK2_jet_eta->GetXaxis();
    xaxis5->SetTitle("#eta^{AK2 Jet}");
    xaxis5->SetTitleFont(43);
    xaxis5->SetTitleSize(55);
    xaxis5->SetLabelFont(43);
    xaxis5->SetLabelSize(35);

    auto yaxis5 = h1_AK2_jet_eta->GetYaxis();
    yaxis5->SetTitle("Events per bin");
    yaxis5->SetTitleFont(43);
    yaxis5->SetTitleSize(55);
    yaxis5->SetLabelFont(43);
    yaxis5->SetLabelSize(35);

    h1_AK2_jet_eta->Draw("hist");

    c5->cd();
    c5->SaveAs("pdffiles/h1_AK2_jet_eta.pdf");

    // AK4
    auto *h1_AK4_jet_eta = f->Get<TH1D>("h1_AK4_jet_eta");
    h1_AK4_jet_eta->SetFillColor(kGreen+1);
    h1_AK4_jet_eta->SetLineColor(kGreen+1);
    h1_AK4_jet_eta->SetStats(0);
    h1_AK4_jet_eta->SetTitle("");
    h1_AK4_jet_eta->SetMarkerSize(2);
    h1_AK4_jet_eta->SetMarkerColor(kGreen+1);
    h1_AK4_jet_eta->SetMinimum(0);

    TCanvas *c6 = new TCanvas("c6", "c6");
    c6->cd();
    c6->SetCanvasSize(1200, 1200);

    TPad *pad6 = new TPad("pad6", "pad6", 0, 0, 1, 1);
    pad6->SetLeftMargin(0.15);
    pad6->SetRightMargin(0.15);
    pad6->SetBottomMargin(0.15);
    pad6->SetTopMargin(0.15);
    pad6->SetTickx();
    pad6->SetTicky();
    pad6->Draw();
    pad6->cd();

    // Formatting
    auto xaxis6 = h1_AK4_jet_eta->GetXaxis();
    xaxis6->SetTitle("#eta^{AK4 Jet}");
    xaxis6->SetTitleFont(43);
    xaxis6->SetTitleSize(55);
    xaxis6->SetLabelFont(43);
    xaxis6->SetLabelSize(35);

    auto yaxis6 = h1_AK4_jet_eta->GetYaxis();
    yaxis6->SetTitle("Events per bin");
    yaxis6->SetTitleFont(43);
    yaxis6->SetTitleSize(55);
    yaxis6->SetLabelFont(43);
    yaxis6->SetLabelSize(35);

    h1_AK4_jet_eta->Draw("hist");

    c6->cd();
    c6->SaveAs("pdffiles/h1_AK4_jet_eta.pdf");

    // AK6
    auto *h1_AK6_jet_eta = f->Get<TH1D>("h1_AK6_jet_eta");
    h1_AK6_jet_eta->SetFillColor(kOrange+1);
    h1_AK6_jet_eta->SetLineColor(kOrange+1);
    h1_AK6_jet_eta->SetStats(0);
    h1_AK6_jet_eta->SetTitle("");
    h1_AK6_jet_eta->SetMarkerSize(2);
    h1_AK6_jet_eta->SetMarkerColor(kOrange+1);
    h1_AK6_jet_eta->SetMinimum(0);

    TCanvas *c7 = new TCanvas("c7", "c7");
    c7->cd();
    c7->SetCanvasSize(1200, 1200);

    TPad *pad7 = new TPad("pad7", "pad7", 0, 0, 1, 1);
    pad7->SetLeftMargin(0.15);
    pad7->SetRightMargin(0.15);
    pad7->SetBottomMargin(0.15);
    pad7->SetTopMargin(0.15);
    pad7->SetTickx();
    pad7->SetTicky();
    pad7->Draw();
    pad7->cd();

    // Formatting
    auto xaxis7 = h1_AK6_jet_eta->GetXaxis();
    xaxis7->SetTitle("#eta^{AK6 Jet}");
    xaxis7->SetTitleFont(43);
    xaxis7->SetTitleSize(55);
    xaxis7->SetLabelFont(43);
    xaxis7->SetLabelSize(35);

    auto yaxis7 = h1_AK6_jet_eta->GetYaxis();
    yaxis7->SetTitle("Events per bin");
    yaxis7->SetTitleFont(43);
    yaxis7->SetTitleSize(55);
    yaxis7->SetLabelFont(43);
    yaxis7->SetLabelSize(35);

    h1_AK6_jet_eta->Draw("hist");

    c7->cd();
    c7->SaveAs("pdffiles/h1_AK6_jet_eta.pdf");

    // AK8
    auto *h1_AK8_jet_eta = f->Get<TH1D>("h1_AK8_jet_eta");
    h1_AK8_jet_eta->SetFillColor(kRed+1);
    h1_AK8_jet_eta->SetLineColor(kRed+1);
    h1_AK8_jet_eta->SetStats(0);
    h1_AK8_jet_eta->SetTitle("");
    h1_AK8_jet_eta->SetMarkerSize(2);
    h1_AK8_jet_eta->SetMarkerColor(kRed+1);
    h1_AK8_jet_eta->SetMinimum(0);

    TCanvas *c8 = new TCanvas("c8", "c8");
    c8->cd();
    c8->SetCanvasSize(1200, 1200);

    TPad *pad8 = new TPad("pad8", "pad8", 0, 0, 1, 1);
    pad8->SetLeftMargin(0.15);
    pad8->SetRightMargin(0.15);
    pad8->SetBottomMargin(0.15);
    pad8->SetTopMargin(0.15);
    pad8->SetTickx();
    pad8->SetTicky();
    pad8->Draw();
    pad8->cd();

    // Formatting
    auto xaxis8 = h1_AK8_jet_eta->GetXaxis();
    xaxis8->SetTitle("#eta^{AK8 Jet}");
    xaxis8->SetTitleFont(43);
    xaxis8->SetTitleSize(55);
    xaxis8->SetLabelFont(43);
    xaxis8->SetLabelSize(35);

    auto yaxis8 = h1_AK8_jet_eta->GetYaxis();
    yaxis8->SetTitle("Events per bin");
    yaxis8->SetTitleFont(43);
    yaxis8->SetTitleSize(55);
    yaxis8->SetLabelFont(43);
    yaxis8->SetLabelSize(35);

    h1_AK8_jet_eta->Draw("hist");

    c8->cd();
    c8->SaveAs("pdffiles/h1_AK8_jet_eta.pdf");

    // -----
    // phi
    // -----

    // AK2
    auto *h1_AK2_jet_phi = f->Get<TH1D>("h1_AK2_jet_phi");
    h1_AK2_jet_phi->SetFillColor(kBlue+1);
    h1_AK2_jet_phi->SetLineColor(kBlue+1);
    h1_AK2_jet_phi->SetStats(0);
    h1_AK2_jet_phi->SetTitle("");
    h1_AK2_jet_phi->SetMarkerSize(2);
    h1_AK2_jet_phi->SetMarkerColor(kBlue+1);
    h1_AK2_jet_phi->SetMinimum(0);

    TCanvas *c9 = new TCanvas("c9", "c9");
    c9->cd();
    c9->SetCanvasSize(1200, 1200);

    TPad *pad9 = new TPad("pad9", "pad9", 0, 0, 1, 1);
    pad9->SetLeftMargin(0.15);
    pad9->SetRightMargin(0.15);
    pad9->SetBottomMargin(0.15);
    pad9->SetTopMargin(0.15);
    pad9->SetTickx();
    pad9->SetTicky();
    pad9->Draw();
    pad9->cd();

    // Formatting
    auto xaxis9 = h1_AK2_jet_phi->GetXaxis();
    xaxis9->SetTitle("#phi^{AK2 Jet}");
    xaxis9->SetTitleFont(43);
    xaxis9->SetTitleSize(55);
    xaxis9->SetLabelFont(43);
    xaxis9->SetLabelSize(35);

    auto yaxis9 = h1_AK2_jet_phi->GetYaxis();
    yaxis9->SetTitle("Events per bin");
    yaxis9->SetTitleFont(43);
    yaxis9->SetTitleSize(55);
    yaxis9->SetLabelFont(43);
    yaxis9->SetLabelSize(35);

    h1_AK2_jet_phi->Draw("hist");

    c9->cd();
    c9->SaveAs("pdffiles/h1_AK2_jet_phi.pdf");

    // AK4
    auto *h1_AK4_jet_phi = f->Get<TH1D>("h1_AK4_jet_phi");
    h1_AK4_jet_phi->SetFillColor(kGreen+1);
    h1_AK4_jet_phi->SetLineColor(kGreen+1);
    h1_AK4_jet_phi->SetStats(0);
    h1_AK4_jet_phi->SetTitle("");
    h1_AK4_jet_phi->SetMarkerSize(2);
    h1_AK4_jet_phi->SetMarkerColor(kGreen+1);
    h1_AK4_jet_phi->SetMinimum(0);

    TCanvas *c10 = new TCanvas("c10", "c10");
    c10->cd();
    c10->SetCanvasSize(1200, 1200);

    TPad *pad10 = new TPad("pad10", "pad10", 0, 0, 1, 1);
    pad10->SetLeftMargin(0.15);
    pad10->SetRightMargin(0.15);
    pad10->SetBottomMargin(0.15);
    pad10->SetTopMargin(0.15);
    pad10->SetTickx();
    pad10->SetTicky();
    pad10->Draw();
    pad10->cd();

    // Formatting
    auto xaxis10 = h1_AK4_jet_phi->GetXaxis();
    xaxis10->SetTitle("#phi^{AK4 Jet}");
    xaxis10->SetTitleFont(43);
    xaxis10->SetTitleSize(55);
    xaxis10->SetLabelFont(43);
    xaxis10->SetLabelSize(35);

    auto yaxis10 = h1_AK4_jet_phi->GetYaxis();
    yaxis10->SetTitle("Events per bin");
    yaxis10->SetTitleFont(43);
    yaxis10->SetTitleSize(55);
    yaxis10->SetLabelFont(43);
    yaxis10->SetLabelSize(35);

    h1_AK4_jet_phi->Draw("hist");

    c10->cd();
    c10->SaveAs("pdffiles/h1_AK4_jet_phi.pdf");

    // AK6
    auto *h1_AK6_jet_phi = f->Get<TH1D>("h1_AK6_jet_phi");
    h1_AK6_jet_phi->SetFillColor(kOrange+1);
    h1_AK6_jet_phi->SetLineColor(kOrange+1);
    h1_AK6_jet_phi->SetStats(0);
    h1_AK6_jet_phi->SetTitle("");
    h1_AK6_jet_phi->SetMarkerSize(2);
    h1_AK6_jet_phi->SetMarkerColor(kOrange+1);
    h1_AK6_jet_phi->SetMinimum(0);

    TCanvas *c11 = new TCanvas("c11", "c11");
    c11->cd();
    c11->SetCanvasSize(1200, 1200);

    TPad *pad11 = new TPad("pad11", "pad11", 0, 0, 1, 1);
    pad11->SetLeftMargin(0.15);
    pad11->SetRightMargin(0.15);
    pad11->SetBottomMargin(0.15);
    pad11->SetTopMargin(0.15);
    pad11->SetTickx();
    pad11->SetTicky();
    pad11->Draw();
    pad11->cd();

    // Formatting
    auto xaxis11 = h1_AK6_jet_phi->GetXaxis();
    xaxis11->SetTitle("#phi^{AK6 Jet}");
    xaxis11->SetTitleFont(43);
    xaxis11->SetTitleSize(55);
    xaxis11->SetLabelFont(43);
    xaxis11->SetLabelSize(35);

    auto yaxis11 = h1_AK6_jet_phi->GetYaxis();
    yaxis11->SetTitle("Events per bin");
    yaxis11->SetTitleFont(43);
    yaxis11->SetTitleSize(55);
    yaxis11->SetLabelFont(43);
    yaxis11->SetLabelSize(35);

    h1_AK6_jet_phi->Draw("hist");

    c11->cd();
    c11->SaveAs("pdffiles/h1_AK6_jet_phi.pdf");

    // AK8
    auto *h1_AK8_jet_phi = f->Get<TH1D>("h1_AK8_jet_phi");
    h1_AK8_jet_phi->SetFillColor(kRed+1);
    h1_AK8_jet_phi->SetLineColor(kRed+1);
    h1_AK8_jet_phi->SetStats(0);
    h1_AK8_jet_phi->SetTitle("");
    h1_AK8_jet_phi->SetMarkerSize(2);
    h1_AK8_jet_phi->SetMarkerColor(kRed+1);
    h1_AK8_jet_phi->SetMinimum(0);

    TCanvas *c12 = new TCanvas("c12", "c12");
    c12->cd();
    c12->SetCanvasSize(1200, 1200);

    TPad *pad12 = new TPad("pad12", "pad12", 0, 0, 1, 1);
    pad12->SetLeftMargin(0.15);
    pad12->SetRightMargin(0.15);
    pad12->SetBottomMargin(0.15);
    pad12->SetTopMargin(0.15);
    pad12->SetTickx();
    pad12->SetTicky();
    pad12->Draw();
    pad12->cd();

    // Formatting
    auto xaxis12 = h1_AK8_jet_phi->GetXaxis();
    xaxis12->SetTitle("#phi^{AK8 Jet}");
    xaxis12->SetTitleFont(43);
    xaxis12->SetTitleSize(55);
    xaxis12->SetLabelFont(43);
    xaxis12->SetLabelSize(35);

    auto yaxis12 = h1_AK8_jet_phi->GetYaxis();
    yaxis12->SetTitle("Events per bin");
    yaxis12->SetTitleFont(43);
    yaxis12->SetTitleSize(55);
    yaxis12->SetLabelFont(43);
    yaxis12->SetLabelSize(35);

    h1_AK8_jet_phi->Draw("hist");

    c12->cd();
    c12->SaveAs("pdffiles/h1_AK8_jet_phi.pdf");

    // Parton
    auto *h1_parton_pt = f->Get<TH1D>("h1_parton_pt");
    h1_parton_pt->SetFillColor(kCyan+1);
    h1_parton_pt->SetLineColor(kCyan+1);
    h1_parton_pt->SetStats(0);
    h1_parton_pt->SetTitle("");
    h1_parton_pt->SetMarkerSize(2);
    h1_parton_pt->SetMarkerColor(kCyan+1);

    TCanvas *c13 = new TCanvas("c13", "c13");
    c13->cd();
    c13->SetCanvasSize(1200, 1200);

    TPad *pad13 = new TPad("pad13", "pad13", 0, 0, 1, 1);
    pad13->SetLeftMargin(0.15);
    pad13->SetRightMargin(0.15);
    pad13->SetBottomMargin(0.15);
    pad13->SetTopMargin(0.15);
    pad13->SetLogy();
    pad13->SetTickx();
    pad13->SetTicky();
    pad13->Draw();
    pad13->cd();

    // Formatting
    auto xaxis13 = h1_parton_pt->GetXaxis();
    xaxis13->SetTitle("p_{T}^{Parton} (GeV)");
    xaxis13->SetTitleFont(43);
    xaxis13->SetTitleSize(55);
    xaxis13->SetLabelFont(43);
    xaxis13->SetLabelSize(35);

    auto yaxis13 = h1_parton_pt->GetYaxis();
    yaxis13->SetTitle("Events per bin");
    yaxis13->SetTitleFont(43);
    yaxis13->SetTitleSize(55);
    yaxis13->SetLabelFont(43);
    yaxis13->SetLabelSize(35);

    h1_parton_pt->Draw("hist");

    c13->cd();
    c13->SaveAs("pdffiles/h1_parton_pt.pdf");

    auto *h1_parton_eta = f->Get<TH1D>("h1_parton_eta");
    h1_parton_eta->SetFillColor(kCyan+1);
    h1_parton_eta->SetLineColor(kCyan+1);
    h1_parton_eta->SetStats(0);
    h1_parton_eta->SetTitle("");
    h1_parton_eta->SetMarkerSize(2);
    h1_parton_eta->SetMarkerColor(kCyan+1);
    h1_parton_eta->SetMinimum(0);

    TCanvas *c14 = new TCanvas("c14", "c14");
    c14->cd();
    c14->SetCanvasSize(1200, 1200);

    TPad *pad14 = new TPad("pad14", "pad14", 0, 0, 1, 1);
    pad14->SetLeftMargin(0.15);
    pad14->SetRightMargin(0.15);
    pad14->SetBottomMargin(0.15);
    pad14->SetTopMargin(0.15);
    pad14->SetTickx();
    pad14->SetTicky();
    pad14->Draw();
    pad14->cd();

    // Formatting
    auto xaxis14 = h1_parton_eta->GetXaxis();
    xaxis14->SetTitle("#eta^{Parton} (GeV)");
    xaxis14->SetTitleFont(43);
    xaxis14->SetTitleSize(55);
    xaxis14->SetLabelFont(43);
    xaxis14->SetLabelSize(35);

    auto yaxis14 = h1_parton_eta->GetYaxis();
    yaxis14->SetTitle("Events per bin");
    yaxis14->SetTitleFont(43);
    yaxis14->SetTitleSize(55);
    yaxis14->SetLabelFont(43);
    yaxis14->SetLabelSize(35);

    h1_parton_eta->Draw("hist");

    c14->cd();
    c14->SaveAs("pdffiles/h1_parton_eta.pdf");

    auto *h1_parton_phi = f->Get<TH1D>("h1_parton_phi");
    h1_parton_phi->SetFillColor(kCyan+1);
    h1_parton_phi->SetLineColor(kCyan+1);
    h1_parton_phi->SetStats(0);
    h1_parton_phi->SetTitle("");
    h1_parton_phi->SetMarkerSize(2);
    h1_parton_phi->SetMarkerColor(kCyan+1);
    h1_parton_phi->SetMinimum(0);

    TCanvas *c15 = new TCanvas("c15", "c15");
    c15->cd();
    c15->SetCanvasSize(1200, 1200);

    TPad *pad15 = new TPad("pad15", "pad15", 0, 0, 1, 1);
    pad15->SetLeftMargin(0.15);
    pad15->SetRightMargin(0.15);
    pad15->SetBottomMargin(0.15);
    pad15->SetTopMargin(0.15);
    pad15->SetTickx();
    pad15->SetTicky();
    pad15->Draw();
    pad15->cd();

    // Formatting
    auto xaxis15 = h1_parton_phi->GetXaxis();
    xaxis15->SetTitle("#eta^{Parton} (GeV)");
    xaxis15->SetTitleFont(43);
    xaxis15->SetTitleSize(55);
    xaxis15->SetLabelFont(43);
    xaxis15->SetLabelSize(35);

    auto yaxis15 = h1_parton_phi->GetYaxis();
    yaxis15->SetTitle("Events per bin");
    yaxis15->SetTitleFont(43);
    yaxis15->SetTitleSize(55);
    yaxis15->SetLabelFont(43);
    yaxis15->SetLabelSize(35);

    h1_parton_phi->Draw("hist");

    c15->cd();
    c15->SaveAs("pdffiles/h1_parton_phi.pdf");

    // -------------
    // Matched Jets
    // -------------

    // pt
    // AK2
    auto *h1_AK2_jet_matched_pt = f->Get<TH1D>("h1_AK2_jet_matched_pt");
    h1_AK2_jet_matched_pt->SetFillColor(kBlue+1);
    h1_AK2_jet_matched_pt->SetLineColor(kBlue+1);
    h1_AK2_jet_matched_pt->SetStats(0);
    h1_AK2_jet_matched_pt->SetTitle("");
    h1_AK2_jet_matched_pt->SetMarkerSize(2);
    h1_AK2_jet_matched_pt->SetMarkerColor(kBlue+1);

    TCanvas *c16 = new TCanvas("c16", "c16");
    c16->cd();
    c16->SetCanvasSize(1200, 1200);

    TPad *pad16 = new TPad("pad16", "pad16", 0, 0, 1, 1);
    pad16->SetLeftMargin(0.15);
    pad16->SetRightMargin(0.15);
    pad16->SetBottomMargin(0.15);
    pad16->SetTopMargin(0.15);
    pad16->SetLogy();
    pad16->SetTickx();
    pad16->SetTicky();
    pad16->Draw();
    pad16->cd();

    // Formatting
    auto xaxis16 = h1_AK2_jet_matched_pt->GetXaxis();
    xaxis16->SetTitle("p_{T}^{AK2 Jet} (GeV)");
    xaxis16->SetTitleFont(43);
    xaxis16->SetTitleSize(55);
    xaxis16->SetLabelFont(43);
    xaxis16->SetLabelSize(35);

    auto yaxis16 = h1_AK2_jet_matched_pt->GetYaxis();
    yaxis16->SetTitle("Events per bin");
    yaxis16->SetTitleFont(43);
    yaxis16->SetTitleSize(55);
    yaxis16->SetLabelFont(43);
    yaxis16->SetLabelSize(35);

    h1_AK2_jet_matched_pt->Draw("hist");

    c16->cd();
    c16->SaveAs("pdffiles/h1_AK2_jet_matched_pt.pdf");

    // AK4
    auto *h1_AK4_jet_matched_pt = f->Get<TH1D>("h1_AK4_jet_matched_pt");
    h1_AK4_jet_matched_pt->SetFillColor(kGreen+1);
    h1_AK4_jet_matched_pt->SetLineColor(kGreen+1);
    h1_AK4_jet_matched_pt->SetStats(0);
    h1_AK4_jet_matched_pt->SetTitle("");
    h1_AK4_jet_matched_pt->SetMarkerSize(2);
    h1_AK4_jet_matched_pt->SetMarkerColor(kGreen+1);

    TCanvas *c17 = new TCanvas("c17", "c17");
    c17->cd();
    c17->SetCanvasSize(1200, 1200);

    TPad *pad17 = new TPad("pad17", "pad17", 0, 0, 1, 1);
    pad17->SetLeftMargin(0.15);
    pad17->SetRightMargin(0.15);
    pad17->SetBottomMargin(0.15);
    pad17->SetTopMargin(0.15);
    pad17->SetLogy();
    pad17->SetTickx();
    pad17->SetTicky();
    pad17->Draw();
    pad17->cd();

    // Formatting
    auto xaxis17 = h1_AK4_jet_matched_pt->GetXaxis();
    xaxis17->SetTitle("p_{T}^{AK4 Jet} (GeV)");
    xaxis17->SetTitleFont(43);
    xaxis17->SetTitleSize(55);
    xaxis17->SetLabelFont(43);
    xaxis17->SetLabelSize(35);

    auto yaxis17 = h1_AK4_jet_matched_pt->GetYaxis();
    yaxis17->SetTitle("Events per bin");
    yaxis17->SetTitleFont(43);
    yaxis17->SetTitleSize(55);
    yaxis17->SetLabelFont(43);
    yaxis17->SetLabelSize(35);

    h1_AK4_jet_matched_pt->Draw("hist");

    c17->cd();
    c17->SaveAs("pdffiles/h1_AK4_jet_matched_pt.pdf");

    // AK6
    auto *h1_AK6_jet_matched_pt = f->Get<TH1D>("h1_AK6_jet_matched_pt");
    h1_AK6_jet_matched_pt->SetFillColor(kOrange+1);
    h1_AK6_jet_matched_pt->SetLineColor(kOrange+1);
    h1_AK6_jet_matched_pt->SetStats(0);
    h1_AK6_jet_matched_pt->SetTitle("");
    h1_AK6_jet_matched_pt->SetMarkerSize(2);
    h1_AK6_jet_matched_pt->SetMarkerColor(kOrange+1);

    TCanvas *c18 = new TCanvas("c18", "c18");
    c18->cd();
    c18->SetCanvasSize(1200, 1200);

    TPad *pad18 = new TPad("pad18", "pad18", 0, 0, 1, 1);
    pad18->SetLeftMargin(0.15);
    pad18->SetRightMargin(0.15);
    pad18->SetBottomMargin(0.15);
    pad18->SetTopMargin(0.15);
    pad18->SetLogy();
    pad18->SetTickx();
    pad18->SetTicky();
    pad18->Draw();
    pad18->cd();

    // Formatting
    auto xaxis18 = h1_AK6_jet_matched_pt->GetXaxis();
    xaxis18->SetTitle("p_{T}^{AK6 Jet} (GeV)");
    xaxis18->SetTitleFont(43);
    xaxis18->SetTitleSize(55);
    xaxis18->SetLabelFont(43);
    xaxis18->SetLabelSize(35);

    auto yaxis18 = h1_AK6_jet_matched_pt->GetYaxis();
    yaxis18->SetTitle("Events per bin");
    yaxis18->SetTitleFont(43);
    yaxis18->SetTitleSize(55);
    yaxis18->SetLabelFont(43);
    yaxis18->SetLabelSize(35);

    h1_AK6_jet_matched_pt->Draw("hist");

    c18->cd();
    c18->SaveAs("pdffiles/h1_AK6_jet_matched_pt.pdf");

    // AK8
    auto *h1_AK8_jet_matched_pt = f->Get<TH1D>("h1_AK8_jet_matched_pt");
    h1_AK8_jet_matched_pt->SetFillColor(kRed+1);
    h1_AK8_jet_matched_pt->SetLineColor(kRed+1);
    h1_AK8_jet_matched_pt->SetStats(0);
    h1_AK8_jet_matched_pt->SetTitle("");
    h1_AK8_jet_matched_pt->SetMarkerSize(2);
    h1_AK8_jet_matched_pt->SetMarkerColor(kRed+1);

    TCanvas *c19 = new TCanvas("c19", "c19");
    c19->cd();
    c19->SetCanvasSize(1200, 1200);

    TPad *pad19 = new TPad("pad19", "pad19", 0, 0, 1, 1);
    pad19->SetLeftMargin(0.15);
    pad19->SetRightMargin(0.15);
    pad19->SetBottomMargin(0.15);
    pad19->SetTopMargin(0.15);
    pad19->SetLogy();
    pad19->SetTickx();
    pad19->SetTicky();
    pad19->Draw();
    pad19->cd();

    // Formatting
    auto xaxis19 = h1_AK8_jet_matched_pt->GetXaxis();
    xaxis19->SetTitle("p_{T}^{AK8 Jet} (GeV)");
    xaxis19->SetTitleFont(43);
    xaxis19->SetTitleSize(55);
    xaxis19->SetLabelFont(43);
    xaxis19->SetLabelSize(35);

    auto yaxis19 = h1_AK8_jet_matched_pt->GetYaxis();
    yaxis19->SetTitle("Events per bin");
    yaxis19->SetTitleFont(43);
    yaxis19->SetTitleSize(55);
    yaxis19->SetLabelFont(43);
    yaxis19->SetLabelSize(35);

    h1_AK8_jet_matched_pt->Draw("hist");

    c19->cd();
    c19->SaveAs("pdffiles/h1_AK8_jet_matched_pt.pdf");

    // eta
    // AK2
    auto *h1_AK2_jet_matched_eta = f->Get<TH1D>("h1_AK2_jet_matched_eta");
    h1_AK2_jet_matched_eta->SetFillColor(kBlue+1);
    h1_AK2_jet_matched_eta->SetLineColor(kBlue+1);
    h1_AK2_jet_matched_eta->SetStats(0);
    h1_AK2_jet_matched_eta->SetTitle("");
    h1_AK2_jet_matched_eta->SetMarkerSize(2);
    h1_AK2_jet_matched_eta->SetMarkerColor(kBlue+1);

    TCanvas *c20 = new TCanvas("c20", "c20");
    c20->cd();
    c20->SetCanvasSize(1200, 1200);

    TPad *pad20 = new TPad("pad20", "pad20", 0, 0, 1, 1);
    pad20->SetLeftMargin(0.15);
    pad20->SetRightMargin(0.15);
    pad20->SetBottomMargin(0.15);
    pad20->SetTopMargin(0.15);
    pad20->SetTickx();
    pad20->SetTicky();
    pad20->Draw();
    pad20->cd();

    // Formatting
    auto xaxis20 = h1_AK2_jet_matched_eta->GetXaxis();
    xaxis20->SetTitle("p_{T}^{AK2 Jet} (GeV)");
    xaxis20->SetTitleFont(43);
    xaxis20->SetTitleSize(55);
    xaxis20->SetLabelFont(43);
    xaxis20->SetLabelSize(35);

    auto yaxis20 = h1_AK2_jet_matched_eta->GetYaxis();
    yaxis20->SetTitle("Events per bin");
    yaxis20->SetTitleFont(43);
    yaxis20->SetTitleSize(55);
    yaxis20->SetLabelFont(43);
    yaxis20->SetLabelSize(35);

    h1_AK2_jet_matched_eta->Draw("hist");

    c20->cd();
    c20->SaveAs("pdffiles/h1_AK2_jet_matched_eta.pdf");

    // AK4
    auto *h1_AK4_jet_matched_eta = f->Get<TH1D>("h1_AK4_jet_matched_eta");
    h1_AK4_jet_matched_eta->SetFillColor(kGreen+1);
    h1_AK4_jet_matched_eta->SetLineColor(kGreen+1);
    h1_AK4_jet_matched_eta->SetStats(0);
    h1_AK4_jet_matched_eta->SetTitle("");
    h1_AK4_jet_matched_eta->SetMarkerSize(2);
    h1_AK4_jet_matched_eta->SetMarkerColor(kGreen+1);

    TCanvas *c21 = new TCanvas("c21", "c21");
    c21->cd();
    c21->SetCanvasSize(1200, 1200);

    TPad *pad21 = new TPad("pad21", "pad21", 0, 0, 1, 1);
    pad21->SetLeftMargin(0.15);
    pad21->SetRightMargin(0.15);
    pad21->SetBottomMargin(0.15);
    pad21->SetTopMargin(0.15);
    pad21->SetTickx();
    pad21->SetTicky();
    pad21->Draw();
    pad21->cd();

    // Formatting
    auto xaxis21 = h1_AK4_jet_matched_eta->GetXaxis();
    xaxis21->SetTitle("p_{T}^{AK4 Jet} (GeV)");
    xaxis21->SetTitleFont(43);
    xaxis21->SetTitleSize(55);
    xaxis21->SetLabelFont(43);
    xaxis21->SetLabelSize(35);

    auto yaxis21 = h1_AK4_jet_matched_eta->GetYaxis();
    yaxis21->SetTitle("Events per bin");
    yaxis21->SetTitleFont(43);
    yaxis21->SetTitleSize(55);
    yaxis21->SetLabelFont(43);
    yaxis21->SetLabelSize(35);

    h1_AK4_jet_matched_eta->Draw("hist");

    c21->cd();
    c21->SaveAs("pdffiles/h1_AK4_jet_matched_eta.pdf");

    // AK6
    auto *h1_AK6_jet_matched_eta = f->Get<TH1D>("h1_AK6_jet_matched_eta");
    h1_AK6_jet_matched_eta->SetFillColor(kOrange+1);
    h1_AK6_jet_matched_eta->SetLineColor(kOrange+1);
    h1_AK6_jet_matched_eta->SetStats(0);
    h1_AK6_jet_matched_eta->SetTitle("");
    h1_AK6_jet_matched_eta->SetMarkerSize(2);
    h1_AK6_jet_matched_eta->SetMarkerColor(kOrange+1);

    TCanvas *c22 = new TCanvas("c22", "c22");
    c22->cd();
    c22->SetCanvasSize(1200, 1200);

    TPad *pad22 = new TPad("pad22", "pad22", 0, 0, 1, 1);
    pad22->SetLeftMargin(0.15);
    pad22->SetRightMargin(0.15);
    pad22->SetBottomMargin(0.15);
    pad22->SetTopMargin(0.15);
    pad22->SetTickx();
    pad22->SetTicky();
    pad22->Draw();
    pad22->cd();

    // Formatting
    auto xaxis22 = h1_AK6_jet_matched_eta->GetXaxis();
    xaxis22->SetTitle("p_{T}^{AK6 Jet} (GeV)");
    xaxis22->SetTitleFont(43);
    xaxis22->SetTitleSize(55);
    xaxis22->SetLabelFont(43);
    xaxis22->SetLabelSize(35);

    auto yaxis22 = h1_AK6_jet_matched_eta->GetYaxis();
    yaxis22->SetTitle("Events per bin");
    yaxis22->SetTitleFont(43);
    yaxis22->SetTitleSize(55);
    yaxis22->SetLabelFont(43);
    yaxis22->SetLabelSize(35);

    h1_AK6_jet_matched_eta->Draw("hist");

    c22->cd();
    c22->SaveAs("pdffiles/h1_AK6_jet_matched_eta.pdf");

    // AK8
    auto *h1_AK8_jet_matched_eta = f->Get<TH1D>("h1_AK8_jet_matched_eta");
    h1_AK8_jet_matched_eta->SetFillColor(kRed+1);
    h1_AK8_jet_matched_eta->SetLineColor(kRed+1);
    h1_AK8_jet_matched_eta->SetStats(0);
    h1_AK8_jet_matched_eta->SetTitle("");
    h1_AK8_jet_matched_eta->SetMarkerSize(2);
    h1_AK8_jet_matched_eta->SetMarkerColor(kRed+1);

    TCanvas *c23 = new TCanvas("c23", "c23");
    c23->cd();
    c23->SetCanvasSize(1200, 1200);

    TPad *pad23 = new TPad("pad23", "pad23", 0, 0, 1, 1);
    pad23->SetLeftMargin(0.15);
    pad23->SetRightMargin(0.15);
    pad23->SetBottomMargin(0.15);
    pad23->SetTopMargin(0.15);
    pad23->SetTickx();
    pad23->SetTicky();
    pad23->Draw();
    pad23->cd();

    // Formatting
    auto xaxis23 = h1_AK8_jet_matched_eta->GetXaxis();
    xaxis23->SetTitle("p_{T}^{AK8 Jet} (GeV)");
    xaxis23->SetTitleFont(43);
    xaxis23->SetTitleSize(55);
    xaxis23->SetLabelFont(43);
    xaxis23->SetLabelSize(35);

    auto yaxis23 = h1_AK8_jet_matched_eta->GetYaxis();
    yaxis23->SetTitle("Events per bin");
    yaxis23->SetTitleFont(43);
    yaxis23->SetTitleSize(55);
    yaxis23->SetLabelFont(43);
    yaxis23->SetLabelSize(35);

    h1_AK8_jet_matched_eta->Draw("hist");

    c23->cd();
    c23->SaveAs("pdffiles/h1_AK8_jet_matched_eta.pdf");

    // phi
    // AK2
    auto *h1_AK2_jet_matched_phi = f->Get<TH1D>("h1_AK2_jet_matched_phi");
    h1_AK2_jet_matched_phi->SetFillColor(kBlue+1);
    h1_AK2_jet_matched_phi->SetLineColor(kBlue+1);
    h1_AK2_jet_matched_phi->SetStats(0);
    h1_AK2_jet_matched_phi->SetTitle("");
    h1_AK2_jet_matched_phi->SetMarkerSize(2);
    h1_AK2_jet_matched_phi->SetMarkerColor(kBlue+1);

    TCanvas *c24 = new TCanvas("c24", "c24");
    c24->cd();
    c24->SetCanvasSize(1200, 1200);

    TPad *pad24 = new TPad("pad24", "pad24", 0, 0, 1, 1);
    pad24->SetLeftMargin(0.15);
    pad24->SetRightMargin(0.15);
    pad24->SetBottomMargin(0.15);
    pad24->SetTopMargin(0.15);
    pad24->SetTickx();
    pad24->SetTicky();
    pad24->Draw();
    pad24->cd();

    // Formatting
    auto xaxis24 = h1_AK2_jet_matched_phi->GetXaxis();
    xaxis24->SetTitle("p_{T}^{AK2 Jet} (GeV)");
    xaxis24->SetTitleFont(43);
    xaxis24->SetTitleSize(55);
    xaxis24->SetLabelFont(43);
    xaxis24->SetLabelSize(35);

    auto yaxis24 = h1_AK2_jet_matched_phi->GetYaxis();
    yaxis24->SetTitle("Events per bin");
    yaxis24->SetTitleFont(43);
    yaxis24->SetTitleSize(55);
    yaxis24->SetLabelFont(43);
    yaxis24->SetLabelSize(35);

    h1_AK2_jet_matched_phi->Draw("hist");

    c24->cd();
    c24->SaveAs("pdffiles/h1_AK2_jet_matched_phi.pdf");

    // AK4
    auto *h1_AK4_jet_matched_phi = f->Get<TH1D>("h1_AK4_jet_matched_phi");
    h1_AK4_jet_matched_phi->SetFillColor(kGreen+1);
    h1_AK4_jet_matched_phi->SetLineColor(kGreen+1);
    h1_AK4_jet_matched_phi->SetStats(0);
    h1_AK4_jet_matched_phi->SetTitle("");
    h1_AK4_jet_matched_phi->SetMarkerSize(2);
    h1_AK4_jet_matched_phi->SetMarkerColor(kGreen+1);

    TCanvas *c25 = new TCanvas("c25", "c25");
    c25->cd();
    c25->SetCanvasSize(1200, 1200);

    TPad *pad25 = new TPad("pad25", "pad25", 0, 0, 1, 1);
    pad25->SetLeftMargin(0.15);
    pad25->SetRightMargin(0.15);
    pad25->SetBottomMargin(0.15);
    pad25->SetTopMargin(0.15);
    pad25->SetTickx();
    pad25->SetTicky();
    pad25->Draw();
    pad25->cd();

    // Formatting
    auto xaxis25 = h1_AK4_jet_matched_phi->GetXaxis();
    xaxis25->SetTitle("p_{T}^{AK4 Jet} (GeV)");
    xaxis25->SetTitleFont(43);
    xaxis25->SetTitleSize(55);
    xaxis25->SetLabelFont(43);
    xaxis25->SetLabelSize(35);

    auto yaxis25 = h1_AK4_jet_matched_phi->GetYaxis();
    yaxis25->SetTitle("Events per bin");
    yaxis25->SetTitleFont(43);
    yaxis25->SetTitleSize(55);
    yaxis25->SetLabelFont(43);
    yaxis25->SetLabelSize(35);

    h1_AK4_jet_matched_phi->Draw("hist");

    c25->cd();
    c25->SaveAs("pdffiles/h1_AK4_jet_matched_phi.pdf");

    // AK6
    auto *h1_AK6_jet_matched_phi = f->Get<TH1D>("h1_AK6_jet_matched_phi");
    h1_AK6_jet_matched_phi->SetFillColor(kOrange+1);
    h1_AK6_jet_matched_phi->SetLineColor(kOrange+1);
    h1_AK6_jet_matched_phi->SetStats(0);
    h1_AK6_jet_matched_phi->SetTitle("");
    h1_AK6_jet_matched_phi->SetMarkerSize(2);
    h1_AK6_jet_matched_phi->SetMarkerColor(kOrange+1);

    TCanvas *c26 = new TCanvas("c26", "c26");
    c26->cd();
    c26->SetCanvasSize(1200, 1200);

    TPad *pad26 = new TPad("pad26", "pad26", 0, 0, 1, 1);
    pad26->SetLeftMargin(0.15);
    pad26->SetRightMargin(0.15);
    pad26->SetBottomMargin(0.15);
    pad26->SetTopMargin(0.15);
    pad26->SetTickx();
    pad26->SetTicky();
    pad26->Draw();
    pad26->cd();

    // Formatting
    auto xaxis26 = h1_AK6_jet_matched_phi->GetXaxis();
    xaxis26->SetTitle("p_{T}^{AK6 Jet} (GeV)");
    xaxis26->SetTitleFont(43);
    xaxis26->SetTitleSize(55);
    xaxis26->SetLabelFont(43);
    xaxis26->SetLabelSize(35);

    auto yaxis26 = h1_AK6_jet_matched_phi->GetYaxis();
    yaxis26->SetTitle("Events per bin");
    yaxis26->SetTitleFont(43);
    yaxis26->SetTitleSize(55);
    yaxis26->SetLabelFont(43);
    yaxis26->SetLabelSize(35);

    h1_AK6_jet_matched_phi->Draw("hist");

    c26->cd();
    c26->SaveAs("pdffiles/h1_AK6_jet_matched_phi.pdf");

    // AK8
    auto *h1_AK8_jet_matched_phi = f->Get<TH1D>("h1_AK8_jet_matched_phi");
    h1_AK8_jet_matched_phi->SetFillColor(kRed+1);
    h1_AK8_jet_matched_phi->SetLineColor(kRed+1);
    h1_AK8_jet_matched_phi->SetStats(0);
    h1_AK8_jet_matched_phi->SetTitle("");
    h1_AK8_jet_matched_phi->SetMarkerSize(2);
    h1_AK8_jet_matched_phi->SetMarkerColor(kRed+1);

    TCanvas *c27 = new TCanvas("c27", "c27");
    c27->cd();
    c27->SetCanvasSize(1200, 1200);

    TPad *pad27 = new TPad("pad27", "pad27", 0, 0, 1, 1);
    pad27->SetLeftMargin(0.15);
    pad27->SetRightMargin(0.15);
    pad27->SetBottomMargin(0.15);
    pad27->SetTopMargin(0.15);
    pad27->SetTickx();
    pad27->SetTicky();
    pad27->Draw();
    pad27->cd();

    // Formatting
    auto xaxis27 = h1_AK8_jet_matched_phi->GetXaxis();
    xaxis27->SetTitle("p_{T}^{AK8 Jet} (GeV)");
    xaxis27->SetTitleFont(43);
    xaxis27->SetTitleSize(55);
    xaxis27->SetLabelFont(43);
    xaxis27->SetLabelSize(35);

    auto yaxis27 = h1_AK8_jet_matched_phi->GetYaxis();
    yaxis27->SetTitle("Events per bin");
    yaxis27->SetTitleFont(43);
    yaxis27->SetTitleSize(55);
    yaxis27->SetLabelFont(43);
    yaxis27->SetLabelSize(35);

    h1_AK8_jet_matched_phi->Draw("hist");

    c27->cd();
    c27->SaveAs("pdffiles/h1_AK8_jet_matched_phi.pdf");

    // delR
    // AK2
    auto *h1_AK2_jet_matched_delR = f->Get<TH1D>("h1_AK2_jet_matched_delR");
    h1_AK2_jet_matched_delR->SetFillColor(kBlue+1);
    h1_AK2_jet_matched_delR->SetLineColor(kBlue+1);
    h1_AK2_jet_matched_delR->SetStats(0);
    h1_AK2_jet_matched_delR->SetTitle("");
    h1_AK2_jet_matched_delR->SetMarkerSize(2);
    h1_AK2_jet_matched_delR->SetMarkerColor(kBlue+1);

    TCanvas *c28 = new TCanvas("c28", "c28");
    c28->cd();
    c28->SetCanvasSize(1200, 1200);

    TPad *pad28 = new TPad("pad28", "pad28", 0, 0, 1, 1);
    pad28->SetLeftMargin(0.15);
    pad28->SetRightMargin(0.15);
    pad28->SetBottomMargin(0.15);
    pad28->SetTopMargin(0.15);
    pad28->SetTickx();
    pad28->SetTicky();
    pad28->Draw();
    pad28->cd();

    // Formatting
    auto xaxis28 = h1_AK2_jet_matched_delR->GetXaxis();
    xaxis28->SetTitle("p_{T}^{AK2 Jet} (GeV)");
    xaxis28->SetTitleFont(43);
    xaxis28->SetTitleSize(55);
    xaxis28->SetLabelFont(43);
    xaxis28->SetLabelSize(35);

    auto yaxis28 = h1_AK2_jet_matched_delR->GetYaxis();
    yaxis28->SetTitle("Events per bin");
    yaxis28->SetTitleFont(43);
    yaxis28->SetTitleSize(55);
    yaxis28->SetLabelFont(43);
    yaxis28->SetLabelSize(35);

    h1_AK2_jet_matched_delR->Draw("hist");

    c28->cd();
    c28->SaveAs("pdffiles/h1_AK2_jet_matched_delR.pdf");

    // AK4
    auto *h1_AK4_jet_matched_delR = f->Get<TH1D>("h1_AK4_jet_matched_delR");
    h1_AK4_jet_matched_delR->SetFillColor(kGreen+1);
    h1_AK4_jet_matched_delR->SetLineColor(kGreen+1);
    h1_AK4_jet_matched_delR->SetStats(0);
    h1_AK4_jet_matched_delR->SetTitle("");
    h1_AK4_jet_matched_delR->SetMarkerSize(2);
    h1_AK4_jet_matched_delR->SetMarkerColor(kGreen+1);

    TCanvas *c29 = new TCanvas("c29", "c29");
    c29->cd();
    c29->SetCanvasSize(1200, 1200);

    TPad *pad29 = new TPad("pad29", "pad29", 0, 0, 1, 1);
    pad29->SetLeftMargin(0.15);
    pad29->SetRightMargin(0.15);
    pad29->SetBottomMargin(0.15);
    pad29->SetTopMargin(0.15);
    pad29->SetTickx();
    pad29->SetTicky();
    pad29->Draw();
    pad29->cd();

    // Formatting
    auto xaxis29 = h1_AK4_jet_matched_delR->GetXaxis();
    xaxis29->SetTitle("p_{T}^{AK4 Jet} (GeV)");
    xaxis29->SetTitleFont(43);
    xaxis29->SetTitleSize(55);
    xaxis29->SetLabelFont(43);
    xaxis29->SetLabelSize(35);

    auto yaxis29 = h1_AK4_jet_matched_delR->GetYaxis();
    yaxis29->SetTitle("Events per bin");
    yaxis29->SetTitleFont(43);
    yaxis29->SetTitleSize(55);
    yaxis29->SetLabelFont(43);
    yaxis29->SetLabelSize(35);

    h1_AK4_jet_matched_delR->Draw("hist");

    c29->cd();
    c29->SaveAs("pdffiles/h1_AK4_jet_matched_delR.pdf");

    // AK6
    auto *h1_AK6_jet_matched_delR = f->Get<TH1D>("h1_AK6_jet_matched_delR");
    h1_AK6_jet_matched_delR->SetFillColor(kOrange+1);
    h1_AK6_jet_matched_delR->SetLineColor(kOrange+1);
    h1_AK6_jet_matched_delR->SetStats(0);
    h1_AK6_jet_matched_delR->SetTitle("");
    h1_AK6_jet_matched_delR->SetMarkerSize(2);
    h1_AK6_jet_matched_delR->SetMarkerColor(kOrange+1);

    TCanvas *c30 = new TCanvas("c30", "c30");
    c30->cd();
    c30->SetCanvasSize(1200, 1200);

    TPad *pad30 = new TPad("pad30", "pad30", 0, 0, 1, 1);
    pad30->SetLeftMargin(0.15);
    pad30->SetRightMargin(0.15);
    pad30->SetBottomMargin(0.15);
    pad30->SetTopMargin(0.15);
    pad30->SetTickx();
    pad30->SetTicky();
    pad30->Draw();
    pad30->cd();

    // Formatting
    auto xaxis30 = h1_AK6_jet_matched_delR->GetXaxis();
    xaxis30->SetTitle("p_{T}^{AK6 Jet} (GeV)");
    xaxis30->SetTitleFont(43);
    xaxis30->SetTitleSize(55);
    xaxis30->SetLabelFont(43);
    xaxis30->SetLabelSize(35);

    auto yaxis30 = h1_AK6_jet_matched_delR->GetYaxis();
    yaxis30->SetTitle("Events per bin");
    yaxis30->SetTitleFont(43);
    yaxis30->SetTitleSize(55);
    yaxis30->SetLabelFont(43);
    yaxis30->SetLabelSize(35);

    h1_AK6_jet_matched_delR->Draw("hist");

    c30->cd();
    c30->SaveAs("pdffiles/h1_AK6_jet_matched_delR.pdf");

    // AK8
    auto *h1_AK8_jet_matched_delR = f->Get<TH1D>("h1_AK8_jet_matched_delR");
    h1_AK8_jet_matched_delR->SetFillColor(kRed+1);
    h1_AK8_jet_matched_delR->SetLineColor(kRed+1);
    h1_AK8_jet_matched_delR->SetStats(0);
    h1_AK8_jet_matched_delR->SetTitle("");
    h1_AK8_jet_matched_delR->SetMarkerSize(2);
    h1_AK8_jet_matched_delR->SetMarkerColor(kRed+1);

    TCanvas *c31 = new TCanvas("c31", "c31");
    c31->cd();
    c31->SetCanvasSize(1200, 1200);

    TPad *pad31 = new TPad("pad31", "pad31", 0, 0, 1, 1);
    pad31->SetLeftMargin(0.15);
    pad31->SetRightMargin(0.15);
    pad31->SetBottomMargin(0.15);
    pad31->SetTopMargin(0.15);
    pad31->SetTickx();
    pad31->SetTicky();
    pad31->Draw();
    pad31->cd();

    // Formatting
    auto xaxis31 = h1_AK8_jet_matched_delR->GetXaxis();
    xaxis31->SetTitle("p_{T}^{AK8 Jet} (GeV)");
    xaxis31->SetTitleFont(43);
    xaxis31->SetTitleSize(55);
    xaxis31->SetLabelFont(43);
    xaxis31->SetLabelSize(35);

    auto yaxis31 = h1_AK8_jet_matched_delR->GetYaxis();
    yaxis31->SetTitle("Events per bin");
    yaxis31->SetTitleFont(43);
    yaxis31->SetTitleSize(55);
    yaxis31->SetLabelFont(43);
    yaxis31->SetLabelSize(35);

    h1_AK8_jet_matched_delR->Draw("hist");

    c31->cd();
    c31->SaveAs("pdffiles/h1_AK8_jet_matched_delR.pdf");

    // nMatchedJet

    // AK2
    auto *h1_AK2_nMatchedJet = f->Get<TH1D>("h1_AK2_nMatchedJet");
    h1_AK2_nMatchedJet->SetFillColor(kBlue+1);
    h1_AK2_nMatchedJet->SetLineColor(kBlue+1);
    h1_AK2_nMatchedJet->SetStats(0);
    h1_AK2_nMatchedJet->SetTitle("");
    h1_AK2_nMatchedJet->SetMarkerSize(2);
    h1_AK2_nMatchedJet->SetMarkerColor(kBlue+1);

    TCanvas *c32 = new TCanvas("c32", "c32");
    c32->cd();
    c32->SetCanvasSize(1200, 1200);

    TPad *pad32 = new TPad("pad32", "pad32", 0, 0, 1, 1);
    pad32->SetLeftMargin(0.15);
    pad32->SetRightMargin(0.15);
    pad32->SetBottomMargin(0.15);
    pad32->SetTopMargin(0.15);
    pad32->SetTickx();
    pad32->SetTicky();
    pad32->Draw();
    pad32->cd();

    // Formatting
    auto xaxis32 = h1_AK2_nMatchedJet->GetXaxis();
    xaxis32->SetTitle("Number of matched jets");
    xaxis32->SetTitleFont(43);
    xaxis32->SetTitleSize(55);
    xaxis32->SetLabelFont(43);
    xaxis32->SetLabelSize(35);
    xaxis32->SetBinLabel(1, "0");
    xaxis32->SetBinLabel(2, "1");
    xaxis32->SetBinLabel(3, "2");
    xaxis32->SetBinLabel(4, "3");
    xaxis32->SetBinLabel(5, "4");
    

    auto yaxis32 = h1_AK2_nMatchedJet->GetYaxis();
    yaxis32->SetTitle("Events per bin");
    yaxis32->SetTitleFont(43);
    yaxis32->SetTitleSize(55);
    yaxis32->SetLabelFont(43);
    yaxis32->SetLabelSize(35);

    h1_AK2_nMatchedJet->Draw("hist");

    c32->cd();
    c32->SaveAs("pdffiles/h1_AK2_nMatchedJet_perEvent.pdf");

    // AK4
    auto *h1_AK4_nMatchedJet = f->Get<TH1D>("h1_AK4_nMatchedJet");
    h1_AK4_nMatchedJet->SetFillColor(kGreen+1);
    h1_AK4_nMatchedJet->SetLineColor(kGreen+1);
    h1_AK4_nMatchedJet->SetStats(0);
    h1_AK4_nMatchedJet->SetTitle("");
    h1_AK4_nMatchedJet->SetMarkerSize(2);
    h1_AK4_nMatchedJet->SetMarkerColor(kGreen+1);

    TCanvas *c33 = new TCanvas("c33", "c33");
    c33->cd();
    c33->SetCanvasSize(1200, 1200);

    TPad *pad33 = new TPad("pad33", "pad33", 0, 0, 1, 1);
    pad33->SetLeftMargin(0.15);
    pad33->SetRightMargin(0.15);
    pad33->SetBottomMargin(0.15);
    pad33->SetTopMargin(0.15);
    pad33->SetTickx();
    pad33->SetTicky();
    pad33->Draw();
    pad33->cd();

    // Formatting
    auto xaxis33 = h1_AK4_nMatchedJet->GetXaxis();
    xaxis33->SetTitle("Number of matched jets");
    xaxis33->SetTitleFont(43);
    xaxis33->SetTitleSize(55);
    xaxis33->SetLabelFont(43);
    xaxis33->SetLabelSize(35);
    xaxis33->SetBinLabel(1, "0");
    xaxis33->SetBinLabel(2, "1");
    xaxis33->SetBinLabel(3, "2");
    xaxis33->SetBinLabel(4, "3");
    xaxis33->SetBinLabel(5, "4");

    auto yaxis33 = h1_AK4_nMatchedJet->GetYaxis();
    yaxis33->SetTitle("Events per bin");
    yaxis33->SetTitleFont(43);
    yaxis33->SetTitleSize(55);
    yaxis33->SetLabelFont(43);
    yaxis33->SetLabelSize(35);

    h1_AK4_nMatchedJet->Draw("hist");

    c33->cd();
    c33->SaveAs("pdffiles/h1_AK4_nMatchedJet_perEvent.pdf");

    // AK6
    auto *h1_AK6_nMatchedJet = f->Get<TH1D>("h1_AK6_nMatchedJet");
    h1_AK6_nMatchedJet->SetFillColor(kOrange+1);
    h1_AK6_nMatchedJet->SetLineColor(kOrange+1);
    h1_AK6_nMatchedJet->SetStats(0);
    h1_AK6_nMatchedJet->SetTitle("");
    h1_AK6_nMatchedJet->SetMarkerSize(2);
    h1_AK6_nMatchedJet->SetMarkerColor(kOrange+1);

    TCanvas *c34 = new TCanvas("c34", "c34");
    c34->cd();
    c34->SetCanvasSize(1200, 1200);

    TPad *pad34 = new TPad("pad34", "pad34", 0, 0, 1, 1);
    pad34->SetLeftMargin(0.15);
    pad34->SetRightMargin(0.15);
    pad34->SetBottomMargin(0.15);
    pad34->SetTopMargin(0.15);
    pad34->SetTickx();
    pad34->SetTicky();
    pad34->Draw();
    pad34->cd();

    // Formatting
    auto xaxis34 = h1_AK6_nMatchedJet->GetXaxis();
    xaxis34->SetTitle("Number of matched jets");
    xaxis34->SetTitleFont(43);
    xaxis34->SetTitleSize(55);
    xaxis34->SetLabelFont(43);
    xaxis34->SetLabelSize(35);
    xaxis34->SetBinLabel(1, "0");
    xaxis34->SetBinLabel(2, "1");
    xaxis34->SetBinLabel(3, "2");
    xaxis34->SetBinLabel(4, "3");
    xaxis34->SetBinLabel(5, "4");

    auto yaxis34 = h1_AK6_nMatchedJet->GetYaxis();
    yaxis34->SetTitle("Events per bin");
    yaxis34->SetTitleFont(43);
    yaxis34->SetTitleSize(55);
    yaxis34->SetLabelFont(43);
    yaxis34->SetLabelSize(35);

    h1_AK6_nMatchedJet->Draw("hist");

    c34->cd();
    c34->SaveAs("pdffiles/h1_AK6_nMatchedJet_perEvent.pdf");

    // AK8
    auto *h1_AK8_nMatchedJet = f->Get<TH1D>("h1_AK8_nMatchedJet");
    h1_AK8_nMatchedJet->SetFillColor(kRed+1);
    h1_AK8_nMatchedJet->SetLineColor(kRed+1);
    h1_AK8_nMatchedJet->SetStats(0);
    h1_AK8_nMatchedJet->SetTitle("");
    h1_AK8_nMatchedJet->SetMarkerSize(2);
    h1_AK8_nMatchedJet->SetMarkerColor(kRed+1);

    TCanvas *c35 = new TCanvas("c35", "c35");
    c35->cd();
    c35->SetCanvasSize(1200, 1200);

    TPad *pad35 = new TPad("pad35", "pad35", 0, 0, 1, 1);
    pad35->SetLeftMargin(0.15);
    pad35->SetRightMargin(0.15);
    pad35->SetBottomMargin(0.15);
    pad35->SetTopMargin(0.15);
    pad35->SetTickx();
    pad35->SetTicky();
    pad35->Draw();
    pad35->cd();

    // Formatting
    auto xaxis35 = h1_AK8_nMatchedJet->GetXaxis();
    xaxis35->SetTitle("Number of matched jets");
    xaxis35->SetTitleFont(43);
    xaxis35->SetTitleSize(55);
    xaxis35->SetLabelFont(43);
    xaxis35->SetLabelSize(35);
    xaxis35->SetBinLabel(1, "0");
    xaxis35->SetBinLabel(2, "1");
    xaxis35->SetBinLabel(3, "2");
    xaxis35->SetBinLabel(4, "3");
    xaxis35->SetBinLabel(5, "4");

    auto yaxis35 = h1_AK8_nMatchedJet->GetYaxis();
    yaxis35->SetTitle("Events per bin");
    yaxis35->SetTitleFont(43);
    yaxis35->SetTitleSize(55);
    yaxis35->SetLabelFont(43);
    yaxis35->SetLabelSize(35);

    h1_AK8_nMatchedJet->Draw("hist");

    c35->cd();
    c35->SaveAs("pdffiles/h1_AK8_nMatchedJet_perEvent.pdf");

    // nParton
    auto *h1_nParton = f->Get<TH1D>("h1_nParton");
    h1_nParton->SetFillColor(kCyan+1);
    h1_nParton->SetLineColor(kCyan+1);
    h1_nParton->SetStats(0);
    h1_nParton->SetTitle("");
    h1_nParton->SetMarkerSize(2);
    h1_nParton->SetMarkerColor(kCyan+1);
    h1_nParton->SetMinimum(0);

    TCanvas *c36 = new TCanvas("c36", "c36");
    c36->cd();
    c36->SetCanvasSize(1200, 1200);

    TPad *pad36 = new TPad("pad36", "pad36", 0, 0, 1, 1);
    pad36->SetLeftMargin(0.15);
    pad36->SetRightMargin(0.15);
    pad36->SetBottomMargin(0.15);
    pad36->SetTopMargin(0.15);
    pad36->SetTickx();
    pad36->SetTicky();
    pad36->Draw();
    pad36->cd();

    // Formatting
    auto xaxis36 = h1_nParton->GetXaxis();
    xaxis36->SetTitle("Number of partons");
    xaxis36->SetTitleFont(43);
    xaxis36->SetTitleSize(55);
    xaxis36->SetLabelFont(43);
    xaxis36->SetLabelSize(35);
    xaxis36->SetBinLabel(1, "0");
    xaxis36->SetBinLabel(2, "1");
    xaxis36->SetBinLabel(3, "2");

    auto yaxis36 = h1_nParton->GetYaxis();
    yaxis36->SetTitle("Events per bin");
    yaxis36->SetTitleFont(43);
    yaxis36->SetTitleSize(55);
    yaxis36->SetLabelFont(43);
    yaxis36->SetLabelSize(35);

    h1_nParton->Draw("hist");

    c36->cd();
    c36->SaveAs("pdffiles/h1_nParton_perEvent.pdf");

    // delR (projection)
    const int pt[6] = {10, 40, 50, 70, 100, 200};

    for (int i = 1; i < 6; i++) {
        // AK2
        string title_AK2 = "h1_AK2_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK2 = title_AK2.c_str();
        auto h1_AK2_project = f->Get<TH1D>(c_title_AK2);

        h1_AK2_project->SetFillColor(kBlue+1);
        h1_AK2_project->SetLineColor(kBlue+1);
        h1_AK2_project->SetStats(0);
        h1_AK2_project->SetTitle("");
        h1_AK2_project->SetMarkerSize(2);
        h1_AK2_project->SetMarkerColor(kBlue+1);

        TCanvas *c37 = new TCanvas("c37", "c37");
        c37->cd();
        c37->SetCanvasSize(1200, 1200);

        TPad *pad37 = new TPad("pad37", "pad37", 0, 0, 1, 1);
        pad37->SetLeftMargin(0.15);
        pad37->SetRightMargin(0.15);
        pad37->SetBottomMargin(0.15);
        pad37->SetTopMargin(0.15);
        pad37->SetTickx();
        pad37->SetTicky();
        pad37->Draw();
        pad37->cd();

        // Formatting
        auto xaxis37 = h1_AK2_project->GetXaxis();
        xaxis37->SetTitle("#Delta R");
        xaxis37->SetTitleFont(43);
        xaxis37->SetTitleSize(55);
        xaxis37->SetLabelFont(43);
        xaxis37->SetLabelSize(35);

        auto yaxis37 = h1_AK2_project->GetYaxis();
        yaxis37->SetTitle("AK2 jets per bin");
        yaxis37->SetTitleFont(43);
        yaxis37->SetTitleSize(55);
        yaxis37->SetLabelFont(43);
        yaxis37->SetLabelSize(35);

        h1_AK2_project->Draw("hist");

        c37->cd();
        TLatex *latex37 = new TLatex();
        latex37->SetNDC();
        latex37->SetTextFont(42);
        latex37->SetTextSize(0.03);
        latex37->SetTextColor(1);
        latex37->SetTextAlign(12);
        string text37 = std::to_string(pt[i-1]) + "GeV < p_{T} < " + std::to_string(pt[i]) + "GeV";
        auto c_text37 = text37.c_str();
        latex37->DrawLatex(0.53, 0.78, c_text37);
        
        string outFile_AK2 = "pdffiles/h1_AK2_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_outFile_AK2 = outFile_AK2.c_str();
        c37->cd();
        c37->SaveAs(c_outFile_AK2);

        // AK4
        string title_AK4 = "h1_AK4_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK4 = title_AK4.c_str();
        auto h1_AK4_project = f->Get<TH1D>(c_title_AK4);

        h1_AK4_project->SetFillColor(kGreen+1);
        h1_AK4_project->SetLineColor(kGreen+1);
        h1_AK4_project->SetStats(0);
        h1_AK4_project->SetTitle("");
        h1_AK4_project->SetMarkerSize(2);
        h1_AK4_project->SetMarkerColor(kGreen+1);

        TCanvas *c38 = new TCanvas("c38", "c38");
        c38->cd();
        c38->SetCanvasSize(1200, 1200);

        TPad *pad38 = new TPad("pad38", "pad38", 0, 0, 1, 1);
        pad38->SetLeftMargin(0.15);
        pad38->SetRightMargin(0.15);
        pad38->SetBottomMargin(0.15);
        pad38->SetTopMargin(0.15);
        pad38->SetTickx();
        pad38->SetTicky();
        pad38->Draw();
        pad38->cd();

        // Formatting
        auto xaxis38 = h1_AK4_project->GetXaxis();
        xaxis38->SetTitle("#Delta R");
        xaxis38->SetTitleFont(43);
        xaxis38->SetTitleSize(55);
        xaxis38->SetLabelFont(43);
        xaxis38->SetLabelSize(35);

        auto yaxis38 = h1_AK4_project->GetYaxis();
        yaxis38->SetTitle("AK4 jets per bin");
        yaxis38->SetTitleFont(43);
        yaxis38->SetTitleSize(55);
        yaxis38->SetLabelFont(43);
        yaxis38->SetLabelSize(35);

        h1_AK4_project->Draw("hist");

        c38->cd();
        TLatex *latex38 = new TLatex();
        latex38->SetNDC();
        latex38->SetTextFont(42);
        latex38->SetTextSize(0.03);
        latex38->SetTextColor(1);
        latex38->SetTextAlign(12);
        string text38 = std::to_string(pt[i-1]) + "GeV < p_{T} < " + std::to_string(pt[i]) + "GeV";
        auto c_text38 = text38.c_str();
        latex38->DrawLatex(0.53, 0.78, c_text38);
        
        string outFile_AK4 = "pdffiles/h1_AK4_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_outFile_AK4 = outFile_AK4.c_str();
        c38->cd();
        c38->SaveAs(c_outFile_AK4);

        // AK6
        string title_AK6 = "h1_AK6_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK6 = title_AK6.c_str();
        auto h1_AK6_project = f->Get<TH1D>(c_title_AK6);

        h1_AK6_project->SetFillColor(kOrange+1);
        h1_AK6_project->SetLineColor(kOrange+1);
        h1_AK6_project->SetStats(0);
        h1_AK6_project->SetTitle("");
        h1_AK6_project->SetMarkerSize(2);
        h1_AK6_project->SetMarkerColor(kOrange+1);

        TCanvas *c39 = new TCanvas("c39", "c39");
        c39->cd();
        c39->SetCanvasSize(1200, 1200);

        TPad *pad39 = new TPad("pad39", "pad39", 0, 0, 1, 1);
        pad39->SetLeftMargin(0.15);
        pad39->SetRightMargin(0.15);
        pad39->SetBottomMargin(0.15);
        pad39->SetTopMargin(0.15);
        pad39->SetTickx();
        pad39->SetTicky();
        pad39->Draw();
        pad39->cd();

        // Formatting
        auto xaxis39 = h1_AK6_project->GetXaxis();
        xaxis39->SetTitle("#Delta R");
        xaxis39->SetTitleFont(43);
        xaxis39->SetTitleSize(55);
        xaxis39->SetLabelFont(43);
        xaxis39->SetLabelSize(35);

        auto yaxis39 = h1_AK6_project->GetYaxis();
        yaxis39->SetTitle("AK6 jets per bin");
        yaxis39->SetTitleFont(43);
        yaxis39->SetTitleSize(55);
        yaxis39->SetLabelFont(43);
        yaxis39->SetLabelSize(35);

        h1_AK6_project->Draw("hist");
        
        c39->cd();
        TLatex *latex39 = new TLatex();
        latex39->SetNDC();
        latex39->SetTextFont(42);
        latex39->SetTextSize(0.03);
        latex39->SetTextColor(1);
        latex39->SetTextAlign(12);
        string text39 = std::to_string(pt[i-1]) + "GeV < p_{T} < " + std::to_string(pt[i]) + "GeV";
        auto c_text39 = text39.c_str();
        latex39->DrawLatex(0.53, 0.78, c_text39);

        string outFile_AK6 = "pdffiles/h1_AK6_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_outFile_AK6 = outFile_AK6.c_str();
        c39->cd();
        c39->SaveAs(c_outFile_AK6);

        // AK8
        string title_AK8 = "h1_AK8_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK8 = title_AK8.c_str();
        auto h1_AK8_project = f->Get<TH1D>(c_title_AK8);

        h1_AK8_project->SetFillColor(kRed+1);
        h1_AK8_project->SetLineColor(kRed+1);
        h1_AK8_project->SetStats(0);
        h1_AK8_project->SetTitle("");
        h1_AK8_project->SetMarkerSize(2);
        h1_AK8_project->SetMarkerColor(kRed+1);

        TCanvas *c40 = new TCanvas("c40", "c40");
        c40->cd();
        c40->SetCanvasSize(1200, 1200);

        TPad *pad40 = new TPad("pad40", "pad40", 0, 0, 1, 1);
        pad40->SetLeftMargin(0.15);
        pad40->SetRightMargin(0.15);
        pad40->SetBottomMargin(0.15);
        pad40->SetTopMargin(0.15);
        pad40->SetTickx();
        pad40->SetTicky();
        pad40->Draw();
        pad40->cd();

        // Formatting
        auto xaxis40 = h1_AK8_project->GetXaxis();
        xaxis40->SetTitle("#Delta R");
        xaxis40->SetTitleFont(43);
        xaxis40->SetTitleSize(55);
        xaxis40->SetLabelFont(43);
        xaxis40->SetLabelSize(35);

        auto yaxis40 = h1_AK8_project->GetYaxis();
        yaxis40->SetTitle("AK8 jets per bin");
        yaxis40->SetTitleFont(43);
        yaxis40->SetTitleSize(55);
        yaxis40->SetLabelFont(43);
        yaxis40->SetLabelSize(35);

        h1_AK8_project->Draw("hist");

        c40->cd();
        TLatex *latex40 = new TLatex();
        latex40->SetNDC();
        latex40->SetTextFont(42);
        latex40->SetTextSize(0.03);
        latex40->SetTextColor(1);
        latex40->SetTextAlign(12);
        string text40 = std::to_string(pt[i-1]) + "GeV < p_{T} < " + std::to_string(pt[i]) + "GeV";
        auto c_text40 = text40.c_str();
        latex40->DrawLatex(0.53, 0.78, c_text40);
        
        string outFile_AK8 = "pdffiles/h1_AK8_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_outFile_AK8 = outFile_AK8.c_str();
        c40->cd();
        c40->SaveAs(c_outFile_AK8);
    }

    // Matched parton
    auto *h1_parton_matched_pt = f->Get<TH1D>("h1_parton_matched_pt");
    h1_parton_matched_pt->SetFillColor(kCyan+1);
    h1_parton_matched_pt->SetLineColor(kCyan+1);
    h1_parton_matched_pt->SetStats(0);
    h1_parton_matched_pt->SetTitle("");
    h1_parton_matched_pt->SetMarkerSize(2);
    h1_parton_matched_pt->SetMarkerColor(kCyan+1);

    TCanvas *c41 = new TCanvas("c41", "c41");
    c41->cd();
    c41->SetCanvasSize(1200, 1200);

    TPad *pad41 = new TPad("pad41", "pad41", 0, 0, 1, 1);
    pad41->SetLeftMargin(0.15);
    pad41->SetRightMargin(0.15);
    pad41->SetBottomMargin(0.15);
    pad41->SetTopMargin(0.15);
    pad41->SetLogy();
    pad41->SetTickx();
    pad41->SetTicky();
    pad41->Draw();
    pad41->cd();

    // Formatting
    auto xaxis41 = h1_parton_matched_pt->GetXaxis();
    xaxis41->SetTitle("p_{T}^{Parton} (GeV)");
    xaxis41->SetTitleFont(43);
    xaxis41->SetTitleSize(55);
    xaxis41->SetLabelFont(43);
    xaxis41->SetLabelSize(35);

    auto yaxis41 = h1_parton_matched_pt->GetYaxis();
    yaxis41->SetTitle("Events per bin");
    yaxis41->SetTitleFont(43);
    yaxis41->SetTitleSize(55);
    yaxis41->SetLabelFont(43);
    yaxis41->SetLabelSize(35);

    h1_parton_matched_pt->Draw("hist");

    c41->cd();
    c41->SaveAs("pdffiles/h1_parton_matched_pt.pdf");

    auto *h1_parton_matched_eta = f->Get<TH1D>("h1_parton_matched_eta");
    h1_parton_matched_eta->SetFillColor(kCyan+1);
    h1_parton_matched_eta->SetLineColor(kCyan+1);
    h1_parton_matched_eta->SetStats(0);
    h1_parton_matched_eta->SetTitle("");
    h1_parton_matched_eta->SetMarkerSize(2);
    h1_parton_matched_eta->SetMarkerColor(kCyan+1);
    h1_parton_matched_eta->SetMinimum(0);

    TCanvas *c42 = new TCanvas("c42", "c42");
    c42->cd();
    c42->SetCanvasSize(1200, 1200);

    TPad *pad42 = new TPad("pad42", "pad42", 0, 0, 1, 1);
    pad42->SetLeftMargin(0.15);
    pad42->SetRightMargin(0.15);
    pad42->SetBottomMargin(0.15);
    pad42->SetTopMargin(0.15);
    pad42->SetTickx();
    pad42->SetTicky();
    pad42->Draw();
    pad42->cd();

    // Formatting
    auto xaxis42 = h1_parton_matched_eta->GetXaxis();
    xaxis42->SetTitle("#eta^{Parton} (GeV)");
    xaxis42->SetTitleFont(43);
    xaxis42->SetTitleSize(55);
    xaxis42->SetLabelFont(43);
    xaxis42->SetLabelSize(35);

    auto yaxis42 = h1_parton_matched_eta->GetYaxis();
    yaxis42->SetTitle("Events per bin");
    yaxis42->SetTitleFont(43);
    yaxis42->SetTitleSize(55);
    yaxis42->SetLabelFont(43);
    yaxis42->SetLabelSize(35);

    h1_parton_matched_eta->Draw("hist");

    c42->cd();
    c42->SaveAs("pdffiles/h1_parton_matched_eta.pdf");

    auto *h1_parton_matched_phi = f->Get<TH1D>("h1_parton_matched_phi");
    h1_parton_matched_phi->SetFillColor(kCyan+1);
    h1_parton_matched_phi->SetLineColor(kCyan+1);
    h1_parton_matched_phi->SetStats(0);
    h1_parton_matched_phi->SetTitle("");
    h1_parton_matched_phi->SetMarkerSize(2);
    h1_parton_matched_phi->SetMarkerColor(kCyan+1);
    h1_parton_matched_phi->SetMinimum(0);

    TCanvas *c43 = new TCanvas("c43", "c43");
    c43->cd();
    c43->SetCanvasSize(1200, 1200);

    TPad *pad43 = new TPad("pad43", "pad43", 0, 0, 1, 1);
    pad43->SetLeftMargin(0.15);
    pad43->SetRightMargin(0.15);
    pad43->SetBottomMargin(0.15);
    pad43->SetTopMargin(0.15);
    pad43->SetTickx();
    pad43->SetTicky();
    pad43->Draw();
    pad43->cd();

    // Formatting
    auto xaxis43 = h1_parton_matched_phi->GetXaxis();
    xaxis43->SetTitle("#eta^{Parton} (GeV)");
    xaxis43->SetTitleFont(43);
    xaxis43->SetTitleSize(55);
    xaxis43->SetLabelFont(43);
    xaxis43->SetLabelSize(35);

    auto yaxis43 = h1_parton_matched_phi->GetYaxis();
    yaxis43->SetTitle("Events per bin");
    yaxis43->SetTitleFont(43);
    yaxis43->SetTitleSize(55);
    yaxis43->SetLabelFont(43);
    yaxis43->SetLabelSize(35);

    h1_parton_matched_phi->Draw("hist");

    c43->cd();
    c43->SaveAs("pdffiles/h1_parton_matched_phi.pdf");

    // Jet width

    // AK2
    auto *h1_AK2_jet_matched_lambda11 = f->Get<TH1D>("h1_AK2_jet_matched_lambda11");
    h1_AK2_jet_matched_lambda11->SetFillColor(kBlue+1);
    h1_AK2_jet_matched_lambda11->SetLineColor(kBlue+1);
    h1_AK2_jet_matched_lambda11->SetStats(0);
    h1_AK2_jet_matched_lambda11->SetTitle("");
    h1_AK2_jet_matched_lambda11->SetMarkerSize(2);
    h1_AK2_jet_matched_lambda11->SetMarkerColor(kBlue+1);
    h1_AK2_jet_matched_lambda11->SetMinimum(0);

    TCanvas *c44 = new TCanvas("c44", "c44");
    c44->cd();
    c44->SetCanvasSize(1200, 1200);

    TPad *pad44 = new TPad("pad44", "pad44", 0, 0, 1, 1);
    pad44->SetLeftMargin(0.15);
    pad44->SetRightMargin(0.15);
    pad44->SetBottomMargin(0.15);
    pad44->SetTopMargin(0.15);
    pad44->SetTickx();
    pad44->SetTicky();
    pad44->Draw();
    pad44->cd();

    // Formatting
    auto xaxis44 = h1_AK2_jet_matched_lambda11->GetXaxis();
    xaxis44->SetTitle("#lambda^{1}_{1}");
    xaxis44->SetTitleFont(43);
    xaxis44->SetTitleSize(55);
    xaxis44->SetLabelFont(43);
    xaxis44->SetLabelSize(35);

    auto yaxis44 = h1_AK2_jet_matched_lambda11->GetYaxis();
    yaxis44->SetTitle("AK2 jets per bin");
    yaxis44->SetTitleFont(43);
    yaxis44->SetTitleSize(55);
    yaxis44->SetLabelFont(43);
    yaxis44->SetLabelSize(35);

    h1_AK2_jet_matched_lambda11->Draw("hist");

    c44->cd();
    c44->SaveAs("pdffiles/h1_AK2_jet_matched_lambda11.pdf");

    // AK4
    auto *h1_AK4_jet_matched_lambda11 = f->Get<TH1D>("h1_AK4_jet_matched_lambda11");
    h1_AK4_jet_matched_lambda11->SetFillColor(kGreen+1);
    h1_AK4_jet_matched_lambda11->SetLineColor(kGreen+1);
    h1_AK4_jet_matched_lambda11->SetStats(0);
    h1_AK4_jet_matched_lambda11->SetTitle("");
    h1_AK4_jet_matched_lambda11->SetMarkerSize(2);
    h1_AK4_jet_matched_lambda11->SetMarkerColor(kGreen+1);
    h1_AK4_jet_matched_lambda11->SetMinimum(0);

    TCanvas *c45 = new TCanvas("c45", "c45");
    c45->cd();
    c45->SetCanvasSize(1200, 1200);

    TPad *pad45 = new TPad("pad45", "pad45", 0, 0, 1, 1);
    pad45->SetLeftMargin(0.15);
    pad45->SetRightMargin(0.15);
    pad45->SetBottomMargin(0.15);
    pad45->SetTopMargin(0.15);
    pad45->SetTickx();
    pad45->SetTicky();
    pad45->Draw();
    pad45->cd();

    // Formatting
    auto xaxis45 = h1_AK4_jet_matched_lambda11->GetXaxis();
    xaxis45->SetTitle("#lambda^{1}_{1}");
    xaxis45->SetTitleFont(43);
    xaxis45->SetTitleSize(55);
    xaxis45->SetLabelFont(43);
    xaxis45->SetLabelSize(35);

    auto yaxis45 = h1_AK4_jet_matched_lambda11->GetYaxis();
    yaxis45->SetTitle("AK4 jets per bin");
    yaxis45->SetTitleFont(43);
    yaxis45->SetTitleSize(55);
    yaxis45->SetLabelFont(43);
    yaxis45->SetLabelSize(35);

    h1_AK4_jet_matched_lambda11->Draw("hist");

    c45->cd();
    c45->SaveAs("pdffiles/h1_AK4_jet_matched_lambda11.pdf");

    // AK6
    auto *h1_AK6_jet_matched_lambda11 = f->Get<TH1D>("h1_AK6_jet_matched_lambda11");
    h1_AK6_jet_matched_lambda11->SetFillColor(kOrange+1);
    h1_AK6_jet_matched_lambda11->SetLineColor(kOrange+1);
    h1_AK6_jet_matched_lambda11->SetStats(0);
    h1_AK6_jet_matched_lambda11->SetTitle("");
    h1_AK6_jet_matched_lambda11->SetMarkerSize(2);
    h1_AK6_jet_matched_lambda11->SetMarkerColor(kOrange+1);
    h1_AK6_jet_matched_lambda11->SetMinimum(0);

    TCanvas *c46 = new TCanvas("c46", "c46");
    c46->cd();
    c46->SetCanvasSize(1200, 1200);

    TPad *pad46 = new TPad("pad46", "pad46", 0, 0, 1, 1);
    pad46->SetLeftMargin(0.15);
    pad46->SetRightMargin(0.15);
    pad46->SetBottomMargin(0.15);
    pad46->SetTopMargin(0.15);
    pad46->SetTickx();
    pad46->SetTicky();
    pad46->Draw();
    pad46->cd();

    // Formatting
    auto xaxis46 = h1_AK6_jet_matched_lambda11->GetXaxis();
    xaxis46->SetTitle("#lambda^{1}_{1}");
    xaxis46->SetTitleFont(43);
    xaxis46->SetTitleSize(55);
    xaxis46->SetLabelFont(43);
    xaxis46->SetLabelSize(35);

    auto yaxis46 = h1_AK6_jet_matched_lambda11->GetYaxis();
    yaxis46->SetTitle("AK6 jets per bin");
    yaxis46->SetTitleFont(43);
    yaxis46->SetTitleSize(55);
    yaxis46->SetLabelFont(43);
    yaxis46->SetLabelSize(35);

    h1_AK6_jet_matched_lambda11->Draw("hist");

    c46->cd();
    c46->SaveAs("pdffiles/h1_AK6_jet_matched_lambda11.pdf");

    // AK8
    auto *h1_AK8_jet_matched_lambda11 = f->Get<TH1D>("h1_AK8_jet_matched_lambda11");
    h1_AK8_jet_matched_lambda11->SetFillColor(kRed+1);
    h1_AK8_jet_matched_lambda11->SetLineColor(kRed+1);
    h1_AK8_jet_matched_lambda11->SetStats(0);
    h1_AK8_jet_matched_lambda11->SetTitle("");
    h1_AK8_jet_matched_lambda11->SetMarkerSize(2);
    h1_AK8_jet_matched_lambda11->SetMarkerColor(kRed+1);
    h1_AK8_jet_matched_lambda11->SetMinimum(0);

    TCanvas *c47 = new TCanvas("c47", "c47");
    c47->cd();
    c47->SetCanvasSize(1200, 1200);

    TPad *pad47 = new TPad("pad47", "pad47", 0, 0, 1, 1);
    pad47->SetLeftMargin(0.15);
    pad47->SetRightMargin(0.15);
    pad47->SetBottomMargin(0.15);
    pad47->SetTopMargin(0.15);
    pad47->SetTickx();
    pad47->SetTicky();
    pad47->Draw();
    pad47->cd();

    // Formatting
    auto xaxis47 = h1_AK8_jet_matched_lambda11->GetXaxis();
    xaxis47->SetTitle("#lambda^{1}_{1}");
    xaxis47->SetTitleFont(43);
    xaxis47->SetTitleSize(55);
    xaxis47->SetLabelFont(43);
    xaxis47->SetLabelSize(35);

    auto yaxis47 = h1_AK8_jet_matched_lambda11->GetYaxis();
    yaxis47->SetTitle("AK8 jets per bin");
    yaxis47->SetTitleFont(43);
    yaxis47->SetTitleSize(55);
    yaxis47->SetLabelFont(43);
    yaxis47->SetLabelSize(35);

    h1_AK8_jet_matched_lambda11->Draw("hist");

    c47->cd();
    c47->SaveAs("pdffiles/h1_AK8_jet_matched_lambda11.pdf");
}