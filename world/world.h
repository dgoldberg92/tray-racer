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
#include "../world/illuminationmodel.h"
#include "../world/intersectdata.h"

class World {
  public:
    World();
    World(Colour& c);
    World(Colour& c, std::list<Object*>& olist);
    virtual ~World();
   
    IlluminationModel* getModel() const{return model_;}; 
    std::list<Object*> getObjectList() const {return objects_;};
    std::list<Light*> getLightList() const {return lights_;};
    Object* getFrontObject() const {return objects_.front();};
    Light* getFrontLight() const {return lights_.front();};
    void popFrontLight() {lights_.pop_front();};
    int getNumObjects() const {return objects_.size();};
    void printObjects() const;
    
    void setModel(IlluminationModel* m){model_=m;};
    void setBgColour(const Colour& c) {bgcolour_=c;};
    Colour getBgColour() const {return bgcolour_;};
    
    void add(Object* o){objects_.push_front(o);};
    void add(Light* l){lights_.push_front(l);};
    
    void transform(Object* o,const Eigen::Matrix4d& mat){o->transform(mat);};
    void transformAll(const Eigen::Matrix4d& mat);
    
    //double intersectWithObjects(const Ray& r, Object** close_o);
    Object* intersectWithObjects(const Ray& r, double& least_w);
    Object* intersectWithObjects(const Ray& r, double& least_w, const Object* ignoreO);
    // Not const beucause it may change colour of each object that the ray hits
    Colour spawn(const Ray& r);

  private:
    std::list<Object*> objects_;
    std::list<Light*> lights_;
    Colour bgcolour_;
    IlluminationModel* model_;
};

#endif
