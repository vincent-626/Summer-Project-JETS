#include <iostream>
#include <vector>
#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"

int main() {
    TFile *output = new TFile("rootfiles/events.root", "RECREATE");

    TTree *tree = new TTree("tree", "tree");

    int nParton;
    int AK2_nJet, AK4_nJet, AK6_nJet, AK8_nJet;
    int AK2_nMatchedJet, AK4_nMatchedJet, AK6_nMatchedJet, AK8_nMatchedJet, nMatchedParton;
    int AK2_nUnmatchedJet, AK4_nUnmatchedJet, AK6_nUnmatchedJet, AK8_nUnmatchedJet, nUnmatchedParton;
    std::vector<bool> AK2_match, AK4_match, AK6_match, AK8_match, Parton_match;

    std::vector<float>  Parton_pt, Parton_eta, Parton_phi, Parton_id,
                        AK2_jet_pt, AK4_jet_pt, AK6_jet_pt, AK8_jet_pt,
                        AK2_jet_eta, AK4_jet_eta, AK6_jet_eta, AK8_jet_eta,
                        AK2_jet_phi, AK4_jet_phi, AK6_jet_phi, AK8_jet_phi,
                        AK2_jet_matched_pt, AK4_jet_matched_pt, AK6_jet_matched_pt, AK8_jet_matched_pt,
                        AK2_jet_matched_eta, AK4_jet_matched_eta, AK6_jet_matched_eta, AK8_jet_matched_eta,
                        AK2_jet_matched_phi, AK4_jet_matched_phi, AK6_jet_matched_phi, AK8_jet_matched_phi,
                        AK2_jet_matched_delR, AK4_jet_matched_delR, AK6_jet_matched_delR, AK8_jet_matched_delR,
                        AK2_jet_matched_lambda11, AK4_jet_matched_lambda11, AK6_jet_matched_lambda11, AK8_jet_matched_lambda11,
                        AK2_jet_sorted_matched_pt, AK4_jet_sorted_matched_pt, AK6_jet_sorted_matched_pt, AK8_jet_sorted_matched_pt,
                        AK2_jet_sorted_matched_eta, AK4_jet_sorted_matched_eta, AK6_jet_sorted_matched_eta, AK8_jet_sorted_matched_eta,
                        AK2_jet_sorted_matched_phi, AK4_jet_sorted_matched_phi, AK6_jet_sorted_matched_phi, AK8_jet_sorted_matched_phi,
                        AK2_jet_sorted_matched_lambda11, AK4_jet_sorted_matched_lambda11, AK6_jet_sorted_matched_lambda11, AK8_jet_sorted_matched_lambda11;

    std::vector<fastjet::PseudoJet> particles, partons,
                                    AK2_inclJets, AK2_sortedJets, AK2_cutJets, AK2_constituents,
                                    AK4_inclJets, AK4_sortedJets, AK4_cutJets, AK4_constituents,
                                    AK6_inclJets, AK6_sortedJets, AK6_cutJets, AK6_constituents,
                                    AK8_inclJets, AK8_sortedJets, AK8_cutJets, AK8_constituents;

    float   AK2_delta_R1, AK2_delta_R2, AK2_delta_R1_temp, AK2_delta_R2_temp,
            AK4_delta_R1, AK4_delta_R2, AK4_delta_R1_temp, AK4_delta_R2_temp,
            AK6_delta_R1, AK6_delta_R2, AK6_delta_R1_temp, AK6_delta_R2_temp,
            AK8_delta_R1, AK8_delta_R2, AK8_delta_R1_temp, AK8_delta_R2_temp; 

    std::vector<float> AK2_delta_R, AK4_delta_R, AK6_delta_R, AK8_delta_R;

    tree->Branch("nParton", &nParton);
    tree->Branch("nMatchedParton", &nMatchedParton);
    tree->Branch("nUnmatchedParton", &nUnmatchedParton);
    tree->Branch("Parton_match", &Parton_match);
    tree->Branch("Parton_pt", &Parton_pt);
    tree->Branch("Parton_eta", &Parton_eta);
    tree->Branch("Parton_phi", &Parton_phi);
    tree->Branch("Parton_id", &Parton_id);

    tree->Branch("AK2_nJet", &AK2_nJet);
    tree->Branch("AK2_jet_pt", &AK2_jet_pt);
    tree->Branch("AK2_jet_eta", &AK2_jet_eta);
    tree->Branch("AK2_jet_phi", &AK2_jet_phi);
    tree->Branch("AK2_match", &AK2_match);
    tree->Branch("AK2_nMatchedJet", &AK2_nMatchedJet);
    tree->Branch("AK2_nUnmatchedJet", &AK2_nUnmatchedJet);
    tree->Branch("AK2_jet_matched_pt", &AK2_jet_matched_pt);
    tree->Branch("AK2_jet_matched_eta", &AK2_jet_matched_eta);
    tree->Branch("AK2_jet_matched_phi", &AK2_jet_matched_phi);
    tree->Branch("AK2_jet_matched_delR", &AK2_jet_matched_delR);
    tree->Branch("AK2_jet_matched_lambda11", &AK2_jet_matched_lambda11);
    tree->Branch("AK2_jet_sorted_matched_pt", &AK2_jet_sorted_matched_pt);
    tree->Branch("AK2_jet_sorted_matched_eta", &AK2_jet_sorted_matched_eta);
    tree->Branch("AK2_jet_sorted_matched_phi", &AK2_jet_sorted_matched_phi);
    tree->Branch("AK2_jet_sorted_matched_lambda11", &AK2_jet_sorted_matched_lambda11);

    tree->Branch("AK4_nJet", &AK4_nJet);
    tree->Branch("AK4_jet_pt", &AK4_jet_pt);
    tree->Branch("AK4_jet_eta", &AK4_jet_eta);
    tree->Branch("AK4_jet_phi", &AK4_jet_phi);
    tree->Branch("AK4_match", &AK4_match);
    tree->Branch("AK4_nMatchedJet", &AK4_nMatchedJet);
    tree->Branch("AK4_nUnmatchedJet", &AK4_nUnmatchedJet);
    tree->Branch("AK4_jet_matched_pt", &AK4_jet_matched_pt);
    tree->Branch("AK4_jet_matched_eta", &AK4_jet_matched_eta);
    tree->Branch("AK4_jet_matched_phi", &AK4_jet_matched_phi);
    tree->Branch("AK4_jet_matched_delR", &AK4_jet_matched_delR);
    tree->Branch("AK4_jet_matched_lambda11", &AK4_jet_matched_lambda11);
    tree->Branch("AK4_jet_sorted_matched_pt", &AK4_jet_sorted_matched_pt);
    tree->Branch("AK4_jet_sorted_matched_eta", &AK4_jet_sorted_matched_eta);
    tree->Branch("AK4_jet_sorted_matched_phi", &AK4_jet_sorted_matched_phi);
    tree->Branch("AK4_jet_sorted_matched_lambda11", &AK4_jet_sorted_matched_lambda11);

    tree->Branch("AK6_nJet", &AK6_nJet);
    tree->Branch("AK6_jet_pt", &AK6_jet_pt);
    tree->Branch("AK6_jet_eta", &AK6_jet_eta);
    tree->Branch("AK6_jet_phi", &AK6_jet_phi);
    tree->Branch("AK6_match", &AK6_match);
    tree->Branch("AK6_nMatchedJet", &AK6_nMatchedJet);
    tree->Branch("AK6_nUnmatchedJet", &AK6_nUnmatchedJet);
    tree->Branch("AK6_jet_matched_pt", &AK6_jet_matched_pt);
    tree->Branch("AK6_jet_matched_eta", &AK6_jet_matched_eta);
    tree->Branch("AK6_jet_matched_phi", &AK6_jet_matched_phi);
    tree->Branch("AK6_jet_matched_delR", &AK6_jet_matched_delR);
    tree->Branch("AK6_jet_matched_lambda11", &AK6_jet_matched_lambda11);
    tree->Branch("AK6_jet_sorted_matched_pt", &AK6_jet_sorted_matched_pt);
    tree->Branch("AK6_jet_sorted_matched_eta", &AK6_jet_sorted_matched_eta);
    tree->Branch("AK6_jet_sorted_matched_phi", &AK6_jet_sorted_matched_phi);
    tree->Branch("AK6_jet_sorted_matched_lambda11", &AK6_jet_sorted_matched_lambda11);

    tree->Branch("AK8_nJet", &AK8_nJet);
    tree->Branch("AK8_jet_pt", &AK8_jet_pt);
    tree->Branch("AK8_jet_eta", &AK8_jet_eta);    
    tree->Branch("AK8_jet_phi", &AK8_jet_phi);
    tree->Branch("AK8_match", &AK8_match);
    tree->Branch("AK8_nMatchedJet", &AK8_nMatchedJet);
    tree->Branch("AK8_nUnmatchedJet", &AK8_nUnmatchedJet);
    tree->Branch("AK8_jet_matched_pt", &AK8_jet_matched_pt);
    tree->Branch("AK8_jet_matched_eta", &AK8_jet_matched_eta);
    tree->Branch("AK8_jet_matched_phi", &AK8_jet_matched_phi);
    tree->Branch("AK8_jet_matched_delR", &AK8_jet_matched_delR);
    tree->Branch("AK8_jet_matched_lambda11", &AK8_jet_matched_lambda11);
    tree->Branch("AK8_jet_sorted_matched_pt", &AK8_jet_sorted_matched_pt);
    tree->Branch("AK8_jet_sorted_matched_eta", &AK8_jet_sorted_matched_eta);
    tree->Branch("AK8_jet_sorted_matched_phi", &AK8_jet_sorted_matched_phi);
    tree->Branch("AK8_jet_sorted_matched_lambda11", &AK8_jet_sorted_matched_lambda11);

    // Initialize pythia
    Pythia8::Pythia pythia;

    pythia.readString("Beams::idA = 2212");
    pythia.readString("Beams::idB = 2212");
    pythia.readString("Beams::eCM = 13600");
    pythia.readString("softQCD:all = on");
    // pythia.readString("HardQCD:all = on");
    // pythia.readString("PhaseSpace:pTHatMin = 100.");
    // pythia.readString("PhaseSpace:pTHatMax = 101.");
    pythia.readString("PartonLevel:ISR = off");
    pythia.readString("PartonLevel:FSR = off");
    pythia.readString("PartonLevel:MPI = off");

    pythia.init();

    int nEvent = 50000;

    auto &event = pythia.event;

    // -----------
    // Event loop
    // -----------

    for (int iEvent = 0; iEvent < nEvent; iEvent++) {
        if (!pythia.next()) continue;

        // Clear vectors
        particles.clear(); partons.clear();

        AK2_inclJets.clear(); AK4_inclJets.clear(); AK6_inclJets.clear(); AK8_inclJets.clear();
        AK2_sortedJets.clear(); AK4_sortedJets.clear(); AK6_sortedJets.clear(); AK8_sortedJets.clear();
        AK2_cutJets.clear(); AK4_cutJets.clear(); AK6_cutJets.clear(); AK8_cutJets.clear();
        AK2_constituents.clear(); AK4_constituents.clear(); AK6_constituents.clear(); AK8_constituents.clear();

        Parton_pt.clear(); Parton_eta.clear(); Parton_phi.clear(); Parton_id.clear();
        AK2_jet_pt.clear(); AK4_jet_pt.clear(); AK6_jet_pt.clear(); AK8_jet_pt.clear();
        AK2_jet_eta.clear(); AK4_jet_eta.clear(); AK6_jet_eta.clear(); AK8_jet_eta.clear();
        AK2_jet_phi.clear(); AK4_jet_phi.clear(); AK6_jet_phi.clear(); AK8_jet_phi.clear();
        AK2_match.clear(); AK4_match.clear(); AK6_match.clear(); AK8_match.clear(); Parton_match.clear();
        AK2_jet_matched_pt.clear(); AK4_jet_matched_pt.clear(); AK6_jet_matched_pt.clear(); AK8_jet_matched_pt.clear(); 
        AK2_jet_matched_eta.clear(); AK4_jet_matched_eta.clear(); AK6_jet_matched_eta.clear(); AK8_jet_matched_eta.clear();
        AK2_jet_matched_phi.clear(); AK4_jet_matched_phi.clear(); AK6_jet_matched_phi.clear(); AK8_jet_matched_phi.clear();
        AK2_jet_matched_delR.clear(); AK4_jet_matched_delR.clear(); AK6_jet_matched_delR.clear(); AK8_jet_matched_delR.clear();
        AK2_jet_matched_lambda11.clear(); AK4_jet_matched_lambda11.clear(); AK6_jet_matched_lambda11.clear(); AK8_jet_matched_lambda11.clear();
        AK2_delta_R.clear(); AK4_delta_R.clear(); AK6_delta_R.clear(); AK8_delta_R.clear();
        AK2_jet_sorted_matched_pt.clear(); AK4_jet_sorted_matched_pt.clear(); AK6_jet_sorted_matched_pt.clear(); AK8_jet_sorted_matched_pt.clear();
        AK2_jet_sorted_matched_eta.clear(); AK4_jet_sorted_matched_eta.clear(); AK6_jet_sorted_matched_eta.clear(); AK8_jet_sorted_matched_eta.clear();
        AK2_jet_sorted_matched_phi.clear(); AK4_jet_sorted_matched_phi.clear(); AK6_jet_sorted_matched_phi.clear(); AK8_jet_sorted_matched_phi.clear();
        AK2_jet_sorted_matched_lambda11.clear(); AK4_jet_sorted_matched_lambda11.clear(); AK6_jet_sorted_matched_lambda11.clear(); AK8_jet_sorted_matched_lambda11.clear();

        // -----------------------
        // Save parton properties
        // -----------------------
        nParton = 0;

        for (int j = 0; j < event.size(); j++) {
            if (TMath::Abs(event[j].status()) != 23) continue;
            // if (TMath::Abs(event[j].eta()) > 1.) continue;

            nParton++;

            Parton_pt.push_back(event[j].pT());
            Parton_eta.push_back(event[j].eta());
            Parton_phi.push_back(event[j].phi());
            Parton_id.push_back(event[j].id());

            fastjet::PseudoJet parton(event[j].px(), event[j].py(), event[j].pz(), event[j].e());
            parton.set_user_index(j);
            partons.push_back(parton);
        }

        // ---------------
        // Jet candidates
        // ---------------

        for (int j = 0; j < event.size(); j++) {
            // Skip non-final state particles.
            if (!event[j].isFinal()) continue;

            // Skip neutrinos.
            if (event[j].idAbs() == 12 || event[j].idAbs() == 14 || event[j].idAbs() == 16) continue;

            // Only |eta| < 2.0
            if (TMath::Abs(event[j].eta()) > 2.) continue;

            // Create pseudojet from particle.
            fastjet::PseudoJet particle(event[j].px(), event[j].py(), event[j].pz(), event[j].e());

            // Only pt > 150 MeV
            if (particle.pt() < 0.15) continue;

            // Label index
            particle.set_user_index(event[j].index());

            particles.push_back(particle);
        }

        if (particles.size() < 0) continue;

        // ----------------
        // Clustering jets
        // ----------------

        // R = 0.2
        fastjet::ClusterSequence AK2_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.2, fastjet::E_scheme, fastjet::Best));
        AK2_inclJets = AK2_clusterSeq.inclusive_jets();
        AK2_sortedJets = sorted_by_pt(AK2_inclJets);

        // R = 0.4
        fastjet::ClusterSequence AK4_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.4, fastjet::E_scheme, fastjet::Best));
        AK4_inclJets = AK4_clusterSeq.inclusive_jets();
        AK4_sortedJets = sorted_by_pt(AK4_inclJets);

        // R = 0.6
        fastjet::ClusterSequence AK6_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.6, fastjet::E_scheme, fastjet::Best));
        AK6_inclJets = AK6_clusterSeq.inclusive_jets();
        AK6_sortedJets = sorted_by_pt(AK6_inclJets);

        // R = 0.8
        fastjet::ClusterSequence AK8_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.8, fastjet::E_scheme, fastjet::Best));
        AK8_inclJets = AK8_clusterSeq.inclusive_jets();
        AK8_sortedJets = sorted_by_pt(AK8_inclJets);

        // Jet pt & eta cut
        for (int j = 0; j < AK2_sortedJets.size(); j++) {
            if (TMath::Abs(AK2_sortedJets[j].eta()) > 1.8) continue;
            // if (AK2_sortedJets[j].pt() < 10.) continue;

            AK2_cutJets.push_back(AK2_sortedJets[j]);
        }

        for (int j = 0; j < AK4_sortedJets.size(); j++) {
            if (TMath::Abs(AK4_sortedJets[j].eta()) > 1.6) continue;
            // if (AK4_sortedJets[j].pt() < 10.) continue;

            AK4_cutJets.push_back(AK4_sortedJets[j]);
        }

        for (int j = 0; j < AK6_sortedJets.size(); j++) {
            if (TMath::Abs(AK6_sortedJets[j].eta()) > 1.4) continue;
            // if (AK6_sortedJets[j].pt() < 10.) continue;

            AK6_cutJets.push_back(AK6_sortedJets[j]);
        }

        for (int j = 0; j < AK8_sortedJets.size(); j++) {
            if (TMath::Abs(AK8_sortedJets[j].eta()) > 1.2) continue;
            // if (AK8_sortedJets[j].pt() < 10.) continue;

            AK8_cutJets.push_back(AK8_sortedJets[j]);
        }

        // nJet
        AK2_nJet = AK2_cutJets.size();
        AK4_nJet = AK4_cutJets.size();
        AK6_nJet = AK6_cutJets.size();
        AK8_nJet = AK8_cutJets.size();

        // Write jet pt eta phi
        for (int j = 0; j < AK2_cutJets.size(); j++) {
            AK2_jet_pt.push_back(AK2_cutJets[j].pt());
            AK2_jet_eta.push_back(AK2_cutJets[j].eta());
            AK2_jet_phi.push_back(AK2_cutJets[j].phi_std());
        }

        for (int j = 0; j < AK4_cutJets.size(); j++) {
            AK4_jet_pt.push_back(AK4_cutJets[j].pt());
            AK4_jet_eta.push_back(AK4_cutJets[j].eta());
            AK4_jet_phi.push_back(AK4_cutJets[j].phi_std());
        }

        for (int j = 0; j < AK6_cutJets.size(); j++) {
            AK6_jet_pt.push_back(AK6_cutJets[j].pt());
            AK6_jet_eta.push_back(AK6_cutJets[j].eta());
            AK6_jet_phi.push_back(AK6_cutJets[j].phi_std());
        }

        for (int j = 0; j < AK8_cutJets.size(); j++) {
            AK8_jet_pt.push_back(AK8_cutJets[j].pt());
            AK8_jet_eta.push_back(AK8_cutJets[j].eta());
            AK8_jet_phi.push_back(AK8_cutJets[j].phi_std());
        }


        // // --------------------------
        // // Jet matching (within 0.2)
        // // --------------------------

        // // AK2
        // AK2_nMatchedJet = 0;
        // AK2_nUnmatchedJet = 0;

        // for (int j = 0; j < Parton_pt.size(); j++) {
        //     AK2_jet_sorted_matched_lambda11.push_back(0.);

        //     if (TMath::Abs(Parton_eta[j]) > 2.) {
        //         AK2_match.push_back(false);
        //         AK2_jet_sorted_matched_pt.push_back(0.);
        //         AK2_jet_sorted_matched_eta.push_back(0.);
        //         AK2_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     if (AK2_cutJets.size() == 0) {
        //         AK2_nUnmatchedJet++;
        //         AK2_match.push_back(false);
        //         AK2_jet_sorted_matched_pt.push_back(0.);
        //         AK2_jet_sorted_matched_eta.push_back(0.);
        //         AK2_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     AK2_delta_R.clear();

        //     for (int k = 0; k < AK2_cutJets.size(); k++) {
        //         AK2_delta_R.push_back(partons[j].delta_R(AK2_cutJets[k]));
        //     }

        //     auto AK2_delta_R_min = min_element(std::begin(AK2_delta_R), std::end(AK2_delta_R));

        //     if (*AK2_delta_R_min > 0.2) {
        //         AK2_nUnmatchedJet++;
        //         AK2_match.push_back(false);
        //         AK2_jet_sorted_matched_pt.push_back(0.);
        //         AK2_jet_sorted_matched_eta.push_back(0.);
        //         AK2_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     AK2_nMatchedJet++;
        //     AK2_match.push_back(true);
        //     AK2_jet_sorted_matched_pt.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].pt());
        //     AK2_jet_sorted_matched_eta.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].eta());
        //     AK2_jet_sorted_matched_phi.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].phi_std());
        //     AK2_jet_matched_pt.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].pt());
        //     AK2_jet_matched_eta.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].eta());
        //     AK2_jet_matched_phi.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].phi_std());
        //     AK2_jet_matched_delR.push_back(*AK2_delta_R_min);

        //     // Compute width
        //     AK2_jet_matched_lambda11.push_back(0.);

        //     AK2_constituents = AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].constituents();
            
        //     for (int k = 0; k < AK2_constituents.size(); k++) {
        //         AK2_jet_sorted_matched_lambda11.back() += AK2_constituents[k].pt()
        //             / AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].pt()
        //             * AK2_constituents[k].delta_R(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)])
        //             / 0.2;
                
        //         AK2_jet_matched_lambda11.back() += AK2_constituents[k].pt()
        //             / AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].pt()
        //             * AK2_constituents[k].delta_R(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)])
        //             / 0.2;
        //     }
        // }

        // // AK4
        // AK4_nMatchedJet = 0;
        // AK4_nUnmatchedJet = 0;

        // for (int j = 0; j < Parton_pt.size(); j++) {
        //     AK4_jet_sorted_matched_lambda11.push_back(0.);

        //     if (TMath::Abs(Parton_eta[j]) > 1.8) {
        //         AK4_match.push_back(false);
        //         AK4_jet_sorted_matched_pt.push_back(0.);
        //         AK4_jet_sorted_matched_eta.push_back(0.);
        //         AK4_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     if (AK4_cutJets.size() == 0) {
        //         AK4_nUnmatchedJet++;
        //         AK4_match.push_back(false);
        //         AK4_jet_sorted_matched_pt.push_back(0.);
        //         AK4_jet_sorted_matched_eta.push_back(0.);
        //         AK4_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     AK4_delta_R.clear();

        //     for (int k = 0; k < AK4_cutJets.size(); k++) {
        //         AK4_delta_R.push_back(partons[j].delta_R(AK4_cutJets[k]));
        //     }

        //     auto AK4_delta_R_min = min_element(std::begin(AK4_delta_R), std::end(AK4_delta_R));

        //     if (*AK4_delta_R_min > 0.2) {
        //         AK4_nUnmatchedJet++;
        //         AK4_match.push_back(false);
        //         AK4_jet_sorted_matched_pt.push_back(0.);
        //         AK4_jet_sorted_matched_eta.push_back(0.);
        //         AK4_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }


        //     AK4_nMatchedJet++;
        //     AK4_match.push_back(true);
        //     AK4_jet_sorted_matched_pt.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].pt());
        //     AK4_jet_sorted_matched_eta.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].eta());
        //     AK4_jet_sorted_matched_phi.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].phi_std());
        //     AK4_jet_matched_pt.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].pt());
        //     AK4_jet_matched_eta.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].eta());
        //     AK4_jet_matched_phi.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].phi_std());
        //     AK4_jet_matched_delR.push_back(*AK4_delta_R_min);
            
        //     // Compute width
        //     AK4_jet_matched_lambda11.push_back(0.);

        //     AK4_constituents = AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].constituents();
            
        //     for (int k = 0; k < AK4_constituents.size(); k++) {
        //         AK4_jet_sorted_matched_lambda11.back() += AK4_constituents[k].pt()
        //             / AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].pt()
        //             * AK4_constituents[k].delta_R(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)])
        //             / 0.4;
                
        //         AK4_jet_matched_lambda11.back() += AK4_constituents[k].pt()
        //             / AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].pt()
        //             * AK4_constituents[k].delta_R(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)])
        //             / 0.4;
        //     }
        // }

        // // AK6
        // AK6_nMatchedJet = 0;
        // AK6_nUnmatchedJet = 0;

        // for (int j = 0; j < Parton_pt.size(); j++) {
        //     AK6_jet_sorted_matched_lambda11.push_back(0.);

        //     if (TMath::Abs(Parton_eta[j]) > 1.6) {
        //         AK6_match.push_back(false);
        //         AK6_jet_sorted_matched_pt.push_back(0.);
        //         AK6_jet_sorted_matched_eta.push_back(0.);
        //         AK6_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }
            
        //     if (AK6_cutJets.size() == 0) {
        //         AK6_nUnmatchedJet++;
        //         AK6_match.push_back(false);
        //         AK6_jet_sorted_matched_pt.push_back(0.);
        //         AK6_jet_sorted_matched_eta.push_back(0.);
        //         AK6_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     AK6_delta_R.clear();

        //     for (int k = 0; k < AK6_cutJets.size(); k++) {
        //         AK6_delta_R.push_back(partons[j].delta_R(AK6_cutJets[k]));
        //     }

        //     auto AK6_delta_R_min = min_element(std::begin(AK6_delta_R), std::end(AK6_delta_R));

        //     if (*AK6_delta_R_min > 0.2) {
        //         AK6_nUnmatchedJet++;
        //         AK6_match.push_back(false);
        //         AK6_jet_sorted_matched_pt.push_back(0.);
        //         AK6_jet_sorted_matched_eta.push_back(0.);
        //         AK6_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     AK6_nMatchedJet++;
        //     AK6_match.push_back(true);
        //     AK6_jet_sorted_matched_pt.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].pt());
        //     AK6_jet_sorted_matched_eta.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].eta());
        //     AK6_jet_sorted_matched_phi.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].phi_std());
        //     AK6_jet_matched_pt.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].pt());
        //     AK6_jet_matched_eta.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].eta());
        //     AK6_jet_matched_phi.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].phi_std());
        //     AK6_jet_matched_delR.push_back(*AK6_delta_R_min);

        //     // Compute width
        //     AK6_jet_matched_lambda11.push_back(0.);

        //     AK6_constituents = AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].constituents();
            
        //     for (int k = 0; k < AK6_constituents.size(); k++) {
        //         AK6_jet_sorted_matched_lambda11.back() += AK6_constituents[k].pt()
        //             / AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].pt()
        //             * AK6_constituents[k].delta_R(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)])
        //             / 0.6;
                
        //         AK6_jet_matched_lambda11.back() += AK6_constituents[k].pt()
        //             / AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].pt()
        //             * AK6_constituents[k].delta_R(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)])
        //             / 0.6;
        //     }
        // }

        // // AK8
        // AK8_nMatchedJet = 0;
        // AK8_nUnmatchedJet = 0;

        // for (int j = 0; j < Parton_pt.size(); j++) {
        //     AK8_jet_sorted_matched_lambda11.push_back(0.);

        //     if (TMath::Abs(Parton_eta[j]) > 1.4) {
        //         AK8_match.push_back(false);
        //         AK8_jet_sorted_matched_pt.push_back(0.);
        //         AK8_jet_sorted_matched_eta.push_back(0.);
        //         AK8_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     if (AK8_cutJets.size() == 0) {
        //         AK8_nUnmatchedJet++;
        //         AK8_match.push_back(false);
        //         AK8_jet_sorted_matched_pt.push_back(0.);
        //         AK8_jet_sorted_matched_eta.push_back(0.);
        //         AK8_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     AK8_delta_R.clear();

        //     for (int k = 0; k < AK8_cutJets.size(); k++) {
        //         AK8_delta_R.push_back(partons[j].delta_R(AK8_cutJets[k]));
        //     }

        //     auto AK8_delta_R_min = min_element(std::begin(AK8_delta_R), std::end(AK8_delta_R));

        //     if (*AK8_delta_R_min > 0.2) {
        //         AK8_nUnmatchedJet++;
        //         AK8_match.push_back(false);
        //         AK8_jet_sorted_matched_pt.push_back(0.);
        //         AK8_jet_sorted_matched_eta.push_back(0.);
        //         AK8_jet_sorted_matched_phi.push_back(0.);
        //         continue;
        //     }

        //     AK8_nMatchedJet++;
        //     AK8_match.push_back(true);
        //     AK8_jet_sorted_matched_pt.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].pt());
        //     AK8_jet_sorted_matched_eta.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].eta());
        //     AK8_jet_sorted_matched_phi.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].phi_std());
        //     AK8_jet_matched_pt.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].pt());
        //     AK8_jet_matched_eta.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].eta());
        //     AK8_jet_matched_phi.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].phi_std());
        //     AK8_jet_matched_delR.push_back(*AK8_delta_R_min);

        //     // Compute width
        //     AK8_jet_matched_lambda11.push_back(0.);

        //     AK8_constituents = AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].constituents();
            
        //     for (int k = 0; k < AK8_constituents.size(); k++) {
        //         AK8_jet_sorted_matched_lambda11.back() += AK8_constituents[k].pt()
        //             / AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].pt()
        //             * AK8_constituents[k].delta_R(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)])
        //             / 0.8;
                
        //         AK8_jet_matched_lambda11.back() += AK8_constituents[k].pt()
        //             / AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].pt()
        //             * AK8_constituents[k].delta_R(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)])
        //             / 0.8;
        //     }
        // }





        // ----------------------------------------------------------
        // Jet matching (contain 50% pT of the parton decay products)
        // ----------------------------------------------------------

        // AK2
        AK2_nMatchedJet = 0;
        AK2_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            AK2_jet_sorted_matched_lambda11.push_back(0.);

            if (AK2_cutJets.size() == 0) {
                AK2_nUnmatchedJet++;
                AK2_match.push_back(false);
                AK2_jet_sorted_matched_pt.push_back(0.);
                AK2_jet_sorted_matched_eta.push_back(0.);
                AK2_jet_sorted_matched_phi.push_back(0.);
                continue;
            }

            AK2_delta_R.clear();

            int parton_index = partons[j].user_index();

            auto daughterList = event[parton_index].daughterListRecursive();

            for (int k = 0; k < AK2_cutJets.size(); k++) {
                double AK2_const_pt = 0;

                AK2_constituents.clear();
                AK2_constituents = AK2_cutJets[k].constituents();

                for (int l = 0; l < AK2_constituents.size(); l++) {
                    for (int m = 0; m < daughterList.size(); m++) {
                        if (AK2_constituents[l].user_index() != daughterList[m]) continue;
                        if (partons[j].delta_R(AK2_constituents[l]) > 1.) continue;

                        AK2_const_pt += AK2_constituents[l].pt();
                        break;
                    }

                    if (AK2_const_pt > 0.5*event[parton_index].pT()) break;
                }

                if (AK2_const_pt < 0.5*event[parton_index].pT()) continue;

                AK2_nMatchedJet++;
                AK2_match.push_back(true);
                AK2_jet_sorted_matched_pt.push_back(AK2_cutJets[k].pt());
                AK2_jet_sorted_matched_eta.push_back(AK2_cutJets[k].eta());
                AK2_jet_sorted_matched_phi.push_back(AK2_cutJets[k].phi_std());
                AK2_jet_matched_pt.push_back(AK2_cutJets[k].pt());
                AK2_jet_matched_eta.push_back(AK2_cutJets[k].eta());
                AK2_jet_matched_phi.push_back(AK2_cutJets[k].phi_std());
                AK2_jet_matched_delR.push_back(partons[j].delta_R(AK2_cutJets[k]));

                // Compute width
                AK2_jet_matched_lambda11.push_back(0.);
                
                for (int l = 0; l < AK2_constituents.size(); l++) {
                    AK2_jet_sorted_matched_lambda11.back() += AK2_constituents[l].pt()
                        / AK2_cutJets[k].pt()
                        * AK2_constituents[l].delta_R(AK2_cutJets[k])
                        / 0.2;
                    
                    AK2_jet_matched_lambda11.back() += AK2_constituents[l].pt()
                        / AK2_cutJets[k].pt()
                        * AK2_constituents[l].delta_R(AK2_cutJets[k])
                        / 0.2;
                }

                break;
            }

            if (AK2_match.size() < j+1) {
                AK2_nUnmatchedJet++;
                AK2_match.push_back(false);
                AK2_jet_sorted_matched_pt.push_back(0.);
                AK2_jet_sorted_matched_eta.push_back(0.);
                AK2_jet_sorted_matched_phi.push_back(0.);
            }
        }

        // AK4
        AK4_nMatchedJet = 0;
        AK4_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            AK4_jet_sorted_matched_lambda11.push_back(0.);

            if (AK4_cutJets.size() == 0) {
                AK4_nUnmatchedJet++;
                AK4_match.push_back(false);
                AK4_jet_sorted_matched_pt.push_back(0.);
                AK4_jet_sorted_matched_eta.push_back(0.);
                AK4_jet_sorted_matched_phi.push_back(0.);
                continue;
            }

            AK4_delta_R.clear();

            int parton_index = partons[j].user_index();

            auto daughterList = event[parton_index].daughterListRecursive();

            for (int k = 0; k < AK4_cutJets.size(); k++) {
                double AK4_const_pt = 0;

                AK4_constituents.clear();
                AK4_constituents = AK4_cutJets[k].constituents();

                for (int l = 0; l < AK4_constituents.size(); l++) {
                    for (int m = 0; m < daughterList.size(); m++) {
                        if (AK4_constituents[l].user_index() != daughterList[m]) continue;
                        if (partons[j].delta_R(AK4_constituents[l]) > 1.) continue;

                        AK4_const_pt += AK4_constituents[l].pt();
                        break;
                    }

                    if (AK4_const_pt > 0.5*event[parton_index].pT()) break;
                }

                if (AK4_const_pt < 0.5*event[parton_index].pT()) continue;

                AK4_nMatchedJet++;
                AK4_match.push_back(true);
                AK4_jet_sorted_matched_pt.push_back(AK4_cutJets[k].pt());
                AK4_jet_sorted_matched_eta.push_back(AK4_cutJets[k].eta());
                AK4_jet_sorted_matched_phi.push_back(AK4_cutJets[k].phi_std());
                AK4_jet_matched_pt.push_back(AK4_cutJets[k].pt());
                AK4_jet_matched_eta.push_back(AK4_cutJets[k].eta());
                AK4_jet_matched_phi.push_back(AK4_cutJets[k].phi_std());
                AK4_jet_matched_delR.push_back(partons[j].delta_R(AK4_cutJets[k]));

                // Compute width
                AK4_jet_matched_lambda11.push_back(0.);
                
                for (int l = 0; l < AK4_constituents.size(); l++) {
                    AK4_jet_sorted_matched_lambda11.back() += AK4_constituents[l].pt()
                        / AK4_cutJets[k].pt()
                        * AK4_constituents[l].delta_R(AK4_cutJets[k])
                        / 0.4;
                    
                    AK4_jet_matched_lambda11.back() += AK4_constituents[l].pt()
                        / AK4_cutJets[k].pt()
                        * AK4_constituents[l].delta_R(AK4_cutJets[k])
                        / 0.4;
                }

                break;
            }

            if (AK4_match.size() < j+1) {
                AK4_nUnmatchedJet++;
                AK4_match.push_back(false);
                AK4_jet_sorted_matched_pt.push_back(0.);
                AK4_jet_sorted_matched_eta.push_back(0.);
                AK4_jet_sorted_matched_phi.push_back(0.);
            }
        }

        // AK6
        AK6_nMatchedJet = 0;
        AK6_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            AK6_jet_sorted_matched_lambda11.push_back(0.);

            if (AK6_cutJets.size() == 0) {
                AK6_nUnmatchedJet++;
                AK6_match.push_back(false);
                AK6_jet_sorted_matched_pt.push_back(0.);
                AK6_jet_sorted_matched_eta.push_back(0.);
                AK6_jet_sorted_matched_phi.push_back(0.);
                continue;
            }

            AK6_delta_R.clear();

            int parton_index = partons[j].user_index();

            auto daughterList = event[parton_index].daughterListRecursive();

            for (int k = 0; k < AK6_cutJets.size(); k++) {
                double AK6_const_pt = 0;

                AK6_constituents.clear();
                AK6_constituents = AK6_cutJets[k].constituents();

                for (int l = 0; l < AK6_constituents.size(); l++) {
                    for (int m = 0; m < daughterList.size(); m++) {
                        if (AK6_constituents[l].user_index() != daughterList[m]) continue;
                        if (partons[j].delta_R(AK6_constituents[l]) > 1.) continue;

                        AK6_const_pt += AK6_constituents[l].pt();
                        break;
                    }

                    if (AK6_const_pt > 0.5*event[parton_index].pT()) break;
                }

                if (AK6_const_pt < 0.5*event[parton_index].pT()) continue;

                AK6_nMatchedJet++;
                AK6_match.push_back(true);
                AK6_jet_sorted_matched_pt.push_back(AK6_cutJets[k].pt());
                AK6_jet_sorted_matched_eta.push_back(AK6_cutJets[k].eta());
                AK6_jet_sorted_matched_phi.push_back(AK6_cutJets[k].phi_std());
                AK6_jet_matched_pt.push_back(AK6_cutJets[k].pt());
                AK6_jet_matched_eta.push_back(AK6_cutJets[k].eta());
                AK6_jet_matched_phi.push_back(AK6_cutJets[k].phi_std());
                AK6_jet_matched_delR.push_back(partons[j].delta_R(AK6_cutJets[k]));

                // Compute width
                AK6_jet_matched_lambda11.push_back(0.);
                
                for (int l = 0; l < AK6_constituents.size(); l++) {
                    AK6_jet_sorted_matched_lambda11.back() += AK6_constituents[l].pt()
                        / AK6_cutJets[k].pt()
                        * AK6_constituents[l].delta_R(AK6_cutJets[k])
                        / 0.6;
                    
                    AK6_jet_matched_lambda11.back() += AK6_constituents[l].pt()
                        / AK6_cutJets[k].pt()
                        * AK6_constituents[l].delta_R(AK6_cutJets[k])
                        / 0.6;
                }

                break;
            }

            if (AK6_match.size() < j+1) {
                AK6_nUnmatchedJet++;
                AK6_match.push_back(false);
                AK6_jet_sorted_matched_pt.push_back(0.);
                AK6_jet_sorted_matched_eta.push_back(0.);
                AK6_jet_sorted_matched_phi.push_back(0.);
            }
        }

        // AK8
        AK8_nMatchedJet = 0;
        AK8_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            AK8_jet_sorted_matched_lambda11.push_back(0.);

            if (AK8_cutJets.size() == 0) {
                AK8_nUnmatchedJet++;
                AK8_match.push_back(false);
                AK8_jet_sorted_matched_pt.push_back(0.);
                AK8_jet_sorted_matched_eta.push_back(0.);
                AK8_jet_sorted_matched_phi.push_back(0.);
                continue;
            }

            AK8_delta_R.clear();

            int parton_index = partons[j].user_index();

            auto daughterList = event[parton_index].daughterListRecursive();

            for (int k = 0; k < AK8_cutJets.size(); k++) {
                double AK8_const_pt = 0;

                AK8_constituents.clear();
                AK8_constituents = AK8_cutJets[k].constituents();

                for (int l = 0; l < AK8_constituents.size(); l++) {
                    for (int m = 0; m < daughterList.size(); m++) {
                        if (AK8_constituents[l].user_index() != daughterList[m]) continue;
                        if (partons[j].delta_R(AK8_constituents[l]) > 1.) continue;

                        AK8_const_pt += AK8_constituents[l].pt();
                        break;
                    }

                    if (AK8_const_pt > 0.5*event[parton_index].pT()) break;
                }

                if (AK8_const_pt < 0.5*event[parton_index].pT()) continue;

                AK8_nMatchedJet++;
                AK8_match.push_back(true);
                AK8_jet_sorted_matched_pt.push_back(AK8_cutJets[k].pt());
                AK8_jet_sorted_matched_eta.push_back(AK8_cutJets[k].eta());
                AK8_jet_sorted_matched_phi.push_back(AK8_cutJets[k].phi_std());
                AK8_jet_matched_pt.push_back(AK8_cutJets[k].pt());
                AK8_jet_matched_eta.push_back(AK8_cutJets[k].eta());
                AK8_jet_matched_phi.push_back(AK8_cutJets[k].phi_std());
                AK8_jet_matched_delR.push_back(partons[j].delta_R(AK8_cutJets[k]));

                // Compute width
                AK8_jet_matched_lambda11.push_back(0.);
                
                for (int l = 0; l < AK8_constituents.size(); l++) {
                    AK8_jet_sorted_matched_lambda11.back() += AK8_constituents[l].pt()
                        / AK8_cutJets[k].pt()
                        * AK8_constituents[l].delta_R(AK8_cutJets[k])
                        / 0.8;
                    
                    AK8_jet_matched_lambda11.back() += AK8_constituents[l].pt()
                        / AK8_cutJets[k].pt()
                        * AK8_constituents[l].delta_R(AK8_cutJets[k])
                        / 0.8;
                }

                break;
            }

            if (AK8_match.size() < j+1) {
                AK8_nUnmatchedJet++;
                AK8_match.push_back(false);
                AK8_jet_sorted_matched_pt.push_back(0.);
                AK8_jet_sorted_matched_eta.push_back(0.);
                AK8_jet_sorted_matched_phi.push_back(0.);
            }
        }

        // Record Parton_match
        nMatchedParton = 0;
        nUnmatchedParton = 0;

        for (int j = 0; j < AK2_match.size(); j++) {
            if (AK2_match[j] == true && AK4_match[j] == true && AK6_match[j] == true && AK8_match[j] == true) {
                Parton_match.push_back(true);
                nMatchedParton++;
            } else {
                Parton_match.push_back(false);
                nUnmatchedParton++;
            }

        }

        tree->Fill();
    }
    
    output->cd();
    output->Write();
    output->Close();

    return 0;
}