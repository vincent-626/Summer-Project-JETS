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

    int nParton, nEtaCutParton;
    int AK2_nJet, AK4_nJet, AK6_nJet, AK8_nJet;
    int AK2_nMatchedJet, AK4_nMatchedJet, AK6_nMatchedJet, AK8_nMatchedJet;
    int AK2_nUnmatchedJet, AK4_nUnmatchedJet, AK6_nUnmatchedJet, AK8_nUnmatchedJet;

    std::vector<float>  Parton_pt, Parton_eta, Parton_phi, Parton_id,
                        AK2_jet_pt, AK4_jet_pt, AK6_jet_pt, AK8_jet_pt,
                        AK2_jet_eta, AK4_jet_eta, AK6_jet_eta, AK8_jet_eta,
                        AK2_jet_phi, AK4_jet_phi, AK6_jet_phi, AK8_jet_phi,
                        AK2_jet_matched_pt, AK4_jet_matched_pt, AK6_jet_matched_pt, AK8_jet_matched_pt,
                        AK2_jet_matched_eta, AK4_jet_matched_eta, AK6_jet_matched_eta, AK8_jet_matched_eta,
                        AK2_jet_matched_phi, AK4_jet_matched_phi, AK6_jet_matched_phi, AK8_jet_matched_phi,
                        AK2_jet_matched_delR, AK4_jet_matched_delR, AK6_jet_matched_delR, AK8_jet_matched_delR;

    std::vector<fastjet::PseudoJet> particles, partons,
                                    AK2_inclJets, AK2_sortedJets, AK2_cutJets,
                                    AK4_inclJets, AK4_sortedJets, AK4_cutJets,
                                    AK6_inclJets, AK6_sortedJets, AK6_cutJets,
                                    AK8_inclJets, AK8_sortedJets, AK8_cutJets;

    float   AK2_delta_R1, AK2_delta_R2, AK2_delta_R1_temp, AK2_delta_R2_temp,
            AK4_delta_R1, AK4_delta_R2, AK4_delta_R1_temp, AK4_delta_R2_temp,
            AK6_delta_R1, AK6_delta_R2, AK6_delta_R1_temp, AK6_delta_R2_temp,
            AK8_delta_R1, AK8_delta_R2, AK8_delta_R1_temp, AK8_delta_R2_temp; 
    
    int AK2_n1, AK2_n2, AK2_n2_temp,
        AK4_n1, AK4_n2, AK4_n2_temp,
        AK6_n1, AK6_n2, AK6_n2_temp,
        AK8_n1, AK8_n2, AK8_n2_temp;

    int AK2_loopOption, AK4_loopOption, AK6_loopOption, AK8_loopOption;
    std::vector<float> AK2_delta_R, AK4_delta_R, AK6_delta_R, AK8_delta_R;

    tree->Branch("nParton", &nParton);
    tree->Branch("nEtaCutParton", &nEtaCutParton);
    tree->Branch("Parton_pt", &Parton_pt);
    tree->Branch("Parton_eta", &Parton_eta);
    tree->Branch("Parton_phi", &Parton_phi);
    tree->Branch("Parton_id", &Parton_id);

    tree->Branch("AK2_nJet", &AK2_nJet);
    tree->Branch("AK2_jet_pt", &AK2_jet_pt);
    tree->Branch("AK2_jet_eta", &AK2_jet_eta);
    tree->Branch("AK2_jet_phi", &AK2_jet_phi);
    tree->Branch("AK2_nMatchedJet", &AK2_nMatchedJet);
    tree->Branch("AK2_nUnmatchedJet", &AK2_nUnmatchedJet);
    tree->Branch("AK2_jet_matched_pt", &AK2_jet_matched_pt);
    tree->Branch("AK2_jet_matched_eta", &AK2_jet_matched_eta);
    tree->Branch("AK2_jet_matched_phi", &AK2_jet_matched_phi);
    tree->Branch("AK2_jet_matched_delR", &AK2_jet_matched_delR);

    tree->Branch("AK4_nJet", &AK4_nJet);
    tree->Branch("AK4_jet_pt", &AK4_jet_pt);
    tree->Branch("AK4_jet_eta", &AK4_jet_eta);
    tree->Branch("AK4_jet_phi", &AK4_jet_phi);
    tree->Branch("AK4_nMatchedJet", &AK4_nMatchedJet);
    tree->Branch("AK4_nUnmatchedJet", &AK4_nUnmatchedJet);
    tree->Branch("AK4_jet_matched_pt", &AK4_jet_matched_pt);
    tree->Branch("AK4_jet_matched_eta", &AK4_jet_matched_eta);
    tree->Branch("AK4_jet_matched_phi", &AK4_jet_matched_phi);
    tree->Branch("AK4_jet_matched_delR", &AK4_jet_matched_delR);

    tree->Branch("AK6_nJet", &AK6_nJet);
    tree->Branch("AK6_jet_pt", &AK6_jet_pt);
    tree->Branch("AK6_jet_eta", &AK6_jet_eta);
    tree->Branch("AK6_jet_phi", &AK6_jet_phi);
    tree->Branch("AK6_nMatchedJet", &AK6_nMatchedJet);
    tree->Branch("AK6_nUnmatchedJet", &AK6_nUnmatchedJet);
    tree->Branch("AK6_jet_matched_pt", &AK6_jet_matched_pt);
    tree->Branch("AK6_jet_matched_eta", &AK6_jet_matched_eta);
    tree->Branch("AK6_jet_matched_phi", &AK6_jet_matched_phi);
    tree->Branch("AK6_jet_matched_delR", &AK6_jet_matched_delR);

    tree->Branch("AK8_nJet", &AK8_nJet);
    tree->Branch("AK8_jet_pt", &AK8_jet_pt);
    tree->Branch("AK8_jet_eta", &AK8_jet_eta);    
    tree->Branch("AK8_jet_phi", &AK8_jet_phi);
    tree->Branch("AK8_nMatchedJet", &AK8_nMatchedJet);
    tree->Branch("AK8_nUnmatchedJet", &AK8_nUnmatchedJet);
    tree->Branch("AK8_jet_matched_pt", &AK8_jet_matched_pt);
    tree->Branch("AK8_jet_matched_eta", &AK8_jet_matched_eta);
    tree->Branch("AK8_jet_matched_phi", &AK8_jet_matched_phi);
    tree->Branch("AK8_jet_matched_delR", &AK8_jet_matched_delR);

    // Initialize pythia
    Pythia8::Pythia pythia;

    pythia.readString("Beams::idA = 2212");
    pythia.readString("Beams::idB = 2212");
    pythia.readString("Beams::eCM = 13600");
    pythia.readString("HardQCD:all = on");
    pythia.readString("PhaseSpace:pTHatMin = 40.");
    pythia.readString("PartonLevel:ISR = off");
    pythia.readString("PartonLevel:FSR = off");
    pythia.readString("PartonLevel:MPI = off");

    pythia.init();

    int nEvent = 10000;

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

        Parton_pt.clear(); Parton_eta.clear(); Parton_phi.clear(); Parton_id.clear();
        AK2_jet_pt.clear(); AK4_jet_pt.clear(); AK6_jet_pt.clear(); AK8_jet_pt.clear();
        AK2_jet_eta.clear(); AK4_jet_eta.clear(); AK6_jet_eta.clear(); AK8_jet_eta.clear();
        AK2_jet_phi.clear(); AK4_jet_phi.clear(); AK6_jet_phi.clear(); AK8_jet_phi.clear();
        AK2_jet_matched_pt.clear(); AK4_jet_matched_pt.clear(); AK6_jet_matched_pt.clear(); AK8_jet_matched_pt.clear(); 
        AK2_jet_matched_eta.clear(); AK4_jet_matched_eta.clear(); AK6_jet_matched_eta.clear(); AK8_jet_matched_eta.clear(); 
        AK2_jet_matched_phi.clear(); AK4_jet_matched_phi.clear(); AK6_jet_matched_phi.clear(); AK8_jet_matched_phi.clear(); 
        AK2_jet_matched_delR.clear(); AK4_jet_matched_delR.clear(); AK6_jet_matched_delR.clear(); AK8_jet_matched_delR.clear(); 
        AK2_delta_R.clear(); AK4_delta_R.clear(); AK6_delta_R.clear(); AK8_delta_R.clear();

        // -----------------------
        // Save parton properties
        // -----------------------
        nParton = 0;
        nEtaCutParton = 0;

        for (int j = 0; j < event.size(); j++) {
            if (TMath::Abs(event[j].status()) != 23) continue;
            if (TMath::Abs(event[j].eta()) > 1.) continue;

            nParton++;
            nEtaCutParton++;

            Parton_pt.push_back(event[j].pT());
            Parton_eta.push_back(event[j].eta());
            Parton_phi.push_back(event[j].phi());
            Parton_id.push_back(event[j].id());

            fastjet::PseudoJet parton(event[j].px(), event[j].py(), event[j].pz(), event[j].e());
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

            // Only |eta| < 3.6
            if (TMath::Abs(event[j].eta()) > 3.6) continue;

            // Create pseudojet from particle.
            fastjet::PseudoJet particle(event[j].px(), event[j].py(), event[j].pz(), event[j].e());

            // Only pt > 150 MeV
            if (particle.pt() < 0.15) continue;

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
            if (AK2_sortedJets[j].pt() < 10.) continue;

            AK2_cutJets.push_back(AK2_sortedJets[j]);
        }

        for (int j = 0; j < AK4_sortedJets.size(); j++) {
            if (TMath::Abs(AK4_sortedJets[j].eta()) > 1.6) continue;
            if (AK4_sortedJets[j].pt() < 10.) continue;

            AK4_cutJets.push_back(AK4_sortedJets[j]);
        }

        for (int j = 0; j < AK6_sortedJets.size(); j++) {
            if (TMath::Abs(AK6_sortedJets[j].eta()) > 1.4) continue;
            if (AK6_sortedJets[j].pt() < 10.) continue;

            AK6_cutJets.push_back(AK6_sortedJets[j]);
        }

        for (int j = 0; j < AK8_sortedJets.size(); j++) {
            if (TMath::Abs(AK8_sortedJets[j].eta()) > 1.2) continue;
            if (AK8_sortedJets[j].pt() < 10.) continue;

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

        // ------------------------------------
        // Jet matching (only the hardest jet)
        // ------------------------------------

        // // AK2
        // AK2_nMatchedJet = 0;
        // AK2_nUnmatchedJet = 0;

        // if (AK2_cutJets.size() != 0) {
        //     AK2_delta_R1 = AK2_cutJets[0].delta_R(partons[0]);
        //     AK2_delta_R2 = AK2_cutJets[0].delta_R(partons[1]);

        //     if (!(AK2_delta_R1 < 0.2 || AK2_delta_R2 < 0.2)) {
        //         AK2_nUnmatchedJet++;
        //     } else {
        //         AK2_nMatchedJet++;
        //         AK2_jet_matched_pt.push_back(AK2_cutJets[0].pt());
        //         AK2_jet_matched_eta.push_back(AK2_cutJets[0].eta());
        //         AK2_jet_matched_phi.push_back(AK2_cutJets[0].phi_std());
        //         AK2_jet_matched_delR.push_back(TMath::Min(AK2_delta_R1, AK2_delta_R2));
        //     }
        // }

        // // AK4
        // AK4_nMatchedJet = 0;
        // AK4_nUnmatchedJet = 0;

        // if (AK4_cutJets.size() != 0) {
        //     AK4_delta_R1 = AK4_cutJets[0].delta_R(partons[0]);
        //     AK4_delta_R2 = AK4_cutJets[0].delta_R(partons[1]);

        //     if (!(AK4_delta_R1 < 0.2 || AK4_delta_R2 < 0.2)) {
        //         AK4_nUnmatchedJet++;
        //     } else {
        //         AK4_nMatchedJet++;
        //         AK4_jet_matched_pt.push_back(AK4_cutJets[0].pt());
        //         AK4_jet_matched_eta.push_back(AK4_cutJets[0].eta());
        //         AK4_jet_matched_phi.push_back(AK4_cutJets[0].phi_std());
        //         AK4_jet_matched_delR.push_back(TMath::Min(AK4_delta_R1, AK4_delta_R2));
        //     }
        // }

        // // AK6
        // AK6_nMatchedJet = 0;
        // AK6_nUnmatchedJet = 0;

        // if (AK6_cutJets.size() != 0) {
        //     AK6_delta_R1 = AK6_cutJets[0].delta_R(partons[0]);
        //     AK6_delta_R2 = AK6_cutJets[0].delta_R(partons[1]);

        //     if (!(AK6_delta_R1 < 0.2 || AK6_delta_R2 < 0.2)) {
        //         AK6_nUnmatchedJet++;
        //     } else {
        //         AK6_nMatchedJet++;
        //         AK6_jet_matched_pt.push_back(AK6_cutJets[0].pt());
        //         AK6_jet_matched_eta.push_back(AK6_cutJets[0].eta());
        //         AK6_jet_matched_phi.push_back(AK6_cutJets[0].phi_std());
        //         AK6_jet_matched_delR.push_back(TMath::Min(AK6_delta_R1, AK6_delta_R2));
        //     }
        // }

        // // AK8
        // AK8_nMatchedJet = 0;
        // AK8_nUnmatchedJet = 0;

        // if (AK8_cutJets.size() != 0) {
        //     AK8_delta_R1 = AK8_cutJets[0].delta_R(partons[0]);
        //     AK8_delta_R2 = AK8_cutJets[0].delta_R(partons[1]);

        //     if (!(AK8_delta_R1 < 0.2 || AK8_delta_R2 < 0.2)) {
        //         AK8_nUnmatchedJet++;
        //     } else {
        //         AK8_nMatchedJet++;
        //         AK8_jet_matched_pt.push_back(AK8_cutJets[0].pt());
        //         AK8_jet_matched_eta.push_back(AK8_cutJets[0].eta());
        //         AK8_jet_matched_phi.push_back(AK8_cutJets[0].phi_std());
        //         AK8_jet_matched_delR.push_back(TMath::Min(AK8_delta_R1, AK8_delta_R2));
        //     }
        // }

        // ------------------------
        // Jet matching (all jets)
        // ------------------------

        // AK2
        AK2_nMatchedJet = 0;
        AK2_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            if (AK2_cutJets.size() == 0) {
                AK2_nUnmatchedJet++;
                continue;
            }

            AK2_delta_R.clear();

            for (int k = 0; k < AK2_cutJets.size(); k++) {
                AK2_delta_R.push_back(partons[j].delta_R(AK2_cutJets[k]));
            }

            auto AK2_delta_R_min = min_element(std::begin(AK2_delta_R), std::end(AK2_delta_R));

            if (*AK2_delta_R_min > 0.2) {
                AK2_nUnmatchedJet++;
                continue;
            }

            AK2_nMatchedJet++;
            AK2_jet_matched_pt.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].pt());
            AK2_jet_matched_eta.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].eta());
            AK2_jet_matched_phi.push_back(AK2_cutJets[std::distance(AK2_delta_R.begin(), AK2_delta_R_min)].phi_std());
            AK2_jet_matched_delR.push_back(*AK2_delta_R_min);
        }

        // AK4
        AK4_nMatchedJet = 0;
        AK4_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            if (AK4_cutJets.size() == 0) {
                AK4_nUnmatchedJet++;
                continue;
            }

            AK4_delta_R.clear();

            for (int k = 0; k < AK4_cutJets.size(); k++) {
                AK4_delta_R.push_back(partons[j].delta_R(AK4_cutJets[k]));
            }

            auto AK4_delta_R_min = min_element(std::begin(AK4_delta_R), std::end(AK4_delta_R));

            if (*AK4_delta_R_min > 0.2) {
                AK4_nUnmatchedJet++;
                continue;
            }


            AK4_nMatchedJet++;
            AK4_jet_matched_pt.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].pt());
            AK4_jet_matched_eta.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].eta());
            AK4_jet_matched_phi.push_back(AK4_cutJets[std::distance(AK4_delta_R.begin(), AK4_delta_R_min)].phi_std());

            AK4_jet_matched_delR.push_back(*AK4_delta_R_min);
        }

        // AK6
        AK6_nMatchedJet = 0;
        AK6_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            if (AK6_cutJets.size() == 0) {
                AK6_nUnmatchedJet++;
                continue;
            }

            AK6_delta_R.clear();

            for (int k = 0; k < AK6_cutJets.size(); k++) {
                AK6_delta_R.push_back(partons[j].delta_R(AK6_cutJets[k]));
            }

            auto AK6_delta_R_min = min_element(std::begin(AK6_delta_R), std::end(AK6_delta_R));

            if (*AK6_delta_R_min > 0.2) {
                AK6_nUnmatchedJet++;
                continue;
            }

            AK6_nMatchedJet++;
            AK6_jet_matched_pt.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].pt());
            AK6_jet_matched_eta.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].eta());
            AK6_jet_matched_phi.push_back(AK6_cutJets[std::distance(AK6_delta_R.begin(), AK6_delta_R_min)].phi_std());
            AK6_jet_matched_delR.push_back(*AK6_delta_R_min);
        }

        // AK8
        AK8_nMatchedJet = 0;
        AK8_nUnmatchedJet = 0;

        for (int j = 0; j < Parton_pt.size(); j++) {
            if (AK8_cutJets.size() == 0) {
                AK8_nUnmatchedJet++;
                continue;
            }

            AK8_delta_R.clear();

            for (int k = 0; k < AK8_cutJets.size(); k++) {
                AK8_delta_R.push_back(partons[j].delta_R(AK8_cutJets[k]));
            }

            auto AK8_delta_R_min = min_element(std::begin(AK8_delta_R), std::end(AK8_delta_R));

            if (*AK8_delta_R_min > 0.2) {
                AK8_nUnmatchedJet++;
                continue;
            }

            AK8_nMatchedJet++;
            AK8_jet_matched_pt.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].pt());
            AK8_jet_matched_eta.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].eta());
            AK8_jet_matched_phi.push_back(AK8_cutJets[std::distance(AK8_delta_R.begin(), AK8_delta_R_min)].phi_std());
            AK8_jet_matched_delR.push_back(*AK8_delta_R_min);
        }

        tree->Fill();
    }
    
    output->Write();
    output->Close();

    return 0;
}