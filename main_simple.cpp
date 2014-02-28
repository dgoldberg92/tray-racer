#include <iostream>
#include <Eigen/Dense>
#include <list>
#include "world/world.h"
#include "aux/colour.h"
#include "world/object.h"
#include "world/sphere.h"
#include "world/triangle.h"
#include "world/camera.h"
#include "world/image.h"

int main() {
  
  Colour bgColour(0,.7,.7);
  World w(bgColour);
  
  Object* o1 = new Sphere(1., Point(-4.5, 4.45, -3.05));
  o1->setColour(Colour(1.,0.,0.));
  
  w.add(o1);
  
  
Eigen::Matrix4d viewMat; 
  
  viewMat(0,0) = 1;//u.getX();
  viewMat(0,1) = 0;//u.getY();
  viewMat(0,2) = 0;//u.getZ();
  viewMat(0,3) = 0;//neyepoint*(u); // dot product
 
  viewMat(1,0) = 0;//v.getX();
  viewMat(1,1) = 1;//v.getY();
  viewMat(1,2) = 0;//v.getZ();
  viewMat(1,3) = 0;//neyepoint*(v); // dot product
  
  viewMat(2,0) = 0;//n.getX();
  viewMat(2,1) = 0;//n.getY();
  viewMat(2,2) = 1;//n.getZ();
  viewMat(2,3) = 0;//neyepoint*(n); // dot product

  viewMat(3,0) = 0;
  viewMat(3,1) = 0;
  viewMat(3,2) = 0;
  viewMat(3,3) = 1;

  w.transformAll(viewMat);

  Sphere* s = dynamic_cast<Sphere*>(w.getFrontObject());
  Point center(s->getCenter());
  std::cout << center << std::endl;

  unsigned int pixW_ = 3;
  unsigned int pixH_ = 4;
  double num(0);
  Colour c;
  Image im(pixW_,pixH_);
  for (unsigned int i=0;i<pixW_;++i){
    for (unsigned int j=0;j<pixH_;++j){
      c.setRGB(num);
      im.setPixel(i,j,c);
      num++;
    }
  }
 
  im.toPPM("small.ppm");


/*
  Object* o2 = new Sphere(.75, Point(-3.17, 3.48, -.2767));
  o2->setColour(Colour(0.,1.,0.));
  
  double xShift = .7151;
  double yShift = -1.3497;
  double zShift = .9818;
  
  Point topLeft(-zShift, -3.5+xShift, 3.+yShift);
  Point topRight(-zShift, 3.5+xShift, 3.+yShift);
  Point botLeft(-zShift, -3.5+xShift, -3.+yShift);
  Point botRight(-zShift, 3.5+xShift, -3.+yShift);
  
  Object* t1 = new Triangle(topLeft, topRight, botLeft);
  Object* t2 = new Triangle(topRight, botRight, botLeft);
  
  t1->setColour(Colour(0.,0.,1.));
  t2->setColour(Colour(0.,0.,1.));

  w.add(t1);
  w.add(t2);
  w.add(o1);
  w.add(o2);
*/

  
/*
  Point camPos(-6.01, 13.44, -2.59);
  Point look(-4.5,4.45,-3.05);
  Vector up(-1.,0.,0.);
  Camera cam(camPos,look,up, .027);
  
  cam.setPixDim();
  cam.setDim(8.88889,5.);

  Image im = cam.render(w);
  
  im.toPPM("test.ppm");
*/
  
/*  Colour c0(.8,.8,.8);
  Colour c1(.5,.5,.5);
  
  Colour c2 = c0*c1;
  
  std::cout << c2.getR() << ", " << c2.getG() << ", " << c2.getB() << std::endl;
*/
  return 0;
}

