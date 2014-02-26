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

void Sphere::transform(const Eigen::Matrix4d& mat){
	c_.transform(mat);
} // transform

/*
void Sphere::setColour(const Colour& c){
	col_ = c;
} // setColour
*/

double Sphere::intersect(const Ray& b) const{ // intersect method
	// Get the origin point of Ray b
	Point o = b.getOrigin(); 
	double xo_ = o.getX();
	double yo_ = o.getY();
	double zo_ = o.getZ();

	// Get the direction point of Ray b
	Vector dir = (b.getDirection()).normalize(); 
	double dx_ = dir.getX();
	double dy_ = dir.getY();
	double dz_ = dir.getZ();

	// Get the centre point of sphere
	double xc_ = c_.getX();
	double yc_ = c_.getY();
	double zc_ = c_.getZ();

	// Intersection equations
	double a_ = pow( dx_, 2) + pow( dy_, 2) + pow( dz_, 2);
	double b_ = 2*( (dx_*(xo_ - xc_)) + (dy_*(yo_ - yc_)) + (dz_*(zo_ - zc_)) );
	double c_ = pow((xo_ - xc_), 2) + pow((yo_ - yc_), 2) + pow((zo_ - zc_), 2) - pow(r_, 2); 

	double test = pow(b_, 2) - (4*c_);

	double w = std::numeric_limits<double>::max();

	if( test < 0 ){ // imaginary roots
		return w;
	}

	// Master equation to find omega
//	double posw = (-1.*b_ + sqrt( pow(b_, 2) - (4*a_*c_) ) ) / (2*a_) ;
//	double negw = (-1.*b_ - sqrt( pow(b_, 2) - (4*a_*c_) ) ) / (2*a_) ;
  double posw = (-1.*b_ + sqrt( pow(b_, 2) - (4*c_) ) ) *.5 ;
  double negw = (-1.*b_ - sqrt( pow(b_, 2) - (4*c_) ) ) *.5 ;
  
  
  // If one is neg
	if ( posw < 0.0 ) { 
		// If the other is also neg
		if( negw <0){
			return w;
		}
    // if the other is pos - Hit
		else{
      std::cout << "1 Hit\n";
			w = negw;
		}
	}
  // If first is pos
	else{
    // If second is also pos
		if( negw > 0.0){
      std::cout << "2 hits\n";
      // If second is greater
			if( negw > posw){
				w = posw;
			}
			else{
				w = negw;
			}
		}
    // Second is neg
		else{
      std::cout<<"1 hit\n";
			w = posw;
		}
	}

	return w;
} // intersect




