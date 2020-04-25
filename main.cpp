#include <iostream>
#include "assignment2/ComplexNumber.hpp"
#include "assignment2/CalculateExponential.hpp"

int main(int argc, char *argv[])
{
    // EXERCISE 6.1.1-6.1.6
    // ComplexNumber z(1, 1), z2(2);
    // ComplexNumber z3(z);
    // std::cout << "z2 = " << z2 << ". z3 = " << z3 << "\n";
    // std::cout << "Real part of z2: " << z2.GetRealPart() 
    //           << ". Imaginary part: " << z2.GetImaginaryPart() << "\n";
    // std::cout << "Real part of z2: " << RealPart(z2) << ". Imaginary part: "
    //           << ImaginaryPart(z2) << "\n";
    // ComplexNumber z4 = z3.CalculateConjugate();
    // std::cout << "z4 = " << z4 << "\n";
    // z4.SetConjugate();
    // std::cout << "z4 = " << z4 << "\n";
    // ComplexNumber z5 = z3*z4.CalculateConjugate();
    // std::cout << "z5 = " << z5 << "\n";

    // EXERCISE 6.1.7
    int power = 100;
    ComplexNumber **z = new ComplexNumber*[3];
    for (int i = 0; i < 3; i++)
    {
        z[i] = new ComplexNumber[3];
        z[i][0] = ComplexNumber(0);
        z[i][1] = ComplexNumber(0);
        z[i][2] = ComplexNumber(0);
    }
    z[0][1] = ComplexNumber(1);
    z[1][0] = ComplexNumber(1);
    z[1][2] = ComplexNumber(0, -1);
    z[2][1] = ComplexNumber(0, 1);

    ComplexNumber **res = new ComplexNumber *[3];
    for (int i = 0; i < 3; i++)
    {
        res[i] = new ComplexNumber[3];
    }

    CalculateExponential(z, power, res);

    int size = 3;
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

    return 0;
}
