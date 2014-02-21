// Dan Goldberg and Vic McGowen
// Triangle class

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

// Included Dependencies
#include <iostream>
#include <math.h>
#include <Eigen/Dense>
#include "ray.h"
#include "point.h"

class Triangle:Object{

public:

	Triangle(); // initial constructor
	Triangle(Point v0, Point v1, Point v2);
	virtual ~Triangle(){}; // deconstructor 
	double intersect(Ray& b) override; // intersect method
	void transform(Eigen::Matrix4d& mat) override;

private:
	Point v0_;
	Point v1_;
	Point v2_;
	double normal_;
};
