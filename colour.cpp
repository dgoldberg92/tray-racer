//Vic McGowen and Dan Goldberg Ray Tracer

#include "colour.h"

Colour::Colour(double r, double g, double b)
	: r_(r), g_(g), b_(b){}

void Colour::setR(double r){ r_ = r; }

void Colour::setG(double g){ g_ = g; }

void Colour::setB(double b){ b_ = b;}

void Colour::setRGB(float r, float g, float b){
	r_ = r; 
	g_ = g;
	b_ = b;
}

const Colour::Colour black(0,0,0);
const Colour::Colour red(1,0,0);
const Colour::Colour green(0,1,0);
const Colour::Colour blue(0,0,1);
const Colour::Colour white(1,1,1);

Colour Colour::operator*( const Colour& other ) const{
	Colour result;
	result.r_ = other.r_ * r_;
	result.g_ = other.g_ * g_;
	result.b_ = other.b_ * b_;
	return result;
}

