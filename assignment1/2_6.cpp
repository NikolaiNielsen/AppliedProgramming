#include <cmath>
#include <iostream>
#include "2_6.h"

double newton_Raphson(double initialGuess, double epsilon)
{
    // Applies the Newton Raphson formula for the equation e^x + x^3 - 5
    double x = initialGuess;
    double x_last;
    for (int i = 1; i <= 100; i++)
    {
        x_last = x;
        x = x - (exp(x) + x*x*x - 5) / (exp(x) + 3*x*x);
        if (fabs(x-x_last) < epsilon)
        {
            break;
        }
    }
    
    return x;

};