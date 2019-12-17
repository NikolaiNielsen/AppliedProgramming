#include "5_9.h"
#include <cmath>
#include <cassert>

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