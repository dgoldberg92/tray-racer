//Vic McGowen and Dan Goldberg Ray Tracer

#include "intersectdata.h"

IntersectData::IntersectData()
	: point_(Point()), normal_(Vector()), incoming_(Point()), reflective_(Point()){}

IntersectData::IntersectData(Point point, Vector normal, Point incoming, Point reflective)
	: point_(point), normal_(normal), incoming_(incoming), reflective_(reflective){}

IntersectData::~IntersectData(){} // deconstructor

void IntersectData::setPoint(Point point){
	point_ = point;
}
void IntersectData::setNormal(Vector normal){
	normal_ = normal;
}
void IntersectData::setIncoming(Point incoming){
	incoming_ = incoming;
}
void IntersectData::setReflective(Point reflective){
	reflective_ = reflective;
}
void IntersectData::setLightList(std::list<Light*> lights){
	lights_ = lights;
}
