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

void World::printLights()const{
  std::list<Light*>::const_iterator it;
  for(it = lights_.begin(); it != lights_.end(); it++)
    std::cout<<(*it)->toString()<<"\n";
}

void World::transformAll(const Eigen::Matrix4d& mat){
  std::list<Object*>::iterator it;
  for(it = objects_.begin(); it != objects_.end(); it++){
    // Same thing as below different notation
    //(*it).transform(mat);
    // need extra * in addition to -> since its a list of pointers
    (*it)->transform(mat);
  }
  std::list<Light*>::iterator it2;
  for(it2 = lights_.begin(); it2 != lights_.end(); it2++){
    (*it2)->transform(mat);
  }
}

Object* World::intersectWithObjects(const Ray& r, double& least_w){
  return intersectWithObjects(r,least_w,NULL);
} 

Object* World::intersectWithObjects(const Ray& r, double& least_w, const Object* ignoreO){
  double w;
  //double least_w = std::numeric_limits<double>::max();
  Object *close_o = NULL;
  std::list<Object*>::iterator it;
  
  for(it = objects_.begin(); it != objects_.end(); it++){
    if (*it!=ignoreO){
      w = (*it)->intersect(r);
      //std::cout<<w<<"\n";
      if (std::isfinite(w) && (w < least_w) && (w>0)){
        //std::cout<<w;
        least_w = w;
        close_o = (*it);
      }
    }
  }
  return close_o;
} 

Colour World::spawn(const Ray& r) {
  // Static functions are ::
  Point p;
  Vector normal;
  Vector incoming;
  Vector reflect;
  std::list<Light*> lights(getLightList());
  IntersectData data;
  double lightW;
  bool useBG = true;

  Colour illumination = getBgColour();
  double max_w = std::numeric_limits<double>::max();
  double least_w = max_w;
  Object* close_o = intersectWithObjects(r,least_w);
 
  if (close_o){
    useBG = false;
    illumination = Colour();
    Vector origin = (r.getOrigin()).getVec();
    Vector dir = r.getDirection();
    p = Point(origin+(dir*least_w));
    normal = close_o->getNormal();
    data.setPoint(p);
    data.setNormal(normal.normalize());
    data.setViewing((p-Point()).normalize());
 
    Ray lightRay;
    Object* blockingObject;
    least_w = std::numeric_limits<double>::max();
    std::list<Light*>::iterator it;
    for(it = lights.begin(); it != lights.end(); it++){
      lightRay = Ray(p,(p-((*it)->getPosition())).normalize());
      blockingObject = NULL;
      blockingObject = intersectWithObjects(lightRay,least_w,close_o);
      if (blockingObject){
        //illumination = Colour();
        // First reflection
      } else {
        //std::cout<<(blockingObject->toString())<<"\n";
        lightW = close_o->intersect(lightRay);
        if (std::isfinite(lightW) || (lightW>0)){
          incoming = p-((*it)->getPosition());
          reflect = ((*it)->getPosition()-p).reflect(normal);
          data.setLight(*(*it));
          data.setIncoming(incoming.normalize());
          data.setReflective(reflect.normalize());
          illumination = illumination + model_->illuminate(close_o,data);
        }
      }
    }
    if (useBG){
      illumination = getBgColour();
    }
  }
  return illumination;
}
