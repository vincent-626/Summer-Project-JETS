#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void compareJetPartonPt() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame rdf("tree", "rootfiles/events.root");

    auto df = rdf.Define("Parton_matched_pt", "Parton_pt[Parton_match]")
                    .Define("Parton_matched_eta", "Parton_eta[Parton_match]")
                    .Define("Parton_matched_phi", "Parton_phi[Parton_match]")
                    .Define("AK2_jet_all_matched_pt", "AK2_jet_sorted_matched_pt[Parton_match]")
                    .Define("AK4_jet_all_matched_pt", "AK4_jet_sorted_matched_pt[Parton_match]")
                    .Define("AK6_jet_all_matched_pt", "AK6_jet_sorted_matched_pt[Parton_match]")
                    .Define("AK8_jet_all_matched_pt", "AK8_jet_sorted_matched_pt[Parton_match]")
                    .Define("AK2_jet_parton_pt_ratio", "AK2_jet_all_matched_pt/Parton_matched_pt")
                    .Define("AK4_jet_parton_pt_ratio", "AK4_jet_all_matched_pt/Parton_matched_pt")
                    .Define("AK6_jet_parton_pt_ratio", "AK6_jet_all_matched_pt/Parton_matched_pt")
                    .Define("AK8_jet_parton_pt_ratio", "AK8_jet_all_matched_pt/Parton_matched_pt");

    // -------------
    // TH1 plotting
    // -------------

    ROOT::RDF::TH1DModel model_AK2("h1_AK2_jet_parton_pt_ratio", "", 60, 0.5, 1.1);
    ROOT::RDF::TH1DModel model_AK4("h1_AK4_jet_parton_pt_ratio", "", 60, 0.5, 1.1);
    ROOT::RDF::TH1DModel model_AK6("h1_AK6_jet_parton_pt_ratio", "", 60, 0.5, 1.1);
    ROOT::RDF::TH1DModel model_AK8("h1_AK8_jet_parton_pt_ratio", "", 60, 0.5, 1.1);

    auto h1_AK2_jet_parton_pt_ratio = df.Histo1D(model_AK2, "AK2_jet_parton_pt_ratio");
    auto h1_AK4_jet_parton_pt_ratio = df.Histo1D(model_AK4, "AK4_jet_parton_pt_ratio");
    auto h1_AK6_jet_parton_pt_ratio = df.Histo1D(model_AK6, "AK6_jet_parton_pt_ratio");
    auto h1_AK8_jet_parton_pt_ratio = df.Histo1D(model_AK8, "AK8_jet_parton_pt_ratio");

    h1_AK2_jet_parton_pt_ratio->Scale(1/h1_AK2_jet_parton_pt_ratio->Integral());
    h1_AK2_jet_parton_pt_ratio->SetFillColor(0);
    h1_AK2_jet_parton_pt_ratio->SetLineColor(kBlue+1);
    h1_AK2_jet_parton_pt_ratio->SetStats(0);
    h1_AK2_jet_parton_pt_ratio->SetTitle("");
    h1_AK2_jet_parton_pt_ratio->SetMarkerStyle(kFullCircle);
    h1_AK2_jet_parton_pt_ratio->SetMarkerSize(2);
    h1_AK2_jet_parton_pt_ratio->SetMarkerColor(kBlue+1);

    h1_AK4_jet_parton_pt_ratio->Scale(1/h1_AK4_jet_parton_pt_ratio->Integral());
    h1_AK4_jet_parton_pt_ratio->SetFillColor(0);
    h1_AK4_jet_parton_pt_ratio->SetLineColor(kGreen+1);
    h1_AK4_jet_parton_pt_ratio->SetStats(0);
    h1_AK4_jet_parton_pt_ratio->SetTitle("");
    h1_AK4_jet_parton_pt_ratio->SetMarkerStyle(kFullSquare);
    h1_AK4_jet_parton_pt_ratio->SetMarkerSize(2);
    h1_AK4_jet_parton_pt_ratio->SetMarkerColor(kGreen+1);

    h1_AK6_jet_parton_pt_ratio->Scale(1/h1_AK6_jet_parton_pt_ratio->Integral());
    h1_AK6_jet_parton_pt_ratio->SetFillColor(0);
    h1_AK6_jet_parton_pt_ratio->SetLineColor(kOrange+1);
    h1_AK6_jet_parton_pt_ratio->SetStats(0);
    h1_AK6_jet_parton_pt_ratio->SetTitle("");
    h1_AK6_jet_parton_pt_ratio->SetMarkerStyle(kFullTriangleUp);
    h1_AK6_jet_parton_pt_ratio->SetMarkerSize(2);
    h1_AK6_jet_parton_pt_ratio->SetMarkerColor(kOrange+1);

    h1_AK8_jet_parton_pt_ratio->Scale(1/h1_AK8_jet_parton_pt_ratio->Integral());
    h1_AK8_jet_parton_pt_ratio->SetFillColor(0);
    h1_AK8_jet_parton_pt_ratio->SetLineColor(kRed+1);
    h1_AK8_jet_parton_pt_ratio->SetStats(0);
    h1_AK8_jet_parton_pt_ratio->SetTitle("");
    h1_AK8_jet_parton_pt_ratio->SetMarkerStyle(kFullTriangleDown);
    h1_AK8_jet_parton_pt_ratio->SetMarkerSize(2);
    h1_AK8_jet_parton_pt_ratio->SetMarkerColor(kRed+1);

    h1_AK2_jet_parton_pt_ratio->SetMaximum(0.18);

    h1_AK2_jet_parton_pt_ratio->Fit("gaus");
    h1_AK4_jet_parton_pt_ratio->Fit("gaus");
    h1_AK6_jet_parton_pt_ratio->Fit("gaus");
    h1_AK8_jet_parton_pt_ratio->Fit("gaus");

    auto f_AK2 = h1_AK2_jet_parton_pt_ratio->GetFunction("gaus");
    auto f_AK4 = h1_AK4_jet_parton_pt_ratio->GetFunction("gaus");
    auto f_AK6 = h1_AK6_jet_parton_pt_ratio->GetFunction("gaus");
    auto f_AK8 = h1_AK8_jet_parton_pt_ratio->GetFunction("gaus");

    f_AK2->SetLineColor(kBlue+1);
    f_AK4->SetLineColor(kGreen+1);
    f_AK6->SetLineColor(kOrange+1);
    f_AK8->SetLineColor(kRed+1);

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

    h1_AK2_jet_parton_pt_ratio->Draw("ep");
    h1_AK4_jet_parton_pt_ratio->Draw("epsame");
    h1_AK6_jet_parton_pt_ratio->Draw("epsame");
    h1_AK8_jet_parton_pt_ratio->Draw("epsame");

    auto yaxis = h1_AK2_jet_parton_pt_ratio->GetYaxis();
    yaxis->SetTitle("Normalized jets per bin");
    yaxis->SetTitleFont(43);
    yaxis->SetTitleSize(55);
    yaxis->SetTitleOffset(1.7);
    yaxis->SetLabelFont(43);
    yaxis->SetLabelSize(35);

    auto xaxis = h1_AK2_jet_parton_pt_ratio->GetXaxis();
    xaxis->SetTitle("p_{T, Jet} / p_{T, Parton}");
    xaxis->SetTitleFont(43);
    xaxis->SetTitleSize(55);
    xaxis->SetLabelFont(43);
    xaxis->SetLabelSize(35);

    // Legend
    TLegend *leg = new TLegend(0.2, 0.55, 0.4, 0.8);
    leg->SetBorderSize(0);
    leg->AddEntry(h1_AK2_jet_parton_pt_ratio.GetPtr(), "R = 0.2", "pl");
    leg->AddEntry(f_AK2, "Gaussian fit", "l");
    leg->AddEntry(h1_AK4_jet_parton_pt_ratio.GetPtr(), "R = 0.4", "pl");
    leg->AddEntry(f_AK4, "Gaussian fit", "l");
    leg->AddEntry(h1_AK6_jet_parton_pt_ratio.GetPtr(), "R = 0.6", "pl");
    leg->AddEntry(f_AK6, "Gaussian fit", "l");
    leg->AddEntry(h1_AK8_jet_parton_pt_ratio.GetPtr(), "R = 0.8", "pl");
    leg->AddEntry(f_AK8, "Gaussian fit", "l");
    leg->Draw();

    c1->cd();
    c1->SaveAs("pdffiles/h1_jet_parton_pt_ratio.pdf");


    // --------------
    // pT projection
    // --------------

    const double ptbins[6] = {10., 40., 50., 70., 100., 200.};

    ROOT::RDF::TH2DModel model_2D_AK2("h2_AK2_jet_parton_pt_ratio", "", 60, 0.5, 1.1, 5, ptbins);
    ROOT::RDF::TH2DModel model_2D_AK4("h2_AK4_jet_parton_pt_ratio", "", 60, 0.5, 1.1, 5, ptbins);
    ROOT::RDF::TH2DModel model_2D_AK6("h2_AK6_jet_parton_pt_ratio", "", 60, 0.5, 1.1, 5, ptbins);
    ROOT::RDF::TH2DModel model_2D_AK8("h2_AK8_jet_parton_pt_ratio", "", 60, 0.5, 1.1, 5, ptbins);

    auto h2_AK2_jet_parton_pt_ratio = df.Histo2D(model_2D_AK2, "AK2_jet_parton_pt_ratio", "AK2_jet_all_matched_pt");
    auto h2_AK4_jet_parton_pt_ratio = df.Histo2D(model_2D_AK4, "AK4_jet_parton_pt_ratio", "AK4_jet_all_matched_pt");
    auto h2_AK6_jet_parton_pt_ratio = df.Histo2D(model_2D_AK6, "AK6_jet_parton_pt_ratio", "AK6_jet_all_matched_pt");
    auto h2_AK8_jet_parton_pt_ratio = df.Histo2D(model_2D_AK8, "AK8_jet_parton_pt_ratio", "AK8_jet_all_matched_pt");

    const int pt[6] = {10, 40, 50, 70, 100, 200};

    double mean_AK2[5], sigma_AK2[5], mean_AK4[5], sigma_AK4[5], mean_AK6[5], sigma_AK6[5], mean_AK8[5], sigma_AK8[5];

    for (int i = 1; i < 6; i++) {
        auto h1_AK2_project = h2_AK2_jet_parton_pt_ratio->ProjectionX("h1_AK2_project", i, i);
        auto h1_AK4_project = h2_AK4_jet_parton_pt_ratio->ProjectionX("h1_AK4_project", i, i);
        auto h1_AK6_project = h2_AK6_jet_parton_pt_ratio->ProjectionX("h1_AK6_project", i, i);
        auto h1_AK8_project = h2_AK8_jet_parton_pt_ratio->ProjectionX("h1_AK8_project", i, i);

        h1_AK2_project->Scale(1/h1_AK2_project->Integral());
        h1_AK2_project->SetFillColor(0);
        h1_AK2_project->SetLineColor(kBlue+1);
        h1_AK2_project->SetStats(0);
        h1_AK2_project->SetTitle("");
        h1_AK2_project->SetMarkerStyle(kFullCircle);
        h1_AK2_project->SetMarkerSize(2);
        h1_AK2_project->SetMarkerColor(kBlue+1);

        h1_AK4_project->Scale(1/h1_AK4_project->Integral());
        h1_AK4_project->SetFillColor(0);
        h1_AK4_project->SetLineColor(kGreen+1);
        h1_AK4_project->SetStats(0);
        h1_AK4_project->SetTitle("");
        h1_AK4_project->SetMarkerStyle(kFullSquare);
        h1_AK4_project->SetMarkerSize(2);
        h1_AK4_project->SetMarkerColor(kGreen+1);

        h1_AK6_project->Scale(1/h1_AK6_project->Integral());
        h1_AK6_project->SetFillColor(0);
        h1_AK6_project->SetLineColor(kOrange+1);
        h1_AK6_project->SetStats(0);
        h1_AK6_project->SetTitle("");
        h1_AK6_project->SetMarkerStyle(kFullTriangleUp);
        h1_AK6_project->SetMarkerSize(2);
        h1_AK6_project->SetMarkerColor(kOrange+1);

        h1_AK8_project->Scale(1/h1_AK8_project->Integral());
        h1_AK8_project->SetFillColor(0);
        h1_AK8_project->SetLineColor(kRed+1);
        h1_AK8_project->SetStats(0);
        h1_AK8_project->SetTitle("");
        h1_AK8_project->SetMarkerStyle(kFullTriangleDown);
        h1_AK8_project->SetMarkerSize(2);
        h1_AK8_project->SetMarkerColor(kRed+1);

        h1_AK2_project->SetMaximum(0.45);

        h1_AK2_project->Fit("gaus");
        h1_AK4_project->Fit("gaus");
        h1_AK6_project->Fit("gaus");
        h1_AK8_project->Fit("gaus");

        auto f_AK2 = h1_AK2_project->GetFunction("gaus");
        auto f_AK4 = h1_AK4_project->GetFunction("gaus");
        auto f_AK6 = h1_AK6_project->GetFunction("gaus");
        auto f_AK8 = h1_AK8_project->GetFunction("gaus");

        f_AK2->SetLineColor(kBlue+1);
        f_AK4->SetLineColor(kGreen+1);
        f_AK6->SetLineColor(kOrange+1);
        f_AK8->SetLineColor(kRed+1);

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

        h1_AK2_project->Draw("ep");
        h1_AK4_project->Draw("epsame");
        h1_AK6_project->Draw("epsame");
        h1_AK8_project->Draw("epsame");

        auto yaxis = h1_AK2_project->GetYaxis();
        yaxis->SetTitle("Normalized jets per bin");
        yaxis->SetTitleFont(43);
        yaxis->SetTitleSize(55);
        yaxis->SetTitleOffset(1.7);
        yaxis->SetLabelFont(43);
        yaxis->SetLabelSize(35);

        auto xaxis = h1_AK2_project->GetXaxis();
        xaxis->SetTitle("p_{T, Jet} / p_{T, Parton}");
        xaxis->SetTitleFont(43);
        xaxis->SetTitleSize(55);
        xaxis->SetLabelFont(43);
        xaxis->SetLabelSize(35);

        // Legend
        TLegend *leg = new TLegend(0.2, 0.55, 0.4, 0.8);
        leg->SetBorderSize(0);
        leg->AddEntry(h1_AK2_project, "R = 0.2", "pl");
        leg->AddEntry(f_AK2, "Gaussian fit", "l");
        leg->AddEntry(h1_AK4_project, "R = 0.4", "pl");
        leg->AddEntry(f_AK4, "Gaussian fit", "l");
        leg->AddEntry(h1_AK6_project, "R = 0.6", "pl");
        leg->AddEntry(f_AK6, "Gaussian fit", "l");
        leg->AddEntry(h1_AK8_project, "R = 0.8", "pl");
        leg->AddEntry(f_AK8, "Gaussian fit", "l");
        leg->Draw();

        string title = "pdffiles/h1_jet_parton_pt_ratio_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]) + ".pdf";
        auto c_title = title.c_str();

        c1->cd();
        c1->SaveAs(c_title);

        mean_AK2[i-1] = f_AK2->GetParameter(1);
        sigma_AK2[i-1] = f_AK2->GetParameter(2);
        mean_AK4[i-1] = f_AK4->GetParameter(1);
        sigma_AK4[i-1] = f_AK4->GetParameter(2);
        mean_AK6[i-1] = f_AK6->GetParameter(1);
        sigma_AK6[i-1] = f_AK6->GetParameter(2);
        mean_AK8[i-1] = f_AK8->GetParameter(1);
        sigma_AK8[i-1] = f_AK8->GetParameter(2);
    }

    // ----------------
    // TGraph plotting
    // ----------------

    double x[5] = {1., 2., 3., 4., 5.};
    double err_x[5] = {0., 0., 0., 0., 0.};

    TGraphAsymmErrors *gr_AK2 = new TGraphAsymmErrors(5, x, mean_AK2, err_x, err_x, sigma_AK2, sigma_AK2);
    TGraphAsymmErrors *gr_AK4 = new TGraphAsymmErrors(5, x, mean_AK4, err_x, err_x, sigma_AK4, sigma_AK4);
    TGraphAsymmErrors *gr_AK6 = new TGraphAsymmErrors(5, x, mean_AK6, err_x, err_x, sigma_AK6, sigma_AK6);
    TGraphAsymmErrors *gr_AK8 = new TGraphAsymmErrors(5, x, mean_AK8, err_x, err_x, sigma_AK8, sigma_AK8);

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

    TH1I *htemp = new TH1I("", "", 5, 0, 5);
    htemp->SetStats(0);
    htemp->SetMaximum(1.3);
    htemp->SetMinimum(0.7);
    
    auto xaxis2 = htemp->GetXaxis();
    xaxis2->SetLabelSize(0.035);
    xaxis2->SetLimits(0.5, 5.5);
    xaxis2->SetNdivisions(5);
    
    for (int i = 1; i < 6; i++) {
        string label = "p_{T, Jet} #in [" + std::to_string(pt[i-1]) + ", " + std::to_string(pt[i]) + "] GeV";
        auto c_label = label.c_str();
        xaxis2->SetBinLabel(i, c_label);
    }
        
    xaxis2->LabelsOption("d");
    xaxis2->SetLabelOffset(0.01);

    auto yaxis2 = htemp->GetYaxis();
    yaxis2->SetTitle("#mu_{p_{T, Jet} / p_{T, Parton}}");
    yaxis2->SetLabelSize(0.03);
    yaxis2->SetTitleSize(0.05);
    yaxis2->CenterTitle(true);

    // Middle line
    TLine *line = new TLine(0.5, 1., 5.5, 1.);
    line->SetLineColor(kBlack);
    line->SetLineStyle(7);

    // Drawing
    pad2->cd();
    htemp->Draw();
    line->Draw("same");
    gr_AK2->Draw("psame");
    gr_AK4->Draw("psame");
    gr_AK6->Draw("psame");
    gr_AK8->Draw("psame");

    // Legend
    TLegend *leg2 = new TLegend(0.65, 0.6, 0.83, 0.8);
    leg2->SetBorderSize(0);
    leg2->AddEntry(gr_AK2, "R = 0.2", "pl");
    leg2->AddEntry(gr_AK4, "R = 0.4", "pl");
    leg2->AddEntry(gr_AK6, "R = 0.6", "pl");
    leg2->AddEntry(gr_AK8, "R = 0.8", "pl");
    leg2->Draw();

    c2->cd();
    c2->SaveAs("pdffiles/g2_jet_parton_pt_ratio_ptbins.pdf");
}