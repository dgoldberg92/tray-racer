// Dan Goldberg and Vic McGowen
// World Class

#ifndef WORLD_H_
#define WORLD_H_

// Dependencies
#include <list>
#include <algorithm>
#include <limits>
#include <cmath>
#include <Eigen/Dense>
#include "world/object.h"
#include "aux/colour.h"

class World {
  public:
    World();
    World(Colour c);
    World(Colour c, Objects o);
    virtual ~World();
    
    std::list<Object> getObjectList() const {return objects_;};
    void setBgColour(const Colour& c) {colour_=c;};
    Colour getBgColour() const {return bgcolour_;};
    
    void add(const Object& o){objects_.push_front(o);};
    
    void transform(Object& o,const Eigen::Matrix4d& mat){o.transform(mat);};
    void transformAll(Eigen::Matrix4d mat);

    Colour spawn(const Ray& r) const;

  private:
    std::list<Object> objects_;
    Colour bgcolour_; 
};
