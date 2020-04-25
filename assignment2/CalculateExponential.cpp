#include <cmath>
#include "ComplexNumber.hpp"
#include <cassert>

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

int factorial(int n)
{
    assert (n >= 0);
    if ((n==0) or (n==1))
    {
        return 1;
    }
    else
    {
        return factorial(n-1);
    }
}


void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    // To calculate the exponential of a 3x3 complex matrix we use the series
    // expansion:
    // exp(A) = sum_{n=0}^{nMax} A**n/n!
    // We do this by calculating one term at a time, where the n'th term is
    // calculated from the (n-1)'th term:
    // x_n = x_{n-1} * A / n
    // Start with the first two terms (n=0, n=1): I + A, and set "last" to "A".
    // calculate the current term and add it to the result. Copy it to last
    // term, and empty out the current term. Increment n and go again.

    // Make sure the arrays we need are empty
    ComplexNumber **current = new ComplexNumber *[3];
    ComplexNumber **last = new ComplexNumber *[3];

    for (int i = 0; i < 3; i++)
    {
        current[i] = new ComplexNumber[3];
        last[i] = new ComplexNumber[3];
        for (int j=0; j<3; j++)
        {
            res[i][j] = ComplexNumber();
            current[i][j] = ComplexNumber();
            last[i][j] = ComplexNumber();
        }
    }
}