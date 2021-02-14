#ifndef mvertex_h
#define mvertex_h

#include <math.h>
#include "TObject.h"


class mvertex : public TObject {

// Vertex class

private:

  int Id;
  int Ncharged;
  int Nneutral;
  double Position[3];
  double Radialpos;

public:

  mvertex() { int Id = 0; int Ncharged = 0; int Nneutral = 0; }
  mvertex( int id, int nchar, int nneut) {  Id = id; Ncharged = nchar; Nneutral = nneut; }
  virtual ~mvertex() {;}

  int      GetId()           { return Id; }
  int      GetNcharged()     { return Ncharged; }
  int      GetNneutral()     { return Nneutral; }
  double   GetRadialpos()    { return Radialpos; }
  void     Addcharged()      { Ncharged++; }
  void     Addneutral()      { Nneutral++; }
  void     Addposition( double x, double y, double z) {Position[0] = x; Position[1] = y; Position[2] = z; Radialpos = sqrt( x*x+y*y); }

};

#endif // #ifndef mvertex_h
