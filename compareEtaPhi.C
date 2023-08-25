// To make an illustration of jet matching

#include <iostream>
#include <vector>
#include <TROOT.h>
#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>

void compareEtaPhi() {
    TFile *file = new TFile("rootfiles/events.root");
    TTreeReader reader("tree", file);

    TTreeReaderValue<std::vector<float>> AK2_jet_matched_eta(reader, "AK2_jet_matched_eta");
    TTreeReaderValue<std::vector<float>> AK4_jet_matched_eta(reader, "AK4_jet_matched_eta");
    TTreeReaderValue<std::vector<float>> AK6_jet_matched_eta(reader, "AK6_jet_matched_eta");
    TTreeReaderValue<std::vector<float>> AK8_jet_matched_eta(reader, "AK8_jet_matched_eta");
    TTreeReaderValue<std::vector<float>> Parton_eta(reader, "Parton_eta");

    TTreeReaderValue<std::vector<float>> AK2_jet_matched_phi(reader, "AK2_jet_matched_phi");
    TTreeReaderValue<std::vector<float>> AK4_jet_matched_phi(reader, "AK4_jet_matched_phi");
    TTreeReaderValue<std::vector<float>> AK6_jet_matched_phi(reader, "AK6_jet_matched_phi");
    TTreeReaderValue<std::vector<float>> AK8_jet_matched_phi(reader, "AK8_jet_matched_phi");
    TTreeReaderValue<std::vector<float>> Parton_phi(reader, "Parton_phi");

    int iEvent = 0;

    for (int i = 0; i < iEvent+1; i++) reader.Next();

    std::cout << "Number of partons: " << Parton_eta->size() << std::endl;
    std::cout << "Number of AK8 jets: " << AK8_jet_matched_eta->size() << std::endl;
    std::cout << "Number of AK6 jets: " << AK6_jet_matched_eta->size() << std::endl;
    std::cout << "Number of AK4 jets: " << AK4_jet_matched_eta->size() << std::endl;
    std::cout << "Number of AK2 jets: " << AK2_jet_matched_eta->size() << std::endl << std::endl;

    for (float eta: *Parton_eta) std::cout << "Parton eta: " << eta << std::endl;
    for (float eta: *AK8_jet_matched_eta) std::cout << "AK8 eta: " << eta << std::endl;
    for (float eta: *AK6_jet_matched_eta) std::cout << "AK6 eta: " << eta << std::endl;
    for (float eta: *AK4_jet_matched_eta) std::cout << "AK4 eta: " << eta << std::endl;
    for (float eta: *AK2_jet_matched_eta) std::cout << "AK2 eta: " << eta << std::endl;

    std::cout << std::endl;
    
    for (float phi: *Parton_phi) std::cout << "Parton phi: " << phi << std::endl;
    for (float phi: *AK8_jet_matched_phi) std::cout << "AK8 phi: " << phi << std::endl;
    for (float phi: *AK6_jet_matched_phi) std::cout << "AK6 phi: " << phi << std::endl;
    for (float phi: *AK4_jet_matched_phi) std::cout << "AK4 phi: " << phi << std::endl;
    for (float phi: *AK2_jet_matched_phi) std::cout << "AK2 phi: " << phi << std::endl;

    // TGraph as the base
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

    const int dummy = 0;
    TGraph *g1 = new TGraph(1, &dummy, &dummy);

    g1->SetTitle(";#eta;#phi");
    g1->GetHistogram()->SetMaximum(TMath::Pi());
    g1->GetHistogram()->SetMinimum(-TMath::Pi());
    g1->SetMarkerColor(0);

    auto xaxis = g1->GetXaxis();
    xaxis->SetLabelSize(0.035);
    xaxis->SetTitleSize(0.055);
    xaxis->SetLimits(-2., 2.);

    auto yaxis = g1->GetYaxis();
    yaxis->SetLabelSize(0.035);
    yaxis->SetTitleSize(0.055);

    g1->Draw();

    // AK8
    for (int i = 0; i < AK8_jet_matched_eta->size(); i++) {
        TEllipse *ell = new TEllipse();

        ell->SetR1(0.8);
        ell->SetR2(0.8);
        ell->SetFillColor(kRed+1);
        ell->SetLineColor(kRed+1);

        ell->SetX1(AK8_jet_matched_eta->at(i));
        ell->SetY1(AK8_jet_matched_phi->at(i));
        
        ell->Draw();
    }

    // AK6
    for (int i = 0; i < AK6_jet_matched_eta->size(); i++) {
        TEllipse *ell = new TEllipse();
        
        ell->SetR1(0.6);
        ell->SetR2(0.6);
        ell->SetFillColor(kOrange+1);
        ell->SetLineColor(kOrange+1);

        ell->SetX1(AK6_jet_matched_eta->at(i));
        ell->SetY1(AK6_jet_matched_phi->at(i));
        
        ell->Draw("same");
    }

    // AK4
    for (int i = 0; i < AK4_jet_matched_eta->size(); i++) {
        TEllipse *ell = new TEllipse();

        ell->SetR1(0.4);
        ell->SetR2(0.4);
        ell->SetFillColor(kGreen+1);
        ell->SetLineColor(kGreen+1);

        ell->SetX1(AK4_jet_matched_eta->at(i));
        ell->SetY1(AK4_jet_matched_phi->at(i));
        
        ell->Draw();
    }

    // AK2
    for (int i = 0; i < AK2_jet_matched_eta->size(); i++) {
        TEllipse *ell = new TEllipse();
        
        ell->SetR1(0.2);
        ell->SetR2(0.2);
        ell->SetFillColor(kBlue+1);
        ell->SetLineColor(kBlue+1);

        ell->SetX1(AK2_jet_matched_eta->at(i));
        ell->SetY1(AK2_jet_matched_phi->at(i));
        
        ell->Draw();
    }

    // Parton
    for (int i = 0; i < Parton_eta->size(); i++) {
        TEllipse *ell = new TEllipse();
        
        ell->SetR1(0.03);
        ell->SetR2(0.03);
        ell->SetFillColor(kBlack);
        ell->SetLineColor(kBlack);

        ell->SetX1(Parton_eta->at(i));
        ell->SetY1(Parton_phi->at(i));
        
        ell->Draw();
    }

    // float Parton_eta_arr[2], Parton_phi_arr[2];

    // for (int i = 0; i < 2; i++) {
    //     Parton_eta_arr[i] = Parton_eta->at(i);
    //     Parton_phi_arr[i] = Parton_phi->at(i);
    // }

    // TGraph *g2 = new TGraph(2, Parton_eta_arr, Parton_phi_arr);
    // g2->Draw("APsame");

    c1->cd();
    c1->SaveAs("pdffiles/g2_compareEtaPhi_0.pdf");
}