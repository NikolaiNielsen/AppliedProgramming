#include <cmath>
#include "ComplexNumber.hpp"

void Multiply(ComplexNumber **res, ComplexNumber **A, ComplexNumber **B)
{
    // Matrix-matrix product. (nxm) X (pxq) = (nxq) if m==p
    int N = 3;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                res[i][j] = res[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void Add(ComplexNumber **res, ComplexNumber **A, ComplexNumber **B)
{
    int N = 3;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
}

void Divide(ComplexNumber **res, ComplexNumber **A, double B)
{
    int N = 3;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res[i][j] = ComplexNumber(A[i][j].GetRealPart()/B,
                                      A[i][j].GetImaginaryPart()/B);
        }
    }
}

void ComplexPower(ComplexNumber **res, ComplexNumber **A, int N)
{
    res = A;
    for (int i=1; i<N; i++)
    {
        Multiply(res, res, A);
    }
}


void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    for (int i = 0; i < 3; i++)
    {
        res[i] = new ComplexNumber[3];
        res[i][0] = ComplexNumber();
        res[i][1] = ComplexNumber();
        res[i][2] = ComplexNumber();
        res[i][i] = ComplexNumber(1);
    }

    Divide(res, A, 2);

    // for (int i=1; i<=nMax; i++)
    // {
    //     ComplexNumber **temp = new ComplexNumber *[3];
    //     for (int i = 0; i < 3; i++)
    //     {
    //         temp[i] = new ComplexNumber[3];
    //     }

    //     std::cout << "TEMP MATRIX. N = " << i << "\nSTARTING VALUE\n";
    //     int size = 3;
    //     for (int i = 0; i < size; i++)
    //     {
    //         for (int j = 0; j < size; j++)
    //         {
    //             std::cout << temp[i][j] << " ";
    //         }
    //         std::cout << std::endl;
    //     }


    //     ComplexPower(temp, A, i);
    //     std::cout << "POWER\n";
    //     for (int i = 0; i < size; i++)
    //     {
    //         for (int j = 0; j < size; j++)
    //         {
    //             std::cout << temp[i][j] << " ";
    //         }
    //         std::cout << std::endl;
    //     }

    //     Divide(temp, temp, tgamma(i+1));
    //     Add(res, res, temp);
    // }
}