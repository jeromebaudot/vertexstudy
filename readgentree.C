#define readgentree_cxx
#include "readgentree.h"

//*****************************************************************
void readgentree::booking() //booking the tree and histograms
{
  outfile = new TFile("B0toKsJPsi-100k-tree.root", "RECREATE");
  outtree = new TTree("outt", "Vertex information");
  //TBranch *b = fEventTree->Branch("fEvent","DEvent",&fEvent,64000,99);

  avertex = new Mvertex();
  outtree->Branch("vertex", "Mvertex", &avertex);                                                                                                                                      // Create branch for vertex properties
  outtree->Branch("event", &counter, "e_id/I:e_nvtx/I:e_nvtxreal1/I:e_nvtxreal2/I:e_nvtxreal3/I:e_nNeutral/I:e_nCharged/I:e_nFcharged/I:e_nF2charged/I:e_nRcharged/I:e_nR2charged/I"); // Create branch for event counter
}

//*****************************************************************
void readgentree::saving() //saving the tree and histograms
{
  //TFile outFile("readgentree.root", "RECREATE");

  outtree->Write();
  outfile->Close();
}

//*****************************************************************
void readgentree::Loop(int nevents)
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
  if (fChain == 0)
    return;

  booking();

  Long64_t nentries = fChain->GetEntriesFast();
  if (nevents == 0)
  {
    nevents = nentries;
  }

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry = 0; jentry < nevents; jentry++)
  { // Start loop on events

    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0)
      break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    cout << endl
         << "************************************" << endl;
    cout << "Event Id: " << jentry + 1 << "\nParticles in event: " << MCParticles_ << endl;
    identifyVertex(jentry);

  } // end loop on events

  saving();
}

//*****************************************************************
int readgentree::ndaughters(int x)
{
  int nb = 0;

  if (MCParticles_m_lastDaughter[x] != 0 && MCParticles_m_firstDaughter[x] != 0)
  {
    nb = MCParticles_m_lastDaughter[x] - MCParticles_m_firstDaughter[x] + 1;
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
int readgentree::particlecharge(int pdg) // This function is not used to calculate the amount of charge yet...
{
  int length = (int)log10(abs(pdg)) + 1;

  switch (length)
  {
  case 4: // sees only protons, neutrons and light baryons for now...
  {
    int sum = (abs(pdg) / 1000 % 10) + (abs(pdg) / 100 % 10) + (abs(pdg) / 10 % 10);

    if ((sum % 2) == 0)
    {
      return 0; // 0 is neutral
    }
    else
    {
      return 1; // 1 is charged
    }
  }
  break;
  case 3: // mesons
  {
    int sum = (abs(pdg) / 100 % 10) + (abs(pdg) / 10 % 10);

    if ((sum % 2) == 0)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  break;
  case 2: // leptons or gauge bosons
  {
    if (abs(pdg) == 21 || abs(pdg) == 23) // gluon or Z boson cases
    {
      return 0;
    }
    else if ((abs(pdg) % 2) == 0)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  break;
  case 1: // quarks
  {
    return 1;
  }
  break;
  default:
  {
    cout << "Error: pdg code " << pdg << " not accounted for."
         << ", Length: " << length << endl;
    return pdg;
  }
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

      // (No quarks as final charged particles)
      if (abs(MCParticles_m_pdg[d - 1]) > 10)
      {
        vertexlist[vId].Addfinalcharged();
      }

      // Check reconstructibility conditions
      // (No quarks as reconstructed particles)
      if (pTransverse(d - 1) > 0.05 && prodAngle(d - 1) > 17 && prodAngle(d - 1) < 150 && abs(MCParticles_m_pdg[d - 1]) > 10)
      {
        vertexlist[vId].Addrstructed();
      }

      if (vertexlist[vId].GetReal() < 3)
      {
        vertexlist[vId].IsReal();
      }

      //cout << "IsReal = " << vertexlist[vId].IsReal() << endl;

      //cout << "Vertex: " << vId << ", Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d - 1] << " is a final charged particle with prod. angle = "
      //     << prodAngle(d - 1) << " deg and pT = " << pTransverse(d - 1) << " GeV/c" << endl;
    }

    else if (ndaughters(d - 1) == 0 && particlecharge(MCParticles_m_pdg[d - 1]) == 0) // final neutral particle
    {
      vertexlist[vId].Addneutral();
      //cout << "Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d - 1] << " is a final neutral particle." << endl;
    }

    else if (decaytime(d - 1) == 0 && ndaughters(d - 1) != 0) // resonance
    {
      // Recursive method for resonance
      daughterloop(MCParticles_m_firstDaughter[d - 1], MCParticles_m_lastDaughter[d - 1], vId);
      //cout << "Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d - 1] << " is a resonance." << endl;
    }

    else if (decaytime(d - 1) != 0 && ndaughters(d - 1) != 0) // vertex (real or not)
    {
      if (particlecharge(MCParticles_m_pdg[d - 1]) == 1)
      {
        vertexlist[vId].Addcharged(); //To be checked, do we account for intermediate vertices? No

        if (vertexlist[vId].GetReal() < 1)
        {
          vertexlist[vId].IsReal();
        }
      }
      else
      {
        vertexlist[vId].Addneutral();
      }

      int newid = addvertex(0, 0, 0, 0, 0, MCParticles_m_pdg[d - 1], MCParticles_m_decayVertex_x[d - 1], MCParticles_m_decayVertex_y[d - 1], MCParticles_m_decayVertex_z[d - 1]); // store information oabout vertex

      // Recursive method
      daughterloop(MCParticles_m_firstDaughter[d - 1], MCParticles_m_lastDaughter[d - 1], newid);
    }
  }

  //cout << "No. of charged at end: " << nC << endl;
  //cout << "No. of neutral at end: " << nN << endl;
}
//*****************************************************************
void readgentree::identifyVertex(int event_id)
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

  vertexlist.resize(0); // Reinitialize vertex list vector in the event
  vtxreal1 = 0;         // Reinitialize no. of real vertices in the event
  vtxreal2 = 0;         // Reinitialize no. of real vertices in the event
  vtxreal3 = 0;         // Reinitialize no. of real vertices in the event
  Neutral = 0;          // Reinitialize no. of neutral particles in the event
  Charged = 0;          // Reinitialize no. of charged particles in the event
  Fcharged = 0;
  F2charged = 0; // Reinitialize no. of final particles in the event
  Rcharged = 0;  // Reinitialize no. of reconstructible particles in the event
  R2charged = 0;

  double skip = 0; // Reinitialize no. of skipped particles in the event, here just to check
  for (int i = 0; i < MCParticles_; i++)
  {
    if (ndaughters(i) != 0 && MCParticles_m_mother[i] == 0)
    {
      cout << "The particle with PDG code : " << MCParticles_m_pdg[i] << " ,Nb of daughters: " << ndaughters(i) << " ,index of mother: "
           << MCParticles_m_mother[i] << " creates a new primary vertex" << endl;

      int vtxid = addvertex(0, 0, 0, 0, 0, MCParticles_m_pdg[i], MCParticles_m_decayVertex_x[i], MCParticles_m_decayVertex_y[i], MCParticles_m_decayVertex_z[i]);

      // Catalogue event vertices with their properties
      daughterloop(MCParticles_m_firstDaughter[i], MCParticles_m_lastDaughter[i], vtxid);
    }
    else
    {
      //cout << "The particle with PDG code : " << MCParticles_m_pdg[i] << " ,Nb of daughters: " << ndaughters(i) << " ,index of mother: "
      //     << MCParticles_m_mother[i] << " is skipped " << endl;
      skip++;
    }
  }
  cout << "The number of skipped particles is: " << skip << endl;

  // Update counts for real vertices
  for (int i = 0; i < vertexlist.size(); i++)
  {
    if (vertexlist[i].GetReal() >= 1) //level 1: at least 2 charged particles in the vertex
    {
      vtxreal1++;
    }
    if (vertexlist[i].GetReal() >= 2) //level 2: at least 2 final charged particles in the vertex
    {
      vtxreal2++;
    }
    if (vertexlist[i].GetReal() == 3) //level 3: at least 2 reconstructible particles in the vertex
    {
      vtxreal3++;
    }
    Neutral += vertexlist[i].GetNneutral();
    Charged += vertexlist[i].GetNcharged();
    Fcharged += vertexlist[i].GetNFinalcharged();
    if (vertexlist[i].GetReal() >= 2)
    {
      F2charged += vertexlist[i].GetNFinalcharged();
      cout << "F2charged= " << F2charged << endl;
    }
    Rcharged += vertexlist[i].GetNrstructed();
    if (vertexlist[i].GetReal() == 3)
    {
      R2charged += vertexlist[i].GetNrstructed();
      cout << "R2charged= " << R2charged << endl;
    }
  }

  // Update event counter branch
  counter.e_id = event_id;
  counter.e_nvtx = vertexlist.size();
  counter.e_nvtxreal1 = vtxreal1;
  counter.e_nvtxreal2 = vtxreal2;
  counter.e_nvtxreal3 = vtxreal3;
  counter.e_nNeutral = Neutral;
  counter.e_nCharged = Charged;
  counter.e_nFcharged = Fcharged;
  counter.e_nF2charged = F2charged;
  counter.e_nRcharged = Rcharged;
  counter.e_nR2charged = R2charged;

  // Loop over vertices to fill tree and print
  for (int i = 0; i < vertexlist.size(); i++)
  {

    cout << "->Vertex id: " << vertexlist[i].GetId() << ", nCharged: " << vertexlist[i].GetNcharged() << ", nNeutral: "
         << vertexlist[i].GetNneutral() << ", nReconstructed = " << vertexlist[i].GetNrstructed()
         << ", nFinalcharged = " << vertexlist[i].GetNFinalcharged() << ", Real = " << vertexlist[i].GetReal() << ", PDGcode = " << vertexlist[i].GetvPdg() << ", Radial position: "
         << vertexlist[i].GetRadialpos() << endl;

    avertex->Copy(vertexlist[i]); // Transfer vertex properties to a separate object for tree fill
    outtree->Fill();              // Fill all tree branches
  }
  cout << "\nEvent Vertices: " << vertexlist.size() << "\nReal Event Vertices: " << vtxreal3 << endl;

  totalvtx += vertexlist.size();
  totalvtxreal += vtxreal3;
  totalFcharged += Fcharged;
  totalRcharged += Rcharged;

  cout << "\n# Vertices Total: " << totalvtx << "\n# Real Vertices Total: " << totalvtxreal << endl;
  cout << "\n# Final Charged Particles Total: " << totalFcharged << "\n# Reconstructible Particles Total: " << totalRcharged << endl;
}
