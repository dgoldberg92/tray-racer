//Vic McGowen and Dan Goldberg Ray Tracer

#include "sphere.h"

Sphere::Sphere() // constructor
	: r_(0), c_() {}

Sphere::Sphere(double r, Point c)
	: r_(r), c_(c){}

Sphere::~Sphere(){} // deconstructor

void Sphere::setCenter(const Point c ){
	c_ = c; 
} // setCenter

void Sphere::transform(Eigen::Matrix4d& mat){
	c_.transform(mat);
} // transform

void Sphere::setColour(const Colour& c){
	col_ = c;
} // setColour

double Sphere::intersect(const Ray& b){ // intersect method
	// Get the origin point of Ray b
	Point o = b.getOrigin(); 
	double xo_ = o.getX();
	double yo_ = o.getY();
	double zo_ = o.getZ();

	// Get the direction point of Ray b
	Vector dir = b.getDirection(); 
	double dx_ = dir.getX();
	double dy_ = dir.getY();
	double dz_ = dir.getZ();

	// Get the centre point of sphere
	double xc_ = c_.getX();
	double yc_ = c_.getY();
	double zc_ = c_.getZ();

	// Intersection equations
	double a = pow( dx_, 2) + pow( dy_, 2) + pow( dz_, 2);
	double b = 2*( (dx_*(xo_ - xc_) + (dy_*(yo_ - yc_) + (dz_*(zo_ - zc_) );
	double c = pow((xo_ - xc_), 2) + pow((yo_ - yc_), 2) + pow((zo_ - zc_), 2) - pow(r_, 2); 

	// Master equation to find omega
	double posw = (-b + sqrt( (b, 2) - (4*a*c) ) ) / (2*a) ;
	double negw = (-b - sqrt( (b, 2) - (4*a*c) ) ) / (2*a) ;

	double w;
	if ( posw < 0.0 ) { 
		w = negw; 
	}
	else{ 
		w = posw; 
	}

	return w; // return the distance
} // intersect




