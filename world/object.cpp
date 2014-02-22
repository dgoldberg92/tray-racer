//Vic McGowen and Dan Goldberg Ray Tracer

#include "object.h"
<<<<<<< HEAD
#include "../aux/colour.h"
=======
>>>>>>> d6c1e729cffb7bd4850fb19d2299f4c20a9042ee

Object::Object()
  : colour_(Colour()){}
 // constructor

Object::~Object(){} // deconstructor

// virtual, abstract methods
double Object::intersect(const Ray& b) const{return 0.0;}
void Object::transform(const Eigen::Matrix4d& mat){}
