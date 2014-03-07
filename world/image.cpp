// Dan Goldberg and Vic McGowen
//Image class

#include "image.h"

Image::Image(){
  height_ = 1024;
  width_ = 768;
  im_ = new Colour[width_*height_];
  //for(unsigned int i = 0; i < width_; ++i)
  //  im_[i] = new double[height_];
  // im_(new double(768,1024))
}

Image::Image(unsigned int w, unsigned int h){
  height_=h;
  width_=w;
  im_ = new Colour[width_*height_];
  //for(unsigned int i = 0; i < width_; ++i)
  //  im_[i] = new double[height_];
}

// PROBLEM IS HERE
Image::~Image(){
 /* Old code: 
    for (unsigned int i = 0; i < width_; ++i){
        delete[] im_[i];
  }
  delete[] im_;*/

  // break point to test?
  // with Phil's help:
  // im_ = new Colour[width_*height_];
  // im_ = new Colour[y*width_+x];
  delete[] im_;
}

void Image::toPPM(const std::string fname) const{
  std::ofstream file;
//  std::string::size_type sz;
  std::ostringstream ss;
  //ss << Number;
  //ss.str();
  ss << width_;
  std::string strWidth(ss.str());
  ss.str(std::string());
  ss << height_;
  std::string strHeight(ss.str());
  ss.str(std::string());
 
  file.open(fname.c_str());
  // Color Image file in ascii
  file << "P3\n";
  // width space height
  file << strWidth << " " << strHeight << "\n";
  // Max Value
  file << "1\n";
  
  Colour c;
  
  for (unsigned int j = 0; j<height_;++j){
    for (unsigned int i = 0; i<width_;++i){
      c = this->getPixel(i,j);
      
      ss << (int)(c.getR());//*255);
      file << ss.str() << " ";
      ss.str(std::string());

      ss << (int)(c.getG());//*255);
      file << ss.str() << " ";
      ss.str(std::string());

      ss << (int)(c.getB());//*255);
      file << ss.str() << " ";
      ss.str(std::string());


    }
    file << "\n";
  }

  file.close();
}
/*
 50 
 51   unsigned int pixW_ = 3;
 52   unsigned int pixH_ = 4;
 53   double num(0);
 54   Colour c;
 55   Image im(pixW_,pixH_);
 56   for (unsigned int i=0;i<pixW_;++i){
 57     for (unsigned int j=0;j<pixH_;++j){
 58       c.setRGB(num);
 59       im.setPixel(i,j,c);
 60       num++;
 61     }
 62   }
 63 
 64   im.toPPM("small.ppm");
*/
