// Dan Goldberg and Vic McGowen
// Box class

#ifndef BOX_H_
#define BOX_H_

// Included Dependencies
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Eigen/Dense>
#include "../aux/ray.h"
#include "../aux/point.h"
#include "../aux/colour.h"
#include "../world/object.h"

class Box: public Object{

public:

	Box(); // initial constructor
  //Box(Point a,Point b,Point c, Point d,Point e,Point f,Point g,Point h);
  Box(const Point& min,const Point& max);
	Box(const Point* p,int nump);
	virtual ~Box(); // deconstructor 

  std::string toString() const;

	double intersect(const Ray& ray); // intersect method
	void transform(const Eigen::Matrix4d& mat);

private:
	Point min_;
  Point max_;
};

#endif
