// Dan Goldberg and Vic McGowen
// Object class

#ifndef OBJECT_H_
#define OBJECT_H_

// Included Dependencies
#include <iostream>
#include <string>
#include <Eigen/Dense>
#include "../aux/ray.h"
#include "../aux/vector.h"
#include "../aux/colour.h"
#include "../texture/texture.h"
//#include "../world/illuminationmodel.h"
//#include "../world/intersectdata.h"


class Object{

public:

	Object(); // initial constructor
  virtual ~Object();

  virtual void setNormal(const Vector& v){normal_=v;};
	virtual void setColour(const Colour& c){colour_=c;};
  virtual void setSpecular(const Colour& c){specular_=c;};
  // Takes ownership of t
  virtual void setTexture(const Texture* t){texture_=t;};
  virtual void setView(const Eigen::Matrix4d& view){viewMatrix_=view;};

  virtual Vector getNormal()const{return normal_;};
  virtual Colour getColour()const{return colour_;};
  virtual Colour getSpecular()const{return specular_;};
  virtual const Texture* getTexture()const{return texture_;};
  virtual Eigen::Matrix4d getView()const{return viewMatrix_;};
  
  virtual bool hasTexture()const{return (getTexture());}
	virtual double intersect(const Ray& ray) = 0; // initial intersect method
	virtual void transform(const Eigen::Matrix4d& mat) = 0; // transform method

  virtual std::string toString() const = 0;


private:
//  IlluminationModel iModel_;
  Vector normal_;
  Colour colour_;
  Colour specular_;
  const Texture* texture_;
  Eigen::Matrix4d viewMatrix_;
//  Colour illumination_;
};

#endif
