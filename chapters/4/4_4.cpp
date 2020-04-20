#include <iostream>

int main()
{
    // dynamically allocate memory for three 2x2 matrices.
    // Assign values to A and B, and calculate C = A + B.
    // deallocate memory, and do it looooads of times.
    for (int n=0; n<50000000; n++)
    {
        int rows=2, cols=2;

        // Declare the variables
        double** A, **B, **C;
        A = new double* [rows];
        B = new double* [rows];
        C = new double* [rows];
        for (int i=0; i<rows; i++)
        {
            A[i] = new double [cols];
            B[i] = new double [cols];
            C[i] = new double [cols];
        }

        // Populate them
        A[0][0] = 1;
        A[0][1] = 2;
        A[1][0] = 3;
        A[1][1] = 4;

        B[0][0] = 5;
        B[0][1] = 6;
        B[1][0] = 7;
        B[1][1] = 8;

        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
                // std::cout << C[i][j] << "\n";
            }
        }

        // Deallocate
        for (int i=0; i<rows; i++)
        {
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;
    }

    return 0;
}