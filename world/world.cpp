// Dan Goldberg and Vic McGowen
// World class

#include "world.h"

World::World()
  : objects_(std::list<Object*>()), bgcolour_(Colour()) {}

World::World(Colour& c)
  : objects_(std::list<Object*>()), bgcolour_(c) {}

World::World(Colour& c, std::list<Object*>& olist)
  : objects_(olist), bgcolour_(c) {}

World::~World(){
  std::list<Object*>::iterator it; 
  for(it = objects_.begin(); it != objects_.end(); it++)
    delete *it;

}

void World::printObjects()const{
  std::list<Object*>::const_iterator it;
  for(it = objects_.begin(); it != objects_.end(); it++)
    std::cout<<(*it)->toString()<<"\n";
}

void World::transformAll(const Eigen::Matrix4d& mat){
  std::list<Object*>::iterator it;
  for(it = objects_.begin(); it != objects_.end(); it++)
    // Same thing as below different notation
    //(*it).transform(mat);
    // need extra * in addition to -> since its a list of pointers
    (*it)->transform(mat);
}

Colour World::spawn(const Ray& r) {
  // Static functions are ::
  double least_w = std::numeric_limits<double>::max();
  double w;
  Point p;
  Vector normal;
  Vector incoming;
  Vector reflect;
  std::list<Light*> lights(getLightList());
  IntersectData data;

  Colour outColour = getBgColour();
  Colour lightColour;
  // Can't have null reference
  Object* close_o = NULL;
  
  std::list<Object*>::iterator it;
  
  for(it = objects_.begin(); it != objects_.end(); it++){
    w = (*it)->intersect(r);
    //std::cout<<w<<"\n";
    if (std::isfinite(w) && (w < least_w) && (w>0)){
      least_w = w;
      close_o = (*it);
   }
  }
  
  if (close_o){
    Vector origin = (r.getOrigin()).getVec();
    Vector dir = r.getDirection();
    p = Point(origin+(dir*least_w));
    normal = close_o->getNormal();
    data.setPoint(p);
    data.setNormal(normal.normalize());
    
    std::list<Light*>::iterator it;
    for(it = lights.begin(); it != lights.end(); it++){
      incoming = p-((*it)->getPosition());
      reflect = ((*it)->getPosition()-p).reflect(normal);
      
      data.setIncoming(incoming);
      data.setReflective(reflect);
      close_o->computeIllumination(data);
    }
    outColour = close_o->getIllumination() * close_o->getColour();
    close_o->resetIllumination();
  } 
  return outColour;
}
