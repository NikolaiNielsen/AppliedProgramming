#include "assignment3/Matrix.hpp"
#include "assignment3/Vector.hpp"
#include "assignment3/SparseVector.hpp"
#include <iostream>

void regressionTestsVector();
void regressionTestsMatrix();
void regressionTestsSparse();

int main()
{
    // Exercise 1
    // Regression tests.
    regressionTestsVector();
    regressionTestsMatrix();
    regressionTestsSparse();
    return 0;
}

void regressionTestsSparse()
{
    std::cout << "s: Empty vector of size 10:\n";
    SparseVector<int> s(10);
    s.print();

    std::cout << "\ns2: Empty vector of size 0:\n";
    SparseVector<int> s2;
    s2.print();

    std::cout << "\nSet 4 values of s, out of order.\n";
    s.setValue(1, 3);
    s.setValue(3, 4);
    s.setValue(6, 1);
    s.setValue(2, 5);


    std::cout << "Then print s:\n";
    for (int i = 0; i<10; i++)
    {
        std::cout << i << ", " << s.getValue(i) << "\n";
    }

    std::cout << "\ns3\n"; 
    SparseVector<int> s3(10);
    s3.setValue(1, 4);
    s3.setValue(0, 3);
    s3.print();

    std::cout << "\ns+s3:\n";
    (s+s3).print();

    std::cout << "\ns-s3:\n";
    (s-s3).print();

    Matrix<int> sm(5, 5);
    sm(0,0) = 1;
    sm(1,1) = 1;
    sm(0,3) = 1;
    sm(2,0) = 1;
    sm(2,2) = 1;
    sm(3,3) = 1;
    sm(4,4) = 1;

    SparseVector<int> s4(5);
    s4.setValue(1, 3);
    s4.setValue(3, 2);

    std::cout << "\ntesting matrix-vector product. Matrix:\n";
    sm.print();
    std::cout << "vector [0, 3, 0, 2, 0]. Result should be [2,3,0,2,0]\n";
    (sm*s4).print();

    std::cout << "vector-matrix product of same matrix/vector.\n"
              << "Result should be [0, 3, 0, 2, 0]\n";
    (s4*sm).print();
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
    v[0] = 1.0;
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