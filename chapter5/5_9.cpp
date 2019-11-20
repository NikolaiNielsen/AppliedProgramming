#include <iostream>
#include <cmath>
#include <cassert>


void solve3by3(double **A, double *b, double *u);


int main() {

    double* u = new double[3]; // {0.111, 0.267, 0.089}
    double A[3][3] = {{1, 2, 4}, {1, 3, 1}, {5, 1, 2}};
    double b[3] = {1, 1, 1};
    solve3by3(A, b, u);

    return 0;
};

void solve3by3(double **A, double *b, double *u){
    // Solve a 3 by 3 system. Use LU decomposition and back/forward-substitution
}
