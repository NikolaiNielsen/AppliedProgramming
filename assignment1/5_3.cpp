#include <iostream>
#include "5_3.h"

void swap_pointer(double *a, double *b)
{
    double *c;
    c = new double;
    *c = *a;
    *a = *b;
    *b = *c;
}


void swap_ref(double &a, double &b)
{
    double c;
    c = a;
    a = b;
    b = c;
}