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

    outFile->Close();
}