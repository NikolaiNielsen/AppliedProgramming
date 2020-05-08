#include <iostream>
#include "assignment2/ComplexNumber.hpp"
#include "assignment2/CalculateExponential.hpp"
#include "assignment2/Matrix2x2.hpp"
#include "assignment2/Student.hpp"
#include "assignment2/GraduateStudent.hpp"
#include "assignment2/PhdStudent.hpp"
#include "assignment2/Exercise82.hpp"
#include "assignment2/Exception.hpp"
#include "assignment2/FileNotOpenException.hpp"
#include "assignment2/OutOfRangeException.hpp"

int main(int argc, char *argv[])
{
    // EXERCISE 6.1.1-6.1.6
    ComplexNumber z(1, 1), z2(2);
    ComplexNumber z3(z);
    std::cout << "z2 = " << z2 << ". z3 = " << z3 << "\n";
    std::cout << "Real part of z2: " << z2.GetRealPart() 
              << ". Imaginary part: " << z2.GetImaginaryPart() << "\n";
    std::cout << "Real part of z2: " << RealPart(z2) << ". Imaginary part: "
              << ImaginaryPart(z2) << "\n";
    ComplexNumber z4 = z3.CalculateConjugate();
    std::cout << "z4 = " << z4 << "\n";
    z4.SetConjugate();
    std::cout << "z4 = " << z4 << "\n";
    ComplexNumber z5 = z3*z4.CalculateConjugate();
    std::cout << "z5 = " << z5 << "\n";

    // EXERCISE 6.1.7
    int power = 100;
    ComplexNumber **z6 = new ComplexNumber*[3];
    ComplexNumber **res = new ComplexNumber *[3];
    for (int i = 0; i < 3; i++)
    {
        res[i] = new ComplexNumber[3];
        z6[i] = new ComplexNumber[3];
        z6[i][0] = ComplexNumber(0);
        z6[i][1] = ComplexNumber(0);
        z6[i][2] = ComplexNumber(0);
    }
    z6[0][1] = ComplexNumber(1);
    z6[1][0] = ComplexNumber(1);
    z6[1][2] = ComplexNumber(0, -1);
    z6[2][1] = ComplexNumber(0, 1);
    CalculateExponential(z6, power, res);
    int size = 3;
    std::cout << "z:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << z6[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "exp(z) for nMax=100:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // According to maple this should be
    // (1.589091778, 1.368298872, 0.5890917783 i)
    // (1.368298872, 2.178183557, 1.368298872 i)
    // (-0.5890917783i, -1.368298872i, 1.589091778)
    

    // 6.2. 2-by-2 matrices.
    std::cout << "Empty matrix z\n";
    Matrix2x2 zmat;
    zmat.Print();
    std::cout << "proper matrix z2\n";
    Matrix2x2 zmat2(1, 2, 3, 4);
    zmat2.Print();
    std::cout << "Construct new matrix z3 by passing in z2\n";
    Matrix2x2 zmat3(zmat2);
    zmat3.Print();
    std::cout << "Set z = z2. Print z\n";
    zmat=zmat2;
    zmat.Print();
    std::cout << "calculate inverse of z2\n";
    Matrix2x2 zinv = zmat2.CalcInverse();
    zinv.Print();
    std::cout << "determinant of z2: " << zmat2.CalcDeterminant() << "\n";
    std::cout << "determinant of inverse of z2: " << zinv.CalcDeterminant() 
              << "\n";
    std::cout << "z=-z2\n";
    zmat = -zmat2;
    zmat.Print();
    std::cout << "z4 = z + z2\n";
    Matrix2x2 zmat4 = zmat + zmat2;
    zmat4.Print();
    std::cout << "z5 = 3*z2\n";
    Matrix2x2 zmat5(zmat2);
    zmat5.MultScalar(3);
    zmat5.Print();
    std::cout << "z6 = z5-z2\n";
    Matrix2x2 zmat6 = zmat5-zmat2;
    zmat6.Print();

    // 7.1
    Student stud;
    Student stud2("stud", 10, 100);
    stud.print();
    stud2.print();
    GraduateStudent gstud;
    GraduateStudent gstud2("stud2", 10, 100, true);
    gstud.print();
    gstud2.print();
    PhdStudent pstud("stud3", 10, 100, true);
    pstud.print();

    // 8.2
    std::cout << CalcAbs<int>(-3) << " " << CalcAbs<int>(3) << "\n";
    std::cout << CalcAbs<double>(-3.1) << " " << CalcAbs<double>(3.31)
              << "\n";


    // 9.1
    // Write a catch block which is able to catch a generic exception but can
    // also differentiate between these two types of errors.

    // Well, the differentiator is the tag - either FILE or RANGE. So we just
    // check the tag.
    for (int i=0; i<10; i++)
    {
        std::cout << "EXCEPTION NUMBER "<<i<<"\n";
        try
        {
            // do stuff
            int val = rand() % 3;
            if (val == 1)
            {
                // Throw an out of range exception
                std::cout << "Sending out of range\n";
                throw(OutOfRangeException("You're out of range dummy"));
            }
            else if (val == 2)
            {
                std::cout << "Sending File not open\n";
                throw(FileNotOpenException("File's not open, dummy"));
            }
            else
            {
                std::cout << "throwing generic exception\n";
                throw(Exception("GENERIC", "A generic problem"));
            }
        }
        catch (FileNotOpenException &error)
        {
            std::cout << "File not found error!\n";
            error.PrintDebug();
        }
        catch (OutOfRangeException &error)
        {
            std::cout << "Out of range exception!\n";
            error.PrintDebug();
        }
        catch (Exception &error)
        {
            std::cout << "Generic Exception!\n";
            error.PrintDebug();
        }
        std::cout << "\n";
    }
    return 0;
}
