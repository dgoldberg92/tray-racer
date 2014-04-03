// Vic McGowen and Dan Goldberg Ray Tracer
// Checkerboard class

#ifndef CHECKERBOARD_H_
#define CHECKERBOARD_H_

#include <iostream>
#include <cmath>
#include <Eigen/LU> 
#include <Eigen/Dense> 
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

  void setV0(const Point& uv,const Point& xyz){uv0_=uv;xyz0_=xyz;};
  void setV1(const Point& uv,const Point& xyz){uv1_=uv;xyz1_=xyz;};
  void setV2(const Point& uv,const Point& xyz){uv2_=uv;xyz2_=xyz;};

	// @override Texture function
	Colour getTexture(const IntersectData& intersect,
                    const Eigen::Matrix4d& view);

private:
	Colour colour1_;
	Colour colour2_;
  // UV point then XYZ point
  Point uv0_;
  Point xyz0_;
  Point uv1_;
  Point xyz1_;
  Point uv2_;
  Point xyz2_;
};


#endif
