#include <iostream>
#include <cmath>

void Multiply(double **res, double **B, double scalar, int BRows, int BCols);
void Multiply(double **res, double scalar, double **B, int BRows, int BCols);
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols);


int main() {

    // double res [3] = {};
    // double A [] = {4,7,9};
    // double** B = new double*[3];
    // for (int i = 0; i < 3; i++){
    //     B[i] = new double[3];
	// B[i][0] = i * 3 + 1;
	// B[i][1] = i * 3 + 2;
	// B[i][2] = i * 3 + 3;
    // } 
    // int ACols = 3;
    // int BCols = 3;
    // int BRows = 3;
    // Multiply(res,A,B,ACols,BRows,BCols);

    int rows=3, cols=3;
    double** res = new double*[3];
    double** B = new double*[3];
    for (int i = 0; i < 3; i++){
        res[i] = new double[3];
        B[i] = new double[3];
	B[i][0] = i * 3 + 1;
	B[i][1] = i * 3 + 2;
	B[i][2] = i * 3 + 3;
    } 
    double scale = 0.5;
    Multiply(res, scale, B, rows, cols);
    return 0;
};


void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){
    // Vector-matrix product
    for (int i=0; i<BRows; i++){
        for (int j=0; j<ACols; j++){
            res[i] = res[i] + B[i][j] * A[j];
            // std::cout << i << " " << j << " " << B[i][j] << "\n";
        }
        // std::cout << i << " " << res[i] << "\n";
    }
}


void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
    // Matrix-scalar product
    for (int i=0; i<BRows; i++){
        for (int j=0; j<BCols; j++){
            res[i][j] = B[i][j] * scalar;
            std::cout << i << " " << j << " " << res[i][j] << "\n";
        }
    }
}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{   
    // Scalar-matrix product
    for (int i=0; i<BRows; i++){
        for (int j=0; j<BCols; j++){
            res[i][j] = scalar * B[i][j];
            std::cout << i << " " << j << " " << res[i][j] << "\n";
        }
    }
}