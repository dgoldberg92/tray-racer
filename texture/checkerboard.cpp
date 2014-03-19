// Vic McGowen and Dan Goldberg Ray Tracer
// Checkerboard class

#include "checkerboard.h"

Checkerboard::Checkerboard()
	: colour1_(Colour(1,1,0)), colour2_(Colour(1,0,0)){}

Checkerboard::Checkerboard(Colour colour1, Colour colour2)
	: colour1_(colour1), colour2_(colour2){}

Checkerboard::~Checkerboard(){}

Colour Checkerboard::getTexture(const IntersectData& intersect){
	Colour outcolour; // output colour

	// get point of intersection in camera space
	Point p = intersect.getPoint();

	// convert point in camera space to world space
	//p.transform(inverse);

	// scale xyz!

	/*notes say this ranges from [-1,1] for plane example*/
	double x = p.getX(); // point x value in world space
	double z = p.getZ(); // point z value in world space

	// convert to (u, v) based on floor specs -- projector function
	// used Planar mapping function
	double u = (z+1)/2;
	double v = (x+1)/2;

	// need to pass in object vertices!
	double planew;
	double planel;

	double width = u/planew; // plane width
	double length = v/planel; // place length

	// apply value transform function



	// modify equation or fragment value 
	// supply as diffuse in Phong or use BRDF


	return outcolour;
}
