//Vic McGowen and Dan Goldberg Ray Tracer

#ifndef POINT_H_
#define POINT_H_
#include "vector.h"

#include <iostream>

class Point{
public:
	Point(){}; //public default constructor
	double distance(){ return distance_ };
	double transform(){};

	Vector operator- const(Point& b){} const;

private:
	double x_;
	double y_;
	double z_;
	double distance_;
};

#endif
