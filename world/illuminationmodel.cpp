// Vic McGowen and Dan Goldberg Ray Tracer

#include "illuminationmodel.h"

IlluminationModel::IlluminationModel()// empty constructor
	:intersect_(IntersectData()){}

IlluminationModel::IlluminationModel(IntersectData intersect)
	: intersect_(intersect){}

IlluminationModel::~IlluminationModel(){}// deconstrucor

//abstract illuminate method
/*type?*/ void IlluminationModel::illuminate(IntersectData intersect){
	
}
