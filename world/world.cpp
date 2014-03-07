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
  IntersectData data;
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
    
    close_o->computeColour(data);
    return close_o->getColour();
  } 
  else{
    return getBgColour();
  }

}
