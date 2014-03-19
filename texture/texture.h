// Dan Goldberg and Vic McGowen
// Texture class

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../aux/colour.h"
#include "../aux/intersectdata.h"

class Texture{
  public:
    Texture();
    virtual ~Texture();

    virtual Colour getTexture(const IntersectData& intersect)const;

};

#endif

