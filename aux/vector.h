// Dan Goldberg and Vic McGowen
// Vector class

#ifndef VECTOR_H_
#define VECTOR_H_

// Included Dependencies
#include <Eigen/Dense>

class Vector {
  public:
    Vector();
    Vector(double x, double y, double z);
    Vector(const Vector& other);
    Vector(const Eigen::Vector3d vec);
    virtual ~Vector(){};

    double getX() const {return vector_(0);};
    double getY() const {return vector_(1);};
    double getZ() const {return vector_(2);};
    Eigen::Vector3d getVector() const {return vector_;};
    double getLength() const {return vector_.norm();};
    void normalize() {return vector_.normalize();};
    void transform(const Eigen::Matrix4d mat);
    Vector cross(const Vector& other) const;

    static Eigen::Matrix4d makeTraslation(double& xt, double& yt, double& zt);
    static Eigen::Matrix4d makeScale(double& xs, double& ys, double& zs);
    static Eigen::Matrix4d makeRotation(double& xr, double& yr, double& zr);
    static Eigen::Matrix4d makeTransformMatrix( double& xt,
                                                double& yt,
                                                double& zt,
                                                double& xs,
                                                double& ys,
                                                double& zs,
                                                double& xr,
                                                double& yr,
                                                double& zr );
    Vector operator+(const Vector& v2) const;
    Vector operator-(const Vector& v2) const;
    double operator*(const Vector& v2) const;
    Vector operator*(const double& a) const;
    double& operator()(const int index) ;

  private:
    Eigen::Vector3d vector_;
};
#endif
