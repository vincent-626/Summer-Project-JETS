#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"

void histoPlotter() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame df("tree", "rootfiles/events.root");

    ROOT::RDF::TH1DModel model_AK2_jet_pt("h1_AK2_jet_pt", "", 20, 0., 200.);
    ROOT::RDF::TH1DModel model_AK4_jet_pt("h1_AK4_jet_pt", "", 20, 0., 200.);
    ROOT::RDF::TH1DModel model_AK6_jet_pt("h1_AK6_jet_pt", "", 20, 0., 200.);
    ROOT::RDF::TH1DModel model_AK8_jet_pt("h1_AK8_jet_pt", "", 20, 0., 200.);

    ROOT::RDF::TH1DModel model_AK2_jet_eta("h1_AK2_jet_eta", "", 40, -2., 2.);
    ROOT::RDF::TH1DModel model_AK4_jet_eta("h1_AK4_jet_eta", "", 40, -2., 2.);
    ROOT::RDF::TH1DModel model_AK6_jet_eta("h1_AK6_jet_eta", "", 40, -2., 2.);
    ROOT::RDF::TH1DModel model_AK8_jet_eta("h1_AK8_jet_eta", "", 40, -2., 2.);

    ROOT::RDF::TH1DModel model_AK2_jet_phi("h1_AK2_jet_phi", "", 63, -TMath::Pi(), TMath::Pi());
    ROOT::RDF::TH1DModel model_AK4_jet_phi("h1_AK4_jet_phi", "", 63, -TMath::Pi(), TMath::Pi());
    ROOT::RDF::TH1DModel model_AK6_jet_phi("h1_AK6_jet_phi", "", 63, -TMath::Pi(), TMath::Pi());
    ROOT::RDF::TH1DModel model_AK8_jet_phi("h1_AK8_jet_phi", "", 63, -TMath::Pi(), TMath::Pi());

    ROOT::RDF::TH1DModel model_parton_pt("h1_parton_pt", "", 20, 0., 200.);
    ROOT::RDF::TH1DModel model_parton_eta("h1_parton_eta", "", 40, -2., 2.);
    ROOT::RDF::TH1DModel model_parton_phi("h1_parton_phi", "", 63, -TMath::Pi(), TMath::Pi());

    ROOT::RDF::TH1DModel model_AK2_jet_matched_pt("h1_AK2_jet_matched_pt", "", 20, 0., 200.);
    ROOT::RDF::TH1DModel model_AK4_jet_matched_pt("h1_AK4_jet_matched_pt", "", 20, 0., 200.);
    ROOT::RDF::TH1DModel model_AK6_jet_matched_pt("h1_AK6_jet_matched_pt", "", 20, 0., 200.);
    ROOT::RDF::TH1DModel model_AK8_jet_matched_pt("h1_AK8_jet_matched_pt", "", 20, 0., 200.);

    ROOT::RDF::TH1DModel model_AK2_jet_matched_eta("h1_AK2_jet_matched_eta", "", 40, -2., 2.);
    ROOT::RDF::TH1DModel model_AK4_jet_matched_eta("h1_AK4_jet_matched_eta", "", 40, -2., 2.);
    ROOT::RDF::TH1DModel model_AK6_jet_matched_eta("h1_AK6_jet_matched_eta", "", 40, -2., 2.);
    ROOT::RDF::TH1DModel model_AK8_jet_matched_eta("h1_AK8_jet_matched_eta", "", 40, -2., 2.);

    ROOT::RDF::TH1DModel model_AK2_jet_matched_phi("h1_AK2_jet_matched_phi", "", 63, -TMath::Pi(), TMath::Pi());
    ROOT::RDF::TH1DModel model_AK4_jet_matched_phi("h1_AK4_jet_matched_phi", "", 63, -TMath::Pi(), TMath::Pi());
    ROOT::RDF::TH1DModel model_AK6_jet_matched_phi("h1_AK6_jet_matched_phi", "", 63, -TMath::Pi(), TMath::Pi());
    ROOT::RDF::TH1DModel model_AK8_jet_matched_phi("h1_AK8_jet_matched_phi", "", 63, -TMath::Pi(), TMath::Pi());

    ROOT::RDF::TH1DModel model_AK2_jet_matched_delR("h1_AK2_jet_matched_delR", "", 20, 0., 0.2);
    ROOT::RDF::TH1DModel model_AK4_jet_matched_delR("h1_AK4_jet_matched_delR", "", 20, 0., 0.2);
    ROOT::RDF::TH1DModel model_AK6_jet_matched_delR("h1_AK6_jet_matched_delR", "", 20, 0., 0.2);
    ROOT::RDF::TH1DModel model_AK8_jet_matched_delR("h1_AK8_jet_matched_delR", "", 20, 0., 0.2);

    ROOT::RDF::TH1DModel model_AK2_nMatchedJet("h1_AK2_nMatchedJet", "", 5, 0, 5);
    ROOT::RDF::TH1DModel model_AK4_nMatchedJet("h1_AK4_nMatchedJet", "", 5, 0, 5);
    ROOT::RDF::TH1DModel model_AK6_nMatchedJet("h1_AK6_nMatchedJet", "", 5, 0, 5);
    ROOT::RDF::TH1DModel model_AK8_nMatchedJet("h1_AK8_nMatchedJet", "", 5, 0, 5);

    ROOT::RDF::TH1DModel model_nEtaCutParton("h1_nEtaCutParton", "", 3, 0, 3);

    const double ptbins[6] = {10., 40., 50., 70., 100., 200.};
    ROOT::RDF::TH2DModel model_AK2_jet_matched_delR_pt("h2_AK2_jet_matched_delR_pt", "", 20, 0., 0.2, 5, ptbins);
    ROOT::RDF::TH2DModel model_AK4_jet_matched_delR_pt("h2_AK4_jet_matched_delR_pt", "", 20, 0., 0.2, 5, ptbins);
    ROOT::RDF::TH2DModel model_AK6_jet_matched_delR_pt("h2_AK6_jet_matched_delR_pt", "", 20, 0., 0.2, 5, ptbins);
    ROOT::RDF::TH2DModel model_AK8_jet_matched_delR_pt("h2_AK8_jet_matched_delR_pt", "", 20, 0., 0.2, 5, ptbins);

    auto h1_AK2_jet_pt = df.Histo1D(model_AK2_jet_pt, "AK2_jet_pt");
    auto h1_AK4_jet_pt = df.Histo1D(model_AK4_jet_pt, "AK4_jet_pt");
    auto h1_AK6_jet_pt = df.Histo1D(model_AK6_jet_pt, "AK6_jet_pt");
    auto h1_AK8_jet_pt = df.Histo1D(model_AK8_jet_pt, "AK8_jet_pt");

    auto h1_AK2_jet_eta = df.Histo1D(model_AK2_jet_eta, "AK2_jet_eta");
    auto h1_AK4_jet_eta = df.Histo1D(model_AK4_jet_eta, "AK4_jet_eta");
    auto h1_AK6_jet_eta = df.Histo1D(model_AK6_jet_eta, "AK6_jet_eta");
    auto h1_AK8_jet_eta = df.Histo1D(model_AK8_jet_eta, "AK8_jet_eta");

    auto h1_AK2_jet_phi = df.Histo1D(model_AK2_jet_phi, "AK2_jet_phi");
    auto h1_AK4_jet_phi = df.Histo1D(model_AK4_jet_phi, "AK4_jet_phi");
    auto h1_AK6_jet_phi = df.Histo1D(model_AK6_jet_phi, "AK6_jet_phi");
    auto h1_AK8_jet_phi = df.Histo1D(model_AK8_jet_phi, "AK8_jet_phi");

    auto h1_parton_pt = df.Histo1D(model_parton_pt, "Parton_pt");
    auto h1_parton_eta = df.Histo1D(model_parton_eta, "Parton_eta");
    auto h1_parton_phi = df.Histo1D(model_parton_phi, "Parton_phi");

    auto h1_AK2_jet_matched_pt = df.Histo1D(model_AK2_jet_matched_pt, "AK2_jet_matched_pt");
    auto h1_AK4_jet_matched_pt = df.Histo1D(model_AK4_jet_matched_pt, "AK4_jet_matched_pt");
    auto h1_AK6_jet_matched_pt = df.Histo1D(model_AK6_jet_matched_pt, "AK6_jet_matched_pt");
    auto h1_AK8_jet_matched_pt = df.Histo1D(model_AK8_jet_matched_pt, "AK8_jet_matched_pt");

    auto h1_AK2_jet_matched_eta = df.Histo1D(model_AK2_jet_matched_eta, "AK2_jet_matched_eta");
    auto h1_AK4_jet_matched_eta = df.Histo1D(model_AK4_jet_matched_eta, "AK4_jet_matched_eta");
    auto h1_AK6_jet_matched_eta = df.Histo1D(model_AK6_jet_matched_eta, "AK6_jet_matched_eta");
    auto h1_AK8_jet_matched_eta = df.Histo1D(model_AK8_jet_matched_eta, "AK8_jet_matched_eta");

    auto h1_AK2_jet_matched_phi = df.Histo1D(model_AK2_jet_matched_phi, "AK2_jet_matched_phi");
    auto h1_AK4_jet_matched_phi = df.Histo1D(model_AK4_jet_matched_phi, "AK4_jet_matched_phi");
    auto h1_AK6_jet_matched_phi = df.Histo1D(model_AK6_jet_matched_phi, "AK6_jet_matched_phi");
    auto h1_AK8_jet_matched_phi = df.Histo1D(model_AK8_jet_matched_phi, "AK8_jet_matched_phi");

    auto h1_AK2_jet_matched_delR = df.Histo1D(model_AK2_jet_matched_delR, "AK2_jet_matched_delR");
    auto h1_AK4_jet_matched_delR = df.Histo1D(model_AK4_jet_matched_delR, "AK4_jet_matched_delR");
    auto h1_AK6_jet_matched_delR = df.Histo1D(model_AK6_jet_matched_delR, "AK6_jet_matched_delR");
    auto h1_AK8_jet_matched_delR = df.Histo1D(model_AK8_jet_matched_delR, "AK8_jet_matched_delR");

    auto h1_AK2_nMatchedJet = df.Histo1D(model_AK2_nMatchedJet, "AK2_nMatchedJet");
    auto h1_AK4_nMatchedJet = df.Histo1D(model_AK4_nMatchedJet, "AK4_nMatchedJet");
    auto h1_AK6_nMatchedJet = df.Histo1D(model_AK6_nMatchedJet, "AK6_nMatchedJet");
    auto h1_AK8_nMatchedJet = df.Histo1D(model_AK8_nMatchedJet, "AK8_nMatchedJet");

    auto h1_nEtaCutParton = df.Histo1D(model_nEtaCutParton, "nEtaCutParton");

    auto h2_AK2_jet_matched_delR_pt = df.Histo2D(model_AK2_jet_matched_delR_pt, "AK2_jet_matched_delR", "AK2_jet_matched_pt");
    auto h2_AK4_jet_matched_delR_pt = df.Histo2D(model_AK4_jet_matched_delR_pt, "AK4_jet_matched_delR", "AK4_jet_matched_pt");
    auto h2_AK6_jet_matched_delR_pt = df.Histo2D(model_AK6_jet_matched_delR_pt, "AK6_jet_matched_delR", "AK6_jet_matched_pt");
    auto h2_AK8_jet_matched_delR_pt = df.Histo2D(model_AK8_jet_matched_delR_pt, "AK8_jet_matched_delR", "AK8_jet_matched_pt");
    

    // ----------------
    // Save histograms
    // ----------------

    TFile *outFile = new TFile("rootfiles/Histo_Jet_Parton.root", "RECREATE");

    h1_AK2_jet_pt->Write();
    h1_AK2_jet_eta->Write();
    h1_AK2_jet_phi->Write();
    h1_AK2_nMatchedJet->Write();
    h1_AK2_jet_matched_pt->Write();
    h1_AK2_jet_matched_eta->Write();
    h1_AK2_jet_matched_phi->Write();
    h1_AK2_jet_matched_delR->Write();
    
    h1_AK4_jet_pt->Write();
    h1_AK4_jet_eta->Write();
    h1_AK4_jet_phi->Write();
    h1_AK4_nMatchedJet->Write();
    h1_AK4_jet_matched_pt->Write();
    h1_AK4_jet_matched_eta->Write();
    h1_AK4_jet_matched_phi->Write();
    h1_AK4_jet_matched_delR->Write();

    h1_AK6_jet_pt->Write();
    h1_AK6_jet_eta->Write();
    h1_AK6_jet_phi->Write();
    h1_AK6_nMatchedJet->Write();
    h1_AK6_jet_matched_pt->Write();
    h1_AK6_jet_matched_eta->Write();
    h1_AK6_jet_matched_phi->Write();
    h1_AK6_jet_matched_delR->Write();

    h1_AK8_jet_pt->Write();
    h1_AK8_jet_eta->Write();
    h1_AK8_jet_phi->Write();
    h1_AK8_nMatchedJet->Write();
    h1_AK8_jet_matched_pt->Write();
    h1_AK8_jet_matched_eta->Write();
    h1_AK8_jet_matched_phi->Write();
    h1_AK8_jet_matched_delR->Write();

    h1_parton_pt->Write();
    h1_parton_eta->Write();
    h1_parton_phi->Write();

    h1_nEtaCutParton->Write();

    h2_AK2_jet_matched_delR_pt->Write();
    h2_AK4_jet_matched_delR_pt->Write();
    h2_AK6_jet_matched_delR_pt->Write();
    h2_AK8_jet_matched_delR_pt->Write();

    // Projection
    const int pt[6] = {10, 40, 50, 70, 100, 200};

    for (int i = 1; i < 6; i++) {
        string title_AK2 = "h1_AK2_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK2 = title_AK2.c_str();
        auto h1_AK2_project = h2_AK2_jet_matched_delR_pt->ProjectionX(c_title_AK2, i, i);

        h1_AK2_project->Write();

        string title_AK4 = "h1_AK4_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK4 = title_AK4.c_str();
        auto h1_AK4_project = h2_AK4_jet_matched_delR_pt->ProjectionX(c_title_AK4, i, i);

        h1_AK4_project->Write();

        string title_AK6 = "h1_AK6_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK6 = title_AK6.c_str();
        auto h1_AK6_project = h2_AK6_jet_matched_delR_pt->ProjectionX(c_title_AK6, i, i);

        h1_AK6_project->Write();

        string title_AK8 = "h1_AK8_jet_matched_delR_Pt" + std::to_string(pt[i-1]) + "to" + std::to_string(pt[i]);
        auto c_title_AK8 = title_AK8.c_str();
        auto h1_AK8_project = h2_AK8_jet_matched_delR_pt->ProjectionX(c_title_AK8, i, i);

        h1_AK8_project->Write();
    }

    outFile->Close();
}