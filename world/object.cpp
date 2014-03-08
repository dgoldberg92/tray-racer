//Vic McGowen and Dan Goldberg Ray Tracer

#include "object.h"

Object::Object()
  : colour_(Colour()){}
 // constructor

Object::~Object(){} // deconstructor

// virtual, abstract methods
double Object::intersect(const Ray& ray) {return 0.0;}
void Object::transform(const Eigen::Matrix4d& mat){}

// implementation
void Object::computeIllumination(const IntersectData& data){
  addIllumination(iModel_.illuminate(data));
}
