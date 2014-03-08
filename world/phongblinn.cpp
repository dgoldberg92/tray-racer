// Vic McGowen and Dan Goldberg Ray Tracer 
// PhongBlinn Illumination Model

#include "phongblinn.h"

PhongBlinn::PhongBlinn()
  :kd_(.8),ks_(.2),ke_(2){}

PhongBlinn::~PhongBlinn(){}

Colour PhongBlinn::illuminate(const Object* o, const IntersectData& data){
  Colour outColour;
//  Point p = data.getPoint();
  Vector N = data.getNormal();
  Vector S = data.getIncoming();
  Vector V = data.getViewing();
  Light l = data.getLight();

  // Calculate H
  Vector H = (S + V);
  H.normalize();

  Colour L = l.getColour();
  Colour Co = o->getColour();
  double diff = S*N;
  if (diff<0)
    diff = 0;

  Colour Cs = o->getSpecular();
  double spec = H*V;

  if (spec<0)
    spec = 0;
  if (spec>1)
    spec = 0;

  outColour = L*Co*diff*kd_ + L*Cs*std::pow(spec, ke_)*ks_;
  
/*  if (outColour.getR()<0||outColour.getG()<0||outColour.getB()<0){
    std::cout<<diff<<"\n"<<spec<<"\n";
    outColour = Colour();
  }*/

  return outColour;
}
