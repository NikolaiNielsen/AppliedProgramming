#include <iostream>

int main()
{
    for (int i=0; i < 1000000000; i++){
        double* x, *y;
        double dot;
        x = new double[3];
        x[0] = 1;
        x[1] = 2;
        x[2] = 3;
        y = new double[3];
        y[0] = 3;
        y[1] = 2;
        y[2] = 1;
        dot = x[0]*y[0] + x[1]*y[1] + x[2]*y[2];
        delete[] x;
        delete[] y;
    }

    return 0;
}