// Dan Goldberg and Vic McGowen
// Texture class

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <Eigen/Dense>
#include "../aux/colour.h"
#include "../aux/intersectdata.h"

class Texture{
  public:
    Texture();
    virtual ~Texture();

    virtual Colour getTexture(const IntersectData& intersect,
                              const Eigen::Matrix4d& view) const;

};

#endif

