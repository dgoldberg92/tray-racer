// Dan Goldberg and Vic McGowen
// World class

#include "world.h"

World::World()
  : objects_(std::list<Object*>()),lights_(std::list<Light*>()), bgcolour_(Colour()), model_(new IlluminationModel()) {}
/*
World::World(Colour& c)
  : objects_(std::list<Object*>()), bgcolour_(c) {}

World::World(Colour& c, std::list<Object*>& olist)
  : objects_(olist), bgcolour_(c) {}
*/
World::~World(){
  std::list<Object*>::iterator it; 
  for(it = objects_.begin(); it != objects_.end(); it++)
    delete *it;
  std::list<Light*>::iterator it2;
  for(it2 = lights_.begin(); it2 != lights_.end();it2++)
    delete *it2;
  
  delete model_;

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
  double lightW;

  Colour illumination = getBgColour();
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
    illumination = Colour();
    Vector origin = (r.getOrigin()).getVec();
    Vector dir = r.getDirection();
    p = Point(origin+(dir*least_w));
    normal = close_o->getNormal();
//    data.setPoint(p);
    data.setNormal(normal.normalize());
    data.setViewing((p-Point()).normalize());
    std::list<Light*>::iterator it;
    for(it = lights.begin(); it != lights.end(); it++){
      lightW = close_o->intersect(Ray(p,p-(*it)->getPosition()));
      if (std::isfinite(lightW) || (lightW>0)){
        incoming = p-((*it)->getPosition());
        reflect = ((*it)->getPosition()-p).reflect(normal);
        data.setLight(*(*it));
        data.setIncoming(incoming.normalize());
        data.setReflective(reflect.normalize());
        illumination = illumination + model_->illuminate(close_o,data);
      }
    }
    if (illumination.getR()==0 && illumination.getG()==0  && illumination.getB()==0)
      illumination = getBgColour();
  }
  return illumination;
}
