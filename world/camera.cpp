//Vic McGowen and Dan Goldberg Ray Tracer

#include "camera.h"

Camera::Camera() {
  pos_ = Point(0.,0.,0.);
  look_ = Vector(0.,0.,0.);
  focal_ = 0.;
  pixH_ = 0;
  pixW_ = 0;
  height_ = 0;
  width_ = 0;
}

Camera::Camera(Point& pos, Vector& look, double& f) {
  pos_ = pos;
  look_ = look;
  focal_ = f;
  pixH_ = 0;
  pixW_ = 0;
  height_ = 0;
  width_ = 0;
}

Camera::Camera(Point& pos, Vector& look, double& f,
              unsigned int pixW, unsigned int pixH, double height, double width) {
  pos_ = pos;
  look_ = look;
  focal_ = f;
  pixH_ = pixH;
  pixW_ = pixW;
  height_ = height;
  width_ = width;
}

void Camera::setPixDim(const unsigned int& pixW, const unsigned int& pixH){
  pixH_ = pixH;
  pixW_ = pixW;
}

void Camera::setDim(const double& wid, const double& hei){
  height_ = hei;
  width_ = wid;
}

Image Camera::render(World& world){
  double pixHeight = height_/(double)pixH_;
  double pixWidth = width_/(double)pixW_;
  
  
  double x = -width_/2. + 0.5*pixWidth;
  double y = height_/2. - .5*pixHeight;
  double z = focal_;
  
  Ray r;
  Colour c;
  Point origin;
  Vector dir;
  Image im(pixW_,pixH_);
  
  for (int i=0;i<pixW_;++i){
    for (int j=0;j<pixH_;++j){
      dir = Vector(x,y,z);
      r.setDirection(dir);
      c = world.spawn(r);
      im.setPixel(i,j,c);
      x+=pixWidth;
    }
    y-=pixHeight;
  }
  
  return im;
  
} 
