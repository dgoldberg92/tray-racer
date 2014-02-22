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
#include "../world/object.h"
#include "../aux/colour.h"
#include "../aux/ray.h"

class World {
  public:
    World();
    World(Colour& c);
    World(Colour& c, std::list<Object>& olist);
    virtual ~World();
    
    std::list<Object> getObjectList() const {return objects_;};
    void setBgColour(const Colour& c) {bgcolour_=c;};
    Colour getBgColour() const {return bgcolour_;};
    
    void add(const Object& o){objects_.push_front(o);};
    
    void transform(Object& o,const Eigen::Matrix4d& mat){o.transform(mat);};
    void transformAll(const Eigen::Matrix4d& mat);

    // Not const beucause it may change colour of each object that the ray hits
    Colour spawn(const Ray& r);

  private:
    std::list<Object> objects_;
    Colour bgcolour_; 
};

#endif
