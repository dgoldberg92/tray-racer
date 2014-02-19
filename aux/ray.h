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
    Ray(const Point& p,const Vector& v);
    Ray(const Ray& other);
<<<<<<< HEAD:ray.h
    virtual ~Light();

    Vector getDirection();
=======
    virtual ~Ray(){};
>>>>>>> 75dc608cdb903357c58f119e5d79c5bc57e3084f:aux/ray.h
    
    Point getOrigin() const {return origin_;};
    Vector getDirection() const {return direction_;};
    
    void setOrigin(Point& p) {origin_=p;};
    void setDirection(Vector& v) {direction_=v;};

  private:
    Point origin_;
    Vector direction_;

};

#endif
