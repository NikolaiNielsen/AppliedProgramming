#include "5_9.h"
#include <cmath>
#include <cassert>

void solve3by3(double **A, double *b, double *u){
    // Solve a n by n system. Use LU decomposition, pivoting and back
    // substitution.

    // Create intermediary values
    double swap;
    double current_max;
    int current_row;
    int n=3;

    // LU-decomposition. Diagonal and superdiagonal of modified A construct U.
    // Lower diagonal part makes up L, which has an implicit diagonal of 1
    for (int k = 0; k < n - 1; k++)
    {
        // Find pivot
        current_max = fabs(A[k][k]);
        current_row = k;
        for (int p = k; p < n; p++)
        {
            if (fabs(A[p][k]) > current_max)
            {
                current_max = fabs(A[p][k]);
                current_row = p;
            }
        }
        // perform pivot if needed
        if (current_row != k)
        {
            // Permute A
            for (int p = k; p < n; p++)
            {
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
        for (int i = k + 1; i < n; i++)
        {
            A[i][k] = A[i][k] / A[k][k];
        }
        // Update U and b. Corresponds to elementary elimination matrices
        for (int j = k + 1; j < n; j++)
        {
            b[j] = b[j] - b[k] * A[j][k];
            for (int i = k + 1; i < n; i++)
            {
                A[i][j] = A[i][j] - A[i][k] * A[k][j];
            }
        }
    }

    // Solution obtained by back-substitution with Ux=b'
    // where b' is permuted and transformed b
    for (int j = n - 1; j >= 0; j--)
    {
        u[j] = b[j] / A[j][j];
        for (int i = 0; i < j; i++)
        {
            b[i] = b[i] - A[i][j] * u[j];
        }
    }
}