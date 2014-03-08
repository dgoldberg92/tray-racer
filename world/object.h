// Dan Goldberg and Vic McGowen
// Object class

#ifndef OBJECT_H_
#define OBJECT_H_

// Included Dependencies
#include <iostream>
#include <string>
#include "../aux/ray.h"
#include "../aux/vector.h"
#include "../aux/colour.h"
//#include "../world/illuminationmodel.h"
//#include "../world/intersectdata.h"


class Object{

public:

	Object(); // initial constructor
  virtual ~Object();

	virtual double intersect(const Ray& ray) = 0; // initial intersect method
	virtual void transform(const Eigen::Matrix4d& mat) = 0; // transform method

  virtual std::string toString() const = 0;

  virtual void setNormal(const Vector& v){normal_=v;};
	virtual void setColour(const Colour& c){colour_=c;};
  virtual void setSpecular(const Colour& c){specular_=c;};

  virtual Vector getNormal()const{return normal_;};
  virtual Colour getColour()const{return colour_;};
  virtual Colour getSpecular()const{return specular_;};
  

private:
//  IlluminationModel iModel_;
  Vector normal_;
  Colour colour_;
  Colour specular_;
//  Colour illumination_;
};

#endif
