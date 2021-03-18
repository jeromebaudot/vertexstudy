{
    #include <TFile.h>
    #include <TTree.h>
    #include <TH2.h>
    #include <TCanvas.h>


    // Display all histo one by one on the same canvas
    // Print them on an output file in PDF format

    TFile f("B0toKsJPsi-tree.root");
    TH1F *h1;
    TH2F *h2;

    TCanvas *c = new TCanvas("c", "vertex study", 25, 25, 800, 800);
    c->Print("B0toKsJPsi-histos.pdf[");

    //By events
    h1 = new TH1F("h1", "# Vertices/Event;# Vertices", 10, 0, 10);
    outt->Draw( "event.e_nvtx>>h1", "id==0");
    c->Print("B0toKsJPsi-histos.pdf");


    h1 = new TH1F("h1", "# Real Vertices/Event;# Real Vertices", 10, 0, 10);
    outt->Draw("event.e_nvtxreal>>h1", "id==0");
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Neutral particles/Event;# Final Charged", 20, 0, 20);
    outt->Draw("event.e_nNeutral>>h1"); 
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Charged particles/Event;# Final Charged", 20, 0, 20);
    outt->Draw("event.e_nCharged>>h1");
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Final charged particles/Event;# Final Charged", 20, 0, 20);
    outt->Draw("event.e_nFcharged>>h1");
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Recontructible charged particles/Event;# Final charged", 20, 0, 20);
    outt->Draw("event.e_nRcharged>>h1");
    c->Print("B0toKsJPsi-histos.pdf");
    
    //By vertices
    h1 = new TH1F("h1", "# Charged particles/Vertex;# Charged", 20, 0, 20);
    outt->Draw("nCharged>>h1");
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Final Charged particles/Vertex;# Final Charged", 20, 0, 20);
    outt->Draw("nFinalcharged>>h1");
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Reconstructible particles/Vertex;# Reconstructible Charged", 20, 0, 20);
    outt->Draw("nRstructed>>h1");
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Neutral particles/Vertex;# Neutral Charged", 20, 0, 20);
    outt->Draw("nNeutral>>h1");
    c->Print("B0toKsJPsi-histos.pdf");

    h1 = new TH1F("h1", "# Real Vertices with Pdg Code;# Pdg Code", 1000, 0, 1000);
    outt->Draw("vPdg>>h1","vReal==3");
    c->Print("B0toKsJPsi-histos.pdf");

    //2D histograms by vertex
    h2 = new TH2F("h2", "# Neutral vs. # Charged;# Charged;# Neutral", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nNeutral:nCharged>>h2");
    h2->Draw("colz");
    c->Print("B0toKsJPsi-histos.pdf");

    h2 = new TH2F("h2", "# Final charged vs. # Charged;# Charged;# Final charged", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nFinalcharged:nCharged>>h2");
    h2->Draw("colz");
    c->Print("B0toKsJPsi-histos.pdf");

    h2 = new TH2F("h2", "# Reconstructible vs. # Charged;# Charged;# Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nCharged>>h2");
    h2->Draw("colz");
    c->Print("B0toKsJPsi-histos.pdf");

    h2 = new TH2F("h2", "# Reconstructible vs. # Final charged; # Final charged;# Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nFinalcharged>>h2");
    h2->Draw("colz");
    c->Print("B0toKsJPsi-histos.pdf");


    //Radial position
    h1 = new TH1F("h1", "Radial position of vertices; distance [mm]", 200, 0, 100);
    outt->Draw("radialpos>>h1");
    c->SetLogy();
    c->Print("B0toKsJPsi-histos.pdf");
 
    //Radial position
    h1 = new TH1F("h1", "Radial position of real vertices; distance [mm]", 200, 0, 100);
    outt->Draw("radialpos>>h1", "vReal==3");
    c->SetLogy();
    c->Print("B0toKsJPsi-histos.pdf");
 

    c->Print("B0toKsJPsi-histos.pdf]");
    
    f.Close();
}
