#include <iostream>
#include <cmath>

double Determinant(double** A, int size);
void printMat(double** A, int size);


int main(){
    // Write a recursive function that may be used to calculate the determinant
    // of a square matrix of a given size
    // int size = 3;

    // double **A = new double *[size];
    // for (int i = 0; i < size; i++)
    // {
    //     A[i] = new double[size];
    // }

    // A[0][0] = 1;
    // A[0][1] = 2;
    // A[0][2] = 3;
    // A[1][0] = 4;
    // A[1][1] = 5;
    // A[1][2] = 6;
    // A[2][0] = 1;
    // A[2][1] = 3;
    // A[2][2] = 2;

    int size = 4;

    double **A = new double *[size];
    for (int i = 0; i < size; i++)
    {
        A[i] = new double[size];
    }

    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[0][3] = 2;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[1][3] = 2;
    A[2][0] = 1;
    A[2][1] = 3;
    A[2][2] = 2;
    A[2][2] = 2;
    A[2][3] = 2;
    A[3][0] = 2;
    A[3][1] = 2;
    A[3][2] = 2;
    A[3][3] = 2;

    std::cout << "input matrix is" << std::endl; 
    printMat(A, size);
    
    double det = Determinant(A, size);
    std::cout << "Final determinant is " <<  det << std::endl;
    return 0;
}

double Determinant(double** A, int size)
{   
    // recursively calculate the determinant of a matrix A of size size, using
    // the formula in section A.1.3 of Guide to Scientific Computing in c++.
    double det = 0.0;

    // trivial cases
    if (size == 1)
    {
        det = A[0][0];
    }
    else if (size == 2)
    {
        det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
    else
    {
        for (int N=0; N<size; N++)
        {   
            // create the submatrix
            double** newmat = new double*[size-1];
            for (int i=0; i<size-1; i++)
            {
                newmat[i] = new double[size-1];
            }

            int realcol;
            int realrow;
            // populate the submatrix
            for (int row=0; row<size-1; row++)
            {

                for (int col=0; col<size-1; col++)
                {
                    realrow = row+1;
                    if (col >= N){
                        realcol = col+1;
                    }
                    else
                    {
                        realcol = col;
                    }
                    newmat[row][col] = A[realrow][realcol];
                }
            }

            // calculate the term recursively
            double res = A[0][N] * pow(-1, N) * Determinant(newmat, size - 1);
            det += res;

            // Print stuuuufff
            // std::cout << "RECURSION N = " << N << std::endl;
            // std::cout << "submatrix " << N << " is " << std::endl;
            // printMat(newmat, size - 1);
            // std::cout << "sign is " << pow(-1, N) << std::endl;
            // std::cout << "term is " << res << std::endl;
        }
    }
    return det;
}

void printMat(double** A, int size)
// Helper function to print a square matrix.
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}