//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar  8 17:13:19 2021 by ROOT version 6.22/02
// from TTree outt/Vertex information
// found on file: readgentree.root
//////////////////////////////////////////////////////////

#ifndef readout_h
#define readout_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TObject.h"

class readout {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
 //Mvertex         *vertex;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Int_t           id;
   Int_t           nCharged;
   Int_t           nRstructed;
   Int_t           nNeutral;
   Double_t        position[3];
   Double_t        radialpos;
   Bool_t          vReal;
   Int_t           vPdg;
   Int_t           counts_eventid;
   Int_t           counts_nvtx;
   Int_t           counts_nvtxreal;

   // List of branches
   TBranch        *b_vertex_fUniqueID;   //!
   TBranch        *b_vertex_fBits;   //!
   TBranch        *b_vertex_id;   //!
   TBranch        *b_vertex_nCharged;   //!
   TBranch        *b_vertex_nRstructed;   //!
   TBranch        *b_vertex_nNeutral;   //!
   TBranch        *b_vertex_position;   //!
   TBranch        *b_vertex_radialpos;   //!
   TBranch        *b_vertex_vReal;   //!
   TBranch        *b_vertex_vPdg;   //!
   TBranch        *b_counts;   //!

   readout(TTree *tree=0);
   virtual ~readout();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef readout_cxx
readout::readout(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("readgentree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("readgentree.root");
      }
      f->GetObject("outt",tree);

   }
   Init(tree);
}

readout::~readout()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t readout::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t readout::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void readout::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_vertex_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_vertex_fBits);
   fChain->SetBranchAddress("id", &id, &b_vertex_id);
   fChain->SetBranchAddress("nCharged", &nCharged, &b_vertex_nCharged);
   fChain->SetBranchAddress("nRstructed", &nRstructed, &b_vertex_nRstructed);
   fChain->SetBranchAddress("nNeutral", &nNeutral, &b_vertex_nNeutral);
   fChain->SetBranchAddress("position[3]", position, &b_vertex_position);
   fChain->SetBranchAddress("radialpos", &radialpos, &b_vertex_radialpos);
   fChain->SetBranchAddress("vReal", &vReal, &b_vertex_vReal);
   fChain->SetBranchAddress("vPdg", &vPdg, &b_vertex_vPdg);
   fChain->SetBranchAddress("counts", &counts_eventid, &b_counts);
   Notify();
}

Bool_t readout::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void readout::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t readout::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef readout_cxx
