#include <iostream>
#include "world/camera.h"
#include "world/world.h"
#include "world/image.h"

int main() {
  //std::cout << "HI!\n";
  World w;
  //std::cout << "HOW ARE YOU!?!\n";
  Camera c;
  //std::cout << "Calling render\n" <<std::flush;
  Image im = c.render(w);
  
  //std::cout << "IT WORKED\n"<<std::flush;
  return 0;
}
