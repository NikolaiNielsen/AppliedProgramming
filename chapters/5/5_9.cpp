#include <iostream>
#include <cmath>
#include <cassert>


void solve3by3(double **A, double *b, double *u);


int main() {

    double* u = new double[3]; // {0.111, 0.267, 0.089}
    // double A[3][3] = {{1, 2, 4}, {1, 3, 1}, {5, 1, 2}};
    double b[3] = {1, 1, 1};

    // double B[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    double **B = new double*[3];
    for (int i=0; i<3; i++){
        B[i] = new double[3];
    }
    B[0][0] = 1;
    B[0][1] = 2;
    B[0][2] = 4;
    B[1][0] = 1;
    B[1][1] = 3;
    B[1][2] = 1;
    B[2][0] = 5;
    B[2][1] = 1;
    B[2][2] = 2;
    solve3by3(B, b, u);
    std::cout << u[0] << " " << u[1] << " " << u[2] << " " << "\n";
    return 0;
};

void solve3by3(double **A, double *b, double *u){
    // Solve a 3 by 3 system. Use LU decomposition and back/forward-substitution
    
    // Number of equations:
    int n=3;
    
    // Create intermediary matrices and vectors
    double y[n];

    // LU-decomposition. Diagonal and superdiagonal of modified A construct U.
    // Lower diagonal part makes up L, which has an implicit diagonal of 1
    for (int k=0; k<n-1; k++){
        assert(A[k][k] != 0);
        for (int i=k+1; i<n; i++){
            A[i][k] = A[i][k]/A[k][k];
        }
        for (int j=k+1; j<n; j++){
            for (int i=k+1; i<n; i++){
                A[i][j] = A[i][j] - A[i][k]*A[k][j];
            }
        }
    }

    // Forward substitution
    for (int j=0; j<n; j++){
        // Make sure we don't have a singular L matrix
        assert(A[j][j] != 0);
        y[j] = b[j]; // We don't divide by diagonal element of A, since that is a part of U, and we know L[j][j] == 0.
        for (int i=j+1; i<3; i++){
            b[i] = b[i] - A[i][j]*y[j];
        }
    }

    // Back substitution
    for (int j=n-1; j>=0; j--){
        u[j] = y[j] / A[j][j];
        for (int i=0; i<j; i++){
            y[i] = y[i] - A[i][j]*u[j];
        }
    }
}
