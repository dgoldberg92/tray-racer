// Dan Goldberg and Vic McGowen
// Triangle class

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

// Included Dependencies
#include "ray.h"
#include "point.h"
#include <iostream>
#include <Eigen/Dense>

class Triangle:Object{

public:

	Triangle(); // initial constructor

	Triangle(Point v1, Point v2, Point v3);

	double intersect(Ray& b); // intersect method

private:
	Point v1_;
	Point v2_;
	Point v3_;
	double normal_;
};
