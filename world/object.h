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


class Object{

public:

	Object(); // initial constructor
  virtual ~Object();

	virtual double intersect(const Ray& b) const = 0; // initial intersect method
	virtual void transform(const Eigen::Matrix4d& mat) = 0; // transform method
  virtual void computeColour(const Ray& r,const double& w);

  virtual std::string toString() const = 0;

  virtual void setNormal(const Vector& v){normal_=v;};
  virtual void setModel(const IlluminationModel& m) {iModel_=m;};
	virtual void setColour(const Colour& c){colour_=c;};

  virtual Colour getColour(){return colour_;};

private:
  IlluminationModel iModel_;
  Vector normal_;
  Colour colour_;
};

#endif
