{
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

    // Display all histo one by one on the same canvas
    // Print them on an output file in PDF format

    TFile f("./data/vtx2B0toKsJPsi-1k.root");
    TTree *variables = (TTree *)f.Get("variables");

    TCanvas *c1 = new TCanvas("c1", "Histograms", 100, 100, 900, 900);
    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf[");

    //**************************//
    //Count nb of vertices correctly reconstructed (-> purity)

    //**************************//
    //Distribution

    //MotherPDG using vtx2_mcPDG
    TH1F *h1_vtx_PDG = new TH1F("h1_vtx_PDG", "PDG of vertices correctly reconstructed;Abs vertices PDG ", 600, 0, 600);
    h1_vtx_PDG->SetLineColor(kGreen + 2);
    h1_vtx_PDG->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("abs(vtx2_mcPDG)>>h1_vtx_PDG", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf");

    //MotherPDG using mcPDG_m
    TH1F *h1_mcPDG_m = new TH1F("h1_mcPDG_m", "PDG of vertices correctly reconstructed;Abs vertices PDG ", 600, 0, 600);
    h1_mcPDG_m->SetLineColor(kGreen + 2);
    h1_mcPDG_m->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("abs(t1_mcPDG_m)>>h1_mcPDG_m", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf");
    //>//Same number of entries differents stdr deviation

    //X distance
    TH1F *h1_vtx_X = new TH1F("h1_vtx_X", "Decay vertex in X ; X in [cm] ", 100, 0, 20);
    h1_vtx_X->SetLineColor(kGreen + 2);
    h1_vtx_X->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("vtx2_mcDecayVertexX>>h1_vtx_X", "t1_mcID_m==t2_mcID_m");
    c1->SetLogy();
    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf");

    //Y distance
    TH1F *h1_vtx_Y = new TH1F("h1_vtx_Y", "Decay vertex in Y ; Y in [cm] ", 100, 0, 20);
    h1_vtx_Y->SetLineColor(kGreen + 2);
    h1_vtx_Y->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("vtx2_mcDecayVertexY>>h1_vtx_Y", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf");

    //Radial distance
    TH1F *h1_vtx_rad = new TH1F("h1_vtx_rad", "Radial distance of decay vertex; Radial distance in [cm] ", 100, 0, 20);
    h1_vtx_rad->SetLineColor(kGreen + 2);
    h1_vtx_rad->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("vtx2_mcDecayVertexRho>>h1_vtx_rad", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf");

    c1->SetLogy(0);

    //particle_momentum
    TH1F *h1_t1_PT = new TH1F("h1_t1_PT", "Transverse momentum of the particle t1 and t2 ; Momentum in [GeV] ", 100, 0, 2.5);
    variables->Draw("t1_mcPT>>h1_t1_PT", "t1_mcID_m==t2_mcID_m");

    TH1F *h1_t2_PT = new TH1F("h1_t2_PT", "Transverse momentum of the particle t1 and t2 ; Momentum in [GeV] ", 100, 0, 2.5);
    variables->Draw("t2_mcPT>>h1_t2_PT", "t1_mcID_m==t2_mcID_m");

    h1_t1_PT->SetLineColor(kBlue + 2);
    h1_t1_PT->SetFillColorAlpha(kBlue + 2, 0.20);
    h1_t1_PT->Draw();
    h1_t2_PT->SetLineColor(kRed + 2);
    h1_t2_PT->SetFillColorAlpha(kRed + 2, 0.20);
    h1_t2_PT->Draw("Sames");

    gPad->Update();
    TPaveStats *st = (TPaveStats *)h1_t2_PT->FindObject("stats");
    st->SetY1NDC(0.75);
    st->SetY2NDC(0.6);

    c1->Update();
    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf");

    //>//Discuss how to plot for t1 and t2 in the same time?

    //**************************//

    c1->Print("./histo/vtx2B0toKsJPsi-1k-histos.pdf]");
    f.Close();
}
