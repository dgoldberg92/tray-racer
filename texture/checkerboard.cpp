// Vic McGowen and Dan Goldberg Ray Tracer
// Checkerboard class

#include "checkerboard.h"

Checkerboard::Checkerboard()
	: colour1_(Colour(1,1,0)), colour2_(Colour(1,0,0)){}

Checkerboard::Checkerboard(Colour colour1, Colour colour2)
	: colour1_(colour1), colour2_(colour2){}

Checkerboard::~Checkerboard(){}

Colour Checkerboard::illuminate(const Object* o,const IntersectData& intersect){
	Colour outcolour;

	// get point of intersection in object space
	Point p = intersect.getPoint();

	// convert to (u, v) based on floor specs
	



	// apply value transform function


	// modify equation or fragment value 
	// supply as diffuse in Phong or use BRDF


	return outcolour;
}
