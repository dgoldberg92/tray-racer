// Dan Goldberg and Vic McGowen
// Phong class

#include "phong.h"

Phong::Phong()
  :kd_(.8),ks_(.5),ke_(10){}

Phong::~Phong(){}

Colour Phong::illuminate(const Object* o, const IntersectData& data){
  Colour outColour;
//  Point p = data.getPoint();
  Vector N = data.getNormal();
  Vector S = data.getIncoming();
  Vector R = data.getReflective();
  Vector V = data.getViewing();
  Light l = data.getLight();

  Colour L = l.getColour();
  Colour Co = o->getColour();
  double diff = S*N;
  if (diff<0)
    diff = 0;

  Colour Cs = o->getSpecular();
  double spec = R*V;

  outColour = L*Co*diff*kd_ + L*Cs*std::pow(spec, ke_)*kd_;
  
/*  if (outColour.getR()<0||outColour.getG()<0||outColour.getB()<0){
    std::cout<<diff<<"\n"<<spec<<"\n";
    outColour = Colour();
  }*/

  return outColour;
}
