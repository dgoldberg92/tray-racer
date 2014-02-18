// Dan Goldberg
// Vector Class

#include "vector.h"

Vector::Vector()
  : vector_(Eigen::Vector3d())  {}

Vector::Vector(double x, double y, double z)
  : vector_(Eigen::Vector3d(x,y,z)) {}

Vector::Vector(const Vector& other)
  : vector_(other.getVector()){}

Vector::Vector(const Eigen::Vector3d vec)
  : vector_(vec){}

void Vector::transform(const Eigen::Matrix4d mat){
  Eigen::Vector4d v(vector_(0),vector_(1),vector_(2),1.0);
  Eigen::Vector4d newV = mat*v;
  vector_(0) = newV(0);
  vector_(1) = newV(1);
  vector_(2) = newV(2);
}

Vector Vector::operator+(const Vector& v1, const Vector& v2) const{
  
  return Vector(v1(0)+v2(0),v1(1)+v2(1),v1(2)+v2(2));

}

Vector Vector::operator-(const Vector& v1, const Vector& v2) const{
  return v1+(-1)*v2;
}

Vector Vector::operator*(const Vector& v1, const Vector& v2) const{
  return Vector(v1.getVector()*v2.getVector());
}

Vector Vector::operator*(const double& a, const Vector& v1) const{
  return Vector(v1(0)*a,v1(1)*a,v1(2)*a);
}

Vector Vector::operator*(const Vector& v1, const double& a) const{
  return Vector(v1(0)*a,v1(1)*a,v1(2)*a);
}

Vector Vector::operator**(const Vector& v1, const Vector& v2) const{
  return (v1.getVector()).cross(v2.getVector());
}

double& operator()(const int index) const{
  assert(index >= 0 && index<3);

  return vector_(index);
}


