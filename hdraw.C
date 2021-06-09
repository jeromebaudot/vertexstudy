{
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

    // Display all histo one by one on the same canvas
    // Print them on an output file in PDF format

    TFile f("./data/B0toKsJPsi-100k-tree.root");
    TTree *outt = (TTree *)f.Get("outt");

    TCanvas *c1 = new TCanvas("c1", "Histograms", 80, 80, 900, 900);
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf[");

    //By events

    TH1F *h1_nvtx = new TH1F("h1_nvtx", "Number of Vertices by event;Number of Vertices", 16, 0, 16); //all vertices
    outt->Draw("event.e_nvtx>>h1_nvtx", "id==0");

    TH1F *h1_nvtxreal2 = new TH1F("h1_nvtxreal2", "Number of Vertices by event;Number of Vertices", 12, 0, 12); //at least 2 final charged particles
    outt->Draw("event.e_nvtxreal2>>h1_nvtxreal2", "id==0");

    TH1F *h1_nvtxreal4 = new TH1F("h1_nvtxreal4", "Number of Vertices by event;Number of Vertices", 12, 0, 12); //at least 2 reconstructible particles
    outt->Draw("event.e_nvtxreal4>>h1_nvtxreal4", "id==0");

    TH1F *h1_nvtxreal34 = new TH1F("h1_nvtxreal34", "Number of Vertices by event;Number of Vertices", 14, 0, 14); //at least 2 reconstructible + intermediate particles
    outt->Draw("event.e_nvtxreal4 + event.e_nvtxreal3>>h1_nvtxreal34", "id==0");

    h1_nvtx->SetMaximum(55000);
    h1_nvtx->SetLineColor(860);
    h1_nvtx->SetFillColorAlpha(860, 0.3);
    h1_nvtx->Draw();
    h1_nvtxreal2->SetMaximum(55000);
    h1_nvtxreal2->SetLineColor(49);
    h1_nvtxreal2->SetFillColorAlpha(46, 0.45);
    h1_nvtxreal2->Draw("Sames");

    gPad->Update();
    TPaveStats *st = (TPaveStats *)h1_nvtxreal2->FindObject("stats");
    st->SetY1NDC(0.75);
    st->SetY2NDC(0.6);

    gStyle->SetLegendTextSize(0.02); //Legend
    auto leg1 = new TLegend(0.68, 0.50, 0.99, 0.30);
    leg1->AddEntry(h1_nvtx, "Vertices (lvl0)", "f");
    leg1->AddEntry(h1_nvtxreal2, "#splitline{Vertices with at least 2}{final charged particles (lvl2)}", "f");
    leg1->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    h1_nvtxreal2->SetLineColor(49);
    h1_nvtxreal2->SetFillColorAlpha(46, 0.45);
    h1_nvtxreal2->Draw();
    h1_nvtxreal4->SetLineColor(30);
    h1_nvtxreal4->SetFillColorAlpha(30, 0.55);
    h1_nvtxreal4->Draw("Sames");

    gPad->Update();
    TPaveStats *st2 = (TPaveStats *)h1_nvtxreal4->FindObject("stats");
    st->SetY1NDC(0.94);
    st->SetY2NDC(0.78);
    st2->SetY1NDC(0.75);
    st2->SetY2NDC(0.6);

    auto leg2 = new TLegend(0.65, 0.50, 0.99, 0.30);
    leg2->AddEntry(h1_nvtxreal2, "#splitline{Vertices with at least 2}{final charged particles (lvl2)} ", "f");
    leg2->AddEntry(h1_nvtxreal4, "#splitline{Vertices with at least 2}{reconstructible particles (lvl4)}", "f");
    leg2->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    h1_nvtxreal4->SetMaximum(55000);
    h1_nvtxreal4->SetLineColor(30);
    h1_nvtxreal4->SetFillColorAlpha(30, 0.45);
    h1_nvtxreal4->Draw();
    h1_nvtxreal34->SetLineColor(kCyan + 2);
    h1_nvtxreal34->SetFillColorAlpha(kCyan + 2, 0.55);
    h1_nvtxreal34->Draw("Sames");

    gPad->Update();
    TPaveStats *st24 = (TPaveStats *)h1_nvtxreal34->FindObject("stats");
    st2->SetY1NDC(0.94);
    st2->SetY2NDC(0.78);
    st24->SetY1NDC(0.75);
    st24->SetY2NDC(0.6);

    auto leg24 = new TLegend(0.68, 0.50, 0.99, 0.30);
    leg24->AddEntry(h1_nvtxreal4, "#splitline{Vertices with at least}{#splitline{2 reconstructible particles}{(lvl4)}} ", "f");
    leg24->AddEntry(h1_nvtxreal34, "#splitline{Vertices with at least}{#splitline{2 reconstructible or }{#splitline{intermediate particles}{(lvl3+4)}}}", "f");
    leg24->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_Neutral = new TH1F("h1_e_Neutral", "Nb of neutral particles/Event;Nb of neutral particles", 45, 0, 45); //Neutral
    h1_e_Neutral->SetLineColor(14);                                                                                    //neutral color
    h1_e_Neutral->SetFillColorAlpha(14, 0.45);
    outt->Draw("event.e_nNeutral>>h1_e_Neutral");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_Charged = new TH1F("h1_e_Charged", "Nb of charged particles/Event;Nb of charged particles", 30, 0, 30); //Charged
    h1_e_Charged->SetLineColor(46);                                                                                    //charged color
    h1_e_Charged->SetFillColorAlpha(46, 0.45);
    outt->Draw("event.e_nCharged>>h1_e_Charged");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_nRInter = new TH1F("h1_e_nRInter", "Nb of intermediate particles/Event;Nb of intermediate particles", 20, 0, 20); //Intermediate
    h1_e_nRInter->SetLineColor(kCyan + 2);                                                                                       //Intermediate color
    h1_e_nRInter->SetFillColorAlpha(kCyan + 2, 0.45);
    outt->Draw("event.e_nRInter>>h1_e_nRInter");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");
    
    //**************************//

    TH1F *h1_e_Fcharged = new TH1F("h1_e_Fcharged", "Number of final charged particles/Event;Nb of final charged particles", 24, 0, 24); //Final charged
    outt->Draw("event.e_nFcharged>>h1_e_Fcharged", "id == 0");
    
    TH1F *h1_Ftracks = new TH1F("h1_Ftracks", "Nb of final charged particles/Event;Nb of Charged", 24, 0, 24); //Final Charged that belong to vertices level 2
    outt->Draw("event.e_nF2charged>>h1_Ftracks", "id == 0");

    h1_e_Fcharged->SetLineColor(800);
    h1_e_Fcharged->SetFillColorAlpha(800, 0.55);
    //h1_e_Fcharged->SetMaximum(50000);
    h1_e_Fcharged->Draw();
    h1_Ftracks->SetLineColor(804);
    h1_Ftracks->SetFillColorAlpha(804, 0.45);
    h1_Ftracks->Draw("Sames");

    gPad->Update();
    TPaveStats *st3 = (TPaveStats *)h1_Ftracks->FindObject("stats");
    st3->SetY1NDC(0.75);
    st3->SetY2NDC(0.6);

    auto leg3 = new TLegend(0.68, 0.50, 0.99, 0.30);
    leg3->AddEntry(h1_e_Fcharged, "Final charged particles", "f");
    leg3->AddEntry(h1_Ftracks, "#splitline{Final tracks that belong to}{#splitline{vertices with at least 2}{final charged particles}}", "f");
    leg3->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_Rcharged = new TH1F("h1_e_Rcharged", "Number of recontructible charged particles/Event;Nb of reconstructible charged particles", 24, 0, 24); //Reconstrutible
    outt->Draw("event.e_nRcharged>>h1_e_Rcharged", "id==0");

    TH1F *h1_Rtracks = new TH1F("h1_Rtracks", "Number of recontructible charged particles/Event;Nb of reconstructible charged particles", 28, 0, 28); //Reconstructible that belong to vertices level 3
    outt->Draw("event.e_nR2charged>>h1_Rtracks", "id==0");                                                                                            //(recontructible track)

    h1_e_Rcharged->SetLineColor(30);
    h1_e_Rcharged->SetFillColorAlpha(30, 0.55);
    //h1_e_Rcharged->SetMaximum(70000);
    h1_e_Rcharged->Draw();
    h1_Rtracks->SetLineColor(418);
    h1_Rtracks->SetFillColorAlpha(418, 0.45);
    h1_Rtracks->Draw("Sames");

    gPad->Update();
    TPaveStats *st4 = (TPaveStats *)h1_Rtracks->FindObject("stats");
    st4->SetY1NDC(0.75);
    st4->SetY2NDC(0.6);

    auto leg4 = new TLegend(0.68, 0.50, 0.99, 0.30);
    leg4->AddEntry(h1_e_Rcharged, "#splitline{Recontructible}{charged particles}", "f");
    leg4->AddEntry(h1_Rtracks, "#splitline{Reconstructible tracks}{#splitline{that belong to vertices with}{#splitline{at least 2 reconstructible}{charged particles}}}", "f");
    leg4->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    TH1F *h1_e_RInter = new TH1F("h1_e_RInter", "Number of recontructible intermediate particles/Event;Nb of reconstructible charged particles", 20, 0, 20); //Reconstructible intermediate
    outt->Draw("event.e_nRInter>>h1_e_RInter", "id==0");

    TH1F *h1_RIntertracks = new TH1F("h1_RIntertracks", "Number of recontructible charged particles/Event;Nb of reconstructible charged particles", 20, 0, 20); //Intermediate that belong to vertices level 3
    outt->Draw("event.e_nR2Inter>>h1_RIntertracks", "id==0");

    h1_e_RInter->SetLineColor(kCyan + 2);
    h1_e_RInter->SetFillColorAlpha(kCyan + 2, 0.55);
    h1_e_RInter->SetMaximum(70000);
    h1_e_RInter->Draw();
    h1_RIntertracks->SetLineColor(kCyan - 3);
    h1_RIntertracks->SetFillColorAlpha(kCyan - 3, 0.45);
    h1_RIntertracks->Draw("Sames");

    gPad->Update();
    TPaveStats *st4Inter = (TPaveStats *)h1_RIntertracks->FindObject("stats");
    st4Inter->SetY1NDC(0.75);
    st4Inter->SetY2NDC(0.6);

    auto leg4Inter = new TLegend(0.68, 0.50, 0.99, 0.30);
    leg4Inter->AddEntry(h1_e_RInter, "#splitline{Intermediate reconstructible}{charged particles}", "f");
    leg4Inter->AddEntry(h1_RIntertracks, "#splitline{Intermediate tracks}{#splitline{that belong to vertices with}{#splitline{at least 2 reconstructible}{or intermediate particles}}}", "f");
    leg4Inter->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//
    //By vertices

    TH1F *h1_v_Neutral = new TH1F("h1_v_Neutral", "Nb of Neutral particles/Vertex;Nb of Neutral Charged", 20, 0, 20);
    h1_v_Neutral->SetLineColor(14);
    h1_v_Neutral->SetFillColorAlpha(14, 0.45);
    outt->Draw("nNeutral>>h1_v_Neutral");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH1F *h1_v_Charged = new TH1F("h1_v_Charged", "Number of charged particles/Vertex;Nb of particles", 20, 0, 20);
    h1_v_Charged->SetLineColor(860);
    h1_v_Charged->SetFillColorAlpha(860, 0.55);
    outt->Draw("nCharged>>h1_v_Charged");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH1F *h1_v_Fcharged = new TH1F("h1_v_Fcharged", "Number of final charged particles/Vertex;Nb of particles", 20, 0, 20);
    h1_v_Fcharged->SetLineColor(804);
    h1_v_Fcharged->SetFillColorAlpha(804, 0.55);
    outt->Draw("nFinalcharged>>h1_v_Fcharged");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH1F *h1_v_Rcharged = new TH1F("h1_v_Rcharged", "Number of reconstructible particles/Vertex;Nb of particles", 20, 0, 20);
    h1_v_Rcharged->SetLineColor(418);
    h1_v_Rcharged->SetFillColorAlpha(418, 0.55);
    outt->Draw("nRstructed>>h1_v_Rcharged");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH1F *h1_v_RInter = new TH1F("h1_v_RInter", "Number of reconstructible intermediate particles/Vertex;Nb of particles", 10, 0, 10);
    h1_v_RInter->SetLineColor(kCyan + 2);
    h1_v_RInter->SetFillColorAlpha(kCyan + 2, 0.55);
    outt->Draw("nRstInter>>h1_v_RInter");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    TH1F *h1_pdg_all = new TH1F("h1_pdg_all", "Total Number of Vertices/PDG ID code;PDG ID code", 100000, 0, 100000); //PDG code of NON-reconstructible vertices
    outt->Draw("abs(vPdg)>>h1_pdg_all");
    c1->SetLogy();
    c1->SetLogx();

    TH1F *h1_pdg_real = new TH1F("h1_pdg_real", "Total Number of Vertices/PDG ID code;PDG ID code", 100000, 0, 100000); //PDG code of reconstructible vertices
    outt->Draw("abs(vPdg)>>h1_pdg_real", "vReal==3");
    c1->SetLogy();
    c1->SetLogx();

    h1_pdg_all->SetLineColor(kMagenta + 2);
    h1_pdg_all->SetFillColorAlpha(kMagenta + 2, 0.45);
    h1_pdg_all->SetStats(0);
    h1_pdg_all->Draw();
    h1_pdg_real->SetLineColor(kGreen + 2);
    h1_pdg_real->SetFillColorAlpha(kGreen + 2, 0.55);
    h1_pdg_real->SetStats(0);
    h1_pdg_real->Draw("Sames");

    gPad->Update();
    //TPaveStats *st5 = (TPaveStats *)h1_pdg_real->FindObject("stats");
    //st5->SetY1NDC(0.75);
    //st5->SetY2NDC(0.6);

    auto leg5 = new TLegend(0.72, 0.9, 0.99, 0.70);
    leg5->AddEntry(h1_pdg_all, "Non-reconstructible", "f");
    leg5->AddEntry(h1_pdg_real, "Reconstructible", "f");
    leg5->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//

    TH1F *h1_pdg_realInter = new TH1F("h1_pdg_realInter", "Total Number of Vertices/PDG ID code;PDG ID code", 100000, 0, 100000); //PDG code of real vertices (lvl 3 or 4)
    outt->Draw("abs(vPdg)>>h1_pdg_realInter", "vReal>=3");
    c1->SetLogy();
    c1->SetLogx();

    h1_pdg_all->SetLineColor(kMagenta + 2);
    h1_pdg_all->SetFillColorAlpha(kMagenta + 2, 0.45);
    h1_pdg_all->SetStats(0);
    h1_pdg_all->Draw();
    h1_pdg_realInter->SetLineColor(kCyan + 2);
    h1_pdg_realInter->SetFillColorAlpha(kCyan + 2, 0.55);
    h1_pdg_realInter->SetStats(0);
    h1_pdg_realInter->Draw("Sames");

    gPad->Update();
    //TPaveStats *st5 = (TPaveStats *)h1_pdg_real->FindObject("stats");
    //st5->SetY1NDC(0.75);
    //st5->SetY2NDC(0.6);

    auto leg5Inter = new TLegend(0.72, 0.9, 0.99, 0.70);
    leg5Inter->AddEntry(h1_pdg_all, "Non-reconstructible", "f");
    leg5Inter->AddEntry(h1_pdg_realInter, "#splitline{Reconstructible and}{intermediates}", "f");
    leg5Inter->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    //**************************//
    /*
    //2D histograms by vertex
    TH2F *h2_neut_vs_char = new TH2F("h2_neut_vs_char", "Nb of Neutral vs. Nb of Charged;Nb of Charged;Nb of Neutral", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nNeutral:nCharged>>h2_neut_vs_char");
    h2_neut_vs_char->Draw("colz");
    c1->SetLogy(0);
    c1->SetLogx(0);
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH2F *h2_fchar_vs_char = new TH2F("h2_fchar_vs_char", "Nb of Final charged vs. Nb of Charged;Nb of Charged;Nb of Final charged", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nFinalcharged:nCharged>>h2_fchar_vs_char");
    h2_fchar_vs_char->Draw("colz");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH2F *h2_rchar_vs_char = new TH2F("h2_rchar_vs_char", "Nb of Reconstructible vs. Nb of Charged;Nb of Charged;Nb of Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nCharged>>h2_rchar_vs_char");
    h2_rchar_vs_char->Draw("colz");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH2F *h2_rchar_vs_fchar = new TH2F("h2_rchar_vs_fchar", "Nb of Reconstructible vs. Nb of Final charged; Nb of Final charged;Nb of Reconstructible", 30, 0, 10, 30, 0, 10); // over vertices
    outt->Draw("nRstructed:nFinalcharged>>h2_rchar_vs_fchar");
    h2_rchar_vs_fchar->Draw("colz");
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");
    
    TH2F *h2_pdg_rad = new TH2F("h2_pdg_rad", "PDG ID vs. Radial distance;Distance [cm];PDG ID", 200, 0, 10, 10000, 0, 10000);
    outt->Draw("abs(vPdg):radialpos>>h2_pdg_rad", "vReal==3");
    h2_pdg_rad->Draw("colz");
    c1->SetLogy();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");
    */
    //**************************//

    //Radial distance

    TH1F *h1_rad_all = new TH1F("h1_rad_all", "Radial distance of vertices; distance [cm]", 200, 0, 10); //all vertices
    outt->Draw("radialpos>>h1_rad_all");
    c1->SetLogx(0);
    c1->SetLogy();

    TH1F *h1_rad_real = new TH1F("h1_rad_real", "Radial distance of vertices; distance [cm]", 200, 0, 10); //real vertices (lvl3 + lvl4)
    outt->Draw("radialpos>>h1_rad_real", "vReal>=3");
    c1->SetLogy();

    TH1F *h1_rad_pipe = new TH1F("h1_rad_pipe", "Radial distance of vertices; distance [cm]", 200, 0, 10); //real vertices in beam pipe
    outt->Draw("radialpos>>h1_rad_pipe", "vReal>=3 && radialpos<1.2 ");
    c1->SetLogy();

    h1_rad_all->SetLineColor(kMagenta + 2);
    h1_rad_all->SetFillColorAlpha(kMagenta + 2, 0.45);
    h1_rad_all->Draw();
    h1_rad_real->SetLineColor(kGreen + 2);
    h1_rad_real->SetFillColorAlpha(kGreen + 2, 0.55);
    h1_rad_real->Draw("Sames");
    h1_rad_pipe->SetLineColor(kRed);
    h1_rad_pipe->SetFillColorAlpha(kRed, 0.55);
    h1_rad_pipe->Draw("Sames");

    gPad->Update();
    TPaveStats *st6a = (TPaveStats *)h1_rad_real->FindObject("stats");
    st6a->SetY1NDC(0.75);
    st6a->SetY2NDC(0.6);
    gPad->Update();
    TPaveStats *st6b = (TPaveStats *)h1_rad_pipe->FindObject("stats");
    st6b->SetY1NDC(0.57);
    st6b->SetY2NDC(0.42);

    auto leg6 = new TLegend(0.42, 0.8, 0.69, 0.63);
    leg6->AddEntry(h1_rad_all, "Non-reconstructible", "f");
    leg6->AddEntry(h1_rad_real, "#splitline{Real vertices}{(Reconstructible + Inter)}", "f");
    leg6->AddEntry(h1_rad_pipe, "#splitline{Real vertices inside}{the beam pipe}", "f");
    leg6->Draw();
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    TH1F *h1_rad_r = new TH1F("h1_rad_r", "Radial distance of vertices; distance [cm]", 100, 0, 2); //cumulative
    outt->Draw("radialpos>>h1_rad_r", "vReal>=3");
    TH1F *hcumul = (TH1F *)h1_rad_r->GetCumulative();
    hcumul->Scale(1 / (h1_rad_r->GetEntries()));
    hcumul->SetStats(0);
    hcumul->Draw();
    c1->SetGrid();
    c1->SetLogy(0);
    c1->Update();
    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf");

    c1->Print("./histo/B0toKsJPsi-100k-histos.pdf]");
    f.Close();
}
