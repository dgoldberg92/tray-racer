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
#include "../world/illuminationmodel.h"
#include "../world/intersectdata.h"


class Object{

public:

	Object(); // initial constructor
  virtual ~Object();

	virtual double intersect(const Ray& ray) = 0; // initial intersect method
	virtual void transform(const Eigen::Matrix4d& mat) = 0; // transform method
  virtual void computeIllumination(const IntersectData& data);

  virtual std::string toString() const = 0;

  virtual void setNormal(const Vector& v){normal_=v;};
  virtual void setModel(const IlluminationModel& m) {iModel_=m;};
	virtual void setColour(const Colour& c){colour_=c;};
  virtual void addIllumination(const Colour& c){illumination_=illumination_+c;};

  virtual Vector getNormal()const{return normal_;};
  virtual IlluminationModel getModel()const{return iModel_;};
  virtual Colour getColour()const{return colour_;};
  virtual Colour getIllumination()const{return illumination_;};

private:
  IlluminationModel iModel_;
  Vector normal_;
  Colour colour_;
  Colour illumination_;
};

#endif
