{
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

    // Display all histo one by one on the same canvas
    // Print them on an output file in PDF format

    TFile f("continumcc-100k-tree.root");
    TTree *outt = (TTree *)f.Get("outt");
    TH1F *h1;
    TH2F *h2;

    TCanvas *c1 = new TCanvas("c1", "Histograms", 80, 80, 900, 900);
    c1->Print("continumcc-100k-histos.pdf[");

    //By events
    TH1F *h1_nvtx = new TH1F("h1_nvtx", "Number of Vertices by event;Number of Vertices", 14, 0, 14); //all vertices
    outt->Draw("event.e_nvtx>>h1_nvtx", "id==0");
    //c->Print("continumcc-100k-histos.pdf");

    TH1F *h1_nvtxreal2 = new TH1F("h1_nvtxreal2", "Number of Vertices by event;Number of Vertices", 14, 0, 14); //at least 2 final charged particles
    outt->Draw("event.e_nvtxreal2>>h1_nvtxreal2", "id==0");
    //c->Print("continumcc-100k-histos.pdf");

    TH1F *h1_nvtxreal3 = new TH1F("h1_nvtxreal3", "Number of Vertices by event;Number of Vertices", 14, 0, 14); //at least 2 reconstructible particles
    outt->Draw("event.e_nvtxreal3>>h1_nvtxreal3", "id==0");
    //c->Print("continumcc-100k-histos.pdf");

    h1_nvtx->SetMaximum(45000);
    h1_nvtx->SetLineColor(860);
    h1_nvtx->SetFillColorAlpha(860, 0.3);
    h1_nvtx->Draw();
    h1_nvtxreal2->SetMaximum(45000);
    h1_nvtxreal2->SetLineColor(49);
    h1_nvtxreal2->SetFillColorAlpha(46, 0.45);
    h1_nvtxreal2->Draw("Sames");
    gPad->Update();
    TPaveStats *st = (TPaveStats *)h1_nvtxreal2->FindObject("stats");
    st->SetY1NDC(0.75);
    st->SetY2NDC(0.6);

    gStyle->SetLegendTextSize(0.02); //Legend
    auto legend = new TLegend(0.68, 0.50, 0.99, 0.30);
    legend->AddEntry(h1_nvtx, "Nb of Vertices", "f");
    legend->AddEntry(h1_nvtxreal2, "#splitline{Nb of vertices with at least }{2 final charged particles}", "f");
    legend->Draw();
    c1->Update();
    c1->Print("continumcc-100k-histos.pdf");

    //**************************//

    h1_nvtx->SetLineColor(860);
    h1_nvtx->SetFillColorAlpha(860, 0.3);
    h1_nvtx->Draw();
    h1_nvtxreal3->SetLineColor(30);
    h1_nvtxreal3->SetFillColorAlpha(30, 0.55);
    h1_nvtxreal3->Draw("Sames");
    gPad->Update();
    TPaveStats *st2 = (TPaveStats *)h1_nvtxreal3->FindObject("stats");
    st2->SetY1NDC(0.75);
    st2->SetY2NDC(0.6);
    legend->Clear();
    legend->AddEntry(h1_nvtx, "Nb of Vertices", "f");
    legend->AddEntry(h1_nvtxreal3, "#splitline{Nb of vertices with at least }{2 reconstructible particles}", "f");
    legend->Draw();
    c1->Update();
    c1->Print("continumcc-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_Neutral = new TH1F("h1_e_Neutral", "Nb of neutral particles/Event;Nb of neutral particles", 40, 0, 40); //Neutral
    h1_e_Neutral->SetLineColor(16);                                                                          //neutral color
    h1_e_Neutral->SetFillColorAlpha(14, 0.45);
    outt->Draw("event.e_nNeutral>>h1_e_Neutral");
    c1->Print("continumcc-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_Charged = new TH1F("h1_e_Charged", "Nb of charged particles/Event;Nb of charged particles", 30, 0, 30); //Charged
    h1_e_Charged->SetLineColor(46);                                                                          //charged color
    h1_e_Charged->SetFillColorAlpha(46, 0.45);
    outt->Draw("event.e_nCharged>>h1_e_Charged");
    c1->Print("continumcc-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_Fcharged = new TH1F("h1_e_Fcharged", "Number of final charged particles/Event;Nb of final charged particles", 22, 0, 22); //Final charged
    outt->Draw("event.e_nFcharged>>h1_e_Fcharged");

    TH1F *h1_Ftracks = new TH1F("h1_Ftracks", "Nb of final charged particles/Event;Nb of Charged", 22, 0, 22); //Final Charged that belong to vertices level 2
    outt->Draw("event.e_nFcharged>>h1_Ftracks", "vReal == 2");

    h1_e_Fcharged->SetLineColor(800);
    h1_e_Fcharged->SetFillColorAlpha(800, 0.55);
    h1_e_Fcharged->Draw();
    h1_Ftracks->SetLineColor(804);
    h1_Ftracks->SetFillColorAlpha(804, 0.45);
    h1_Ftracks->Draw("Sames");

    gPad->Update();
    TPaveStats *st3 = (TPaveStats *)h1_Ftracks->FindObject("stats");
    st3->SetY1NDC(0.75);
    st3->SetY2NDC(0.6);

    gStyle->SetLegendTextSize(0.02); //Legend
    legend->Clear();
    legend->AddEntry(h1_e_Fcharged, "Nb of final charged particles", "f");
    legend->AddEntry(h1_Ftracks, "#splitline{Nb of charged particles}{#splitline{that belong to vertices}{#splitline{with at least 2 final charged}{particles}}}", "f");
    legend->Draw();
    c1->Update();
    c1->Print("continumcc-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_Rcharged = new TH1F("h1_e_Rcharged", "Number of recontructible charged particles/Event;Nb of reconstructible charged particles", 22, 0, 22); //Reconstrutible
    outt->Draw("event.e_nRcharged>>h1_e_Rcharged");

    TH1F *h1_Rtracks = new TH1F("h1_Rtracks", "Number of recontructible charged particles/Event;Nb of reconstructible charged particles", 22, 0, 22); //Charged that belong to vertices level 3
    outt->Draw("event.e_nRcharged>>h1_Rtracks", "vReal == 3");                                                                                                                     //(recontructable track)

    h1_e_Rcharged->SetLineColor(30);
    h1_e_Rcharged->SetFillColorAlpha(30, 0.55);
    h1_e_Rcharged->Draw();
    h1_Rtracks->SetLineColor(418);
    h1_Rtracks->SetFillColorAlpha(418, 0.45);
    h1_Rtracks->Draw("Sames");

    gPad->Update();
    TPaveStats *st4 = (TPaveStats *)h1_Rtracks->FindObject("stats");
    st4->SetY1NDC(0.75);
    st4->SetY2NDC(0.6);

    gStyle->SetLegendTextSize(0.02); //Legend
    legend->Clear();
    legend->AddEntry(h1_e_Rcharged, "#splitline{Number of recontructible}{charged particles}", "f");
    legend->AddEntry(h1_Rtracks, "#splitline{Nb of charged particles}{#splitline{that belong to vertices}{#splitline{with at least 2 reconstructible}{charged particles}}}", "f");
    legend->Draw();
    c1->Update();
    c1->Print("continumcc-100k-histos.pdf");


    //**************************//

    //By vertices
    h1 = new TH1F("h1", "Nb of charged particles/Vertex;Nb of charged", 20, 0, 20);
    outt->Draw("nCharged>>h1");
    c1->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of final charged particles/Vertex;Nb of final charged", 20, 0, 20);
    outt->Draw("nFinalcharged>>h1");
    c1->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of reconstructible particles/Vertex;Nb of Reconstructible Charged", 20, 0, 20);
    outt->Draw("nRstructed>>h1");
    c1->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of Neutral particles/Vertex;Nb of Neutral Charged", 20, 0, 20);
    outt->Draw("nNeutral>>h1");
    c1->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of Real Vertices with Pdg Code;Nb of Pdg Code", 10000, 0, 10000); //PDG code of reconstructible vertices
    outt->Draw("vPdg>>h1", "vReal==3");
    c1->SetLogy();
    c1->SetLogx();
    c1->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of Non-reconstructible vertices with Pdg Code;Nb of Pdg Code", 10000, 0, 10000); //PDG code of NON-reconstructible vertices
    outt->Draw("vPdg>>h1", "vReal<3");
    c1->SetLogy();
    c1->SetLogx();
    c1->Print("continumcc-100k-histos.pdf");

    //2D histograms by vertex
    h2 = new TH2F("h2", "Nb of Neutral vs. Nb of Charged;Nb of Charged;Nb of Neutral", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nNeutral:nCharged>>h2");
    h2->Draw("colz");
    c1->SetLogy(0);
    c1->SetLogx(0);
    c1->Print("continumcc-100k-histos.pdf");

    h2 = new TH2F("h2", "Nb of Final charged vs. Nb of Charged;Nb of Charged;Nb of Final charged", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nFinalcharged:nCharged>>h2");
    h2->Draw("colz");
    c1->Print("continumcc-100k-histos.pdf");

    h2 = new TH2F("h2", "Nb of Reconstructible vs. Nb of Charged;Nb of Charged;Nb of Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nCharged>>h2");
    h2->Draw("colz");
    c1->Print("continumcc-100k-histos.pdf");

    h2 = new TH2F("h2", "Nb of Reconstructible vs. Nb of Final charged; Nb of Final charged;Nb of Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nFinalcharged>>h2");
    h2->Draw("colz");
    c1->Print("continumcc-100k-histos.pdf");

    //Radial position
    h1 = new TH1F("h1", "Radial position of vertices; distance [cm]", 200, 0, 100);
    outt->Draw("radialpos>>h1");
    c1->SetLogy();
    c1->Print("continumcc-100k-histos.pdf");

    //Radial position
    h1 = new TH1F("h1", "Radial position of real vertices; distance [cm]", 200, 0, 100);
    outt->Draw("radialpos>>h1", "vReal==3");
    c1->SetLogy();
    c1->Print("continumcc-100k-histos.pdf");

    //Radial position
    h1 = new TH1F("h1", "Radial position of real vertices; distance [cm]", 200, 0, 4);
    outt->Draw("radialpos>>h1", "vReal==3 && radialpos<1.2 ");
    c1->SetLogy();
    c1->Print("continumcc-100k-histos.pdf");

    c1->Print("continumcc-100k-histos.pdf]");
    f.Close();
}
