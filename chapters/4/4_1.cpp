#include <iostream>

int main()
{
    // Declare int and pointer to that ints address.
    int i = 5;
    int* p_j = &i;

    std::cout << "first output for i and p_j:\n";
    std::cout << i << ", " << p_j << "\n";

    // Multiply contents of int using only pointers:
    // We de-reference p_j, and set it to the de_referencing of p_j,,, times 5.
    *p_j = *p_j * 5;
    
    std::cout << "new value for i, by de-referencing of pointer:\n" 
              << i << "\n";

    // Declare new dynamically allocated integer
    int* p_k;
    p_k = new int;

    // Store the value of i in this new address.
    *p_k = i;

    std::cout << "Address p_k and the value it points to.\n";
    std::cout << p_k << ", " << *p_k << "\n";

    // Change value pointed to, by p_j, to 0:
    *p_j = 0;

    // Check that the program is outputting correctly:
    // I assume that i=0, since p_j points to i, and we've change the value at
    // this address to be 0. Similarly I assume p_k to point to a value of 25
    // (5*5), since this is the value of i (pointed to by p_j), at the time of
    // assignment.
    std::cout << "final output. Should be 0 0 25:\n" 
              << i << " " << *p_j << " " << *p_k << "\n";

    return 0;
}