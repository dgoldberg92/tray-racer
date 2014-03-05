// Dan Goldberg and Vic McGowen
// Light source class

#ifndef LIGHT_H_
#define LIGHT_H_

#include <iostream>
#include "../aux/point.h"
#include "../aux/colour.h"

class Light{

public:
  Light();
  Light(Point& p, Colour& c);
  Light(Light& l);
  virtual ~Light();

  Colour getColour() const {return col_;};
  Point getPosition() const {return pos_;};

private:
  Point pos_;
  Colour col_;

#endif
