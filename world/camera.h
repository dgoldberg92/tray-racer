//Vic McGowen and Dan Goldberg Ray Tracer
// Camera class

#ifndef CAMERA_H_
#define CAMERA_H_

// Included Dependencies
#include <iostream>
#include <math.h>
#include "vector.h"
#include "ray.h"
#include "point.h"

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
