// Dan Goldberg and Vic McGowen
// Sphere class

#ifndef SPHERE_H_
#define SPHERE_H_

// Included Dependencies
#include "ray.h"
#include <iostream>
#include <Eigen/Dense>

class Sphere:Object{

public:

	Sphere(); // initial constructor

	Sphere(double r, double c);

	double intersect(Ray& b); // intersect method

private:
	double r_;
	double c_;
};
