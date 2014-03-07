// Vic McGowen and Dan Goldberg
// Illumination class

#ifndef ILLUMINATIONMODEL_H_
#define ILLUMINATIONMODEL_H_

// Included Dependencies
#include <iostream>
#include "../aux/colour.h"
#include "../world/intersectdata.h"

//Abstract IlluminationModel Class
class IlluminationModel{
public:
	IlluminationModel();// empty constructor
	IlluminationModel(const IntersectData& intersect);
	virtual ~IlluminationModel();

	virtual Colour illuminate() const;
  virtual Colour illuminate(const IntersectData& intersect);

  virtual void setIntersectData(const IntersectData& intersect){intersect_=intersect;};
  virtual IntersectData getIntersectData() const {return intersect_;};


private:
	IntersectData intersect_;
};

#endif
