// Dan Goldberg and Vic McGowen
// Sphere class

#ifndef SPHERE_H_
#define SPHERE_H_

// Included Dependencies
#include <iostream>
#include <math.h>
#include <Eigen/Dense>
#include "ray.h"
#include "point.h"

class Sphere:Object{

public:

	Sphere(); // initial constructor

	Sphere(double r, Point c);

	void setCenter( Point c ); // change center to move sphere

	Point getCenter() { return c_; } // returns center to get coordinates

  virtual ~Sphere(){}

	double intersect(Ray& b); // intersect method

private:
	double r_; // radius
	Point c_; // center
};
