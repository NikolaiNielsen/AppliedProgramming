#include <iostream>
#include <cmath>
#include <cassert>

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);

    int main()
{
    // Write a function Multiply, that may be used to multiply two matrices
    // given the two matrices and the size of both matrices. Use assertions to
    // verify that the matrices are of suitable sizes to be multiplied.
    double **res = new double *[3];
    double **A = new double *[3];
    double **B = new double *[3];
    for (int i = 0; i < 3; i++)
    {
        B[i] = new double[3];
        res[i] = new double[3];
        A[i] = new double[3];
        B[i][0] = i * 3 + 1;
        B[i][1] = i * 3 + 2;
        B[i][2] = i * 3 + 3;
        A[i][0] = i * 3 + 1;
        A[i][1] = i * 3 + 2;
        A[i][2] = i * 3 + 3;
    }
    int ACols = 3;
    int BCols = 3;
    int BRows = 3;
    Multiply(res, A, B, 3, ACols, BRows, BCols);
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols)
{
    // Matrix-matrix product. (nxm) X (pxq) = (nxq) if m==p
    assert(ACols == BRows);
    for (int i = 0; i < ARows; i++)
    {
        for (int j = 0; j < BCols; j++)
        {
            for (int k = 0; k < ACols; k++)
            {
                res[i][j] = res[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}