#include <iostream>

void swap_pointer(double *a, double *b);
void swap_ref(double &a, double &b);


int main(){
    double x=2.5, y=3.1;

    std::cout << x << " " << y << "\n";
    swap_ref(x, y);
    std::cout << x << " " << y << "\n";

    return 0;
}


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