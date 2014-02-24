#include <iostream>
#include "world/world.h"
#include "aux/colour.h"
#include "world/object.h"
#include "world/sphere.h"
#include "world/triangle.h"
#include "world/camera.h"

int main() {
  
 // Colour bgColour(0,0.7,0.7);
  Colour bgColour(1,1,1);
  World w(bgColour);
  
 // Object* o1 = new Sphere(1., Point(-4.5, 4.45, -3.05));
//Object* o1 = new Sphere(0.81, Point(17.89, 10.51, -5.65));
  Object* o1 = new Sphere(0.2, Point(29, 0, 0));
  o1->setColour(Colour(1.,0.,0.));

  //Object* o2 = new Sphere(.75, Point(-3.17, 3.48, -.2767));
 // Object* o2 = new Sphere(.81, Point(0.11, 1.27, -3.54));
    Object* o2 = new Sphere(.2, Point(17, 0, 0));
  o2->setColour(Colour(0.,1.,0.));
  
  double xShift = .7151;
  double yShift = -1.3497;
  double zShift = .9818;
  
 /* Point topLeft(-zShift, -3.5+xShift, 3.+yShift);
  Point topRight(-zShift, 3.5+xShift, 3.+yShift);
  Point botLeft(-zShift, -3.5+xShift, -3.+yShift);
  Point botRight(-zShift, 3.5+xShift, -3.+yShift);*/

 // Point topLeft(-4., 0., -5.);
 // Point topRight(4., 0., 5.);
 // Point botLeft(4., 0., 5.);
 // Point botRight(-4., 0., -5.);

  Point topLeft(6., -2., 0.);
  Point topRight(6., 2., 0.);
  Point botLeft(4., 2., 0.);
  Point botRight(4., -2., 0.);
  
  
  Object* t1 = new Triangle(topLeft, topRight, botLeft);
  Object* t2 = new Triangle(topRight, botRight, botLeft);
  
  t1->setColour(Colour(0.,0.,1.));
  t2->setColour(Colour(0.,0.,1.));

  //w.add(t1);
  //w.add(t2);
  w.add(o1);
  //w.add(o2);

  //Point camPos(-6.01, 13.44, -2.59);
  //Point camPos(-1.8, 2.33, -10.32);
  Point camPos(0, 0, 0);
  //Point look(-4.5,4.45,-3.05);
  Point look(0, 0, 5);
  //Point look(0.,0.,0.);
  Vector up(0.,0.,1.);
  //Camera cam(camPos,look,up, 3.5);
  Camera cam(camPos,look,up, 5);
  cam.setPixDim(720,540);
  cam.setDim(4,3);
  
  Image im = cam.render(w);
  
  im.toPPM("test.ppm");
  
/*  Colour c0(.8,.8,.8);
  Colour c1(.5,.5,.5);
  
  Colour c2 = c0*c1;
  
  std::cout << c2.getR() << ", " << c2.getG() << ", " << c2.getB() << std::endl;
*/
  return 0;
}

