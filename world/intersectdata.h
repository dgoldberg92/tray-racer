//Vic McGowen and Dan Goldberg Ray Tracer
// IntersectData class

#ifndef INTERSECTDATA_H_
#define INTERSECTDATA_H_

// Included Dependencies
#include <iostream>
#include <Eigen/Dense>
#include <list>
#include "../aux/light.h"
#include "../aux/vector.h"
#include "../aux/point.h"

class IntersectData{
public:

	IntersectData(); // empty constructor
	IntersectData(Point point, Vector normal, Point incoming, Point reflective);
	virtual ~IntersectData(); // deconstructor

	// getters
	Point getPoint()const {return point_;};
	Vector getNormal()const {return normal_;};
	Point getIncoming()const {return incoming_;};
	Point getReflective()const {return reflective_;};
	std::list<Light*> getLightList() const {return lights_;};

	// setters
	void setPoint(Point point);
	void setNormal(Vector normal);
	void setIncoming(Point incoming);
	void setReflective(Point reflective);
	void setLightList(std::list<Light*> lights);

private:
	Point point_;
	Vector normal_;
	Point incoming_;
	Point reflective_;
	std::list<Light*> lights_;
};

#endif
