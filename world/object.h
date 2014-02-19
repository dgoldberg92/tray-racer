// Dan Goldberg and Vic McGowen
// Object class

#ifndef OBJECT_H_
#define OBJECT_H_

// Included Dependencies
#include "ray.h"
#include <iostream>

class Object{

public:

	Object(); // initial constructor
  
  virtual ~Object(){}
  
	double intersect(Ray& b); // initial intersect method


private:
	//float material_; needed later
};

#endif
