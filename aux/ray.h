// Dan Goldberg and Vic McGowen
// Ray class header

#ifndef RAY_H_
#define RAY_H_

// Included Dependencies
#include "../aux/vector.h"
#include "../aux/point.h"

class Ray {
  public:
    Ray();
    Ray(const Point& p,const Vector& v);
    Ray(const Ray& other);

    Vector getDirection();
    virtual ~Ray();
    
    Point getOrigin() const {return origin_;};
    Vector getDirection() const {return direction_;};
    
    void setOrigin(Point& p) {origin_=p;};
    void setDirection(Vector& v) {direction_=v;};

  private:
    Point origin_;
    Vector direction_;

};

#endif
