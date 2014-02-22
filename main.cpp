#include <iostream>
#include "world/world.h"
#include "aux/colour.h"
#include "world/object.h"
#include "world/sphere.h"
#include "world/triangle.h"
#include "world/camera.h"

int main() {
  
  Colour bgColour(0,7.,7.);
  World w(bgColour);
  
  Object o1 = Sphere(1., Point(-4.5, 4.45, -3.05));
  o1.setColour(Colour(1.,0.,0.));

  Object o2 = Sphere(.75, Point(-3.17, 3.48, -.2767));
  o2.setColour(Colour(0.,1.,0.));
  
  double xShift = .7151;
  double yShift = -1.3497;
  double zShift = .9818;
  
  Point topLeft(-zShift, -3.5+xShift, 3.+yShift);
  Point topRight(-zShift, 3.5+xShift, 3.+yShift);
  Point botLeft(-zShift, -3.5+xShift, -3.+yShift);
  Point botRight(-zShift, 3.5+xShift, -3.+yShift);
  
  Object t1 = Triangle(topLeft, topRight, botLeft);
  Object t2 = Triangle(topRight, botRight, botLeft);
  
  t1.setColour(Colour(0.,0.,1.));
  t2.setColour(Colour(0.,0.,1.));

  w.add(t1);
  w.add(t2);
  w.add(o1);
  w.add(o2);
  
  Point camPos(-6.01, 13.44, -2.59);
  Point look(-4.5,4.45,-3.05);
  Vector up(-1.,0.,0.);
  Camera cam(camPos,look,up, .027);
  cam.setPixDim(1280,720);
  cam.setDim(8.88889,5.);
  
  Image im = cam.render(w);
  
  im.toPPM("test.ppm");
  
/*  Colour c0(.8,.8,.8);
  Colour c1(.5,.5,.5);
  
  Colour c2 = c0*c1;
  
  std::cout << c2.getR() << ", " << c2.getG() << ", " << c2.getB() << std::endl;
*/
  return 0;
}

