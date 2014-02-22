//Vic McGowen and Dan Goldberg Ray Tracer

#include "point.h"

Point::Point()
	: point_(Vector(0.0, 0.0, 0.0)){}

Point::Point(double x, double y, double z)
	: point_(Vector(x, y, z)){}

Point::Point(Vector v)
  : point_(Vector(v)){}

Point::~Point(){} // deconstructor

double Point::distance(const Point& other){
	double xx = pow( (other.getX()-getX()), 2);
	double yy = pow( (other.getY()-getY()), 2);
	double zz = pow( (other.getZ()-getZ()), 2);

	double distance = sqrt(xx + yy + zz );
	return distance; 
}

Vector Point::operator-(const Point& b) const{
	double x = getX()-b.getX();
	double y = getY()-b.getY();
	double z = getZ()-b.getZ();
	return Vector(x,y,z);
}

double& Point::operator()(const int index) {
  assert(index>=0 && index<3);

  return point_(index);
}
