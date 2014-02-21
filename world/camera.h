//Vic McGowen and Dan Goldberg Ray Tracer
// Camera class

#ifndef CAMERA_H_
#define CAMERA_H_

// Included Dependencies
#include <iostream>
#include <cmath>
#include "aux/vector.h"
#include "aux/ray.h"
#include "aux/point.h"
#include "world/image.h"

class Camera{

public:

	Camera();
	Camera(Point pos, Vector look, double f);
	virtual ~Camera(){};
	render(World world);

private:
	Point pos_;
	Vector look_;
	double focal_;
	double height_; // pixels
	double width_; // pixels
	double pheight_; // world coordinates
	double pwidth_; // world coordinates

};

#endif
