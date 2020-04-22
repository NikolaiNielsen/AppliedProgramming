#include <cmath>
double CalculateNorm(double * x, int size, int p=2)
{
    
    double a = 0.0;
    for (int i=0; i<size; i++)
    {
        double temp = fabs(x[i]);
        a += pow(temp, p);
    }
    return pow(a, 1.0/p);
}

// Extend the above code to calculate the p-norm of a given vector, where p
// defaults to 2.