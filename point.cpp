//Vic McGowen and Dan Goldberg Ray Tracer

#include "point.h"

Point::Point()
	: point_(Vector(0.0, 0.0, 0.0)){}

Point::Point(double x, double y, double z)
	: point_(Vector(x, y, z)){}

Point::distance(Point other){
	double xx = pow( (other.getX()-getX()), 2);
	double yy = pow( (other.getY()-getY()), 2);
	double zz = pow( (other.getZ()-getZ()), 2);

	double distance = sqrt(xx + yy + zz );
	return distance; 
}

Point::transform(Eigen::Matrix4d){
	point_.transform(Eigen::Matrix4d);
}

Point Point::operator-(const Point& b) const{
	double x = other.getX()-getX();
	double y = other.getY()-getY();
	double z = other.getZ()-getZ();
	return Vector(x,y,z);
}
