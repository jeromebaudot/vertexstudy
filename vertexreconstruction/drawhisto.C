{
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

    // Display all histo one by one on the same canvas
    // Print them on an output file in PDF format

    TFile f("./data/vtx2mixedB-10k.root");
    TTree *variables = (TTree *)f.Get("variables");

    TCanvas *c1 = new TCanvas("c1", "Histograms", 100, 100, 900, 900);
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf[");

    //***************************//
    //Count nb of vertices correctly reconstructed (-> purity)

    //***************************//
    //Distribution

    //MotherPDG using vtx2_mcPDG
    TH1F *h1_vtx_PDG = new TH1F("h1_vtx_PDG", "PDG of vertices correctly reconstructed;Abs vertices PDG ", 600, 0, 600);
    h1_vtx_PDG->SetLineColor(kGreen + 2);
    h1_vtx_PDG->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("abs(vtx2_mcPDG)>>h1_vtx_PDG", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    //MotherPDG using t1_mcPDG_m
    TH1F *h1_mcPDG_m = new TH1F("h1_mcPDG_m", "PDG of vertices correctly reconstructed;Abs vertices PDG ", 600, 0, 600);
    h1_mcPDG_m->SetLineColor(kGreen + 2);
    h1_mcPDG_m->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("abs(t1_mcPDG_m)>>h1_mcPDG_m", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");
    //>//Same number of entries different stdr deviation

    //X distance
    TH1F *h1_vtx_X = new TH1F("h1_vtx_X", "Decay vertex in X ; X in [cm] ", 100, 0, 20);
    h1_vtx_X->SetLineColor(kGreen + 2);
    h1_vtx_X->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("vtx2_mcDecayVertexX>>h1_vtx_X", "t1_mcID_m==t2_mcID_m");
    c1->SetLogy();
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    //Y distance
    TH1F *h1_vtx_Y = new TH1F("h1_vtx_Y", "Decay vertex in Y ; Y in [cm] ", 100, 0, 20);
    h1_vtx_Y->SetLineColor(kGreen + 2);
    h1_vtx_Y->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("vtx2_mcDecayVertexY>>h1_vtx_Y", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    //Radial distance
    TH1F *h1_vtx_rad = new TH1F("h1_vtx_rad", "Radial distance of decay vertex; Radial distance in [cm] ", 100, 0, 20);
    h1_vtx_rad->SetLineColor(kGreen + 2);
    h1_vtx_rad->SetFillColorAlpha(kGreen + 2, 0.55);
    variables->Draw("vtx2_mcDecayVertexRho>>h1_vtx_rad", "t1_mcID_m==t2_mcID_m");
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    c1->SetLogy(0);

    //Momentum
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
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    //>//Discuss how to plot for t1 and t2 in the same time?

    //***************************//
    // Analysis tree file histos //
    //***************************//

    f.Close();
    TFile g("./data/vtx2mixedB-10k-tree.root");
    TTree *outt = (TTree *)g.Get("outt");

    // Number of Vertices per Event
    
    TH1F *h1_ncand = new TH1F("h1_ncand", "Number of Candidates by event;Number of Candidates", 160, 0, 160);
    outt->Draw("event.e_ncand>>h1_ncand", "id==0");

    TH1F *h1_nvtx = new TH1F("h1_nvtx", "Number of Vertices by event;Number of Vertices", 25, 0, 25);
    outt->Draw("event.e_nvtx>>h1_nvtx", "id==0");

    TH1F *h1_nvtxreal = new TH1F("h1_nvtxreal", "Number of Vertices by event;Number of Vertices", 25, 0, 25);
    outt->Draw("event.e_nvtxreal>>h1_nvtxreal", "id==0");

    // Number of Candidates per Event

    h1_ncand->SetLineColor(kBlue);
    h1_ncand->SetFillColorAlpha(kBlue, 0.55);
    h1_ncand->Draw();

    c1->Update();
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    // Number of Vertices per Event

    h1_nvtxreal->SetLineColor(30);
    h1_nvtxreal->SetFillColorAlpha(30, 0.55);
    h1_nvtxreal->Draw();
    h1_nvtx->SetLineColor(860);
    h1_nvtx->SetFillColorAlpha(860, 0.3);
    h1_nvtx->Draw("Sames");

    gPad->Update();
    TPaveStats *st2 = (TPaveStats *)h1_nvtxreal->FindObject("stats");
    st2->SetY1NDC(0.75);
    st2->SetY2NDC(0.6);

    auto leg2 = new TLegend(0.65, 0.50, 0.99, 0.30);
    leg2->AddEntry(h1_nvtx, "#splitline{L4 vertices including}{double-counted ones}", "f");
    leg2->AddEntry(h1_nvtxreal, "#splitline{L4 vertices excluding}{double-counted ones}", "f");
    leg2->Draw();
    c1->Update();
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    // Number of Skipped Vertices per Event

    TH1F *h1_skip = new TH1F("h1_skip", "Number of Skipped Vertices by event;Number of Skipped Vertices", 16, 0, 16);
    outt->Draw("event.e_skip>>h1_skip", "id==0");

    h1_skip->SetLineColor(14);
    h1_skip->SetFillColorAlpha(14, 0.45);
    h1_skip->Draw();
    c1->Update();
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    // Radial Distance

    TH1F *h1_rad = new TH1F("h1_rad", "Radial distance of vertices; distance [cm]", 200, 0, 10); //real vertices (lvl3 + lvl4)
    outt->Draw("radialpos>>h1_rad");
    c1->SetLogy();

    TH1F *h1_rad_pipe = new TH1F("h1_rad_pipe", "Radial distance of vertices; distance [cm]", 200, 0, 10); //real vertices in beam pipe
    outt->Draw("radialpos>>h1_rad_pipe", "radialpos<1.2");
    c1->SetLogy();

    h1_rad->SetLineColor(kGreen + 2);
    h1_rad->SetFillColorAlpha(kGreen + 2, 0.55);
    h1_rad->Draw();
    h1_rad_pipe->SetLineColor(kRed);
    h1_rad_pipe->SetFillColorAlpha(kRed, 0.55);
    h1_rad_pipe->Draw("Sames");

    gPad->Update();
    TPaveStats *st3 = (TPaveStats *)h1_rad->FindObject("stats");
    st3->SetY1NDC(0.75);
    st3->SetY2NDC(0.6);

    auto leg3 = new TLegend(0.42, 0.8, 0.69, 0.63);
    leg3->AddEntry(h1_rad, "Real vertices (L4)", "f");
    leg3->AddEntry(h1_rad_pipe, "#splitline{Real vertices inside}{the beam pipe}", "f");
    leg3->Draw();
    c1->Update();
    c1->Print("./histo/vtx2mixedB-10k-histos.pdf");

    c1->Print("./histo/vtx2mixedB-10k-histos.pdf]");
    g.Close();
}
