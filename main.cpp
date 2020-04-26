#include <iostream>
#include "./assignment1/2_6.h"
#include "./assignment1/3_3.h"
#include "./assignment1/5_4.h"
#include "./assignment1/5_3.h"
#include "./assignment1/5_6.h"
#include "./assignment1/5_10.h"

int main()
{
    double initialGuess = 0;
    double epsilon = 0.001; 
    double x = newton_Raphson(initialGuess, epsilon);
    std::cout << x << "\n";
    
    int n = 100;
    implicit_Euler(n);

    double a[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    int length = 5;
    double mean = calc_mean(a, length);
    double std_data = calc_std(a, length);
    std::cout << mean << "\n";
    std::cout << std_data << "\n";

    double c = 1.0;
    double b = 2.0;
    std::cout << c << "," << b << "\n";
    swap_pointer(&c, &b);
    swap_ref(c, b);
    std:: cout << c << "," << b << "\n";

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
    for (int i=0; i < (sizeof(res)/sizeof(*res)); i++){
       std::cout << res[i] << "\n";
    }
    std::cout << "\n";

    double u [3] = {};
    double Bv [] = {1,2,1};
    double** Am  = new double*[3];
    for (int i = 0; i < 3; i++){
        Am[i] = new double[3];
    }
    Am[0][0] = 1;
    Am[0][1] = 2; 
    Am[0][2] = 3;
    Am[1][0] = 1;
    Am[1][1] = 2;
    Am[1][2] = 4;
    Am[2][0] = 7;
    Am[2][1] = 8;
    Am[2][2] = 3;

    guassian_elimination(Am, Bv, u, 3);
    for (int i=0; i < (sizeof(u)/sizeof(*u)); i++){
       std::cout << u[i] << "\n";
    }
    std::cout << "\n";

}
