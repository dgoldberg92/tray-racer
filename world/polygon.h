// Dan Goldberg and Vic McGowen
// Sphere class

#ifndef POLYGON_H_
#define POLYGON_H_

// Included Dependencies
#include "ray.h"
#include <iostream>
#include <Eigen/Dense>

class Polygon:Object{

public:

	Polygon(); // initial constructor

	Polygon(double v, double n);

	double intersect(Ray& b); // intersect method

private:
	double vertices_;
	double normal_;
};
