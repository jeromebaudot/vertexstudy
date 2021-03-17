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
    int nFinalcharged;
    double position_x, position_y, position_z;
    double radialpos;
    int vReal; // for real vertex = 1;
    int vPdg;

  public:
    Mvertex()
    {
      int id = 0;
      int nCharged = 0;
      int nNeutral = 0;
      int nRstructed = 0;
      int nFinalcharged = 0;
      int vReal = 0;
      int vPdg = 0;
    }
    Mvertex(int id_, int nChar, int nNeut, int nRstructed_, int nFinalcharged_, int vReal_, int vPdg_)
    {
      id = id_;
      nCharged = nChar;
      nNeutral = nNeut;
      nRstructed = nRstructed_;
      nFinalcharged = nFinalcharged_;
      vReal = vReal_;
      vPdg = vPdg_;
    }
    virtual ~Mvertex() { ; }

    int GetId() { return id; }
    int GetNcharged() { return nCharged; }
    int GetNneutral() { return nNeutral; }
    int GetNrstructed() { return nRstructed; }
    int GetNFinalcharged() { return nFinalcharged; }
    double GetRadialpos() { return radialpos; }
    int GetReal() { return vReal; }
    int GetvPdg() { return vPdg; }
    void AddId() { id++; }
    void Addcharged() { nCharged++; }
    void Addneutral() { nNeutral++; }
    void Addrstructed() { nRstructed++; }
    void Addfinalcharged() { nFinalcharged++; }
    int IsReal() //Test if the vertex is a fake one and return bool value for realness
    {
      if (nRstructed >= 2) // at least 2 reconstructible (lvl 3)
      {
        vReal = 3;
      }
      else if (nFinalcharged >= 2) // at least 2 final charged (lvl 2)
      {
        vReal = 2;
      }
      else if (nCharged >= 2) // at least 2 charged (lvl 1)
      {
        vReal = 1;
      }
      else // just a vertex (lvl 0)
      {
        vReal = 0;
      }
      return vReal;
    }

  void Addposition(double x, double y, double z)
  {
    position_x = x;
    position_y = y;
    position_z = z;
    radialpos = sqrt(x * x + y * y);
  }

  void Copy( Mvertex vertex )
  {
    id = vertex.GetId();
    nCharged  = vertex.GetNcharged();
    nRstructed = vertex.GetNrstructed();
    nNeutral = vertex.GetNneutral();
    nFinalcharged = vertex.GetNFinalcharged();
    position_x = vertex.position_x;
    position_y = vertex.position_y;
    position_z = vertex.position_z;
    radialpos = vertex.GetRadialpos();
    vReal = vertex.GetReal();
    vPdg = vertex.GetvPdg();
  }
};

#endif // #ifndef Mvertex_h
