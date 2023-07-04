#include <iostream>
#include <vector>
#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"

int main() {
    TFile *output = new TFile("rootfiles/events.root", "RECREATE");

    TTree *tree = new TTree("tree", "tree");

    std::vector<float> AK2_jet_pt, AK4_jet_pt, AK6_jet_pt, AK8_jet_pt;
    std::vector<float> AK2_jet_eta, AK4_jet_eta, AK6_jet_eta, AK8_jet_eta;
    std::vector<float> AK2_jet_phi, AK4_jet_phi, AK6_jet_phi, AK8_jet_phi;

    tree->Branch("AK2_jet_pt", &AK2_jet_pt);
    tree->Branch("AK4_jet_pt", &AK4_jet_pt);
    tree->Branch("AK6_jet_pt", &AK6_jet_pt);
    tree->Branch("AK8_jet_pt", &AK8_jet_pt);

    tree->Branch("AK2_jet_eta", &AK2_jet_eta);
    tree->Branch("AK4_jet_eta", &AK4_jet_eta);
    tree->Branch("AK6_jet_eta", &AK6_jet_eta);
    tree->Branch("AK8_jet_eta", &AK8_jet_eta);

    tree->Branch("AK2_jet_phi", &AK2_jet_phi);
    tree->Branch("AK4_jet_phi", &AK4_jet_phi);
    tree->Branch("AK6_jet_phi", &AK6_jet_phi);
    tree->Branch("AK8_jet_phi", &AK8_jet_phi);

    Pythia8::Pythia pythia;

    pythia.readString("Beams::idA = 2212");
    pythia.readString("Beams::idB = 2212");
    pythia.readString("Beams::eCM = 13600");
    pythia.readString("HardQCD:all = on");
    // pythia.readString("SoftQCD:all = on");

    pythia.init();

    int nEvent = 10000;

    auto &event = pythia.event;

    std::vector<fastjet::PseudoJet> particles, AK2_inclJets, AK2_sortedJets, AK4_inclJets, AK4_sortedJets,
                                    AK6_inclJets, AK6_sortedJets, AK8_inclJets, AK8_sortedJets;

    // -----------
    // Event loop
    // -----------

    for (int iEvent = 0; iEvent < nEvent; iEvent++) {
        if (!pythia.next()) continue;

        // Clear vectors
        particles.clear();
        AK2_jet_pt.clear(); AK4_jet_pt.clear(); AK6_jet_pt.clear(); AK8_jet_pt.clear();
        AK2_jet_eta.clear(); AK4_jet_eta.clear(); AK6_jet_eta.clear(); AK8_jet_eta.clear();
        AK2_jet_phi.clear(); AK4_jet_phi.clear(); AK6_jet_phi.clear(); AK8_jet_phi.clear();

        for (int j = 0; j < event.size(); j++) {
            // Skip non-final state particles.
            if (!event[j].isFinal()) continue;

            // Skip neutrinos.
            if (event[j].idAbs() == 12 || event[j].idAbs() == 14 || event[j].idAbs() == 16) continue;

            // Only |eta| < 3.6
            if (abs(event[j].eta()) > 3.6) continue;

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

        // R = 0.2.
        fastjet::ClusterSequence AK2_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.2, fastjet::E_scheme, fastjet::Best));
        AK2_inclJets = AK2_clusterSeq.inclusive_jets();
        AK2_sortedJets = sorted_by_pt(AK2_inclJets);

        // R = 0.4.
        fastjet::ClusterSequence AK4_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.4, fastjet::E_scheme, fastjet::Best));
        AK4_inclJets = AK4_clusterSeq.inclusive_jets();
        AK4_sortedJets = sorted_by_pt(AK4_inclJets);

        // R = 0.6.
        fastjet::ClusterSequence AK6_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.6, fastjet::E_scheme, fastjet::Best));
        AK6_inclJets = AK6_clusterSeq.inclusive_jets();
        AK6_sortedJets = sorted_by_pt(AK6_inclJets);

        // R = 0.8.
        fastjet::ClusterSequence AK8_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.8, fastjet::E_scheme, fastjet::Best));
        AK8_inclJets = AK8_clusterSeq.inclusive_jets();
        AK8_sortedJets = sorted_by_pt(AK8_inclJets);

        // ------------------------
        // Obtain jet pt, eta, phi
        // ------------------------

        for (int j = 0; j < AK2_sortedJets.size(); j++) {
            AK2_jet_pt.push_back(AK2_sortedJets[j].pt());
            AK2_jet_eta.push_back(AK2_sortedJets[j].eta());
            AK2_jet_phi.push_back(AK2_sortedJets[j].phi());
        }

        for (int j = 0; j < AK4_sortedJets.size(); j++) {
            AK4_jet_pt.push_back(AK4_sortedJets[j].pt());
            AK4_jet_eta.push_back(AK4_sortedJets[j].eta());
            AK4_jet_phi.push_back(AK4_sortedJets[j].phi());
        }

        for (int j = 0; j < AK6_sortedJets.size(); j++) {
            AK6_jet_pt.push_back(AK6_sortedJets[j].pt());
            AK6_jet_eta.push_back(AK6_sortedJets[j].eta());
            AK6_jet_phi.push_back(AK6_sortedJets[j].phi());
        }

        for (int j = 0; j < AK8_sortedJets.size(); j++) {
            AK8_jet_pt.push_back(AK8_sortedJets[j].pt());
            AK8_jet_eta.push_back(AK8_sortedJets[j].eta());
            AK8_jet_phi.push_back(AK8_sortedJets[j].phi());
        }

        tree->Fill();
    }
    
    output->Write();
    output->Close();

    return 0;
}