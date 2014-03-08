// Dan Goldberg and Vic McGowen
// Phong Illumination Model

#ifndef PHONG_H_
#define PHONG_H_

#include "../world/illuminationmodel.h"
#include "../world/intersectdata.h"
#include "../aux/colour.h"

class Phong: public IlluminationModel{

public:

  Phong();
  virtual ~Phong();

  Colour illuminate(const Object* o,const IntersectData& intersect);







};


#endif
