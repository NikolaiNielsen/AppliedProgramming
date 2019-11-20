#include <iostream>
#include <cmath>
#include <cassert>

void Multiply(double **res, double **B, double scalar, int BRows, int BCols);
void Multiply(double **res, double scalar, double **B, int BRows, int BCols);
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols);
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);


int main() {

    double** res = new double*[3];
    double** A = new double*[3];
    double** B = new double*[3];
    for (int i = 0; i < 3; i++){
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
    Multiply(res,A,B,3, ACols,BRows,BCols);

    // int rows=3, cols=3;
    // double** res = new double*[3];
    // double** B = new double*[3];
    // for (int i = 0; i < 3; i++){
    //     res[i] = new double[3];
    //     B[i] = new double[3];
	// B[i][0] = i * 3 + 1;
	// B[i][1] = i * 3 + 2;
	// B[i][2] = i * 3 + 3;
    // } 
    // double scale = 0.5;
    // Multiply(res, scale, B, rows, cols);
    return 0;
};

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