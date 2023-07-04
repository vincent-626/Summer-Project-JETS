#include <iostream>
#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"

int main() {
    TFile *output = new TFile("rootfiles/events.root", "RECREATE");

    TTree *tree = new TTree("tree", "tree");

    int AK2_jetCountIncl, AK2_jetCount10, AK2_jetCount20;
    int AK4_jetCountIncl, AK4_jetCount10, AK4_jetCount20;
    int AK6_jetCountIncl, AK6_jetCount10, AK6_jetCount20;

    tree->Branch("AK2_jetCountIncl", &AK2_jetCountIncl, "AK2_jetCountIncl/I");
    tree->Branch("AK2_jetCount10", &AK2_jetCount10, "AK2_jetCount10/I");
    tree->Branch("AK2_jetCount20", &AK2_jetCount20, "AK2_jetCount20/I");
    tree->Branch("AK4_jetCountIncl", &AK4_jetCountIncl, "AK4_jetCountIncl/I");
    tree->Branch("AK4_jetCount10", &AK4_jetCount10, "AK4_jetCount10/I");
    tree->Branch("AK4_jetCount20", &AK4_jetCount20, "AK4_jetCount20/I");
    tree->Branch("AK6_jetCountIncl", &AK6_jetCountIncl, "AK6_jetCountIncl/I");
    tree->Branch("AK6_jetCount10", &AK6_jetCount10, "AK6_jetCount10/I");
    tree->Branch("AK6_jetCount20", &AK6_jetCount20, "AK6_jetCount20/I");

    Pythia8::Pythia pythia;

    pythia.readString("Beams::idA = 2212");
    pythia.readString("Beams::idB = 2212");
    pythia.readString("Beams::eCM = 13600");
    pythia.readString("SoftQCD:all = on");
    pythia.readString("HardQCD:all = on");

    pythia.init();

    int nEvent = 100000;

    auto &event = pythia.event;

    std::vector<fastjet::PseudoJet> particles, AK2_inclJets, AK2_sortedJets, AK4_inclJets, AK4_sortedJets, AK6_inclJets, AK6_sortedJets;

    for (int iEvent = 0; iEvent < nEvent; iEvent++) {
        if (!pythia.next()) continue;

        // Clear vector of pseudojets and fill it with final state particles.
        particles.clear();

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

        // Cluster jets with R = 0.2.
        fastjet::ClusterSequence AK2_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.2, fastjet::E_scheme, fastjet::Best));
        AK2_inclJets = AK2_clusterSeq.inclusive_jets();
        AK2_sortedJets = sorted_by_pt(AK2_inclJets);

        AK2_jetCountIncl = 0;
        AK2_jetCount10 = 0;
        AK2_jetCount20 = 0;

        for (int j = 0; j < AK2_sortedJets.size(); j++) {
            if (abs(AK2_sortedJets[j].eta()) > 0.7) continue;

            AK2_jetCountIncl++;
            if (AK2_sortedJets[j].pt() > 10) AK2_jetCount10++;
            if (AK2_sortedJets[j].pt() > 20) AK2_jetCount20++;
        }

        // Cluster jets with R = 0.4.
        fastjet::ClusterSequence AK4_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.4, fastjet::E_scheme, fastjet::Best));
        AK4_inclJets = AK4_clusterSeq.inclusive_jets();
        AK4_sortedJets = sorted_by_pt(AK4_inclJets);

        AK4_jetCountIncl = 0;
        AK4_jetCount10 = 0;
        AK4_jetCount20 = 0;

        for (int j = 0; j < AK4_sortedJets.size(); j++) {
            if (abs(AK4_sortedJets[j].eta()) > 0.5) continue;

            AK4_jetCountIncl++;
            if (AK4_sortedJets[j].pt() > 10) AK4_jetCount10++;
            if (AK4_sortedJets[j].pt() > 20) AK4_jetCount20++;
        }

        // Cluster jets with R = 0.6.
        fastjet::ClusterSequence AK6_clusterSeq(particles, fastjet::JetDefinition(
            fastjet::antikt_algorithm, 0.6, fastjet::E_scheme, fastjet::Best));
        AK6_inclJets = AK6_clusterSeq.inclusive_jets();
        AK6_sortedJets = sorted_by_pt(AK6_inclJets);

        AK6_jetCountIncl = 0;
        AK6_jetCount10 = 0;
        AK6_jetCount20 = 0;

        for (int j = 0; j < AK6_sortedJets.size(); j++) {
            if (abs(AK6_sortedJets[j].eta()) > 0.3) continue;

            AK6_jetCountIncl++;
            if (AK6_sortedJets[j].pt() > 10) AK6_jetCount10++;
            if (AK6_sortedJets[j].pt() > 20) AK6_jetCount20++;
        }

        tree->Fill();
    }
    
    output->Write();
    output->Close();

    return 0;
}