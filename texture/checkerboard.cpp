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
<<<<<<< HEAD
	Eigen::Matrix4d& inverse = view.inverse();
	p.transform(inverse);
=======
	p.transform(view.inverse());
>>>>>>> 53597365967fb7f7ffbc08bfeb019f36758c3b71

  

	/*notes say this ranges from [-1,1] for plane example*/
	double u = p.getX(); // point x value in world space
	double v = p.getZ(); // point z value in world space
	// convert to (u, v) based on floor specs -- projector function
	// used Planar mapping function
	//double u = (z+1)/2;
	//double v = (x+1)/2;
  
  
  
	return outUV;
}

Colour Checkerboard::getTexture(const double* uv)const{
  Colour outcolour; // output colour
  
  double u = uv[0];
  double v = uv[1];
  delete[] uv;
  
  int col = (int) u*2;
  int row = (int) v*2;
  bool oddRow = (row % 2 == 1);
  bool oddCol = (col % 2 == 1);
  
  if (oddRow && oddCol) {
    outcolour = colour1_;
  } else {
    outcolour = colour2_;
  }
  
  return outcolour;
}

Colour Checkerboard::getTexture(const IntersectData& intersect,
                                const Eigen::Matrix4d& view)const{
  Colour outcolour;
  
  double* uv = getUV(intersect,view);
  outcolour = getTexture(uv);
  return outcolour;
}

