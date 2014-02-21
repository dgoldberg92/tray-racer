//Vic McGowen and Dan Goldberg Ray Tracer
// Camera class

#ifndef CAMERA_H_
#define CAMERA_H_

// Included Dependencies
#include <iostream>
#include <cmath>
#include <Eigen:Dense>
#include "../aux/vector.h"
#include "../aux/ray.h"
#include "../aux/point.h"
#include "../world/image.h"

class Camera{

public:

	Camera();
	Camera(Point pos, Point look, Vector up, double f);
  Camera(Point pos, Point look, Vector up, double f,
              unsigned int pixW, unsigned int pixH, double height, double width);
	virtual ~Camera();
  
  void setPixDim(unsigned int pixW, unsigned int pixH);
  void setDim(double wid, double hei);
  
	Image render(World& world);
  

private:
	Point pos_;
	Point look_;
  Vector up_;
	double focal_;
	unsigned int pixH_; // pixels
	unsigned int pixW_; // pixels
	double height_; // world coordinates
	double width_; // world coordinates

};

#endif
