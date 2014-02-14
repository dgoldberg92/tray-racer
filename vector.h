// Dan Goldberg and Vic McGowen
// Vector class

#ifndef VECTOR_H_
#define VECTOR_H_

#include <Eigen/Dense>

class Vector {
  friend Vector operator+(const Vector& v1, const Vector& v2) const;
  friend Vector operator-(const Vector& v1, const Vector& v2) const;
  friend Vector operator*(const Vector& v1, const Vector& v2) const;
  friend Vector operator**(const Vector& v1, const Vector& v2) const;
  public:
    Vector();
    Vector(double x, double y, double z);
    Vector(const Vector& other);
    Vector(Eigen::Vector3d vec);
    virtual ~Vector();

    double getX() const {return vector_[0]};
    double getY() const {return vector_[1]};
    double getZ() const {return vector_[2]};
    double getLength() const {return vector_.norm()};
    void normalize() {return vector_.normalize()};
    void transform(Eigen::Matrix4d);

  private:
    Eigen::Vector3d vector_;
}
#endif
