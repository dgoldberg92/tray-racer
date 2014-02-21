// Dan Goldberg and Vic McGowen
// World class

#include "world.h"

World::World()
  : objects_(std::list<Object>), bgcolour_(Colour()) {}

World::World(Colour c)
  : objects_(std::list<Object>), bgcolour_(c) {}

World::World(Colour c, Objects o)
  : objects_(o), bgcolour_(c) {}

void World::World(){}

void World::transformAll(Eigen::Matrix4d mat){
  std::list<Object>::iterator it;
  for(it = objects_.begin(); it != objects_.end(); it++)
    // Same thing as below different notation
    (*it).transform(mat);
}

Colour World::spawn(const Ray& r) const {
  // Static functions are ::
  double least_w = std::numeric_limits<double>::max();
  double w;
  // Can't have null reference
  Object* close_o = NULL;

  for(it = objects_.begin(); it != objects_.end(); it++)
    it->transform(mat);
    w = it->intersect(r);
    if (isfinite(w) && w < least_w){
      least_w = w;
      close_o = &(*it);
    }
  }
  
  if (close_o){
    return close_o->getColour();
  } else {
    return getBgColour();
  }
}
