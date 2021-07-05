#ifndef Mvertex_h
#define Mvertex_h

#include <math.h>
#include "TObject.h"

class Mvertex : public TObject
{

  // Vertex class

private:
  int id;
  int m_id; // mother vertex id
  double position_x, position_y, position_z;
  double radialpos;
  int vReal; // level of the vertex
  int vPdg;

public:
  Mvertex()
  {
    int id = 0;
    int m_id = 0;
    int vReal = 0;
    int vPdg = 0;
  }
  Mvertex(int id_, int m_id_, int vReal_, int vPdg_)
  {
    id = id_;
    m_id = m_id_;
    vReal = vReal_;
    vPdg = vPdg_;
  }
  virtual ~Mvertex() { ; }

  int GetId() { return id; }
  int Getm_id() { return m_id; }
  double GetRadialpos() { return radialpos; }
  int GetReal() { return vReal; }
  int GetvPdg() { return vPdg; }
  void AddId() { id++; }

  void Addposition(double x, double y, double z)
  {
    position_x = x;
    position_y = y;
    position_z = z;
    radialpos = sqrt(x * x + y * y);
  }

  void Copy(Mvertex vertex)
  {
    id = vertex.GetId();
    m_id = vertex.Getm_id();
    position_x = vertex.position_x;
    position_y = vertex.position_y;
    position_z = vertex.position_z;
    radialpos = vertex.GetRadialpos();
    vReal = vertex.GetReal();
    vPdg = vertex.GetvPdg();
  }

  void Copy()
  {
    id = 0;
    m_id = 0;
    position_x = 0;
    position_y = 0;
    position_z = 0;
    radialpos = 0;
    vReal = 0;
    vPdg = 0;
  }
};

#endif // #ifndef Mvertex_h
