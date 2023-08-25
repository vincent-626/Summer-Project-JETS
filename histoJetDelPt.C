#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void histoJetDelPt() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame rdf("matched_jets", "rootfiles/matched_jets.root");

    auto df = rdf.Define("AK4_Delta_pt", "AK4_jet_all_matched_pt - AK2_jet_all_matched_pt")
                    .Define("AK6_Delta_pt", "AK6_jet_all_matched_pt - AK4_jet_all_matched_pt")
                    .Define("AK8_Delta_pt", "AK8_jet_all_matched_pt - AK6_jet_all_matched_pt")
                    .Define("AK4_Percent_pt", "100*AK4_Delta_pt/AK2_jet_all_matched_pt")
                    .Define("AK6_Percent_pt", "100*AK6_Delta_pt/AK4_jet_all_matched_pt")
                    .Define("AK8_Percent_pt", "100*AK8_Delta_pt/AK6_jet_all_matched_pt");

    const double ptbins[6] = {0., 10., 20., 40., 60., 200.};
    const int pt[6] = {0, 10, 20, 40, 60, 200};

    // ---------
    // Delta pT
    // ---------

    ROOT::RDF::TH2DModel model_AK4_Delta_pt("h2_AK4_Delta_pt", "", 200, 0., 20., 5, ptbins);
    ROOT::RDF::TH2DModel model_AK6_Delta_pt("h2_AK6_Delta_pt", "", 200, 0., 20., 5, ptbins);
    ROOT::RDF::TH2DModel model_AK8_Delta_pt("h2_AK8_Delta_pt", "", 200, 0., 20., 5, ptbins);

    auto h2_AK4_Delta_pt = df.Histo2D(model_AK4_Delta_pt, "AK4_Delta_pt", "AK4_jet_all_matched_pt");
    auto h2_AK6_Delta_pt = df.Histo2D(model_AK6_Delta_pt, "AK6_Delta_pt", "AK6_jet_all_matched_pt");
    auto h2_AK8_Delta_pt = df.Histo2D(model_AK8_Delta_pt, "AK8_Delta_pt", "AK8_jet_all_matched_pt");

    // AK4 - AK2
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK4 = "h1_AK4_Delta_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK4 = title_AK4.c_str();
        auto h1_AK4_Delta_pt = h2_AK4_Delta_pt->ProjectionX(c_title_AK4, i, i);

        h1_AK4_Delta_pt->SetStats(0);
        h1_AK4_Delta_pt->SetFillColor(kGreen+1);
        h1_AK4_Delta_pt->SetLineColor(kGreen+1);
        h1_AK4_Delta_pt->SetTitle("");
        h1_AK4_Delta_pt->SetMarkerSize(2);
        h1_AK4_Delta_pt->SetMarkerColor(kGreen+1);

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
        auto xaxis1 = h1_AK4_Delta_pt->GetXaxis();
        xaxis1->SetTitle("#Delta p_{T} (AK2, AK4) (GeV)");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK4_Delta_pt->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK4_Delta_pt->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK4 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.45, 0.78, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK4_Delta_pt->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.455, 0.73, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK4_Delta_pt->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.455, 0.68, c_text3);

        string output_AK4 = "pdffiles/h1_AK4_Delta_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK4 = output_AK4.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK4);
    }

    // AK6 - AK4
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK6 = "h1_AK6_Delta_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK6 = title_AK6.c_str();
        auto h1_AK6_Delta_pt = h2_AK6_Delta_pt->ProjectionX(c_title_AK6, i, i);

        h1_AK6_Delta_pt->SetStats(0);
        h1_AK6_Delta_pt->SetFillColor(kOrange+1);
        h1_AK6_Delta_pt->SetLineColor(kOrange+1);
        h1_AK6_Delta_pt->SetTitle("");
        h1_AK6_Delta_pt->SetMarkerSize(2);
        h1_AK6_Delta_pt->SetMarkerColor(kOrange+1);

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
        auto xaxis1 = h1_AK6_Delta_pt->GetXaxis();
        xaxis1->SetTitle("#Delta p_{T} (AK4, AK6) (GeV)");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK6_Delta_pt->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK6_Delta_pt->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK6 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.45, 0.78, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK6_Delta_pt->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.455, 0.73, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK6_Delta_pt->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.455, 0.68, c_text3);

        string output_AK6 = "pdffiles/h1_AK6_Delta_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK6 = output_AK6.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK6);
    }

    // AK8 - AK6
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK8 = "h1_AK8_Delta_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK8 = title_AK8.c_str();
        auto h1_AK8_Delta_pt = h2_AK8_Delta_pt->ProjectionX(c_title_AK8, i, i);

        h1_AK8_Delta_pt->SetStats(0);
        h1_AK8_Delta_pt->SetFillColor(kRed+1);
        h1_AK8_Delta_pt->SetLineColor(kRed+1);
        h1_AK8_Delta_pt->SetTitle("");
        h1_AK8_Delta_pt->SetMarkerSize(2);
        h1_AK8_Delta_pt->SetMarkerColor(kRed+1);

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
        auto xaxis1 = h1_AK8_Delta_pt->GetXaxis();
        xaxis1->SetTitle("#Delta p_{T} (AK6, AK8) (GeV)");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK8_Delta_pt->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK8_Delta_pt->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK8 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.45, 0.78, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK8_Delta_pt->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.455, 0.73, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK8_Delta_pt->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.455, 0.68, c_text3);

        string output_AK8 = "pdffiles/h1_AK8_Delta_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK8 = output_AK8.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK8);
    }


    // ------------------
    // Percentage change
    // ------------------

    ROOT::RDF::TH2DModel model_AK4_Percent_pt("h2_AK4_Percent_pt", "", 300, 0., 30., 5, ptbins);
    ROOT::RDF::TH2DModel model_AK6_Percent_pt("h2_AK6_Percent_pt", "", 300, 0., 30., 5, ptbins);
    ROOT::RDF::TH2DModel model_AK8_Percent_pt("h2_AK8_Percent_pt", "", 300, 0., 30., 5, ptbins);

    auto h2_AK4_Percent_pt = df.Histo2D(model_AK4_Percent_pt, "AK4_Percent_pt", "AK4_jet_all_matched_pt");
    auto h2_AK6_Percent_pt = df.Histo2D(model_AK6_Percent_pt, "AK6_Percent_pt", "AK6_jet_all_matched_pt");
    auto h2_AK8_Percent_pt = df.Histo2D(model_AK8_Percent_pt, "AK8_Percent_pt", "AK8_jet_all_matched_pt");

    double mean_AK4[5], rms_AK4[5], mean_AK6[5], rms_AK6[5], mean_AK8[5], rms_AK8[5];

    // AK4 - AK2
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK4 = "h1_AK4_Percent_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK4 = title_AK4.c_str();
        auto h1_AK4_Percent_pt = h2_AK4_Percent_pt->ProjectionX(c_title_AK4, i, i);

        h1_AK4_Percent_pt->SetStats(0);
        h1_AK4_Percent_pt->SetFillColor(kGreen+1);
        h1_AK4_Percent_pt->SetLineColor(kGreen+1);
        h1_AK4_Percent_pt->SetTitle("");
        h1_AK4_Percent_pt->SetMarkerSize(2);
        h1_AK4_Percent_pt->SetMarkerColor(kGreen+1);

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
        auto xaxis1 = h1_AK4_Percent_pt->GetXaxis();
        xaxis1->SetTitle("#Delta p_{T} (AK2, AK4) (\%)");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK4_Percent_pt->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK4_Percent_pt->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK4 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.45, 0.78, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK4_Percent_pt->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.455, 0.73, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK4_Percent_pt->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.455, 0.68, c_text3);

        string output_AK4 = "pdffiles/h1_AK4_Percent_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK4 = output_AK4.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK4);

        mean_AK4[i-1] = h1_AK4_Percent_pt->GetMean();
        rms_AK4[i-1] = h1_AK4_Percent_pt->GetRMS();
    }

    // AK6 - AK4
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK6 = "h1_AK6_Percent_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK6 = title_AK6.c_str();
        auto h1_AK6_Percent_pt = h2_AK6_Percent_pt->ProjectionX(c_title_AK6, i, i);

        h1_AK6_Percent_pt->SetStats(0);
        h1_AK6_Percent_pt->SetFillColor(kOrange+1);
        h1_AK6_Percent_pt->SetLineColor(kOrange+1);
        h1_AK6_Percent_pt->SetTitle("");
        h1_AK6_Percent_pt->SetMarkerSize(2);
        h1_AK6_Percent_pt->SetMarkerColor(kOrange+1);

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
        auto xaxis1 = h1_AK6_Percent_pt->GetXaxis();
        xaxis1->SetTitle("#Delta p_{T} (AK4, AK6) (\%)");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK6_Percent_pt->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK6_Percent_pt->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK6 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.45, 0.78, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK6_Percent_pt->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.455, 0.73, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK6_Percent_pt->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.455, 0.68, c_text3);

        string output_AK6 = "pdffiles/h1_AK6_Percent_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK6 = output_AK6.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK6);

        mean_AK6[i-1] = h1_AK6_Percent_pt->GetMean();
        rms_AK6[i-1] = h1_AK6_Percent_pt->GetRMS();
    }

    // AK8 - AK6
    for (int i = 1; i < 6; i++) {
        TCanvas *c1 = new TCanvas("c1", "c1");
        c1->cd();
        c1->SetCanvasSize(1200, 1200);
        
        string title_AK8 = "h1_AK8_Percent_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK8 = title_AK8.c_str();
        auto h1_AK8_Percent_pt = h2_AK8_Percent_pt->ProjectionX(c_title_AK8, i, i);

        h1_AK8_Percent_pt->SetStats(0);
        h1_AK8_Percent_pt->SetFillColor(kRed+1);
        h1_AK8_Percent_pt->SetLineColor(kRed+1);
        h1_AK8_Percent_pt->SetTitle("");
        h1_AK8_Percent_pt->SetMarkerSize(2);
        h1_AK8_Percent_pt->SetMarkerColor(kRed+1);

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
        auto xaxis1 = h1_AK8_Percent_pt->GetXaxis();
        xaxis1->SetTitle("#Delta p_{T} (AK6, AK8) (\%)");
        xaxis1->SetTitleFont(43);
        xaxis1->SetTitleSize(55);
        xaxis1->SetLabelFont(43);
        xaxis1->SetLabelSize(35);

        auto yaxis1 = h1_AK8_Percent_pt->GetYaxis();
        yaxis1->SetTitle("Jets per bin");
        yaxis1->SetTitleFont(43);
        yaxis1->SetTitleSize(55);
        yaxis1->SetLabelFont(43);
        yaxis1->SetLabelSize(35);

        h1_AK8_Percent_pt->Draw("hist");

        // Text
        TLatex *latex = new TLatex();
        latex->SetNDC();
        latex->SetTextFont(42);
        latex->SetTextSize(0.03);
        latex->SetTextColor(1);
        latex->SetTextAlign(12);
        string text = std::to_string(pt[i-1]) + "GeV < p_{T, AK8 Jet} < " + std::to_string(pt[i]) + "GeV";
        auto c_text = text.c_str();
        latex->DrawLatex(0.45, 0.78, c_text);

        TLatex *latex2 = new TLatex();
        latex2->SetNDC();
        latex2->SetTextFont(42);
        latex2->SetTextSize(0.03);
        latex2->SetTextColor(1);
        latex2->SetTextAlign(12);
        string text2 = "Mean = " + std::to_string(h1_AK8_Percent_pt->GetMean());
        auto c_text2 = text2.c_str();
        latex2->DrawLatex(0.455, 0.73, c_text2);

        TLatex *latex3 = new TLatex();
        latex3->SetNDC();
        latex3->SetTextFont(42);
        latex3->SetTextSize(0.03);
        latex3->SetTextColor(1);
        latex3->SetTextAlign(12);
        string text3 = "RMS = " + std::to_string(h1_AK8_Percent_pt->GetRMS());
        auto c_text3 = text3.c_str();
        latex3->DrawLatex(0.455, 0.68, c_text3);

        string output_AK8 = "pdffiles/h1_AK8_Percent_pt_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_output_AK8 = output_AK8.c_str();

        c1->cd();
        c1->SaveAs(c_output_AK8);

        mean_AK8[i-1] = h1_AK8_Percent_pt->GetMean();
        rms_AK8[i-1] = h1_AK8_Percent_pt->GetRMS();
    }


    // -----------------------------------------
    // Plot mean % Delta pT as a function of pT
    // -----------------------------------------

    double x[5] = {1., 2., 3., 4., 5.};
    double err_x[5] = {0.5, 0.5, 0.5, 0.5, 0.5};

    TGraphAsymmErrors *gr_AK4 = new TGraphAsymmErrors(5, x, mean_AK4, err_x, err_x, rms_AK4, rms_AK4);
    TGraphAsymmErrors *gr_AK6 = new TGraphAsymmErrors(5, x, mean_AK6, err_x, err_x, rms_AK6, rms_AK6);
    TGraphAsymmErrors *gr_AK8 = new TGraphAsymmErrors(5, x, mean_AK8, err_x, err_x, rms_AK8, rms_AK8);

    // TGraph formatting
    gr_AK4->SetTitle("");
    gr_AK4->SetMarkerColor(kGreen+1);
    gr_AK4->SetMarkerStyle(kFullSquare);
    gr_AK4->SetMarkerSize(3);
    gr_AK4->SetLineColor(kGreen+1);
    gr_AK4->SetFillColorAlpha(kGreen+1, 0.2);

    gr_AK6->SetTitle("");
    gr_AK6->SetMarkerColor(kOrange+1);
    gr_AK6->SetMarkerStyle(kFullTriangleUp);
    gr_AK6->SetMarkerSize(3);
    gr_AK6->SetLineColor(kOrange+1);
    gr_AK6->SetFillColorAlpha(kOrange+1, 0.2);

    gr_AK8->SetTitle("");
    gr_AK8->SetMarkerColor(kRed+1);
    gr_AK8->SetMarkerStyle(kFullTriangleDown);
    gr_AK8->SetMarkerSize(3);
    gr_AK8->SetLineColor(kRed+1);
    gr_AK8->SetFillColorAlpha(kRed+1, 0.2);

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
    htemp->SetMaximum(25.);
    
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
    yaxis->SetTitle("#LT\%#Deltap_{T}#GT");
    yaxis->SetLabelSize(0.03);
    yaxis->SetTitleSize(0.05);
    yaxis->CenterTitle(true);

    // Drawing
    pad1->cd();
    htemp->Draw();
    gr_AK4->Draw("5psame");
    gr_AK6->Draw("5psame");
    gr_AK8->Draw("5psame");

    // Legend
    TLegend *leg = new TLegend(0.65, 0.6, 0.83, 0.8);
    leg->SetBorderSize(0);
    leg->AddEntry(gr_AK4, "AK4 - AK2", "pl");
    leg->AddEntry(gr_AK6, "AK6 - AK4", "pl");
    leg->AddEntry(gr_AK8, "AK8 - AK6", "pl");
    leg->Draw();

    c1->cd();
    c1->SaveAs("pdffiles/g2_jet_all_matched_meanPercentDelPt.pdf");
}