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

  void setV0(const Point& p[2]){v0_=p;};
  void setV1(const Point& p[2]){v1_=p;};
  void setV2(const Point& p[2]){v2_=p;};

	// @override Texture function
	Colour getTexture(const IntersectData& intersect,
                    const Eigen::Matrix4d& view);

private:
	Colour colour1_;
	Colour colour2_;
  // UV point then XYZ point
  Point v0_[2];
  Point v1_[2];
  Point v2_[2];
};


#endif
