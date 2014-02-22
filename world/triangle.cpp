//Vic McGowen and Dan Goldberg Ray Tracer

#include "triangle.h"

Triangle::Triangle() // initial constructor
	: v0_(Point()), v1_(Point()), v2_(Point()){} 

Triangle::Triangle(Point v0, Point v1, Point v2) // constructor w vertices
	: v0_(v0), v1_(v1), v2_(v2){}

Triangle::~Triangle(){} // deconstructor

void Triangle::transform(const Eigen::Matrix4d& mat){
	v0_.transform(mat);
	v1_.transform(mat);
	v2_.transform(mat);
} // transform

/*
void Triangle::setColour(const Colour& c){
	col_ = c;
} // setColour
*/

double Triangle::intersect(const Ray& b) const{ // intersection between triangle and ray b
	double distance = 0; // distance to return

	// Define Ray properties
	Vector d = b.getDirection();
	Point o = b.getOrigin();
	
	// define triangle vectors
	Vector e1 = v1_ - v0_;
	Vector e2 = v2_ - v0_;
	Vector t_ = o - v0_;
	Vector p_ = d.cross(e2);
	Vector q_ = t_.cross(e1);

	// define dot products for matrix
	double pe1 = p_ * e1; // denominator 
	double fraction = 1.0/pe1;

	// matrix
	Eigen::Vector3d m;
	m(0) = q_ * e2;
	m(1) = p_* t_;
	m(2) = q_ * d;

	// t u v matrix
	Eigen::Vector3d tuv = fraction * m;

	// defining t u and v
	double t = tuv(0);
	double u = tuv(1);
	double v = tuv(2);

	bool hit = true;

	// no hit cases
	if (pe1 == 0) { //no intersect
		hit = false;
	}
	
	if (t < 0) { //intersect behind origin
		hit = false;
	}
	
	if (u< 0 && v < 0 && u+v >1) { // intersect outside of triangle
		hit = false;
	}

	// yes hit case
	if (hit == true){ 
		distance = t;
	}

	return distance;
} // intersect
