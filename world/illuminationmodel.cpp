// Vic McGowen and Dan Goldberg Ray Tracer

#include "illuminationmodel.h"

IlluminationModel::IlluminationModel()// empty constructor
	:intersect_(IntersectData()){}

IlluminationModel::IlluminationModel(const IntersectData& intersect)
	: intersect_(intersect){}

IlluminationModel::~IlluminationModel(){}// deconstrucor

//abstract illuminate method
Colour IlluminationModel::illuminate()const{
  Light l(intersect_.getLight());
	return l.getColour();
}

Colour IlluminationModel::illuminate(const IntersectData& intersect){
  setIntersectData(intersect);
  return illuminate();
}
