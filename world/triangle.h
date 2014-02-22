// Dan Goldberg and Vic McGowen
// Triangle class

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

// Included Dependencies
#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include "../aux/ray.h"
#include "../aux/point.h"
#include "../aux/colour.h"
#include "../aux/vector.h"
#include "../world/object.h"

class Triangle: public Object{

public:

	Triangle(); // initial constructor
	Triangle(Point v0, Point v1, Point v2); // clockwise
	virtual ~Triangle(); // deconstructor 
	double intersect(const Ray& b) const; // intersect method
	void transform(const Eigen::Matrix4d& mat);
	void setColour(const Colour& c);

private:
	Point v0_;
	Point v1_;
	Point v2_;
	double normal_;
	Colour col_;
};

#endif
