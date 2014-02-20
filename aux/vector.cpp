// Dan Goldberg
// Vector Class

#include "vector.h"

Vector::Vector()
  : vector_(Eigen::Vector3d())  {}

Vector::Vector(double x, double y, double z)
  : vector_(Eigen::Vector3d(x,y,z)) {}

Vector::Vector(const Vector& other)
  : vector_(other.getVector()){}

Vector::Vector(const Eigen::Vector3d& vec)
  : vector_(vec){}

void Vector::transform(const Eigen::Matrix4d mat){
  Eigen::Vector4d v(vector_(0),vector_(1),vector_(2),1.0);
  Eigen::Vector4d newV = mat*v;
  vector_(0) = newV(0);
  vector_(1) = newV(1);
  vector_(2) = newV(2);
}

Vector Vector::cross(const Vector& other) const {
  return getVector().cross(other.getVector());
}

Eigen::Matrix4d makeTranslation( double& xt, double& yt, double& zt ) {
  
  Eigen::Matrix4d out = Eigen::Matrix3d::Identity();












Vector Vector::operator+(const Vector& v2) const {
  return Vector(getX()+v2.getX(),getY()+v2.getY(),getZ()+v2.getZ());
}

Vector Vector::operator-(const Vector& v2) const {
  return Vector(getX()-v2.getX(),getY()-v2.getY(),getZ()-v2.getZ());
}

double Vector::operator*(const Vector& v2) const {
  return getVector().dot(v2.getVector());
}

Vector Vector::operator*(const double& a) const {
  return Vector(getX()*a,getY()*a,getZ()*a);
}

double& Vector::operator()(const int index) {
  assert(index >= 0 && index<3);

  return vector_(index);
}


