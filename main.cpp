#include "assignment2/ComplexNumber.hpp"
#include <iostream>

int main()
{
    ComplexNumber z(1, 1), z2(2);
    ComplexNumber z3(z);

    std::cout << "z2 = " << z2 << " z3 = " << z3 << "\n";

    return 0;
}