// Dan Goldberg and Vic McGowen
// Ray class

#include "ray.h"

Ray::Ray()
  : origin_(Point(0.0,0.0,0.0)), direction_(Vector(0.0,0.0,0.0)){}

Ray::Ray(const Point& p, const Vector& v)
  : origin_(p), direction_(v) {}

Ray::Ray(const Ray& other)
  : origin_(other.getOrigin()), direction_(other.getDirection()){}

Ray::~Ray(){} // deconstructor

std::string Ray::toString() const{
  std::string strOut("Ray: ");
  strOut = strOut + origin_.toString();
  strOut = strOut + ", ";
  strOut = strOut + direction_.toString();
  return strOut;
}
