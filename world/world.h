// Dan Goldberg and Vic McGowen
// World Class

#ifndef WORLD_H_
#define WORLD_H_

// Dependencies
#include <list>
#include <Eigen/Dense>
#include "world/object.h"

class World {
  public:
    World();
    virtual ~World(){};
    
    std::list<Object> getObjectList() const {return objects_;};
    
    void add(const Object o){objects_.push_front(o);};
    
    Object transform(Object o,const Eigen::Matrix4d mat){return o.transform(mat);};
    void transformAll(Eigen::Matrix4d mat);

    void spawn(const Ray& r) const {}

  private:
    std::list<Object> objects_;
    
