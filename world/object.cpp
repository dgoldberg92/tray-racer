//Vic McGowen and Dan Goldberg Ray Tracer

#include "object.h"

Object::Object()
  : colour_(Colour()){}
 // constructor

Object::~Object(){} // deconstructor

// virtual, abstract methods
double Object::intersect(const Ray& b) const{return 0.0;}
void Object::transform(const Eigen::Matrix4d& mat){}

// implementation
void Object::computeColour(const IntersectData& data){
  
  iModel_.illuminate(data);
}
