i// Dan Goldberg and Vic McGowen
// Ray class

#include "ray.h"

Ray::Ray()
  : origin_(Point(0.0,0.0,0.0)), direction_(Vector(0.0,0.0,0.0)){}

Ray::Ray(const Point& p, const Vector& v)
  : origin_(p), direction_(v) {}

Ray::Ray(const Ray& other)
  : origin_(other.getOrigin()), direction_(other.getDirection()){}

Ray::~Ray(){} // deconstructor

std::ostream& operator<< (std::ostream &out, Ray &r)
{
  // Since operator<< is a friend of the Point class, we can access
  // Point's members directly.
  out << "Origin: " << r.origin_ << " Dir: " <<r.direction_;
  return out;
}


