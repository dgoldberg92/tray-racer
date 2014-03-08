#include <iostream>
#include "world/world.h"
#include "aux/colour.h"
#include "world/object.h"
#include "world/sphere.h"
#include "world/triangle.h"
#include "world/camera.h"
#include "aux/light.h"

int main() {
   // Colour bgColour(0,0.7,0.7);
  Colour bgColour(0,0,0);
  World w(bgColour);
  
  // larger sphere
  Object* o1 = new Sphere(2, Point(-0.75, 1, 11));
  o1->setColour(Colour(1.,0.,0.));

  // smaller sphere
  Object* o2 = new Sphere(2, Point(2.75, 0, 17));
  o2->setColour(Colour(0.,1.,0.));
  
  // plane coordinates
   Point topLeft(-5, 2, 30);//6., -2., 0.);
   Point topRight(7,2, 30);//6., 2., 0.);
   Point botLeft(-15,-20, 1);//,4., 2., 0.);
   Point botRight(25,-20, -10);//,4., 2., 0.);

  // triangle objects to make plane
  Object* t1 = new Triangle(topLeft, topRight, botLeft);
  Object* t2 = new Triangle(topRight, botRight, botLeft);
    
  t1->setColour(Colour(0.,0.,1.));
  t2->setColour(Colour(0.,0.,1.));

  w.add(t1);
  w.add(t2);
  w.add(o1);
  w.add(o2);

  Light* l = new Light(Point(10,0,0),Colour(1,1,1));
  w.add(l);

  // Front view camera
  Point camPos(0, 0, 0);
  Point look(0, 0, 5);
  Vector up(0,1,0);
  Camera cam(camPos,look,up, 5);
  cam.setPixDim(720,540);
  cam.setDim(4,3);

  Image im = cam.render(w);

  im.toneReproduction();
  
  im.toPPM("test.ppm");
   
  return 0;
}

