#ifndef MATRIX3X3_HPP
#define MATRIX3X3_HPP

#include <array>

class Matrix3x3{
private:
  //The matrix is an array of 9 contiguous memory boxes, <Imagine that there are 3 sets of 3 boxes stacked next to each other>
  std::array<double, 9> m;

public:
  //The default constructor of the matrix.
  Matrix3x3();

  //The explicit constructor for initiallizing the matrix.
  Matrix3x3(double m0, double m1, double m2,
            double m3, double m4, double m5,
            double m6, double m7, double m8);

  //My theoretical drone rotation builders
  static Matrix3x3 createRotationY(double theta); //Pitch
  static Matrix3x3 createRotationZ(double theta); //Yaw

  //To print the values correctly
  void print() const;
};

#endif
