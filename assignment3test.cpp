#include "assignment3/Matrix.hpp"
#include "assignment3/Vector.hpp"
#include <iostream>

void regressionTestsVector();
void regressionTestsMatrix();

int main()
{
    // Exercise 1
    // Regression tests.
    regressionTestsVector();
    regressionTestsMatrix();

    return 0;
}

void regressionTestsMatrix()
{
    std::cout << "matrix m=[[1, 2], [3, 4]]:\n";
    Matrix<double> m(2, 2);
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(1, 0) = 3;
    m(1, 1) = 4;
    m.print();

    std::cout << "\nEmpty, 2x2 matrix m2:\n";
    Matrix<double> m2(2, 2);
    m2.print();

    std::cout << "\nSet m2=m\n";
    m2=m;
    m2.print();

    std::cout << "\nConstruct m3(m):\n";
    Matrix<double> m3(m);
    m3.print();

    std::cout << "\nm4 is empty 3x2 matrix.\n";
    Matrix<double> m4(3, 2);
    std::cout << "m4 has " << m4.GetNumberOfRows() << " rows and "
              << m4.GetNumberOfColumns() << "columns\n";

    std::cout << "\nm(1,1) should be 3. it is: " << m(1,1) << "\n";

    std::cout << "\n-m:\n";
    (-m).print();

    std::cout << "\nm+m2 = [[2, 4], [6, 8]]\n";
    (m+m2).print();

    std::cout << "\nm-m2 = [[0, 0], [0, 0]]\n";
    (m-m2).print();

    std::cout << "\nm*3 = [[3, 6], [9, 12]]\n";
    (m*3).print();

    Vector<double> vm(2);
    vm[0] = 3;
    vm[1] = 2;
    std::cout << "\n[3, 2] * m = [9, 14]\n";
    (vm*m).print();

    std::cout << "\nm * [3, 2] = [7, 17]\n";
    (m*vm).print();
}

void regressionTestsVector()
{
    std::cout << "vector v=[1, 0, 3]:\n";
    Vector<double> v(3);
    v[0] = 1;
    v[1] = 0;
    v[2] = 3;
    v.print();

    std::cout << "\nvector v2=v:\n";
    Vector<double> v2(v);
    v2.print();

    std::cout << "\nvector v3=[0, 0, 0, 0]:\n";
    Vector<double> v3(4);
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