#include <iostream>

void changeValueOfAddress(int* a);

int main()
{
    // write code that send the address of an integer to a function that
    // changes the value of the integer.
    int i = 4;
    std::cout << i << "\n";
    changeValueOfAddress(&i);
    std::cout << "new value " << i << "\n";
    return 0;
}

void changeValueOfAddress(int* a)
{
    *a = 2;
}