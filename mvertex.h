#ifndef Mvertex_h
#define Mvertex_h

#include <math.h>
#include "TObject.h"


class Mvertex : public TObject
{

  // Vertex class

  private:
    int id;
    int nCharged;
    int nRstructed;
    int nNeutral;
    double position[3];
    double radialpos;
    bool vReal; // for real vertex = 1;
    int vPdg;
    // event nb
    // nb of vertices

  public:
    Mvertex()
    {
      int id = 0;
      int nCharged = 0;
      int nNeutral = 0;
      int nRstructed = 0;
      bool vReal = 0;
      int vPdg = 0;
    }
    Mvertex(int id_, int nChar, int nNeut, int nRstructed_, bool vReal_, int vPdg_)
    {
      id = id_;
      nCharged = nChar;
      nNeutral = nNeut;
      nRstructed = nRstructed_;
      vReal = vReal_;
      vPdg = vPdg_;
    }
    virtual ~Mvertex() { ; }

    int GetId() { return id; }
    int GetNcharged() { return nCharged; }
    int GetNneutral() { return nNeutral; }
    int GetNrstructed() { return nRstructed; }
    double GetRadialpos() { return radialpos; }
    bool GetReal() { return vReal; }
    int GetvPdg() { return vPdg; }
    void AddId() { id++; }
    void Addcharged() { nCharged++; }
    void Addneutral() { nNeutral++; }
    void Addrstructed() { nRstructed++; }
    void isReal() //Test if the vertex is a fake one
    {
      if (nRstructed >= 2 )
      {
        vReal = 1;
      }
      else
      {
        vReal = 0;
      }
    }

  void Addposition(double x, double y, double z)
  {
    position[0] = x;
    position[1] = y;
    position[2] = z;
    radialpos = sqrt(x * x + y * y);
  }

  void Copy( Mvertex vertex )
  {
    id = vertex.GetId();
    nCharged  = vertex.GetNcharged();
    nRstructed = vertex.GetNrstructed();
    nNeutral = vertex.GetNneutral();
    position[0] = vertex.position[0];
    position[1] = vertex.position[1];
    position[2] = vertex.position[2];
    radialpos = vertex.GetRadialpos();
    vReal = vertex.GetReal();
    vPdg = vertex.GetvPdg();
  }
};

#endif // #ifndef Mvertex_h
