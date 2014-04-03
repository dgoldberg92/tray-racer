// Vic McGowen and Dan Goldberg Ray Tracer
// Checkerboard class

#include "checkerboard.h"

Checkerboard::Checkerboard()
	: colour1_(Colour(1,1,0)), colour2_(Colour(1,0,0)){}

Checkerboard::Checkerboard(Colour colour1, Colour colour2)
	: colour1_(colour1), colour2_(colour2){}

Checkerboard::~Checkerboard(){}

double* Checkerboard::getUV(const IntersectData& intersect,
                                const Eigen::Matrix4d& view)const{
  double* outUV = new double[2];
  // get point of intersection in camera space
	Point p = intersect.getPoint();

	// convert point in camera space to world space
	p.transform(view.inverse());

	/*notes say this ranges from [-1,1] for plane example*/
	double x = p.getX(); // point x value in world space
	double z = p.getZ(); // point z value in world space

	// convert to (u, v) based on floor specs -- projector function
	// used Planar mapping function
	double u = (z+1)/2;
	double v = (x+1)/2;

	// modify equation or fragment value 
	// supply as diffuse in Phong or use BRDF

  

	return outUV;
}

Colour Checkerboard::getTexture(const double* uv)const{
  Colour outcolour; // output colour
  
  return outcolour;
}

Colour Checkerboard::getTexture(const IntersectData& intersect,
                                const Eigen::Matrix4d& view)const{
  Colour outcolour;
  
  double* uv = getUV(intersect,view);
  outcolour = getTexture(uv);
  delete[] uv;
  return outcolour;
}

