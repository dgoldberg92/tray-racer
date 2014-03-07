//Vic McGowen and Dan Goldberg Ray Tracer

#include "intersectdata.h"

IntersectData::IntersectData()
	: point_(Point()), normal_(Vector()), incoming_(Ray()), reflective_(Ray()){}

IntersectData::IntersectData(Point point, Vector normal, Ray incoming, Ray reflective)
	: point_(point), normal_(normal), incoming_(incoming), reflective_(reflective){}

IntersectData::~IntersectData(){} // deconstructor

void IntersectData::setPoint(Point point){
	point_ = point;
}
void IntersectData::setNormal(Vector normal){
	normal_ = normal;
}
void IntersectData::setIncoming(Ray incoming){
	incoming_ = incoming;
}
void IntersectData::setReflective(Ray reflective){
	reflective_ = reflective;
}
void IntersectData::setLightList(std::list<Light*> lights){
	lights_ = lights;
}
