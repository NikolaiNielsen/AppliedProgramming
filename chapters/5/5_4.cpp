#include <iostream>
#include <cmath>

double calc_std(double a[], int length);
double calc_mean(double a[], int length);

int main(){
    int N = 14;
    double x[N] = {14, 15, 16, 16, 16, 22, 22, 24, 24, 25, 25, 25, 25, 25};
    double mean = calc_mean(x, N);
    std::cout << mean << "\n";
    double std = calc_std(x, N);
    std::cout << std << "\n";
    return 0;
}


double calc_std(double a[], int length){
    // Calculates the standard deviation of a vector "a" of length "length"
    double mean = calc_mean(a, length);
    if (length == 1) {
        return 0.0;
    }
    double std = 0;
    for (int i=0; i<length; i++){
        std += pow(a[i] - mean, 2);
    }
    std /= (length-1);
    std = sqrt(std);
    return std;
}


double calc_mean(double a[], int length){
    // Calculates the mean of a vector of doubles
    double mean = 0;
    for (int i = 0; i<length; i++){
        mean += a[i];
    }
    mean /= length;
    return mean;
}