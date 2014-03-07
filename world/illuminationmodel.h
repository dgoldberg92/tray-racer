// Vic McGowen and Dan Goldberg
// Illumination class

#ifndef ILLUMINATIONMODEL_H_
#define ILLUMINATIONMODEL_H_

// Included Dependencies
#include <iostream>

//Abstract IlluminationModel Class
class IlluminationModel{
public:
	IlluminationModel();// empty constructor
	IlluminationModel(IntersectData intersect);
	virtual ~IlluminationModel();

	void illuminate(IntersectData& intersect);


private:
	IntersectData intersect_;
};

#endif
