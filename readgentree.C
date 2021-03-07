#define readgentree_cxx
#include "readgentree.h"


//*****************************************************************
void readgentree::booking( )
{

  outtree = new TTree( "outt", "Vertex information");
  // outtree->Branch( "vertex", &avertex, "id/I:ncharged/I:nneutral/I:radialdist/D");

  h1nvertex = new TH1F("h1nvertex", "# vertices/event;# vertex", 100, 0, 100);

}

//*****************************************************************
void readgentree::saving( )
{

  TFile outFile("readgentree.root","RECREATE");

  outtree->Write();
  h1nvertex->Write();

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
int readgentree::ndaughters (int x) {

  int nb = MCParticles_m_lastDaughter[x]-MCParticles_m_firstDaughter[x];

  if (nb!=0) {

    nb++;
  }

  return nb;
}

//*****************************************************************
double readgentree::decaytime (int x) {

  double t = MCParticles_m_decayTime[x]-MCParticles_m_productionTime[x];

  return t;
}

//*****************************************************************
int readgentree::particlecharge (int pdg) { //This function is not used to calculate the charge of resonance

  int length = (int)log10(abs(pdg)) + 1;

  if (length==3) {

    int sum = (pdg / 100 % 10) + (pdg / 10 % 10);

    if ((sum%2)==0) { // mesons

      return 0; // 0 is neutral
    }
    else {

      return 1; // 1 is charged
    }
  }

  else if (length==2) { // leptons

    if ((pdg%2)==0) {

      return 0;
    }

    else {

      return 1;
    }
  }

  else {

    //cout << "Pdg code: " << pdg << " not accounted for." << ", Length: " << length << endl;

    return pdg;
  }
}

//*****************************************************************
void readgentree::daughterloop (int first, int last, int &nC, int &nN) {

  //cout << "No. of charged at start: " << nC << endl;
  //cout << "No. of neutral at start: " << nN << endl;

  for (int d = first; d <= last; d++) {

    if (ndaughters(d-1)==0 && particlecharge(MCParticles_m_pdg[d-1])==1) {

      nC++;
      treated[d-1] = 1;
      cout << "Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d-1] << " is a final charged particle." << endl;
    }

    else if (ndaughters(d-1)==0 && particlecharge(MCParticles_m_pdg[d-1])==0) {

      nN++;
      treated[d-1] = 1;
      cout << "Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d-1] << " is a final neutral particle." << endl;
    }

    else if (decaytime(d-1)==0 && ndaughters(d-1)!=0) {

      //cout << "before d=" << d << ", pdg: " << MCParticles_m_pdg[d-1] << endl;
      daughterloop (MCParticles_m_firstDaughter[d-1], MCParticles_m_lastDaughter[d-1], nC, nN);
      //cout << "First daughter: " << MCParticles_m_firstDaughter[d-1] << " of particle: " << MCParticles_m_pdg[d-1] << endl;
      //cout << "Last daughter: " << MCParticles_m_lastDaughter[d-1] << " of particle: " << MCParticles_m_pdg[d-1] << endl;
      //cout << "after d=" << d << ", pdg: " << MCParticles_m_pdg[d-1] << endl;
      treated[d-1] = 1;
      cout << "Index no. " << d << ", pdg code: " << MCParticles_m_pdg[d-1] << " is a resonance." << endl;
    }
  }

  //cout << "No. of charged at end: " << nC << endl;
  //cout << "No. of neutral at end: " << nN << endl;

}

//*****************************************************************
void readgentree::identifyVertex( )
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


  nvertex = 0;
  nmothers = 0;
  std::fill(std::begin(treated), std::end(treated), 0);
  treated[0] = 1; // Upsilon is already treated
  vtxid = 0;

  for (size_t ipart = 0; ipart < MCParticles_; ipart++) {

    if (treated[ipart]==1) {continue;}

    vtxchrgd = 0;
    vtxntrl = 0;

    if (ndaughters(ipart)!=0) {

      daughterloop(MCParticles_m_firstDaughter[ipart], MCParticles_m_lastDaughter[ipart], vtxchrgd, vtxntrl);
      addvertex( vtxid, vtxchrgd, vtxntrl, 0, 0, 0);
    }

    cout << "A vertex appears with " << vtxchrgd << " charged particles and " << vtxntrl << " neutral particles." << endl;

    vtxid++; // Create a vertex at some point...
  }

  cout << "Event vertices: " << vtxid << endl;

  h1nvertex->Fill( vtxid);

  /*
  for (size_t ipart = 0; ipart < MCParticles_; ipart++) {

    if (ndaughters(ipart)!=0) {

      nmothers++;
    }
  }

  cout << "no. of mothers = " << nmothers << endl;
  */
  /*
  for (size_t ipart = 0; ipart < MCParticles_; ipart++) { // Loop on particles

    cout << ipart+1 << ": PDG code = " << MCParticles_m_pdg[ipart]
	 << ", production-decay time " << decaytime(ipart)
	 << ", nb of daughters " << ndaughters(ipart)
	 << ", mother PDG code = " << MCParticles_m_pdg[MCParticles_m_mother[ipart]-1]
	 << endl;
    cout << endl;

    if (ndaughters(ipart)!=0) {

      if (decaytime(ipart)==0) {

	cout << "-->Particle index no." << ipart+1 << " is a resonance and it has " << ndaughters(ipart) << " daughters." << endl;
	cout << endl;
      }

      else {

	cout << "-->Particle index no." << ipart+1 << " has " << ndaughters(ipart) << " daughters." << endl;
	cout << endl;

	nvertex++;

	cout << "-->A vertex is created at this point.***" << endl;
	cout << endl;
      }
    }

    else {

      cout << "-->Particle index no." << ipart+1 << " has no daughter." << endl;
      cout << endl;
    }

  } // end loop on particles
  cout << "No. of vertices " << nvertex << endl;
  */
}
