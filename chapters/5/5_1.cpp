#include <iostream>


int addressToValue(int *a);

int main()
{
    // Write code that send the address of an integer to a function, and then
    // prints out the value of that integer
    int a = 3;
    int *p_a = &a;
    std::cout << addressToValue(p_a) << "\n";

    return 0;
}

int addressToValue(int* a)
{
    return *a;
}