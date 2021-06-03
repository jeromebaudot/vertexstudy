//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb  1 23:01:28 2021 by ROOT version 6.22/06
// from TTree tree/tree
// found on file: ./data/B0toKsJPsi-100k.root
//////////////////////////////////////////////////////////

#ifndef readgentree_h
#define readgentree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

#include "mvertex.h"
#include <vector>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

class readgentree
{
public:
   TTree *fChain;  //!pointer to the analyzed TTree or TChain
   Int_t fCurrent; //!current Tree number in a TChain

   // Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxMCParticles = 100;

   // Declaration of leaf types
   //Belle2::EventMetaData *EventMetaData;
   UInt_t fUniqueID;
   UInt_t fBits;
   UInt_t m_event;
   Int_t m_run;
   Int_t m_subrun;
   Int_t m_experiment;
   Int_t m_production;
   ULong64_t m_time;
   string m_parentLfn;
   Double_t m_generatedWeight;
   UInt_t m_errorFlag;
   //Belle2::MCInitialParticles *MCInitialParticles;
   TLorentzVector m_her;
   TLorentzVector m_ler;
   TVector3 m_vertex;
   Bool_t m_validFlag;
   Int_t m_generationFlags;
   Int_t MCParticles_;
   UInt_t MCParticles_fUniqueID[kMaxMCParticles];                //[MCParticles_]
   UInt_t MCParticles_fBits[kMaxMCParticles];                    //[MCParticles_]
   UShort_t MCParticles_m_status[kMaxMCParticles];               //[MCParticles_]
   Int_t MCParticles_m_pdg[kMaxMCParticles];                     //[MCParticles_]
   Float_t MCParticles_m_mass[kMaxMCParticles];                  //[MCParticles_]
   Float_t MCParticles_m_energy[kMaxMCParticles];                //[MCParticles_]
   Float_t MCParticles_m_momentum_x[kMaxMCParticles];            //[MCParticles_]
   Float_t MCParticles_m_momentum_y[kMaxMCParticles];            //[MCParticles_]
   Float_t MCParticles_m_momentum_z[kMaxMCParticles];            //[MCParticles_]
   Bool_t MCParticles_m_validVertex[kMaxMCParticles];            //[MCParticles_]
   Float_t MCParticles_m_productionTime[kMaxMCParticles];        //[MCParticles_]
   Float_t MCParticles_m_productionVertex_x[kMaxMCParticles];    //[MCParticles_]
   Float_t MCParticles_m_productionVertex_y[kMaxMCParticles];    //[MCParticles_]
   Float_t MCParticles_m_productionVertex_z[kMaxMCParticles];    //[MCParticles_]
   Float_t MCParticles_m_decayTime[kMaxMCParticles];             //[MCParticles_]
   Float_t MCParticles_m_decayVertex_x[kMaxMCParticles];         //[MCParticles_]
   Float_t MCParticles_m_decayVertex_y[kMaxMCParticles];         //[MCParticles_]
   Float_t MCParticles_m_decayVertex_z[kMaxMCParticles];         //[MCParticles_]
   Int_t MCParticles_m_mother[kMaxMCParticles];                  //[MCParticles_]
   Int_t MCParticles_m_firstDaughter[kMaxMCParticles];           //[MCParticles_]
   Int_t MCParticles_m_lastDaughter[kMaxMCParticles];            //[MCParticles_]
   Int_t MCParticles_m_secondaryPhysicsProcess[kMaxMCParticles]; //[MCParticles_]
   UShort_t MCParticles_m_seenIn_m_bits[kMaxMCParticles];        //[MCParticles_]

   // List of branches
   TBranch *b_EventMetaData_fUniqueID;               //!
   TBranch *b_EventMetaData_fBits;                   //!
   TBranch *b_EventMetaData_m_event;                 //!
   TBranch *b_EventMetaData_m_run;                   //!
   TBranch *b_EventMetaData_m_subrun;                //!
   TBranch *b_EventMetaData_m_experiment;            //!
   TBranch *b_EventMetaData_m_production;            //!
   TBranch *b_EventMetaData_m_time;                  //!
   TBranch *b_EventMetaData_m_parentLfn;             //!
   TBranch *b_EventMetaData_m_generatedWeight;       //!
   TBranch *b_EventMetaData_m_errorFlag;             //!
   TBranch *b_MCInitialParticles_fUniqueID;          //!
   TBranch *b_MCInitialParticles_fBits;              //!
   TBranch *b_MCInitialParticles_m_her;              //!
   TBranch *b_MCInitialParticles_m_ler;              //!
   TBranch *b_MCInitialParticles_m_vertex;           //!
   TBranch *b_MCInitialParticles_m_time;             //!
   TBranch *b_MCInitialParticles_m_validFlag;        //!
   TBranch *b_MCInitialParticles_m_generationFlags;  //!
   TBranch *b_MCParticles_;                          //!
   TBranch *b_MCParticles_fUniqueID;                 //!
   TBranch *b_MCParticles_fBits;                     //!
   TBranch *b_MCParticles_m_status;                  //!
   TBranch *b_MCParticles_m_pdg;                     //!
   TBranch *b_MCParticles_m_mass;                    //!
   TBranch *b_MCParticles_m_energy;                  //!
   TBranch *b_MCParticles_m_momentum_x;              //!
   TBranch *b_MCParticles_m_momentum_y;              //!
   TBranch *b_MCParticles_m_momentum_z;              //!
   TBranch *b_MCParticles_m_validVertex;             //!
   TBranch *b_MCParticles_m_productionTime;          //!
   TBranch *b_MCParticles_m_productionVertex_x;      //!
   TBranch *b_MCParticles_m_productionVertex_y;      //!
   TBranch *b_MCParticles_m_productionVertex_z;      //!
   TBranch *b_MCParticles_m_decayTime;               //!
   TBranch *b_MCParticles_m_decayVertex_x;           //!
   TBranch *b_MCParticles_m_decayVertex_y;           //!
   TBranch *b_MCParticles_m_decayVertex_z;           //!
   TBranch *b_MCParticles_m_mother;                  //!
   TBranch *b_MCParticles_m_firstDaughter;           //!
   TBranch *b_MCParticles_m_lastDaughter;            //!
   TBranch *b_MCParticles_m_secondaryPhysicsProcess; //!
   TBranch *b_MCParticles_m_seenIn_m_bits;           //!

   // Global variables needed for the analysis
   int nvertex;
   int nmothers;
   int vtxreal1;
   int vtxreal2;
   int vtxreal3;
   int Neutral;
   int Charged;
   int Fcharged;
   int F2charged;
   int Rcharged;
   int R2charged;
   int totalvtx;
   int totalvtxreal;
   int totalFcharged;
   int totalRcharged;

   std::vector<Mvertex> vertexlist; // Vector containing event vertices

   //Tree, File and struc

   TTree *outtree;
   TFile *outfile;
   Mvertex *avertex;
   struct event
   {
      int e_id;         //id of the event
      int e_nvtx;       //Number of vertices in the event
      int e_nvtxreal1;  //Number of vertices at level 1 in the event
      int e_nvtxreal2;  //Number of vertices at level 2  in the event
      int e_nvtxreal3;  //Number of vertices at level 3 in the event
      int e_nNeutral;   //Number of neutral particles in the event
      int e_nCharged;   //Number of charged particles in the event
      int e_nFcharged;  //Number of final charged particles in the event
      int e_nF2charged; //Number of final charged particles in the event belonging to vertices w at least 2 final charged
      int e_nRcharged;  //Number of reconstructible charged particles in the event
      int e_nR2charged;  //Number of reconstructible charged particles in the event belonging to vertices w at least 2 reconstructable charged
   };

   struct event counter;

   // Methods for reading the input tree
   readgentree(TTree *tree = 0);
   virtual ~readgentree();
   virtual Int_t Cut(Long64_t entry);
   virtual Int_t GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void Init(TTree *tree);
   virtual void Loop(int nevents = 0);
   virtual Bool_t Notify();
   virtual void Show(Long64_t entry = -1);

   // Methods for the analysis
   int ndaughters(int entry);
   double decaytime(int entry);
   void daughterloop(int first, int last, int vId);
   int particlecharge(int entry);
   void identifyVertex(int entry);
   int addvertex(int nc, int nn, int nR, int nFc, int vR, int vPdg, double x, double y, double z);
   double pTransverse(int id);
   double prodAngle(int id);
   void booking();
   void saving();
   void display();
};

#endif

#ifdef readgentree_cxx
readgentree::readgentree(TTree *tree) : fChain(0)
{
   // if parameter tree is not specified (or zero), connect the file
   // used to generate this class and read the Tree.
   if (tree == 0)
   {
      TFile *f = (TFile *)gROOT->GetListOfFiles()->FindObject("./data/B0toKsJPsi-100k.root");
      if (!f || !f->IsOpen())
      {
         f = new TFile("./data/B0toKsJPsi-100k.root");
      }
      f->GetObject("tree", tree);
   }
   Init(tree);
}

readgentree::~readgentree()
{
   if (!fChain)
      return;
   delete fChain->GetCurrentFile();
}

Int_t readgentree::GetEntry(Long64_t entry)
{
   // Read contents of entry.
   if (!fChain)
      return 0;
   return fChain->GetEntry(entry);
}
Long64_t readgentree::LoadTree(Long64_t entry)
{
   // Set the environment to read one entry
   if (!fChain)
      return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0)
      return centry;
   if (fChain->GetTreeNumber() != fCurrent)
   {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void readgentree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree)
      return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("MCParticles", &MCParticles_, &b_MCParticles_);
   fChain->SetBranchAddress("MCParticles.fUniqueID", MCParticles_fUniqueID, &b_MCParticles_fUniqueID);
   fChain->SetBranchAddress("MCParticles.fBits", MCParticles_fBits, &b_MCParticles_fBits);
   fChain->SetBranchAddress("MCParticles.m_status", MCParticles_m_status, &b_MCParticles_m_status);
   fChain->SetBranchAddress("MCParticles.m_pdg", MCParticles_m_pdg, &b_MCParticles_m_pdg);
   fChain->SetBranchAddress("MCParticles.m_mass", MCParticles_m_mass, &b_MCParticles_m_mass);
   fChain->SetBranchAddress("MCParticles.m_energy", MCParticles_m_energy, &b_MCParticles_m_energy);
   fChain->SetBranchAddress("MCParticles.m_momentum_x", MCParticles_m_momentum_x, &b_MCParticles_m_momentum_x);
   fChain->SetBranchAddress("MCParticles.m_momentum_y", MCParticles_m_momentum_y, &b_MCParticles_m_momentum_y);
   fChain->SetBranchAddress("MCParticles.m_momentum_z", MCParticles_m_momentum_z, &b_MCParticles_m_momentum_z);
   fChain->SetBranchAddress("MCParticles.m_validVertex", MCParticles_m_validVertex, &b_MCParticles_m_validVertex);
   fChain->SetBranchAddress("MCParticles.m_productionTime", MCParticles_m_productionTime, &b_MCParticles_m_productionTime);
   fChain->SetBranchAddress("MCParticles.m_productionVertex_x", MCParticles_m_productionVertex_x, &b_MCParticles_m_productionVertex_x);
   fChain->SetBranchAddress("MCParticles.m_productionVertex_y", MCParticles_m_productionVertex_y, &b_MCParticles_m_productionVertex_y);
   fChain->SetBranchAddress("MCParticles.m_productionVertex_z", MCParticles_m_productionVertex_z, &b_MCParticles_m_productionVertex_z);
   fChain->SetBranchAddress("MCParticles.m_decayTime", MCParticles_m_decayTime, &b_MCParticles_m_decayTime);
   fChain->SetBranchAddress("MCParticles.m_decayVertex_x", MCParticles_m_decayVertex_x, &b_MCParticles_m_decayVertex_x);
   fChain->SetBranchAddress("MCParticles.m_decayVertex_y", MCParticles_m_decayVertex_y, &b_MCParticles_m_decayVertex_y);
   fChain->SetBranchAddress("MCParticles.m_decayVertex_z", MCParticles_m_decayVertex_z, &b_MCParticles_m_decayVertex_z);
   fChain->SetBranchAddress("MCParticles.m_mother", MCParticles_m_mother, &b_MCParticles_m_mother);
   fChain->SetBranchAddress("MCParticles.m_firstDaughter", MCParticles_m_firstDaughter, &b_MCParticles_m_firstDaughter);
   fChain->SetBranchAddress("MCParticles.m_lastDaughter", MCParticles_m_lastDaughter, &b_MCParticles_m_lastDaughter);
   fChain->SetBranchAddress("MCParticles.m_secondaryPhysicsProcess", MCParticles_m_secondaryPhysicsProcess, &b_MCParticles_m_secondaryPhysicsProcess);
   fChain->SetBranchAddress("MCParticles.m_seenIn.m_bits", MCParticles_m_seenIn_m_bits, &b_MCParticles_m_seenIn_m_bits);

   Notify();
}

Bool_t readgentree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void readgentree::Show(Long64_t entry)
{
   // Print contents of entry.
   // If entry is not specified, print current entry
   if (!fChain)
      return;
   fChain->Show(entry);
}
Int_t readgentree::Cut(Long64_t entry)
{
   // This function may be called from Loop.
   // returns  1 if entry is accepted.
   // returns -1 otherwise.
   return 1;
}

int readgentree::addvertex(int nc, int nn, int nR, int nFc, int vR, int vPdg, double x, double y, double z)
{
   int id = vertexlist.size();
   Mvertex v(id, nc, nn, nR, nFc, vR, vPdg); // Create object
   v.Addposition(x, y, z);                   // Add position to the object
   vertexlist.push_back(v);                  // Add object to the list of vertices (vector)

   return id; // return vertex ID
}

double readgentree::pTransverse(int id)
{
   return sqrt(pow(MCParticles_m_momentum_x[id], 2) + pow(MCParticles_m_momentum_y[id], 2));
}

double readgentree::prodAngle(int id)
{
   return acos(MCParticles_m_momentum_z[id] / sqrt(pow(MCParticles_m_momentum_x[id], 2) + pow(MCParticles_m_momentum_y[id], 2) + pow(MCParticles_m_momentum_z[id], 2))) * 180 / M_PI;
}

#endif // #ifdef readgentree_cxx
