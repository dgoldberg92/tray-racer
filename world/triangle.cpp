//Vic McGowen and Dan Goldberg Ray Tracer

#include "triangle.h"

Triangle::Triangle() // initial constructor
	: v0_(Point()), v1_(Point()), v2_(Point()){
  setNormal(Vector());
} 

Triangle::Triangle(Point v0, Point v1, Point v2) // constructor w vertices
	: v0_(v0), v1_(v1), v2_(v2){
  setNormal(((v1-v0).cross(v2-v0)).normalize());
}

Triangle::~Triangle(){} // deconstructor


std::string Triangle::toString() const {
  return "Triangle: ("+v0_.toString()+", "+v1_.toString()+", "+v2_.toString()+")";
}

void Triangle::transform(const Eigen::Matrix4d& mat){
	v0_.transform(mat);
	v1_.transform(mat);
	v2_.transform(mat);
  setNormal(((v1_-v0_).cross(v2_-v0_)).normalize());
} // transform

double Triangle::intersect(const Ray& b) { // intersection between triangle and ray b
	double distance_; // distance to return

	// Define Ray properties
	Vector d_ = b.getDirection();
	Point o_ = b.getOrigin();

	// define triangle vectors
	Vector e1_ = v0_ - v1_;
	Vector e2_ = v0_ - v2_;
	Vector T_ = v0_ - o_;
	Vector p_ = d_.cross(e2_);
	Vector q_ = T_.cross(e1_);

	// define dot products for matrix
	double pe1_ = p_ *(e1_); // denominator 
	double fraction = 1.0/pe1_;

	// Vector
	Eigen::Vector3d m;
	m(0) = q_ * e2_;
	m(1) = p_* T_;
	m(2) = q_ * d_;

	// t u v Vector
	Eigen::Vector3d tuv = fraction * m;

	// defining t u and v
	double t_ = tuv(0);
	double u_ = tuv(1);
	double v_ = tuv(2);

	// no hit cases
	if (pe1_ == 0.0) { //parallel ray
		distance_ = 0;
	}
	
	else if (t_ < 0.0) { //intersect behind origin
		distance_ = 0;
	}
	
	else if (u_< 0.0 || v_ < 0.0 || u_+v_ >1.0) { // intersect outside of triangle
		distance_ = 0;
	}

	else{// intersect
		distance_ = t_;
	}


	return distance_;
} // intersect
