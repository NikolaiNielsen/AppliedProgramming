#include <cmath>
#include <iostream>

double newton_Raphson(double initialGuess, double epsilon)
{
    // Applies the Newton Raphson formula for the equation e^x + x^3 - 5
    double x = initialGuess;
    double x_last;
    std::cout << x << "\n";
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

int main()
{
    double initialGuess = 0;
    double epsilon = 0.001; 
    double x = newton_Raphson(initialGuess, epsilon);
    std::cout << x << "\n";

    return 0;
}