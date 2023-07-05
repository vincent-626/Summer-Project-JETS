#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"

void histoPlotter() {
    ROOT::EnableImplicitMT();

    ROOT::RDataFrame df("tree", "rootfiles/events.root");

    ROOT::RDF::TH1DModel model_AK2_jet_pt("h1_AK2_jet_pt", "", 100, 0., 100.);
    ROOT::RDF::TH1DModel model_AK4_jet_pt("h1_AK4_jet_pt", "", 100, 0., 100.);
    ROOT::RDF::TH1DModel model_AK6_jet_pt("h1_AK6_jet_pt", "", 100, 0., 100.);
    ROOT::RDF::TH1DModel model_AK8_jet_pt("h1_AK8_jet_pt", "", 100, 0., 100.);

    ROOT::RDF::TH1DModel model_AK2_jet_eta("h1_AK2_jet_eta", "", 80, -4., 4.);
    ROOT::RDF::TH1DModel model_AK4_jet_eta("h1_AK4_jet_eta", "", 80, -4., 4.);
    ROOT::RDF::TH1DModel model_AK6_jet_eta("h1_AK6_jet_eta", "", 80, -4., 4.);
    ROOT::RDF::TH1DModel model_AK8_jet_eta("h1_AK8_jet_eta", "", 80, -4., 4.);

    ROOT::RDF::TH1DModel model_AK2_jet_phi("h1_AK2_jet_phi", "", 70, 0., 7.);
    ROOT::RDF::TH1DModel model_AK4_jet_phi("h1_AK4_jet_phi", "", 70, 0., 7.);
    ROOT::RDF::TH1DModel model_AK6_jet_phi("h1_AK6_jet_phi", "", 70, 0., 7.);
    ROOT::RDF::TH1DModel model_AK8_jet_phi("h1_AK8_jet_phi", "", 70, 0., 7.);

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

    // ----------------
    // Save histograms
    // ----------------

    TFile *outFile = new TFile("rootfiles/Histo_Jet_PtEtaPhi.root", "RECREATE");

    h1_AK2_jet_pt->Write();
    h1_AK4_jet_pt->Write();
    h1_AK6_jet_pt->Write();
    h1_AK8_jet_pt->Write();

    h1_AK2_jet_eta->Write();
    h1_AK4_jet_eta->Write();
    h1_AK6_jet_eta->Write();
    h1_AK8_jet_eta->Write();

    h1_AK2_jet_phi->Write();
    h1_AK4_jet_phi->Write();
    h1_AK6_jet_phi->Write();
    h1_AK8_jet_phi->Write();

    outFile->Close();
}