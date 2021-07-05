#define readvtx2tree_cxx
#include "readvtx2tree.h"

//*****************************************************************
void readvtx2tree::booking() //booking the tree and histograms
{
  outfile = new TFile("./data/vtx2mixedB-10k-tree.root", "RECREATE");
  outtree = new TTree("outt", "Vertex information");

  avertex = new Mvertex();
  outtree->Branch("vertex", "Mvertex", &avertex);                              // Create branch for vertex properties
  outtree->Branch("event", &counter, "e_id/I:e_ncand/I:e_nvtx/I:e_nvtxreal/I:e_skip/I"); // Create branch for event counter
}

//*****************************************************************
void readvtx2tree::saving() //saving the tree and histograms
{
  outtree->Write();
  outfile->Close();
}

void readvtx2tree::Loop(int nevents)
{
  //   In a ROOT session, you can do:
  //      root> .L readvtx2tree.C
  //      root> readvtx2tree t
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
  { // Start loop on candidates
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0)
      break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if (__candidate__ == 0) // Reset candidate list and vertex list vectors for each new event
    {
      if (event_id != 0)
      {
        updatetree(); // Update tree for previous event
        resetevent(); // Reset event variable lists
      }
      event_id++;
    }
    /*
    cout << "\n************************************" << endl;
    cout << "Entry id: " << jentry + 1 << "\nEvent id: " << __event__ << "\nNo. of tracks: " << vtx2_nTracks << endl;
    cout << "No. of Candidates: " << ncand << "\nCandidate id: " << __candidate__ << "\nvtx2_genID: " << vtx2_genID 
         << "\nt1_mcID_m: " << t1_mcID_m << "\nt2_mcID_m: " << t2_mcID_m << "\nt1_mcPDG: " << t1_mcPDG << "\nt2_mcPDG: " << t2_mcPDG << endl;
    */
    candidateloop(jentry);

  } // End loop on candidates

  updatetree(); // Update tree for the last event

  saving();
}

//*****************************************************************
void readvtx2tree::candidateloop(int candidate_id)
{
  if (t1_mcID_m == t2_mcID_m && candidatescheck(t1_genID, t2_genID) == 1)
  {
    skip++;
    nvtx++;
    candidatelist.push_back(t1_genID);
    candidatelist.push_back(t2_genID);
    //cout << "Skipping pair no. " << candidate_id << endl;
  }
  else if (t1_mcID_m == t2_mcID_m)
  {
    nvtx++;
    candidatelist.push_back(t1_genID);
    candidatelist.push_back(t2_genID);
    addvertex(vtx2_genID, 4, t1_mcPDG_m, vtx2_mcDecayVertexX, vtx2_mcDecayVertexY, vtx2_mcDecayVertexZ);
    //cout << "New vertex created from pair no. " << candidate_id << endl;
  }
}

void readvtx2tree::updatetree()
{
  cout << "\n************************************" << endl;
  cout << "\nEvent id: " << event_id << "\n" << endl;

  // Update event counter branch
  counter.e_id = event_id;
  counter.e_ncand = ncand;
  counter.e_nvtx = nvtx;
  counter.e_nvtxreal = vertexlist.size();
  counter.e_skip = skip;

  // Loop over vertices to fill outtree and print
  if (vertexlist.size() == 0)
  {
    avertex->Copy();
    outtree->Fill();
  }

  else
  {
    for (int i = 0; i < vertexlist.size(); i++)
    {
      cout << "-> Vertex id: " << vertexlist[i].GetId() << ", Mother vertex id: " << vertexlist[i].Getm_id()
           << ", Real = " << vertexlist[i].GetReal() << ", PDGcode = " << vertexlist[i].GetvPdg() << ", Radial position: "
           << vertexlist[i].GetRadialpos() << endl;

      avertex->Copy(vertexlist[i]); // Update vertex branch
      outtree->Fill();              // Fill all tree branches
    }
  }

  cout << "\nEvent Candidates: " << ncand << endl;
  cout << "Event Vertices (just by mother association): " << nvtx << endl;
  cout << "Event Vertices (no 2x counting): " << vertexlist.size() << endl;

  totalvtx += nvtx;
  totalvtxreal += vertexlist.size();
  totalskip += skip;
  totalcand += ncand;

  cout << "\nTotal no. of candidates: " << totalcand << endl;
  cout << "Total no. of vertices: " << totalvtx << endl;
  cout << "Total no. of real vertices (no 2x counting): " << totalvtxreal << endl;
  cout << "Total no. of skipped pairs: " << totalskip << endl;
  cout << "\n************************************" << endl;
}
