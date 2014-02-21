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

Camera::setPixDim(const unsigned int& pixW, const unsigned int& pixH){
  pixH_ = pixH;
  pixW_ = pixW;
}

Camera::setDim(const double& wid, const double& hei){
  height_ = hei;
  width_ = wid;
}

Camera::render(World world){
  
}
