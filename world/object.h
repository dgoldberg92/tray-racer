// Dan Goldberg and Vic McGowen
// Object class

#ifndef OBJECT_H_
#define OBJECT_H_

// Included Dependencies
#include <iostream>
#include "../aux/ray.h"


class Object{

public:

	Object(); // initial constructor
  	virtual ~Object();
	virtual double intersect(const Ray& b) = 0; // initial intersect method
	virtual void transform(Eigen::Matrix4d& mat) = 0; // transform method
	virtual void setColour(const Colour& c);

private:
	// material_; needed later
};

#endif
