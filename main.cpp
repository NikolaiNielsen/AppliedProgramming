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
    int power = atoi(argv[1]);
    ComplexNumber **z = new ComplexNumber*[3];
    for (int i = 0; i < 3; i++)
    {
        z[i] = new ComplexNumber[3];
        z[i][0] = ComplexNumber(i * 3 + 1, i);
        z[i][1] = ComplexNumber(i * 3 + 2, i);
        z[i][2] = ComplexNumber(i * 3 + 3, i);
    }

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

    return 0;
}
