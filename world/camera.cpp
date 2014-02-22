//Vic McGowen and Dan Goldberg Ray Tracer

#include "camera.h"

Camera::Camera() {
  pos_ = Point(0.,0.,0.);
  look_ = Point(0.,0.,0.);
  up_ = Vector();
  focal_ = 0.;
  pixH_ = 0;
  pixW_ = 0;
  height_ = 0;
  width_ = 0;
}

Camera::~Camera(){} // deconstructor

Camera::Camera(Point pos, Point look, Vector up, double f) {
  pos_ = pos;
  look_ = look;
  up_ = up;
  focal_ = f;
  pixH_ = 0;
  pixW_ = 0;
  height_ = 0;
  width_ = 0;
}

Camera::Camera(Point pos, Point look, Vector up, double f,
              unsigned int pixW, unsigned int pixH, double height, double width) {
  pos_ = pos;
  look_ = look;
  up_ = up;
  focal_ = f;
  pixH_ = pixH;
  pixW_ = pixW;
  height_ = height;
  width_ = width;
}

void Camera::setPixDim(const unsigned int pixW, const unsigned int pixH){
  pixH_ = pixH;
  pixW_ = pixW;
}

void Camera::setDim(const double wid, const double hei){
  height_ = hei;
  width_ = wid;
}

Image Camera::render(World& world){

  Vector n = (pos_ - look_).normalize();
  Vector u = (up_.cross(n)).normalize();
  Vector v = (n.cross(u)).normalize();

  Vector eyepoint = pos_.getVec();
  Vector neyepoint = eyepoint.operator*(-1); // multiplication
  Eigen::Matrix4d viewMat;

  viewMat(0,0) = u.getX();
  viewMat(0,1) = u.getY();
  viewMat(0,2) = u.getZ();

//<<<<<<< HEAD
//  viewMat(0,3) = (pos_.getVec())*u*(-1.);
//  viewMat(1,0) = v.getX();
//  viewMat(1,1) = v.getY();
//  viewMat(1,2) = v.getZ();
//  viewMat(1,3) = (pos_.getVec())*v*(-1.);
//  viewMat(2,0) = n.getX();
//  viewMat(2,1) = n.getY();
//  viewMat(2,2) = n.getZ();
//  viewMat(2,3) = (pos_.getVec())*n*(-1.);
//=======
  viewMat(0,3) = neyepoint*(u); // dot product
  viewMat(1,0) = v.getX();
  viewMat(1,1) = v.getY();
  viewMat(1,2) = v.getZ();
  viewMat(1,3) = neyepoint*(v); // dot product
  viewMat(2,0) = n.getX();
  viewMat(2,1) = n.getY();


  viewMat(2,2) = n.getZ();
  viewMat(2,3) = neyepoint*(n); // dot product
//>>>>>>> 6f2f489990ee4ccfa07d293c118c74cdfa119727
  viewMat(3,3) = 1.;
 
  world.transformAll(viewMat);
  
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
  
  for (unsigned int i=0;i<pixW_;++i){
    for (unsigned int j=0;j<pixH_;++j){
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
