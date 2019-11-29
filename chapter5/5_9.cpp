#include <iostream>
#include <cmath>
#include <cassert>


void solve3by3(double **A, double *b, double *u);


int main() {

    double* u = new double[3]; // {0.111, 0.267, 0.089}
    double A[3][3] = {{1, 2, 4}, {1, 3, 1}, {5, 1, 2}};
    double b[3] = {1, 1, 1};

    // double B[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    double **B = new double*[3];
    for (int i=0; i<3; i++){
        B[i] = new double[3];
        B[i][i] = 1;
    }
    B[0][1] = 1;
    B[0][2] = 1;
    B[1][0] = 0;
    B[1][2] = 1;
    B[2][0] = 0;
    B[2][1] = 0;
    // Should give [1, 0, 0]
    solve3by3(B, b, u);

    return 0;
};

void solve3by3(double **A, double *b, double *u){
    // Solve a 3 by 3 system. Use LU decomposition and back/forward-substitution

    // Back substitution
    for (int j=0; j<3; j++){
        // Make sure we don't have a singular L matrix
        assert(A[j][j] != 0);
        u[j] = b[j] / A[j][j];
        for (int i=j+1; i<3; i++){
            b[i] = b[i] - A[i][j]*u[j];
        }
    }

    // Forward substitution
    for (int j=2; j>=0; j--){
        // Make sure we don't have a singular U matrix
        assert(A[j][j] != 0);
        u[j] = b[j] / A[j][j];
        for (int i=0; i<j; i++){
            b[i] = b[i] - A[i][j]*u[j];
        }
    }
}
