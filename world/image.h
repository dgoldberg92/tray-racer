// Dan Goldberg and Vic McGowen
// Image Class

#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "../aux/colour.h"
class Image {
  public:
    Image();
    Image(unsigned int w,unsigned int h);
    Image(const Image& im);
    virtual ~Image();

    unsigned int getHeight()const{return height_;};
    unsigned int getWidth()const{return width_;};
    Colour* getData()const{return im_;};
    double getFactor()const{return factor_;};
    void setFactor(const double f){factor_=f;};
    void setPixel(const unsigned int& x,const unsigned int& y,const Colour& c)
          {im_[x+width_*y]=c;};
    Colour getPixel(const unsigned int& x, const unsigned int& y) const
          {return im_[x+width_*y];};

    void toneReproduction();
    void toPPM(const std::string fname) const;

    Image& operator=(const Image &im);

  private:
    unsigned int height_;
    unsigned int width_;
    Colour* im_;
    double factor_;
};

#endif
