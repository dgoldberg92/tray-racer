//Vic McGowen and Dan Goldberg Ray Tracer
// Camera class

#ifndef CAMERA_H_
#define CAMERA_H_

// Included Dependencies
#include <iostream>
#include <cmath>
#include "../aux/vector.h"
#include "../aux/ray.h"
#include "../aux/point.h"
#include "../world/image.h"

class Camera{

public:

	Camera();
	Camera(Point pos, Vector look, double f);
  Camera::Camera(Point& pos, Vector& look, double& f,
              unsigned int pixW, unsigned int pixH, double height, double width);
	virtual ~Camera(){};
  
  void setPixDim(unsigned int pixW, unsigned int pixH);
  void setDim(double wid, double hei);
  
	void render(World& world);
  

private:
	Point pos_;
	Vector look_;
	double focal_;
	unsigned int pixH_; // pixels
	unsigned int pixW_; // pixels
	double height_; // world coordinates
	double width_; // world coordinates

};

#endif
