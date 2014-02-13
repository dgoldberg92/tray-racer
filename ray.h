#ifndef RAY_H_
#define RAY_H_

// Included Dependencies
#include "vector.h"
#include "point.h"

class Ray {
  public:
    Ray();
    Ray(const Point&,const Vector&);

  private:
    Point origin_;
    Vector direction_;

#endif
