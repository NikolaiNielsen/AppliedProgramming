#include "assignment3/Matrix.hpp"
#include <iostream>

void regressionTestsVector();
void regressionTestsMatrix();

int main()
{
    // Exercise 1
    // Regression tests.
    regressionTestsVector();

    return 0;
}

void regressionTestsMatrix()
{
    
}

void regressionTestsVector()
{
    std::cout << "vector v=[1, 0, 3]:\n";
    Vector v(3);
    v[0] = 1;
    v[1] = 0;
    v[2] = 3;
    v.print();

    std::cout << "\nvector v2=v:\n";
    Vector v2(v);
    v2.print();

    std::cout << "\nvector v3=[0, 0, 0, 0]:\n";
    Vector v3(4);
    v3.print();

    std::cout << "\nlength of v3 (should be 4): " << v3.size() << "\n";

    std::cout << "\nThird element of v, should be 3: " << v[2] << "\n";

    std::cout << "\nSetting v2 = v:\n";
    v2 = v;
    v2.print();

    std::cout << "\n-v2:\n";
    (-v2).print();

    std::cout << "\nv2+v (2,0,6):\n";
    (v + v2).print();

    std::cout << "\nv2-v (0,0,0):\n";
    (v2 - v).print();

    std::cout << "\n3*v (3,0,9):\n";
    (v * 3.0).print();

    std::cout << "\nCalculate 2-norm of v (sqrt(10)=3.16): "
              << v.CalculateNorm(2) << "\n";
}