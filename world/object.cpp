//Vic McGowen and Dan Goldberg Ray Tracer

#include "object.h"

Object::Object(){} // constructor

Object::~Object(){} // deconstructor

// virtual, abstract methods
double Object::intersect(const Ray& b) const {}
void Object::transform(const Eigen::Matrix4d& mat){}
void Object::setColour(const Colour& c){}
