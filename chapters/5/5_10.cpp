#include <iostream>
#include <cmath>
#include <cassert>


void guassian_elimination(double **A, double *b, double *u, int n);


int main() {

    double* u = new double[3]; // {0.111, 0.267, 0.089}
    // double A[3][3] = {{1, 2, 4}, {1, 3, 1}, {5, 1, 2}};

    int n = 3;
    double b[n] = {3, 6, 10};

    double **B = new double*[n];
    for (int i=0; i<n; i++){
        B[i] = new double[n];
    }
    B[0][0] = 1;
    B[0][1] = 2;
    B[0][2] = 2;
    B[1][0] = 4;
    B[1][1] = 4;
    B[1][2] = 2;
    B[2][0] = 4;
    B[2][1] = 6;
    B[2][2] = 4;
    guassian_elimination(B, b, u, n);

    std::cout << "u:\n";
    std::cout << u[0] << ", " << u[1] << ", " << u[2] << "\n";
    return 0;
};

void guassian_elimination(double **A, double *b, double *u, int n){
    // Solve a n by n system. Use LU decomposition, pivoting and back substitution.
    
    
    // Create intermediary values
    double swap;
    double current_max;
    int current_row;

    // LU-decomposition. Diagonal and superdiagonal of modified A construct U.
    // Lower diagonal part makes up L, which has an implicit diagonal of 1
    for (int k=0; k<n-1; k++){
        // Find pivot
        // std::cout << "LU Decomp. k = " << k << "\n";
        current_max = fabs(A[k][k]);
        current_row = k;
        // if (A[k][k] == 0){
        for (int p=k; p<n; p++){
            if (fabs(A[p][k] > current_max)){
                current_max = fabs(A[p][k]);
                current_row = p;
            }
        }
        // perform pivot if needed
        if (current_row != k) {
            // std::cout << "swap rows " << k << " and " << current_row << "\n";
            // Permute A
            for (int p=k; p<n; p++){
                swap = A[current_row][p];
                A[current_row][p] = A[k][p];
                A[k][p] = swap;
            }

            // Permute b
            swap = b[current_row];
            b[current_row] = b[k];
            b[k] = swap;
        }

        // subdiagonals of L
        for (int i=k+1; i<n; i++){
            A[i][k] = A[i][k]/A[k][k];
        }
        // Update U and b. Corresponds to elementary elimination matrices
        for (int j=k+1; j<n; j++){
            b[j] = b[j] - b[k]*A[j][k];
            for (int i=k+1; i<n; i++){
                A[i][j] = A[i][j] - A[i][k]*A[k][j];
            }
        }

        // Stuff for debugging
        // std::cout << "New, permuted matrix:\n";
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<n; j++){
        //         std::cout << A[i][j] << ", ";
        //     }
        //     std::cout << "\n";
        // }
        // std::cout << "And b:\n";
        // for (int i=0; i<n; i++){
        //     std::cout << b[i] << ", ";
        // }
        // std::cout << "\n";
    }

    // Solution obtained by back-substitution with Ux=b'
    // where b' is permuted and transformed b
    for (int j=n-1; j>=0; j--){
        u[j] = b[j] / A[j][j];
        for (int i=0; i<j; i++){
            b[i] = b[i] - A[i][j]*u[j];
        }
    }
}
