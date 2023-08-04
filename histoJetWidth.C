#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void histoJetWidth() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame df("matched_jets", "rootfiles/matched_jets.root");

    const double ptbins[6] = {10., 40., 50., 70., 100., 200.};
    const int pt[6] = {10, 40, 50, 70, 100, 200};

    // ---------
    // Delta pT
    // ---------

    ROOT::RDF::TH2DModel model_AK2_lambda11("h2_AK2_lambda11", "", 100, 0., 1., 5, ptbins);
    ROOT::RDF::TH2DModel model_AK4_lambda11("h2_AK4_lambda11", "", 100, 0., 1., 5, ptbins);
    ROOT::RDF::TH2DModel model_AK6_lambda11("h2_AK6_lambda11", "", 100, 0., 1., 5, ptbins);
    ROOT::RDF::TH2DModel model_AK8_lambda11("h2_AK8_lambda11", "", 100, 0., 1., 5, ptbins);

    auto h2_AK2_lambda11 = df.Histo2D(model_AK2_lambda11, "AK2_jet_all_matched_lambda11", "AK2_jet_all_matched_pt");
    auto h2_AK4_lambda11 = df.Histo2D(model_AK4_lambda11, "AK4_jet_all_matched_lambda11", "AK4_jet_all_matched_pt");
    auto h2_AK6_lambda11 = df.Histo2D(model_AK6_lambda11, "AK6_jet_all_matched_lambda11", "AK6_jet_all_matched_pt");
    auto h2_AK8_lambda11 = df.Histo2D(model_AK8_lambda11, "AK8_jet_all_matched_lambda11", "AK8_jet_all_matched_pt");

    // AK2
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK2 = "h1_AK2_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK2 = title_AK2.c_str();
        auto h1_AK2_lambda11 = h2_AK2_lambda11->ProjectionX(c_title_AK2, i, i);

        h1_AK2_lambda11->SetStats(0);
        h1_AK2_lambda11->SetFillColor(kBlue+1);
        h1_AK2_lambda11->SetLineColor(kBlue+1);
        h1_AK2_lambda11->SetTitle("");
        h1_AK2_lambda11->SetMarkerSize(2);
        h1_AK2_lambda11->SetMarkerColor(kBlue+1);

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
        auto xaxis1 = h1_AK2_lambda11->GetXaxis();
        xaxis1->SetTitle("#lambda^{1}_{1, AK2}");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK2_lambda11->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK2_lambda11->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK2 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.17, 0.88, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK2_lambda11->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.6, 0.93, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK2_lambda11->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.6, 0.88, c_text3);

        string output_AK2 = "pdffiles/h1_AK2_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK2 = output_AK2.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK2);
    }

    // AK4
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK4 = "h1_AK4_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK4 = title_AK4.c_str();
        auto h1_AK4_lambda11 = h2_AK4_lambda11->ProjectionX(c_title_AK4, i, i);

        h1_AK4_lambda11->SetStats(0);
        h1_AK4_lambda11->SetFillColor(kGreen+1);
        h1_AK4_lambda11->SetLineColor(kGreen+1);
        h1_AK4_lambda11->SetTitle("");
        h1_AK4_lambda11->SetMarkerSize(2);
        h1_AK4_lambda11->SetMarkerColor(kGreen+1);

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
        auto xaxis1 = h1_AK4_lambda11->GetXaxis();
        xaxis1->SetTitle("#lambda^{1}_{1, AK2}");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK4_lambda11->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK4_lambda11->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK4 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.17, 0.88, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK4_lambda11->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.6, 0.93, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK4_lambda11->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.6, 0.88, c_text3);

        string output_AK4 = "pdffiles/h1_AK4_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK4 = output_AK4.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK4);
    }

    // AK6
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK6 = "h1_AK6_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK6 = title_AK6.c_str();
        auto h1_AK6_lambda11 = h2_AK6_lambda11->ProjectionX(c_title_AK6, i, i);

        h1_AK6_lambda11->SetStats(0);
        h1_AK6_lambda11->SetFillColor(kOrange+1);
        h1_AK6_lambda11->SetLineColor(kOrange+1);
        h1_AK6_lambda11->SetTitle("");
        h1_AK6_lambda11->SetMarkerSize(2);
        h1_AK6_lambda11->SetMarkerColor(kOrange+1);

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
        auto xaxis1 = h1_AK6_lambda11->GetXaxis();
        xaxis1->SetTitle("#lambda^{1}_{1, AK2}");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK6_lambda11->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK6_lambda11->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK6 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.17, 0.88, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK6_lambda11->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.6, 0.93, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK6_lambda11->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.6, 0.88, c_text3);

        string output_AK6 = "pdffiles/h1_AK6_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK6 = output_AK6.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK6);
    }

    // AK8
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK8 = "h1_AK8_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK8 = title_AK8.c_str();
        auto h1_AK8_lambda11 = h2_AK8_lambda11->ProjectionX(c_title_AK8, i, i);

        h1_AK8_lambda11->SetStats(0);
        h1_AK8_lambda11->SetFillColor(kRed+1);
        h1_AK8_lambda11->SetLineColor(kRed+1);
        h1_AK8_lambda11->SetTitle("");
        h1_AK8_lambda11->SetMarkerSize(2);
        h1_AK8_lambda11->SetMarkerColor(kRed+1);

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
        auto xaxis1 = h1_AK8_lambda11->GetXaxis();
        xaxis1->SetTitle("#lambda^{1}_{1, AK2}");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK8_lambda11->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK8_lambda11->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK8 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.17, 0.88, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK8_lambda11->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.6, 0.93, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK8_lambda11->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.6, 0.88, c_text3);

        string output_AK8 = "pdffiles/h1_AK8_lambda11_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK8 = output_AK8.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK8);
    }
}