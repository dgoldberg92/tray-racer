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
	virtual ~Sphere(); // deconstructor 
	void setCenter(const Point c ); // change center to move sphere
	Point getCenter() { return c_; } // returns center to get coordinates
	double intersect(const Ray& b); // intersect method
	void transform(const Eigen::Matrix4d& mat);
	void setColour(const Colour& c);

private:
	double r_; // radius
	Point c_; // center
	Colour col_; // object colour
};
