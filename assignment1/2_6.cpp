#include <cmath>
#include "2_6.h"

double newton_Raphson(double initialGuess, double epsilon)
{
    // Applies the Newton Raphson formula for the equation e^x + x^3 - 5

    // Initialize the initial guess and temporary variable
    double x = initialGuess;
    double x_last;

    // We have no test for divergence, we just hope the thing converges within
    // 100 iterations.
    for (int i = 1; i <= 100; i++)
    {
        // store last iterations variable and update it
        x_last = x;
        x = x - (exp(x) + x*x*x - 5) / (exp(x) + 3*x*x);

        // Check for convergence
        if (fabs(x-x_last) < epsilon)
        {
            break;
        }
    }
    
    return x;

};