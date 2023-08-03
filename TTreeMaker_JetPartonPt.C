#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TLegend.h"

void TTreeMaker_JetPartonPt() {
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
                    .Define("AK8_jet_parton_pt_ratio", "AK8_jet_all_matched_pt/Parton_matched_pt")
                    .Define("AK2_jet_all_matched_eta", "AK2_jet_sorted_matched_eta[Parton_match]")
                    .Define("AK4_jet_all_matched_eta", "AK4_jet_sorted_matched_eta[Parton_match]")
                    .Define("AK6_jet_all_matched_eta", "AK6_jet_sorted_matched_eta[Parton_match]")
                    .Define("AK8_jet_all_matched_eta", "AK8_jet_sorted_matched_eta[Parton_match]")
                    .Define("AK2_jet_all_matched_phi", "AK2_jet_sorted_matched_phi[Parton_match]")
                    .Define("AK4_jet_all_matched_phi", "AK4_jet_sorted_matched_phi[Parton_match]")
                    .Define("AK6_jet_all_matched_phi", "AK6_jet_sorted_matched_phi[Parton_match]")
                    .Define("AK8_jet_all_matched_phi", "AK8_jet_sorted_matched_phi[Parton_match]")
                    .Define("AK2_jet_all_matched_lambda11", "AK2_jet_sorted_matched_lambda11[Parton_match]")
                    .Define("AK4_jet_all_matched_lambda11", "AK4_jet_sorted_matched_lambda11[Parton_match]")
                    .Define("AK6_jet_all_matched_lambda11", "AK6_jet_sorted_matched_lambda11[Parton_match]")
                    .Define("AK8_jet_all_matched_lambda11", "AK8_jet_sorted_matched_lambda11[Parton_match]");
    
    df.Snapshot("matched_jets", "rootfiles/matched_jets.root", {
        "Parton_matched_pt", "Parton_matched_eta", "Parton_matched_phi",
        "AK2_jet_all_matched_pt", "AK2_jet_all_matched_eta", "AK2_jet_all_matched_phi", "AK2_jet_parton_pt_ratio", "AK2_jet_all_matched_lambda11",
        "AK4_jet_all_matched_pt", "AK4_jet_all_matched_eta", "AK4_jet_all_matched_phi", "AK4_jet_parton_pt_ratio", "AK4_jet_all_matched_lambda11",
        "AK6_jet_all_matched_pt", "AK6_jet_all_matched_eta", "AK6_jet_all_matched_phi", "AK6_jet_parton_pt_ratio", "AK6_jet_all_matched_lambda11",
        "AK8_jet_all_matched_pt", "AK8_jet_all_matched_eta", "AK8_jet_all_matched_phi", "AK8_jet_parton_pt_ratio", "AK8_jet_all_matched_lambda11"
    });
}