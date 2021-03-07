#define readgentree_cxx
#include "readgentree.h"

//*****************************************************************
void readgentree::booking() //histogram
{

  outtree = new TTree("outt", "Vertex information");
  //TBranch *b = fEventTree->Branch("fEvent","DEvent",&fEvent,64000,99);
  avertex = new Mvertex();
  outtree->Branch( "vertex", "Mvertex", &avertex );

  h1nvertex = new TH1F("h1nvertex", "# Vertices/Event;# Vertices", 100, 0, 100); // over events

  h1nreal = new TH1F("h1nreal", "# Real Vertices/Event;# Real Vertices", 100, 0, 100); // over events

  h2nvtxchrgd = new TH2F("h2nvtxchrgd", "# Vertices/Event vs. # Charged;# Charged/Vertex; # Vertices/Event ", 30, 0, 10, 30, 0, 10); // over events

  h1ncharged = new TH1F("h1ncharged", "# Charged/Vertex;# Charged", 100, 0, 100); // over vertices

  h1nneutral = new TH1F("h1nneutral", "# Neutral/Vertex;# Neutral", 100, 0, 100); // over vertices

  h1distance = new TH1F("h1distance", "Distance/Vertex; Distance", 100, 0, 100); // over vertices

  h1realdistance = new TH1F("h1realdistance", "Distance/Real Vertex; Distance", 100, 0, 100); // over vertices

  h2nparticles = new TH2F("h2nparticles", "# Neutral vs. # Charged;# Neutral; # Charged ", 30, 0, 10, 30, 0, 10); // over vertices
}

//*****************************************************************
void readgentree::saving() //saving the histogram
{

  TFile outFile("readgentree.root", "RECREATE");

  outtree->Write();
  h1nvertex->Write();
  h1nreal->Write();
  h2nvtxchrgd->Write();
  h1ncharged->Write();
  h1nneutral->Write();
  h1distance->Write();
  h1realdistance->Write();
  h2nparticles->Write();

  outFile.Close();
}

//*****************************************************************
void readgentree::display( )
{
 // Display all histo one by one on the same canvas
 // Print them on an output file in PDF format

  TCanvas *c = new TCanvas("c","vertex study",25,25,800,800);
  c->Print("readgentree.pdf[");

  h1nvertex->Draw();
  h1nreal->Draw();
  h2nvtxchrgd->Draw("colz");
  h1ncharged->Draw();
  h1nneutral->Draw();
  h1distance->Draw();
  h1realdistance->Draw();
  h2nparticles->Draw("colz");

  c->Print("readgentree.pdf]");

}

//*****************************************************************
void readgentree::Loop( int nevents )
{
//   In a ROOT session, you can do:
//      root> .L readgentree.C
//      root> readgentree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   booking();

   Long64_t nentries = fChain->GetEntriesFast();
   if( nevents==0 ) { nevents = nentries; }

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nevents;jentry++) { // Start loop on events

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      cout << endl << "************************************" << endl;
      cout << "Particles in event: " << MCParticles_ << endl;
      identifyVertex();

   } // end loop on events

   display();
   saving();
}

//*****************************************************************
int readgentree::ndaughters(int x)
{

  int nb = MCParticles_m_lastDaughter[x] - MCParticles_m_firstDaughter[x];

  if (nb != 0)
  {

    nb++;
  }

  return nb;
}

//*****************************************************************
double readgentree::decaytime(int x)
{

  double t = MCParticles_m_decayTime[x] - MCParticles_m_productionTime[x];

  return t;
}

//*****************************************************************
int readgentree::particlecharge(int pdg) //This function is not used to calculate the charge of resonance
{
  int length = (int)log10(abs(pdg)) + 1;

  if (length == 3)
  {

    int sum = (pdg / 100 % 10) + (pdg / 10 % 10);

    if ((sum % 2) == 0) // mesons
    {
      return 0; // 0 is neutral
    }
    else
    {
      return 1; // 1 is charged
    }
  }

  else if (length == 2) // leptons
  {
    if ((pdg % 2) == 0)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  else
  {
    cout << "Error: pdg code " << pdg << " not accounted for."
         << ", Length: " << length << endl;
    return pdg;
  }
}

//*****************************************************************
void readgentree::daughterloop(int first, int last, int vId)
{

  //cout << "No. of charged at start: " << nC << endl;
  //cout << "No. of neutral at start: " << nN << endl;

  for (int d = first; d <= last; d++)
  {
    if (ndaughters(d - 1) == 0 && particlecharge(MCParticles_m_pdg[d - 1]) == 1) // final charged particle
    {
      vertexlist[vId].Addcharged();

      if (pTransverse(d - 1) > 0.05 && prodAngle(d - 1) > 31 && prodAngle(d - 1) < 163)
      {
        vertexlist[vId].Addrstructed();
      }
      vertexlist[vId].isReal();

      cout << "Vertex: " << vId <<  ", Index no. " << d  << ", pdg code: " << MCParticles_m_pdg[d - 1] << " is a final charged particle with prod. angle = "
      << prodAngle(d - 1) << " deg and pT = " << pTransverse(d - 1) << " GeV/c" << endl;
    }

    else if (ndaughters(d - 1) == 0 && particlecharge(MCParticles_m_pdg[d - 1]) == 0) // final neutral particle
    {
      vertexlist[vId].Addneutral();
      //cout << "Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d - 1] << " is a final neutral particle." << endl;
    }

    else if (decaytime(d - 1) == 0 && ndaughters(d - 1) != 0) // resonance
    {
      daughterloop(MCParticles_m_firstDaughter[d - 1], MCParticles_m_lastDaughter[d - 1], vId);
      //cout << "Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d - 1] << " is a resonance." << endl;
    }

    else if (decaytime(d - 1) != 0 && ndaughters(d - 1) != 0) // vertex (real or not)
    {
      if (particlecharge(MCParticles_m_pdg[d - 1]) == 1)
      {
        vertexlist[vId].Addcharged(); //To be checked, do we account for intermediate vertices?
        vertexlist[vId].isReal();
      }
      else
      {
        vertexlist[vId].Addneutral();
      }

      int newid = addvertex(0, 0, 0, 0, MCParticles_m_pdg[d - 1], MCParticles_m_decayVertex_x[d - 1], MCParticles_m_decayVertex_y[d - 1], MCParticles_m_decayVertex_z[d - 1]); // store information oabout vertex

      // Recursive method
      daughterloop(MCParticles_m_firstDaughter[d - 1], MCParticles_m_lastDaughter[d - 1], newid);
    }
  }

  //cout << "No. of charged at end: " << nC << endl;
  //cout << "No. of neutral at end: " << nN << endl;
}
//*****************************************************************
void readgentree::identifyVertex()
{
  // analyse the event and count vertices
  // For each vertex:
  //  - nb of charged particles outgoing
  //  - nb of neutral particles
  //  - radial position

  // available variables
  // Int_t           MCParticles_ // nf of particles in the event
  // UShort_t        MCParticles_m_status[kMaxMCParticles];   //[MCParticles_]
  // Int_t           MCParticles_m_pdg[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_mass[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_energy[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_momentum_x[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_momentum_y[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_momentum_z[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_productionTime[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_productionVertex_x[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_productionVertex_y[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_productionVertex_z[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_decayTime[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_decayVertex_x[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_decayVertex_y[kMaxMCParticles];   //[MCParticles_]
  // Float_t         MCParticles_m_decayVertex_z[kMaxMCParticles];   //[MCParticles_]
  // Int_t           MCParticles_m_mother[kMaxMCParticles];   //[MCParticles_]
  // Int_t           MCParticles_m_firstDaughter[kMaxMCParticles];   //[MCParticles_]
  // Int_t           MCParticles_m_lastDaughter[kMaxMCParticles];   //[MCParticles_]

  vertexlist.resize(0); // reinitialize vertex list vector
  vtxreal = 0;          // Reinitialize no. of real vertices

  int vtxid = addvertex(0, 0, 0, 0, MCParticles_m_pdg[0], MCParticles_m_decayVertex_x[0], MCParticles_m_decayVertex_y[0], MCParticles_m_decayVertex_z[0]);

  daughterloop(MCParticles_m_firstDaughter[0], MCParticles_m_lastDaughter[0], vtxid); // Catalogue event vertices with characteristics into objects

  h1nvertex->Fill(vertexlist.size());

  for (int i = 0; i < vertexlist.size(); i++)
  {

    cout << " Vertex id: " << vertexlist[i].GetId() << ", nCharged: " << vertexlist[i].GetNcharged() << ", nNeutral: "
         << vertexlist[i].GetNneutral() << ", nReconstructed = " << vertexlist[i].GetNrstructed()
         << ", Real = " << vertexlist[i].GetReal() << ", PDGcode = " << vertexlist[i].GetvPdg() << ", Radial position: "
         << vertexlist[i].GetRadialpos() << endl;

    avertex->Copy( vertexlist[i] );
    outtree->Fill();

    h1ncharged->Fill(vertexlist[i].GetNcharged());
    h1nneutral->Fill(vertexlist[i].GetNneutral());
    h1distance->Fill(vertexlist[i].GetRadialpos());
    h2nparticles->Fill(vertexlist[i].GetNneutral(), vertexlist[i].GetNcharged());

    if (vertexlist[i].GetReal() == 1)
    {
      vtxreal++;
      h1realdistance->Fill(vertexlist[i].GetRadialpos());
    }

    switch (vertexlist[i].GetNcharged())
    {

    case 0:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 1:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 2:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 3:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 4:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 5:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 6:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 7:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 8:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 9:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());

    case 10:
      h2nvtxchrgd->Fill(vertexlist[i].GetNcharged(), vertexlist.size());
    }
  }

  h1nreal->Fill(vtxreal);

  cout << "\nEvent Vertices: " << vertexlist.size() << "\nReal Event Vertices: " << vtxreal << endl;

  totalvtx += vertexlist.size();
  totalvtxreal += vtxreal;

  cout << "\n# Vertices Total: " << totalvtx << "\n# Real Vertices Total: " << totalvtxreal << endl;
}
