#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void histoJetPtEtaPhi() {
    TFile *f = new TFile("rootfiles/Histo_Jet_PtEtaPhi.root");

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
    h1_AK2_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

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
    h1_AK4_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

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
    h1_AK6_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

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
    h1_AK8_jet_pt->GetXaxis()->SetRangeUser(0., 20.);

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
}