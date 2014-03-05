// Dan Goldberg and Vic McGowen
// World Class

#ifndef WORLD_H_
#define WORLD_H_

// Dependencies
#include <iostream>
#include <list>
#include <algorithm>
#include <limits>
#include <cmath>
#include <Eigen/Dense>
#include "../world/object.h"
#include "../aux/colour.h"
#include "../aux/ray.h"
#include "../aux/light.h"

class World {
  public:
    World();
    World(Colour& c);
    World(Colour& c, std::list<Object*>& olist);
    virtual ~World();
    
    std::list<Object*> getObjectList() const {return objects_;};
    std::list<Light*> getLightList() const {return lights_;};
    Object* getFrontObject() const {return objects_.front();};
    Light* getFrontLight() const {return lights_.front();};
    void popFrontLight() {lights_.pop_front();};
    int getNumObjects() const {return objects_.size();};
    void printObjects() const;
    
    void setBgColour(const Colour& c) {bgcolour_=c;};
    Colour getBgColour() const {return bgcolour_;};
    
    void add(Object* o){objects_.push_front(o);};
    void add(Light* l){lights_.push_front(l);};
    
    void transform(Object& o,const Eigen::Matrix4d& mat){o.transform(mat);};
    void transformAll(const Eigen::Matrix4d& mat);

    // Not const beucause it may change colour of each object that the ray hits
    Colour spawn(const Ray& r);

  private:
    std::list<Object*> objects_;
    std::list<Light*> lights_;
    Colour bgcolour_;
};

#endif
