// Dan Goldberg and Vic McGowen
// Object class

#ifndef OBJECT_H_
#define OBJECT_H_

// Included Dependencies
#include <iostream>
#include <string>
#include "../aux/ray.h"
#include "../aux/colour.h"
#include "../world/illuminationmodel.h"


class Object{

public:

	Object(); // initial constructor
  virtual ~Object();
	virtual double intersect(const Ray& b) const = 0; // initial intersect method
	virtual void transform(const Eigen::Matrix4d& mat) = 0; // transform method
  virtual std::string toString() const = 0;
  void setModel(const IlluminationModel& m) = 0;
	void setColour(const Colour& c){colour_=c;};
  Colour getColour(const Ray& r, double w) const = 0;

private:
  IlluminationModel iModel_;
  Colour colour_;
	// material_; needed later
};

#endif
