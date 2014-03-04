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
	double distance_; // distance to return

	// Define Ray properties
	Vector d_ = b.getDirection();
	Point o_ = b.getOrigin();

	// define triangle vectors
	Vector e1_ = v1_ - v0_;
	Vector e2_ = v2_ - v0_;
	Vector T_ = o_ - v0_;
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

	//bool hit = true;
	// added elses in front of ifs
	bool hit_ = true;

///PROBLEM pe1_ AND t_ NEVER REACH NO INTERSECTION


	// no hit cases
	if (pe1_ == 0.0) { //parallel ray
		distance_ = 0;
		std::cout<<"No hit case 1\n";
	}
	
	else if (t_ < 0.0) { //intersect behind origin
		distance_ = 0;
		std::cout<<"No hit case 2\n";
	}
	
	else if (u_< 0.0 || v_ < 0.0 || u_+v_ >1.0) { // intersect outside of triangle
		distance_ = 0;
		std::cout<<"No hit case 3\n";
	}

	else{// intersect
		distance_ = t_;
		//std::cout<<"hit\n";
		std::cout<<t_;
		std::cout<<"\n";
	}

	/*if (u_< 0.0){
		hit_ = false;
		if(v_ < 0.0){
			if (u_+v_ >1.0)
			{
				hit_ = false;
				distance_ = 0.0;
				std::cout<<"no hit case 3-1\n";
			}
		}
		if (u_+v_ >1.0)
			{
				hit_ = false;
				distance_ = 0.0;
				std::cout<<"no hit case3-2\n";
			}
		std::cout<<"no hit case 3\n";
	}*/
	

	return distance_;
} // intersect
