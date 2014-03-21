// Vic McGowen and Dan Goldberg Ray Tracer
// Checkerboard class

#ifndef CHECKERBOARD_H_
#define CHECKERBOARD_H_

#include <iostream>
#include <cmath>
#include "../texture/texture.h"
#include "../aux/point.h"
#include "../aux/intersectdata.h"
#include "../aux/colour.h"
#include "../world/camera.h"
#include "../world/world.h"

class Checkerboard: public Texture{

public:

	Checkerboard(); // constructor
	Checkerboard(Colour colour1, Colour colour2); // constructor defining class's colours
	virtual ~Checkerboard(); // destructor

  void setCorner1(const Point& p){corner1_;};
  void setCorner2(const Point& p){corner2_;};

	// @override Texture function
	Colour getTexture(const IntersectData& intersect,
                    const Eigen::Matrix4d& view);

private:
	Colour colour1_;
	Colour colour2_;
  Point corner1_;
  Point corner2_;
};


#endif
