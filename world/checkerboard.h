// Vic McGowen and Dan Goldberg Ray Tracer
// Checkerboard class

#ifndef CHECKERBOARD_H_
#define CHECKERBOARD_H_

#include <iostream>
#include <cmath>
#include "../world/illuminationmodel.h"
#include "../world/intersectdata.h"
#include "../aux/colour.h"
#include "../world/camera.h"

class Checkerboard: public IlluminationModel{

public:

	Checkerboard(); // constructor
	Checkerboard(Colour colour1, Colour colour2); // constructor defining class's colours
	virtual ~Checkerboard(); // destructor

	// @override illuminate function
	Colour illuminate(const Object* o,const IntersectData& intersect);

private:
	Colour colour1_;
	Colour colour2_;

};


#endif
