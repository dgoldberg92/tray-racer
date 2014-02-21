// Dan Goldberg and Vic McGowen
// Image Class

#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Image {
  public:
    Image();
    Image(unsigned int w,unsigned int h);
    virtual ~Image();
    
    void setPixel(const unsigned int& x,const unsigned int& y,const double& val){im_[x][y]=val;};
    double getPixel(const unsigned int& x, const unsigned int& y){return im_[x][y];};

    void toPPM(const std::string fname) const;

  private:
    unsigned int height_;
    unsigned int width_;
    double** im_;
};

#endif
