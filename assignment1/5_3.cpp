#include <iostream>
#include "5_3.h"

void swap_pointer(double *a, double *b)
{
    // Takes in two pointer variables and exchanges them
    double *c;
    c = new double;
    *c = *a;
    *a = *b;
    *b = *c;
}


void swap_ref(double &a, double &b)
{
    // Takes in the addresses for two doubles and changes their values.
    double c;
    c = a;
    a = b;
    b = c;
}