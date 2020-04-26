#include "Matrix2x2.hpp"
#include <cassert>
#include <iostream>

// Override default constructor
Matrix2x2::Matrix2x2()
{
    val00 = 0;
    val01 = 0;
    val10 = 0;
    val11 = 0;
}
Matrix2x2::Matrix2x2(const Matrix2x2& other)
{
    val00 = other.Getval00();
    val01 = other.Getval01();
    val10 = other.Getval10();
    val11 = other.Getval11();
}
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
    val00 = a;
    val01 = b;
    val10 = c;
    val11 = d;
}
double Matrix2x2::CalcDeterminant() const
{
    return val00*val11 - val01*val10;
}
Matrix2x2 Matrix2x2::CalcInverse() const
{
    double det = CalcDeterminant();
    assert (det != 0);
    Matrix2x2 w(val11/det, -val01/det, -val10/det, val00/det);
    return w;
}
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
    val00 = z.Getval00();
    val01 = z.Getval01();
    val10 = z.Getval10();
    val11 = z.Getval11();
    return *this;
}

void Matrix2x2::Print() const
{
    std::cout << val00 << " " << val01 << "\n" << val10 << " " << val11 <<"\n";
}

Matrix2x2 Matrix2x2::operator-() const
{
    Matrix2x2 w(-val00, -val01, -val10, -val11);
    return w;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const
{
    Matrix2x2 w(val00 + z.Getval00(), val01 + z.Getval01(),
                val10 + z.Getval10(), val11 + z.Getval11());
    return w;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const
{
    Matrix2x2 w(val00 - z.Getval00(), val01 - z.Getval01(),
                val10 - z.Getval10(), val11 - z.Getval11());
    return w;
}

void Matrix2x2::MultScalar(double scalar)
{
    val00 = val00 * scalar;
    val01 = val01 * scalar;
    val10 = val10 * scalar;
    val11 = val11 * scalar;
}