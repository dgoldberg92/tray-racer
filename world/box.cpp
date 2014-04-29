//Vic McGowen and Dan Goldberg Ray Tracer

#include "box.h"

Box::Box() // constructor
Box::Box(const Point& min,const Point& max){
  min_ = min;
  max_ = max;
}
Box::Box(const Point& p,int nump){
  double smallx=std::numeric_limits<double>::max();
  double smally=std::numeric_limits<double>::max();
  double smallz=std::numeric_limits<double>::max();
  double largex=0;
  double largey=0;
  double largez=0;
  
  for (int i=0;i<nump;i++){
    if (p[i].getX() < smallx){
      smallx = p[i].getX();
    }
    if (p[i].getY() < smally){
      smally = p[i].getY();
    }
    if (p[i].getZ() < smallz){
      smallz = p[i].getZ();
    }
 
    if (p[i].getX() > largex){
      largex = p[i].getX();
    }
    if (p[i].getY() > largey){
      largey = p[i].getY();
    }
    if (p[i].getZ() > largez){
      largez = p[i].getZ();
    }
  }
  
  Box(Point(smallx,smally,smallz),Point(largex,largey,largez));
}

Box::~Box(){} // deconstructor

std::string Box::toString() const {
  std::ostringstream ss;
  ss << "Box: " << min_.toString() << ", " << max_.toString();
  return ss.str();
}


void Box::transform(const Eigen::Matrix4d& mat){
	min_.transform(mat);
  max_.transform(mat);
} // transform

/*
void Box::setColour(const Colour& c){
	col_ = c;
} // setColour
*/

double Box::intersect(const Ray& ray){ // intersect method
} // intersect




