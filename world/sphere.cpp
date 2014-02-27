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

double Sphere::intersect(const Ray& ray) const{ // intersect method
	// Get the origin point of Ray b
	Point o = ray.getOrigin(); 
	double xo = o.getX();
	double yo = o.getY();
	double zo = o.getZ();

	// Get the direction point of Ray b
	Vector dir = (ray.getDirection()).normalize(); 
	double dx = dir.getX();
	double dy = dir.getY();
	double dz = dir.getZ();

	// Get the centre point of sphere
	double xc = c_.getX();
	double yc = c_.getY();
	double zc = c_.getZ();

  double xdiff = xo-xc;
  double ydiff = yo-yc;
  double zdiff = zo-zc;

	// Intersection equations
	//double a_ = pow( dx_, 2) + pow( dy_, 2) + pow( dz_, 2);
	//double b = 2*( dx*(xo - xc) + (dy*(yo - yc)) + (dz*(zo - zc)) );
	//double c = pow((xo - xc), 2) + pow((yo - yc), 2) + pow((zo - zc), 2) - pow(r_, 2); 
  double b = 2 * ( dx*xdiff + dy*ydiff + dz*zdiff);
  double c = xdiff*xdiff + ydiff*ydiff + zdiff*zdiff - r_*r_;

	//double test = pow(b, 2) - (4*c);
	double det = b*b - (4*c);
  double sqDet = sqrt(det);

	double w = std::numeric_limits<double>::max();

	if( det < 0 ){ // imaginary roots
		return w;
	}

	// Master equation to find omega
//	double posw = (-1.*b_ + sqrt( pow(b_, 2) - (4*a_*c_) ) ) / (2*a_) ;
//	double negw = (-1.*b_ - sqrt( pow(b_, 2) - (4*a_*c_) ) ) / (2*a_) ;
//  double posw = (-1.*b_ + sqrt( pow(b_, 2) - (4*c_) ) ) *.5 ;
//  double negw = (-1.*b_ - sqrt( pow(b_, 2) - (4*c_) ) ) *.5 ;
  double posw = (-b + sqDet) *.5;
  double negw = (-b - sqDet) *.5;
   
  // If one is neg
	if ( posw < 0.0 ) { 
		// If the other is also neg
		if( negw <0){
			return w;
		}
    // if the other is pos - Hit
		else{
      //std::cout << "1 Hit\n";
			w = negw;
		}
	}
  // If first is pos
	else{
    // If second is also pos
		if( negw > 0.0){
      //std::cout << "2 hits\n";
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
      //std::cout<<"1 hit\n";
			w = posw;
		}
	}

	return w;
} // intersect




