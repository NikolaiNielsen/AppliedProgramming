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
        // Make res an identity matrix - the 0th order term
        res[i][i] = ComplexNumber(1);
    }

    // add first order term - it's safe to use the result as input as well, as
    // "future" elements aren't changed
    Add(res, res, A);

    // Set elements of last equal to those of A.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            last[i][j] = ComplexNumber(A[i][j]);
        }
    }

    // Main calculation for nMax>1
    for (int n=2; n<=nMax; n++)
    {
        // multiply the last term by A. Then divide by n to get the current
        // term.
        Multiply(current, last, A);
        Divide(current, current, n);

        // Add it to the result and assign it to last.
        Add(res, res, current);

        // clear current for next iteration
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                last[i][j] = ComplexNumber(current[i][j]);
                current[i][j] = ComplexNumber();
            }
        }
    }

    // Remember to deallocate the temporary arrays!
    for (int i=0; i<3; i++)
    {
        delete[] last[i];
        delete[] current[i];
    }
    delete[] last;
    delete[] current;
}