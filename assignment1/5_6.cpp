#include "5_6.h"
#include <cassert>

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols){
    // Matrix-matrix product. (nxm) X (pxq) = (nxq) if m==p
    assert (ACols == BRows);
    for (int i=0; i<ARows; i++){
        for (int j=0; j<BCols; j++){
            for (int k=0; k<ACols; k++){
                res[i][j] = res[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){
    // Vector-matrix product. (1xn) X (nxm) = (1xm)
    assert (ACols == BRows);
    for (int i=0; i<BRows; i++){
        for (int j=0; j<ACols; j++){
            res[i] = res[i] + B[i][j] * A[j];
        }
    }
}

void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
    // Matrix-vector product (nxm) X (px1) = (nx1) if m=p
    assert (ACols == BRows);
    for (int i=0; i<ARows; i++){
        for (int j=0; j<BRows; j++){
            res[i] = res[i] + A[i][j] * B[j];
        }
    }
}


void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
    // Matrix-scalar product
    for (int i=0; i<BRows; i++){
        for (int j=0; j<BCols; j++){
            res[i][j] = B[i][j] * scalar;
        }
    }
}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{   
    // Scalar-matrix product
    for (int i=0; i<BRows; i++){
        for (int j=0; j<BCols; j++){
            res[i][j] = scalar * B[i][j];
        }
    }
}