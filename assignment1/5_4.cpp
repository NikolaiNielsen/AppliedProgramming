#include <iostream>
#include <cmath>
#include <cassert>
#include "5_4.h"


double calc_std(double a[], int length){
    // Calculates the standard deviation of a vector "a" of length "length"
    double mean = calc_mean(a, length);

    // Make sure we don't divide by zero when taking unbiased standard
    // deviation.
    if (length == 0)
    {
        return 0.0;
    }
    double std = 0.0;
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