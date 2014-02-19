//Vic McGowen and Dan Goldberg Ray Tracer

#ifndef COLOUR_H_
#define COLOUR_H_

// Included Dependencies
#include <iostream>

class Colour{

public:
	Colour();
	Colour(double r, double g, double b); 
	virtual ~Colour();

	static const Colour black;
	static const Colour red;
	static const Colour green;
	static const Colour blue;
	static const Colour white;
	
	double getR() const { return r_; };
	double getG() const { return g_; };
	double getB() const { return b_; };

	void setR(double r);
	void setG(double g);
	void setB(double b);
	void setRGB(double r, double g, double b);

	Colour operator* (const Colour& b) const;

private:
	double r_;
	double g_;
	double b_;

};

#endif
