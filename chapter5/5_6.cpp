#include <iostream>
#include <cmath>

void Multiply(double **res, double **B, double scalar, int BRows, int BCols);
void Multiply(double **res, double scalar, double **B, int BRows, int BCols);
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols);


int main() {

    double res [3] = {};
    double A [] = {4,7,9};
    double** B = new double*[3];
    for (int i = 0; i < 3; i++){
        B[i] = new double[3];
	B[i][0] = i * 3 + 1;
	B[i][1] = i * 3 + 2;
	B[i][2] = i * 3 + 3;
    } 
    int ACols = 3;
    int BCols = 3;
    int BRows = 3;
    Multiply(res,A,B,ACols,BRows,BCols);

    // int rows=3, cols=3;
    // double a[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // double scale = 0.5;
    // double res[rows][cols] = {{},{},{}};
    // Multiply(res, a, scale, rows, cols)
    // std::cout << res[1][1] << "\n";
    return 0;
};


void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){
    // Vector-matrix multiplication
    
}


void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
    for (int i=0; i<BRows; i++){
        for (int j=0; j<BCols; j++){
            res[i][j] = B[i][j] * scalar;
            std::cout << i << " " << j << " " << res[i][j] << "\n";
        }
    }
}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{
    for (int i=0; i<BRows; i++){
        for (int j=0; j<BCols; j++){
            res[i][j] = scalar * B[i][j];
            std::cout << i << " " << j << " " << res[i][j] << "\n";
        }
    }
}