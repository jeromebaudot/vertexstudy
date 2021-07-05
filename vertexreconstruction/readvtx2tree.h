//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun  4 12:44:05 2021 by ROOT version 6.22/02
// from TTree variables/
// found on file: data/vtx2mixedB-10k.root
//////////////////////////////////////////////////////////

#ifndef readvtx2tree_h
#define readvtx2tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

#include <vector>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

#include "mvertex_vtx2.h"
#include <vector>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

class readvtx2tree
{
public:
   TTree *fChain;  //!pointer to the analyzed TTree or TChain
   Int_t fCurrent; //!current Tree number in a TChain

   // Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMax__experiment_ = 1;
   static constexpr Int_t kMax__run_ = 1;
   static constexpr Int_t kMax__event_ = 1;
   static constexpr Int_t kMax__candidate_ = 1;
   static constexpr Int_t kMax__ncandidates_ = 1;
   static constexpr Int_t kMax__weight_ = 1;

   // Declaration of leaf types
   Int_t __experiment__;
   Int_t __run__;
   Int_t __event__;
   Int_t __candidate__;
   Int_t __ncandidates__;
   Double_t __weight__;
   Double_t vtx2_isSignal;
   Double_t vtx2_mcErrors;
   Double_t vtx2_mcPDG;
   Double_t vtx2_mcE;
   Double_t vtx2_mcP;
   Double_t vtx2_mcPT;
   Double_t vtx2_mcPX;
   Double_t vtx2_mcPY;
   Double_t vtx2_mcPZ;
   Double_t vtx2_mcPhi;
   Double_t vtx2_mcDecayVertexX;
   Double_t vtx2_mcDecayVertexY;
   Double_t vtx2_mcDecayVertexZ;
   Double_t vtx2_mcDecayVertexFromIPDistance;
   Double_t vtx2_mcDecayVertexRho;
   Double_t vtx2_mcProductionVertexX;
   Double_t vtx2_mcProductionVertexY;
   Double_t vtx2_mcProductionVertexZ;
   Double_t vtx2_nTracks;
   Double_t vtx2_distance;
   Double_t vtx2_significanceOfDistance;
   Double_t vtx2_dx;
   Double_t vtx2_dy;
   Double_t vtx2_dz;
   Double_t vtx2_x;
   Double_t vtx2_y;
   Double_t vtx2_z;
   Double_t vtx2_x_uncertainty;
   Double_t vtx2_y_uncertainty;
   Double_t vtx2_z_uncertainty;
   Double_t vtx2_dr;
   Double_t vtx2_dphi;
   Double_t vtx2_dcosTheta;
   Double_t vtx2_prodVertexX;
   Double_t vtx2_prodVertexY;
   Double_t vtx2_prodVertexZ;
   Double_t vtx2_prodVertexXErr;
   Double_t vtx2_prodVertexYErr;
   Double_t vtx2_prodVertexZErr;
   Double_t vtx2_chiProb;
   Double_t vtx2_genID;
   Double_t vtx2_mcPDG_m;
   Double_t vtx2_mcPDG_gm;
   Double_t vtx2_mcPDG_ggm;
   Double_t vtx2_mcPDG_gggm;
   Double_t vtx2_mcID_m;
   Double_t vtx2_mcID_gm;
   Double_t vtx2_mcID_ggm;
   Double_t vtx2_mcID_gggm;
   Double_t vtx2_mcIsMissing;
   Double_t vtx2_isCloneTrack;
   Double_t vtx2_mcDecayTime;
   Double_t vtx2_charge;
   Double_t vtx2_nDaughters;
   Double_t t1_isSignal;
   Double_t t1_mcErrors;
   Double_t t1_mcPDG;
   Double_t t1_mcE;
   Double_t t1_mcP;
   Double_t t1_mcPT;
   Double_t t1_mcPX;
   Double_t t1_mcPY;
   Double_t t1_mcPZ;
   Double_t t1_mcPhi;
   Double_t t1_mcDecayVertexX;
   Double_t t1_mcDecayVertexY;
   Double_t t1_mcDecayVertexZ;
   Double_t t1_mcDecayVertexFromIPDistance;
   Double_t t1_mcDecayVertexRho;
   Double_t t1_mcProductionVertexX;
   Double_t t1_mcProductionVertexY;
   Double_t t1_mcProductionVertexZ;
   Double_t t1_nTracks;
   Double_t t1_distance;
   Double_t t1_significanceOfDistance;
   Double_t t1_dx;
   Double_t t1_dy;
   Double_t t1_dz;
   Double_t t1_x;
   Double_t t1_y;
   Double_t t1_z;
   Double_t t1_x_uncertainty;
   Double_t t1_y_uncertainty;
   Double_t t1_z_uncertainty;
   Double_t t1_dr;
   Double_t t1_dphi;
   Double_t t1_dcosTheta;
   Double_t t1_prodVertexX;
   Double_t t1_prodVertexY;
   Double_t t1_prodVertexZ;
   Double_t t1_prodVertexXErr;
   Double_t t1_prodVertexYErr;
   Double_t t1_prodVertexZErr;
   Double_t t1_chiProb;
   Double_t t1_genID;
   Double_t t1_mcPDG_m;
   Double_t t1_mcPDG_gm;
   Double_t t1_mcPDG_ggm;
   Double_t t1_mcPDG_gggm;
   Double_t t1_mcID_m;
   Double_t t1_mcID_gm;
   Double_t t1_mcID_ggm;
   Double_t t1_mcID_gggm;
   Double_t t1_mcIsMissing;
   Double_t t1_isCloneTrack;
   Double_t t1_mcDecayTime;
   Double_t t1_charge;
   Double_t t1_nDaughters;
   Double_t t2_isSignal;
   Double_t t2_mcErrors;
   Double_t t2_mcPDG;
   Double_t t2_mcE;
   Double_t t2_mcP;
   Double_t t2_mcPT;
   Double_t t2_mcPX;
   Double_t t2_mcPY;
   Double_t t2_mcPZ;
   Double_t t2_mcPhi;
   Double_t t2_mcDecayVertexX;
   Double_t t2_mcDecayVertexY;
   Double_t t2_mcDecayVertexZ;
   Double_t t2_mcDecayVertexFromIPDistance;
   Double_t t2_mcDecayVertexRho;
   Double_t t2_mcProductionVertexX;
   Double_t t2_mcProductionVertexY;
   Double_t t2_mcProductionVertexZ;
   Double_t t2_nTracks;
   Double_t t2_distance;
   Double_t t2_significanceOfDistance;
   Double_t t2_dx;
   Double_t t2_dy;
   Double_t t2_dz;
   Double_t t2_x;
   Double_t t2_y;
   Double_t t2_z;
   Double_t t2_x_uncertainty;
   Double_t t2_y_uncertainty;
   Double_t t2_z_uncertainty;
   Double_t t2_dr;
   Double_t t2_dphi;
   Double_t t2_dcosTheta;
   Double_t t2_prodVertexX;
   Double_t t2_prodVertexY;
   Double_t t2_prodVertexZ;
   Double_t t2_prodVertexXErr;
   Double_t t2_prodVertexYErr;
   Double_t t2_prodVertexZErr;
   Double_t t2_chiProb;
   Double_t t2_genID;
   Double_t t2_mcPDG_m;
   Double_t t2_mcPDG_gm;
   Double_t t2_mcPDG_ggm;
   Double_t t2_mcPDG_gggm;
   Double_t t2_mcID_m;
   Double_t t2_mcID_gm;
   Double_t t2_mcID_ggm;
   Double_t t2_mcID_gggm;
   Double_t t2_mcIsMissing;
   Double_t t2_isCloneTrack;
   Double_t t2_mcDecayTime;
   Double_t t2_charge;
   Double_t t2_nDaughters;

   // List of branches
   TBranch *b___experiment__;                   //!
   TBranch *b___run__;                          //!
   TBranch *b___event__;                        //!
   TBranch *b___candidate__;                    //!
   TBranch *b___ncandidates__;                  //!
   TBranch *b___weight__;                       //!
   TBranch *b_vtx2_isSignal;                    //!
   TBranch *b_vtx2_mcErrors;                    //!
   TBranch *b_vtx2_mcPDG;                       //!
   TBranch *b_vtx2_mcE;                         //!
   TBranch *b_vtx2_mcP;                         //!
   TBranch *b_vtx2_mcPT;                        //!
   TBranch *b_vtx2_mcPX;                        //!
   TBranch *b_vtx2_mcPY;                        //!
   TBranch *b_vtx2_mcPZ;                        //!
   TBranch *b_vtx2_mcPhi;                       //!
   TBranch *b_vtx2_mcDecayVertexX;              //!
   TBranch *b_vtx2_mcDecayVertexY;              //!
   TBranch *b_vtx2_mcDecayVertexZ;              //!
   TBranch *b_vtx2_mcDecayVertexFromIPDistance; //!
   TBranch *b_vtx2_mcDecayVertexRho;            //!
   TBranch *b_vtx2_mcProductionVertexX;         //!
   TBranch *b_vtx2_mcProductionVertexY;         //!
   TBranch *b_vtx2_mcProductionVertexZ;         //!
   TBranch *b_vtx2_nTracks;                     //!
   TBranch *b_vtx2_distance;                    //!
   TBranch *b_vtx2_significanceOfDistance;      //!
   TBranch *b_vtx2_dx;                          //!
   TBranch *b_vtx2_dy;                          //!
   TBranch *b_vtx2_dz;                          //!
   TBranch *b_vtx2_x;                           //!
   TBranch *b_vtx2_y;                           //!
   TBranch *b_vtx2_z;                           //!
   TBranch *b_vtx2_x_uncertainty;               //!
   TBranch *b_vtx2_y_uncertainty;               //!
   TBranch *b_vtx2_z_uncertainty;               //!
   TBranch *b_vtx2_dr;                          //!
   TBranch *b_vtx2_dphi;                        //!
   TBranch *b_vtx2_dcosTheta;                   //!
   TBranch *b_vtx2_prodVertexX;                 //!
   TBranch *b_vtx2_prodVertexY;                 //!
   TBranch *b_vtx2_prodVertexZ;                 //!
   TBranch *b_vtx2_prodVertexXErr;              //!
   TBranch *b_vtx2_prodVertexYErr;              //!
   TBranch *b_vtx2_prodVertexZErr;              //!
   TBranch *b_vtx2_chiProb;                     //!
   TBranch *b_vtx2_genID;                       //!
   TBranch *b_vtx2_mcPDG_m;                     //!
   TBranch *b_vtx2_mcPDG_gm;                    //!
   TBranch *b_vtx2_mcPDG_ggm;                   //!
   TBranch *b_vtx2_mcPDG_gggm;                  //!
   TBranch *b_vtx2_mcID_m;                      //!
   TBranch *b_vtx2_mcID_gm;                     //!
   TBranch *b_vtx2_mcID_ggm;                    //!
   TBranch *b_vtx2_mcID_gggm;                   //!
   TBranch *b_vtx2_mcIsMissing;                 //!
   TBranch *b_vtx2_isCloneTrack;                //!
   TBranch *b_vtx2_mcDecayTime;                 //!
   TBranch *b_vtx2_charge;                      //!
   TBranch *b_vtx2_nDaughters;                  //!
   TBranch *b_t1_isSignal;                      //!
   TBranch *b_t1_mcErrors;                      //!
   TBranch *b_t1_mcPDG;                         //!
   TBranch *b_t1_mcE;                           //!
   TBranch *b_t1_mcP;                           //!
   TBranch *b_t1_mcPT;                          //!
   TBranch *b_t1_mcPX;                          //!
   TBranch *b_t1_mcPY;                          //!
   TBranch *b_t1_mcPZ;                          //!
   TBranch *b_t1_mcPhi;                         //!
   TBranch *b_t1_mcDecayVertexX;                //!
   TBranch *b_t1_mcDecayVertexY;                //!
   TBranch *b_t1_mcDecayVertexZ;                //!
   TBranch *b_t1_mcDecayVertexFromIPDistance;   //!
   TBranch *b_t1_mcDecayVertexRho;              //!
   TBranch *b_t1_mcProductionVertexX;           //!
   TBranch *b_t1_mcProductionVertexY;           //!
   TBranch *b_t1_mcProductionVertexZ;           //!
   TBranch *b_t1_nTracks;                       //!
   TBranch *b_t1_distance;                      //!
   TBranch *b_t1_significanceOfDistance;        //!
   TBranch *b_t1_dx;                            //!
   TBranch *b_t1_dy;                            //!
   TBranch *b_t1_dz;                            //!
   TBranch *b_t1_x;                             //!
   TBranch *b_t1_y;                             //!
   TBranch *b_t1_z;                             //!
   TBranch *b_t1_x_uncertainty;                 //!
   TBranch *b_t1_y_uncertainty;                 //!
   TBranch *b_t1_z_uncertainty;                 //!
   TBranch *b_t1_dr;                            //!
   TBranch *b_t1_dphi;                          //!
   TBranch *b_t1_dcosTheta;                     //!
   TBranch *b_t1_prodVertexX;                   //!
   TBranch *b_t1_prodVertexY;                   //!
   TBranch *b_t1_prodVertexZ;                   //!
   TBranch *b_t1_prodVertexXErr;                //!
   TBranch *b_t1_prodVertexYErr;                //!
   TBranch *b_t1_prodVertexZErr;                //!
   TBranch *b_t1_chiProb;                       //!
   TBranch *b_t1_genID;                         //!
   TBranch *b_t1_mcPDG_m;                       //!
   TBranch *b_t1_mcPDG_gm;                      //!
   TBranch *b_t1_mcPDG_ggm;                     //!
   TBranch *b_t1_mcPDG_gggm;                    //!
   TBranch *b_t1_mcID_m;                        //!
   TBranch *b_t1_mcID_gm;                       //!
   TBranch *b_t1_mcID_ggm;                      //!
   TBranch *b_t1_mcID_gggm;                     //!
   TBranch *b_t1_mcIsMissing;                   //!
   TBranch *b_t1_isCloneTrack;                  //!
   TBranch *b_t1_mcDecayTime;                   //!
   TBranch *b_t1_charge;                        //!
   TBranch *b_t1_nDaughters;                    //!
   TBranch *b_t2_isSignal;                      //!
   TBranch *b_t2_mcErrors;                      //!
   TBranch *b_t2_mcPDG;                         //!
   TBranch *b_t2_mcE;                           //!
   TBranch *b_t2_mcP;                           //!
   TBranch *b_t2_mcPT;                          //!
   TBranch *b_t2_mcPX;                          //!
   TBranch *b_t2_mcPY;                          //!
   TBranch *b_t2_mcPZ;                          //!
   TBranch *b_t2_mcPhi;                         //!
   TBranch *b_t2_mcDecayVertexX;                //!
   TBranch *b_t2_mcDecayVertexY;                //!
   TBranch *b_t2_mcDecayVertexZ;                //!
   TBranch *b_t2_mcDecayVertexFromIPDistance;   //!
   TBranch *b_t2_mcDecayVertexRho;              //!
   TBranch *b_t2_mcProductionVertexX;           //!
   TBranch *b_t2_mcProductionVertexY;           //!
   TBranch *b_t2_mcProductionVertexZ;           //!
   TBranch *b_t2_nTracks;                       //!
   TBranch *b_t2_distance;                      //!
   TBranch *b_t2_significanceOfDistance;        //!
   TBranch *b_t2_dx;                            //!
   TBranch *b_t2_dy;                            //!
   TBranch *b_t2_dz;                            //!
   TBranch *b_t2_x;                             //!
   TBranch *b_t2_y;                             //!
   TBranch *b_t2_z;                             //!
   TBranch *b_t2_x_uncertainty;                 //!
   TBranch *b_t2_y_uncertainty;                 //!
   TBranch *b_t2_z_uncertainty;                 //!
   TBranch *b_t2_dr;                            //!
   TBranch *b_t2_dphi;                          //!
   TBranch *b_t2_dcosTheta;                     //!
   TBranch *b_t2_prodVertexX;                   //!
   TBranch *b_t2_prodVertexY;                   //!
   TBranch *b_t2_prodVertexZ;                   //!
   TBranch *b_t2_prodVertexXErr;                //!
   TBranch *b_t2_prodVertexYErr;                //!
   TBranch *b_t2_prodVertexZErr;                //!
   TBranch *b_t2_chiProb;                       //!
   TBranch *b_t2_genID;                         //!
   TBranch *b_t2_mcPDG_m;                       //!
   TBranch *b_t2_mcPDG_gm;                      //!
   TBranch *b_t2_mcPDG_ggm;                     //!
   TBranch *b_t2_mcPDG_gggm;                    //!
   TBranch *b_t2_mcID_m;                        //!
   TBranch *b_t2_mcID_gm;                       //!
   TBranch *b_t2_mcID_ggm;                      //!
   TBranch *b_t2_mcID_gggm;                     //!
   TBranch *b_t2_mcIsMissing;                   //!
   TBranch *b_t2_isCloneTrack;                  //!
   TBranch *b_t2_mcDecayTime;                   //!
   TBranch *b_t2_charge;                        //!
   TBranch *b_t2_nDaughters;                    //!

   // Global variables needed for the analysis

   int skip = 0;
   int ncand = 0;
   int nvtx = 0;
   int event_id = 0;
   int totalvtx;
   int totalvtxreal;
   int totalskip;
   int totalcand;
   std::vector<Mvertex> vertexlist; // Vector containing event vertices
   std::vector<int> candidatelist;

   //Tree, File and struct

   TTree *outtree;
   TFile *outfile;
   Mvertex *avertex;
   struct event
   {
      int e_id;
      int e_ncand;
      int e_nvtx;
      int e_nvtxreal;
      int e_skip;
   };

   struct event counter;

   // Methods for reading the input tree
   readvtx2tree(TTree *tree = 0);
   virtual ~readvtx2tree();
   virtual Int_t Cut(Long64_t entry);
   virtual Int_t GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void Init(TTree *tree);
   virtual void Loop(int nevents = 0);
   virtual Bool_t Notify();
   virtual void Show(Long64_t entry = -1);

   // Methods for the analysis
   void candidateloop(int entry);
   int candidatescheck(int entry1, int entry2);
   int addvertex(int m_id, int vR, int vPdg, double x, double y, double z);
   void updatetree();
   void resetevent();
   void booking();
   void saving();
};

#endif

#ifdef readvtx2tree_cxx
readvtx2tree::readvtx2tree(TTree *tree) : fChain(0)
{
   // if parameter tree is not specified (or zero), connect the file
   // used to generate this class and read the Tree.
   if (tree == 0)
   {
      TFile *f = (TFile *)gROOT->GetListOfFiles()->FindObject("data/vtx2mixedB-10k.root");
      if (!f || !f->IsOpen())
      {
         f = new TFile("data/vtx2mixedB-10k.root");
      }
      f->GetObject("variables", tree);
   }
   Init(tree);
}

readvtx2tree::~readvtx2tree()
{
   if (!fChain)
      return;
   delete fChain->GetCurrentFile();
}

Int_t readvtx2tree::GetEntry(Long64_t entry)
{
   // Read contents of entry.
   if (!fChain)
      return 0;
   return fChain->GetEntry(entry);
}
Long64_t readvtx2tree::LoadTree(Long64_t entry)
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

void readvtx2tree::Init(TTree *tree)
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

   fChain->SetBranchAddress("__experiment__", &__experiment__, &b___experiment__);
   fChain->SetBranchAddress("__run__", &__run__, &b___run__);
   fChain->SetBranchAddress("__event__", &__event__, &b___event__);
   fChain->SetBranchAddress("__candidate__", &__candidate__, &b___candidate__);
   fChain->SetBranchAddress("__ncandidates__", &__ncandidates__, &b___ncandidates__);
   fChain->SetBranchAddress("__weight__", &__weight__, &b___weight__);
   fChain->SetBranchAddress("vtx2_isSignal", &vtx2_isSignal, &b_vtx2_isSignal);
   fChain->SetBranchAddress("vtx2_mcErrors", &vtx2_mcErrors, &b_vtx2_mcErrors);
   fChain->SetBranchAddress("vtx2_mcPDG", &vtx2_mcPDG, &b_vtx2_mcPDG);
   fChain->SetBranchAddress("vtx2_mcE", &vtx2_mcE, &b_vtx2_mcE);
   fChain->SetBranchAddress("vtx2_mcP", &vtx2_mcP, &b_vtx2_mcP);
   fChain->SetBranchAddress("vtx2_mcPT", &vtx2_mcPT, &b_vtx2_mcPT);
   fChain->SetBranchAddress("vtx2_mcPX", &vtx2_mcPX, &b_vtx2_mcPX);
   fChain->SetBranchAddress("vtx2_mcPY", &vtx2_mcPY, &b_vtx2_mcPY);
   fChain->SetBranchAddress("vtx2_mcPZ", &vtx2_mcPZ, &b_vtx2_mcPZ);
   fChain->SetBranchAddress("vtx2_mcPhi", &vtx2_mcPhi, &b_vtx2_mcPhi);
   fChain->SetBranchAddress("vtx2_mcDecayVertexX", &vtx2_mcDecayVertexX, &b_vtx2_mcDecayVertexX);
   fChain->SetBranchAddress("vtx2_mcDecayVertexY", &vtx2_mcDecayVertexY, &b_vtx2_mcDecayVertexY);
   fChain->SetBranchAddress("vtx2_mcDecayVertexZ", &vtx2_mcDecayVertexZ, &b_vtx2_mcDecayVertexZ);
   fChain->SetBranchAddress("vtx2_mcDecayVertexFromIPDistance", &vtx2_mcDecayVertexFromIPDistance, &b_vtx2_mcDecayVertexFromIPDistance);
   fChain->SetBranchAddress("vtx2_mcDecayVertexRho", &vtx2_mcDecayVertexRho, &b_vtx2_mcDecayVertexRho);
   fChain->SetBranchAddress("vtx2_mcProductionVertexX", &vtx2_mcProductionVertexX, &b_vtx2_mcProductionVertexX);
   fChain->SetBranchAddress("vtx2_mcProductionVertexY", &vtx2_mcProductionVertexY, &b_vtx2_mcProductionVertexY);
   fChain->SetBranchAddress("vtx2_mcProductionVertexZ", &vtx2_mcProductionVertexZ, &b_vtx2_mcProductionVertexZ);
   fChain->SetBranchAddress("vtx2_nTracks", &vtx2_nTracks, &b_vtx2_nTracks);
   fChain->SetBranchAddress("vtx2_distance", &vtx2_distance, &b_vtx2_distance);
   fChain->SetBranchAddress("vtx2_significanceOfDistance", &vtx2_significanceOfDistance, &b_vtx2_significanceOfDistance);
   fChain->SetBranchAddress("vtx2_dx", &vtx2_dx, &b_vtx2_dx);
   fChain->SetBranchAddress("vtx2_dy", &vtx2_dy, &b_vtx2_dy);
   fChain->SetBranchAddress("vtx2_dz", &vtx2_dz, &b_vtx2_dz);
   fChain->SetBranchAddress("vtx2_x", &vtx2_x, &b_vtx2_x);
   fChain->SetBranchAddress("vtx2_y", &vtx2_y, &b_vtx2_y);
   fChain->SetBranchAddress("vtx2_z", &vtx2_z, &b_vtx2_z);
   fChain->SetBranchAddress("vtx2_x_uncertainty", &vtx2_x_uncertainty, &b_vtx2_x_uncertainty);
   fChain->SetBranchAddress("vtx2_y_uncertainty", &vtx2_y_uncertainty, &b_vtx2_y_uncertainty);
   fChain->SetBranchAddress("vtx2_z_uncertainty", &vtx2_z_uncertainty, &b_vtx2_z_uncertainty);
   fChain->SetBranchAddress("vtx2_dr", &vtx2_dr, &b_vtx2_dr);
   fChain->SetBranchAddress("vtx2_dphi", &vtx2_dphi, &b_vtx2_dphi);
   fChain->SetBranchAddress("vtx2_dcosTheta", &vtx2_dcosTheta, &b_vtx2_dcosTheta);
   fChain->SetBranchAddress("vtx2_prodVertexX", &vtx2_prodVertexX, &b_vtx2_prodVertexX);
   fChain->SetBranchAddress("vtx2_prodVertexY", &vtx2_prodVertexY, &b_vtx2_prodVertexY);
   fChain->SetBranchAddress("vtx2_prodVertexZ", &vtx2_prodVertexZ, &b_vtx2_prodVertexZ);
   fChain->SetBranchAddress("vtx2_prodVertexXErr", &vtx2_prodVertexXErr, &b_vtx2_prodVertexXErr);
   fChain->SetBranchAddress("vtx2_prodVertexYErr", &vtx2_prodVertexYErr, &b_vtx2_prodVertexYErr);
   fChain->SetBranchAddress("vtx2_prodVertexZErr", &vtx2_prodVertexZErr, &b_vtx2_prodVertexZErr);
   fChain->SetBranchAddress("vtx2_chiProb", &vtx2_chiProb, &b_vtx2_chiProb);
   fChain->SetBranchAddress("vtx2_genID", &vtx2_genID, &b_vtx2_genID);
   fChain->SetBranchAddress("vtx2_mcPDG_m", &vtx2_mcPDG_m, &b_vtx2_mcPDG_m);
   fChain->SetBranchAddress("vtx2_mcPDG_gm", &vtx2_mcPDG_gm, &b_vtx2_mcPDG_gm);
   fChain->SetBranchAddress("vtx2_mcPDG_ggm", &vtx2_mcPDG_ggm, &b_vtx2_mcPDG_ggm);
   fChain->SetBranchAddress("vtx2_mcPDG_gggm", &vtx2_mcPDG_gggm, &b_vtx2_mcPDG_gggm);
   fChain->SetBranchAddress("vtx2_mcID_m", &vtx2_mcID_m, &b_vtx2_mcID_m);
   fChain->SetBranchAddress("vtx2_mcID_gm", &vtx2_mcID_gm, &b_vtx2_mcID_gm);
   fChain->SetBranchAddress("vtx2_mcID_ggm", &vtx2_mcID_ggm, &b_vtx2_mcID_ggm);
   fChain->SetBranchAddress("vtx2_mcID_gggm", &vtx2_mcID_gggm, &b_vtx2_mcID_gggm);
   fChain->SetBranchAddress("vtx2_mcIsMissing", &vtx2_mcIsMissing, &b_vtx2_mcIsMissing);
   fChain->SetBranchAddress("vtx2_isCloneTrack", &vtx2_isCloneTrack, &b_vtx2_isCloneTrack);
   fChain->SetBranchAddress("vtx2_mcDecayTime", &vtx2_mcDecayTime, &b_vtx2_mcDecayTime);
   fChain->SetBranchAddress("vtx2_charge", &vtx2_charge, &b_vtx2_charge);
   fChain->SetBranchAddress("vtx2_nDaughters", &vtx2_nDaughters, &b_vtx2_nDaughters);
   fChain->SetBranchAddress("t1_isSignal", &t1_isSignal, &b_t1_isSignal);
   fChain->SetBranchAddress("t1_mcErrors", &t1_mcErrors, &b_t1_mcErrors);
   fChain->SetBranchAddress("t1_mcPDG", &t1_mcPDG, &b_t1_mcPDG);
   fChain->SetBranchAddress("t1_mcE", &t1_mcE, &b_t1_mcE);
   fChain->SetBranchAddress("t1_mcP", &t1_mcP, &b_t1_mcP);
   fChain->SetBranchAddress("t1_mcPT", &t1_mcPT, &b_t1_mcPT);
   fChain->SetBranchAddress("t1_mcPX", &t1_mcPX, &b_t1_mcPX);
   fChain->SetBranchAddress("t1_mcPY", &t1_mcPY, &b_t1_mcPY);
   fChain->SetBranchAddress("t1_mcPZ", &t1_mcPZ, &b_t1_mcPZ);
   fChain->SetBranchAddress("t1_mcPhi", &t1_mcPhi, &b_t1_mcPhi);
   fChain->SetBranchAddress("t1_mcDecayVertexX", &t1_mcDecayVertexX, &b_t1_mcDecayVertexX);
   fChain->SetBranchAddress("t1_mcDecayVertexY", &t1_mcDecayVertexY, &b_t1_mcDecayVertexY);
   fChain->SetBranchAddress("t1_mcDecayVertexZ", &t1_mcDecayVertexZ, &b_t1_mcDecayVertexZ);
   fChain->SetBranchAddress("t1_mcDecayVertexFromIPDistance", &t1_mcDecayVertexFromIPDistance, &b_t1_mcDecayVertexFromIPDistance);
   fChain->SetBranchAddress("t1_mcDecayVertexRho", &t1_mcDecayVertexRho, &b_t1_mcDecayVertexRho);
   fChain->SetBranchAddress("t1_mcProductionVertexX", &t1_mcProductionVertexX, &b_t1_mcProductionVertexX);
   fChain->SetBranchAddress("t1_mcProductionVertexY", &t1_mcProductionVertexY, &b_t1_mcProductionVertexY);
   fChain->SetBranchAddress("t1_mcProductionVertexZ", &t1_mcProductionVertexZ, &b_t1_mcProductionVertexZ);
   fChain->SetBranchAddress("t1_nTracks", &t1_nTracks, &b_t1_nTracks);
   fChain->SetBranchAddress("t1_distance", &t1_distance, &b_t1_distance);
   fChain->SetBranchAddress("t1_significanceOfDistance", &t1_significanceOfDistance, &b_t1_significanceOfDistance);
   fChain->SetBranchAddress("t1_dx", &t1_dx, &b_t1_dx);
   fChain->SetBranchAddress("t1_dy", &t1_dy, &b_t1_dy);
   fChain->SetBranchAddress("t1_dz", &t1_dz, &b_t1_dz);
   fChain->SetBranchAddress("t1_x", &t1_x, &b_t1_x);
   fChain->SetBranchAddress("t1_y", &t1_y, &b_t1_y);
   fChain->SetBranchAddress("t1_z", &t1_z, &b_t1_z);
   fChain->SetBranchAddress("t1_x_uncertainty", &t1_x_uncertainty, &b_t1_x_uncertainty);
   fChain->SetBranchAddress("t1_y_uncertainty", &t1_y_uncertainty, &b_t1_y_uncertainty);
   fChain->SetBranchAddress("t1_z_uncertainty", &t1_z_uncertainty, &b_t1_z_uncertainty);
   fChain->SetBranchAddress("t1_dr", &t1_dr, &b_t1_dr);
   fChain->SetBranchAddress("t1_dphi", &t1_dphi, &b_t1_dphi);
   fChain->SetBranchAddress("t1_dcosTheta", &t1_dcosTheta, &b_t1_dcosTheta);
   fChain->SetBranchAddress("t1_prodVertexX", &t1_prodVertexX, &b_t1_prodVertexX);
   fChain->SetBranchAddress("t1_prodVertexY", &t1_prodVertexY, &b_t1_prodVertexY);
   fChain->SetBranchAddress("t1_prodVertexZ", &t1_prodVertexZ, &b_t1_prodVertexZ);
   fChain->SetBranchAddress("t1_prodVertexXErr", &t1_prodVertexXErr, &b_t1_prodVertexXErr);
   fChain->SetBranchAddress("t1_prodVertexYErr", &t1_prodVertexYErr, &b_t1_prodVertexYErr);
   fChain->SetBranchAddress("t1_prodVertexZErr", &t1_prodVertexZErr, &b_t1_prodVertexZErr);
   fChain->SetBranchAddress("t1_chiProb", &t1_chiProb, &b_t1_chiProb);
   fChain->SetBranchAddress("t1_genID", &t1_genID, &b_t1_genID);
   fChain->SetBranchAddress("t1_mcPDG_m", &t1_mcPDG_m, &b_t1_mcPDG_m);
   fChain->SetBranchAddress("t1_mcPDG_gm", &t1_mcPDG_gm, &b_t1_mcPDG_gm);
   fChain->SetBranchAddress("t1_mcPDG_ggm", &t1_mcPDG_ggm, &b_t1_mcPDG_ggm);
   fChain->SetBranchAddress("t1_mcPDG_gggm", &t1_mcPDG_gggm, &b_t1_mcPDG_gggm);
   fChain->SetBranchAddress("t1_mcID_m", &t1_mcID_m, &b_t1_mcID_m);
   fChain->SetBranchAddress("t1_mcID_gm", &t1_mcID_gm, &b_t1_mcID_gm);
   fChain->SetBranchAddress("t1_mcID_ggm", &t1_mcID_ggm, &b_t1_mcID_ggm);
   fChain->SetBranchAddress("t1_mcID_gggm", &t1_mcID_gggm, &b_t1_mcID_gggm);
   fChain->SetBranchAddress("t1_mcIsMissing", &t1_mcIsMissing, &b_t1_mcIsMissing);
   fChain->SetBranchAddress("t1_isCloneTrack", &t1_isCloneTrack, &b_t1_isCloneTrack);
   fChain->SetBranchAddress("t1_mcDecayTime", &t1_mcDecayTime, &b_t1_mcDecayTime);
   fChain->SetBranchAddress("t1_charge", &t1_charge, &b_t1_charge);
   fChain->SetBranchAddress("t1_nDaughters", &t1_nDaughters, &b_t1_nDaughters);
   fChain->SetBranchAddress("t2_isSignal", &t2_isSignal, &b_t2_isSignal);
   fChain->SetBranchAddress("t2_mcErrors", &t2_mcErrors, &b_t2_mcErrors);
   fChain->SetBranchAddress("t2_mcPDG", &t2_mcPDG, &b_t2_mcPDG);
   fChain->SetBranchAddress("t2_mcE", &t2_mcE, &b_t2_mcE);
   fChain->SetBranchAddress("t2_mcP", &t2_mcP, &b_t2_mcP);
   fChain->SetBranchAddress("t2_mcPT", &t2_mcPT, &b_t2_mcPT);
   fChain->SetBranchAddress("t2_mcPX", &t2_mcPX, &b_t2_mcPX);
   fChain->SetBranchAddress("t2_mcPY", &t2_mcPY, &b_t2_mcPY);
   fChain->SetBranchAddress("t2_mcPZ", &t2_mcPZ, &b_t2_mcPZ);
   fChain->SetBranchAddress("t2_mcPhi", &t2_mcPhi, &b_t2_mcPhi);
   fChain->SetBranchAddress("t2_mcDecayVertexX", &t2_mcDecayVertexX, &b_t2_mcDecayVertexX);
   fChain->SetBranchAddress("t2_mcDecayVertexY", &t2_mcDecayVertexY, &b_t2_mcDecayVertexY);
   fChain->SetBranchAddress("t2_mcDecayVertexZ", &t2_mcDecayVertexZ, &b_t2_mcDecayVertexZ);
   fChain->SetBranchAddress("t2_mcDecayVertexFromIPDistance", &t2_mcDecayVertexFromIPDistance, &b_t2_mcDecayVertexFromIPDistance);
   fChain->SetBranchAddress("t2_mcDecayVertexRho", &t2_mcDecayVertexRho, &b_t2_mcDecayVertexRho);
   fChain->SetBranchAddress("t2_mcProductionVertexX", &t2_mcProductionVertexX, &b_t2_mcProductionVertexX);
   fChain->SetBranchAddress("t2_mcProductionVertexY", &t2_mcProductionVertexY, &b_t2_mcProductionVertexY);
   fChain->SetBranchAddress("t2_mcProductionVertexZ", &t2_mcProductionVertexZ, &b_t2_mcProductionVertexZ);
   fChain->SetBranchAddress("t2_nTracks", &t2_nTracks, &b_t2_nTracks);
   fChain->SetBranchAddress("t2_distance", &t2_distance, &b_t2_distance);
   fChain->SetBranchAddress("t2_significanceOfDistance", &t2_significanceOfDistance, &b_t2_significanceOfDistance);
   fChain->SetBranchAddress("t2_dx", &t2_dx, &b_t2_dx);
   fChain->SetBranchAddress("t2_dy", &t2_dy, &b_t2_dy);
   fChain->SetBranchAddress("t2_dz", &t2_dz, &b_t2_dz);
   fChain->SetBranchAddress("t2_x", &t2_x, &b_t2_x);
   fChain->SetBranchAddress("t2_y", &t2_y, &b_t2_y);
   fChain->SetBranchAddress("t2_z", &t2_z, &b_t2_z);
   fChain->SetBranchAddress("t2_x_uncertainty", &t2_x_uncertainty, &b_t2_x_uncertainty);
   fChain->SetBranchAddress("t2_y_uncertainty", &t2_y_uncertainty, &b_t2_y_uncertainty);
   fChain->SetBranchAddress("t2_z_uncertainty", &t2_z_uncertainty, &b_t2_z_uncertainty);
   fChain->SetBranchAddress("t2_dr", &t2_dr, &b_t2_dr);
   fChain->SetBranchAddress("t2_dphi", &t2_dphi, &b_t2_dphi);
   fChain->SetBranchAddress("t2_dcosTheta", &t2_dcosTheta, &b_t2_dcosTheta);
   fChain->SetBranchAddress("t2_prodVertexX", &t2_prodVertexX, &b_t2_prodVertexX);
   fChain->SetBranchAddress("t2_prodVertexY", &t2_prodVertexY, &b_t2_prodVertexY);
   fChain->SetBranchAddress("t2_prodVertexZ", &t2_prodVertexZ, &b_t2_prodVertexZ);
   fChain->SetBranchAddress("t2_prodVertexXErr", &t2_prodVertexXErr, &b_t2_prodVertexXErr);
   fChain->SetBranchAddress("t2_prodVertexYErr", &t2_prodVertexYErr, &b_t2_prodVertexYErr);
   fChain->SetBranchAddress("t2_prodVertexZErr", &t2_prodVertexZErr, &b_t2_prodVertexZErr);
   fChain->SetBranchAddress("t2_chiProb", &t2_chiProb, &b_t2_chiProb);
   fChain->SetBranchAddress("t2_genID", &t2_genID, &b_t2_genID);
   fChain->SetBranchAddress("t2_mcPDG_m", &t2_mcPDG_m, &b_t2_mcPDG_m);
   fChain->SetBranchAddress("t2_mcPDG_gm", &t2_mcPDG_gm, &b_t2_mcPDG_gm);
   fChain->SetBranchAddress("t2_mcPDG_ggm", &t2_mcPDG_ggm, &b_t2_mcPDG_ggm);
   fChain->SetBranchAddress("t2_mcPDG_gggm", &t2_mcPDG_gggm, &b_t2_mcPDG_gggm);
   fChain->SetBranchAddress("t2_mcID_m", &t2_mcID_m, &b_t2_mcID_m);
   fChain->SetBranchAddress("t2_mcID_gm", &t2_mcID_gm, &b_t2_mcID_gm);
   fChain->SetBranchAddress("t2_mcID_ggm", &t2_mcID_ggm, &b_t2_mcID_ggm);
   fChain->SetBranchAddress("t2_mcID_gggm", &t2_mcID_gggm, &b_t2_mcID_gggm);
   fChain->SetBranchAddress("t2_mcIsMissing", &t2_mcIsMissing, &b_t2_mcIsMissing);
   fChain->SetBranchAddress("t2_isCloneTrack", &t2_isCloneTrack, &b_t2_isCloneTrack);
   fChain->SetBranchAddress("t2_mcDecayTime", &t2_mcDecayTime, &b_t2_mcDecayTime);
   fChain->SetBranchAddress("t2_charge", &t2_charge, &b_t2_charge);
   fChain->SetBranchAddress("t2_nDaughters", &t2_nDaughters, &b_t2_nDaughters);
   Notify();
}

Bool_t readvtx2tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void readvtx2tree::Show(Long64_t entry)
{
   // Print contents of entry.
   // If entry is not specified, print current entry
   if (!fChain)
      return;
   fChain->Show(entry);
}
Int_t readvtx2tree::Cut(Long64_t entry)
{
   // This function may be called from Loop.
   // returns  1 if entry is accepted.
   // returns -1 otherwise.
   return 1;
}

int readvtx2tree::addvertex(int m_id, int vR, int vPdg, double x, double y, double z)
{
   int id = vertexlist.size();
   Mvertex v(id, m_id, vR, vPdg); // Create object
   v.Addposition(x, y, z);        // Add position to the object
   vertexlist.push_back(v);       // Add object to the list of vertices (vector)

   return id; // return vertex ID
}

int readvtx2tree::candidatescheck(int c1, int c2)
{
   for (int i = 0; i < candidatelist.size(); i++)
   {
      if (candidatelist[i] == c1 || candidatelist[i] == c2)
      {
         //cout << "Already existing candidate pair." << endl;
         return 1;
      }
   }
   //cout << "New candidate pair!" << endl;
   return 0;
}

void readvtx2tree::resetevent()
{
   skip = 0;
   ncand = __ncandidates__;
   nvtx = 0;
   vertexlist.resize(0);
   candidatelist.resize(0);
}
#endif // #ifdef readvtx2tree_cxx
