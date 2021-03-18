{
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

    // Display all histo one by one on the same canvas
    // Print them on an output file in PDF format

    TFile f("continumcc-100k-tree.root");
    TH1F *h1;
    TH2F *h2;

    TCanvas *c = new TCanvas("c", "vertex study", 25, 25, 800, 800);
    c->Print("continumcc-100k-histos.pdf[");

    //By events
    h1 = new TH1F("h1", "Nb of Vertices/Event;Nb of Vertices", 10, 0, 10); //all vertices
    outt->Draw("event.e_nvtx>>h1", "id==0");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of vertices with at least 2 final charged particles/Event;Nb of Vertices", 10, 0, 10); //at least 2 final charged particles
    outt->Draw("event.e_nvtxreal2>>h1", "id==0");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of vertices with at least 2 reconstructable particles/Event;Nb of Real Vertices", 10, 0, 10); //at least 2 reconstructable particles
    outt->Draw("event.e_nvtxreal3>>h1", "id==0");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of neutral particles/Event;Nb of neutral", 20, 0, 20); //Neutral
    outt->Draw("event.e_nNeutral>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of charged particles/Event;Nb of Charged", 20, 0, 20); //Charged
    outt->Draw("event.e_nCharged>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of final charged particles/Event;Nb of final charged", 20, 0, 20); //Final charged
    outt->Draw("event.e_nFcharged>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of recontructible charged particles/Event;Nb of final charged", 20, 0, 20); //Reconstrutable
    outt->Draw("event.e_nRcharged>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of charged particles that belong to vertices with at least 2 charged particles/Event;Nb of Charged", 20, 0, 20); //Charged that belong to vertices level 1
    outt->Draw("event.e_nCharged>>h1", "vReal == 1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of reconstructable particles that belong to vertices with at least 2 reconstructable particles/Event;Nb of Charged", 20, 0, 20); //Charged that belong to vertices level 3
    outt->Draw("event.e_nRcharged>>h1", "vReal == 3");                                                                                                       //(recontructable track)
    c->Print("continumcc-100k-histos.pdf");

    //By vertices
    h1 = new TH1F("h1", "Nb of charged particles/Vertex;Nb of charged", 20, 0, 20);
    outt->Draw("nCharged>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of final charged particles/Vertex;Nb of final charged", 20, 0, 20);
    outt->Draw("nFinalcharged>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of reconstructible particles/Vertex;Nb of Reconstructible Charged", 20, 0, 20);
    outt->Draw("nRstructed>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of Neutral particles/Vertex;Nb of Neutral Charged", 20, 0, 20);
    outt->Draw("nNeutral>>h1");
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of Real Vertices with Pdg Code;Nb of Pdg Code", 10000, 0, 10000); //PDG code of reconstructable vertices
    outt->Draw("vPdg>>h1", "vReal==3");
     c->SetLogy();
    c->SetLogx();
    c->Print("continumcc-100k-histos.pdf");

    h1 = new TH1F("h1", "Nb of Non-reconstructable vertices with Pdg Code;Nb of Pdg Code", 10000, 0, 10000); //PDG code of NON-reconstructable vertices
    outt->Draw("vPdg>>h1", "vReal<3");
    c->SetLogy();
    c->SetLogx();
    c->Print("continumcc-100k-histos.pdf");

    //2D histograms by vertex
    h2 = new TH2F("h2", "Nb of Neutral vs. Nb of Charged;Nb of Charged;Nb of Neutral", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nNeutral:nCharged>>h2");
    h2->Draw("colz");
    c->SetLogy(0);
    c->SetLogx(0);
    c->Print("continumcc-100k-histos.pdf");

    h2 = new TH2F("h2", "Nb of Final charged vs. Nb of Charged;Nb of Charged;Nb of Final charged", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nFinalcharged:nCharged>>h2");
    h2->Draw("colz");
    c->Print("continumcc-100k-histos.pdf");

    h2 = new TH2F("h2", "Nb of Reconstructible vs. Nb of Charged;Nb of Charged;Nb of Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nCharged>>h2");
    h2->Draw("colz");
    c->Print("continumcc-100k-histos.pdf");

    h2 = new TH2F("h2", "Nb of Reconstructible vs. Nb of Final charged; Nb of Final charged;Nb of Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nFinalcharged>>h2");
    h2->Draw("colz");
    c->Print("continumcc-100k-histos.pdf");

    //Radial position
    h1 = new TH1F("h1", "Radial position of vertices; distance [cm]", 200, 0, 100);
    outt->Draw("radialpos>>h1");
    c->SetLogy();
    c->Print("continumcc-100k-histos.pdf");

    //Radial position
    h1 = new TH1F("h1", "Radial position of real vertices; distance [cm]", 200, 0, 100);
    outt->Draw("radialpos>>h1", "vReal==3");
    c->SetLogy();
    c->Print("continumcc-100k-histos.pdf");

    //Radial position
    h1 = new TH1F("h1", "Radial position of real vertices; distance [cm]", 200, 0, 4);
    outt->Draw("radialpos>>h1", "vReal==3 && radialpos<1.2 ");
    c->SetLogy();
    c->Print("continumcc-100k-histos.pdf");

    c->Print("continumcc-100k-histos.pdf]");

    f.Close();
}
