// Dan Goldberg and Vic McGowen
// Light Class

#include "light.h"

Light::Light()
  : pos_(Point p), col_(Colour c){}

Light::Light(Point& p, Colour& c)
  : pos_(p), col_(c){}

Light::Light(Light& l)
  : pos_(l.getPosition()), col_(l.getColour()){}

Light::~Light(){}

