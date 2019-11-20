#include "3_3.h"
#include <iostream>
#include <fstream>
#include <cassert>
// #include <cmath>

// double* linspace(double start, double stop, int N)
// {
//     assert(N>1);
//     double h = (start-stop)/(N-1.);
//     double x[N];
//     for (int i=0; i<N; i++)
//     {
//         x[i] = start + i*h;
//     }
//     return x;
// }

void implicit_Euler(int N)
{
    assert (N > 1);

    double h=1/((double)(N)-1);
    double y[N];
    y[0] = 1;
    double x[N];
    x[0] = 0;
    double res[N];
    res[0] = exp(x[0]);

    for (int i = 1; i < N; i++)
    {
        y[i] = y[i-1]/(h+1);
        x[i] = x[i-1] + h;
        res[i] = exp(-x[i]);
    }

    // write to the file
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());
    for (int i=0; i<N; i++)
    {
        write_output << x[i] << "," << y[i] << "," << y[i]-res[i] <<"\n";
    }
    write_output.close();

}

// int main()
// {
//     // double start=0;
//     // double stop=1;
//     // int N=50;
//     // double x* = linspace(start, stop, N);
//     // for (int i=0; i<N; i++)
//     // {
//     //     std::cout << x[i];
//     // }
//     implicit_Euler(50);
//     return 0;
// }