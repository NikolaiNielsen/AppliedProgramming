#include "3_3.h"
#include <fstream>
#include <cassert>
#include <cmath>

void implicit_Euler(int N)
{
    // We need more than one point to be able to integrate
    assert (N > 1);

    // initialize spacing h
    double h=1/((double)(N)-1);

    // Initialize arrays for x and y, and set their initial values
    double y[N];
    y[0] = 1;
    double x[N];
    x[0] = 0;

    // Optional analytical result.
    // double res[N];
    // res[0] = exp(x[0]);

    // Perform simple implicit euler integration
    for (int i = 1; i < N; i++)
    {
        y[i] = y[i-1]/(h+1);
        x[i] = x[i-1] + h;
        // res[i] = exp(-x[i]);
    }

    // write to the file - but make sure it is open first.
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());
    for (int i=0; i<N; i++)
    {
        write_output << x[i] << "," << y[i] << "\n";
        // write_output << x[i] << "," << y[i] << "," << y[i]-res[i] <<"\n";
    }
    write_output.close();

}
