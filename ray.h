// Dan Goldberg and Vic McGowen
// Ray class header

#ifndef RAY_H_
#define RAY_H_

// Included Dependencies
#include "vector.h"
#include "point.h"

class Ray {
  public:
    Ray();
    Ray(const Point&,const Vector&);
    Ray(const Ray& other);
    virtual ~Light();
    

  private:
    Point origin_;
    Vector direction_;

}

#endif
