//Vic McGowen and Dan Goldberg Ray Tracer

#ifndef POINT_H_
#define POINT_H_

// Included Dependencies
#include "vector.h"
#include <iostream>

class Point{
public:
	Point(); //public default constructor
	Point(double x, double y, double z); 
	virtual ~Point();
	double distance(Point other);
	void transform(Eigen::Matrix4d);

	double getX(){ return point_.getX();};
	double getY(){return point_.getY();};
	double getZ(){ return point_.getZ();};

	Vector operator- const(Point& b) const;

private:
	Vector point_;
};

#endif
