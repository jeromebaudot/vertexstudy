* documentation
papers or any documents for the internship context

* vertexstudy
repository under git versioning -> do not edit directly!
get the code and use the brach "oceane" with:
git clone https://github.com/jeromebaudot/vertexstudy.git
git checkout oceane

* code xxxx contains various code versions

* data
contains root and text files with the data to analyse
- B0toKsJPsi.root = 1000 events B0B0bar where one of the B0 goes to Ks+J/Psi
- B0toKsJPsi-100k.root = 100 k events as above
- mixedB-100k.root =100 k events with either B0B0bar or B+B- which decay according to PDG various probabilities
- continumcc-100k.root = 100 k events with no Upislon(4s) but rather continuum decays e+e- -> ccbar
- tautau-100k.root = 100 k events with e+e- -> tau+tau-
- continuumuds-100k.root = combination of the three files below, so 100k uubar, ddbar ssbar events
    continuumuu-33k.root = 33k e+e- -> uubar continuum events
    continuumdd-33k.root = 33k e+e- -> ddbar continuum events
    continuumss-33k.root = 33k e+e- -> ssbar continuum events
- vtx2B0toKsJPsi-1k.root = 1k events B0B0bar where one of the B0 goes to Ks+J/Psi, with 2 particle-vertices reconstructed
- vtx2mixedB-10k.root = 10 k events with either B0B0bar or B+B-, with 2 particle-vertices reconstructed
- vtx2continumcc-20k.root = 20 k events e+e- -> ccbar, with 2 particle-vertices reconstructed
- vtx2mixedBv3-small.root = 20 k events e+e- -> tau+tau-, with 2 particle-vertices reconstructed

* QUESIONS
** General context = how do look like the various event types in Belle II?
- How many vertices do we have per event (average, std deviation)?
- How many of these vertices can actually be identified directly because they have at least two charged particles?
- Same question with the condition "at least two charged particles, that can be reconstructed"
- What are the main particle types (identified by their PDG-code) that produce these reconstructible vertices?
- (Complementary question) What are the main particle types (identified by their PDG-code) that produce these NON-reconstructible vertices?
- What is the distribution of the radial distance of the reconstructible vertices?
- How many of the reconstructible vertices are inside the beam-pipe (radius 12 mm)?

** Regarding a method based on the reconstruction of 2-charged-particle vertices = how will the method perform to "recognize" the event?
- How many charged particles (hence tracks) are present in the event?
- How many of these charged particles actually belong to vertices with at least two charged tracks ?
    => a different formulation of this question is: how many charged particles are not associated to such vertices?
- The same two previous questions can be addressed with charged particles which are reconstructed. The definition of "reconstructed track" should also be changed (maybe modify the pT limit to 50, 100 MeV).
- Assume we have associated 2 tracks with every reconstructible vertices. For vertices with more than 2 tracks, the third, fourth (and so on) tracks are not yet associated. How many such tracks are left over?

* JUNE WORK
 A/ Improve current algo readgentree.C
  Take into account lv0 vertices which can be reconstructed from a final charged particle + lv3 vertex = lv???

 B/ Run readgentree.C over new data
  continuumuds, tautau
  if A is done, redo mixed, ccbar

 C/ Simple Analyse reconstructed vertices (use variables->Draw)
  data vtx2mixedB-10k.root
  goal 1 = count nb of vertices correctly reconstructed (-> purity)
  goal 2 = distributions (motherPDG, XYdistance, particle_momentum) for correct vertices
  goal 3 = resolution on vertex position and momentum !!! <- maybe not possible yet

 D/ Complex Analysis of reconstructed vertices (use class)
  build an analysis class/code with variables->MakeClass("yourName"), in a similar way as readgentree.C
   -> solve the double counting (-> efficiency)
   -> count vertices per event

 E/ Do complex vertex reconstruction
  we are missing : vtx2 with 2 same charge particles, vtx3, vtx4
  we are missing : vtx2+singleCharged

 D/ Let's try to recognize the event !!!
  no idea... (artificial intelligence)
