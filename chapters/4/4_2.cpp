#include <iostream>

int main()
{
    // Assign values to two integer variables
    int i=5, j=2;

    // 3 new pointers. p_i and p_j point to i and j, respectively
    int *p_i=&i, *p_j=&j, *p_k;

    // dynamically allocate p_k
    p_k = new int;

    // print out some addresses and references
    std::cout << "p_i and what it points to (i):\n";
    std::cout << p_i << ", " << *p_i << "\n";
    std::cout << "p_j and what it points to (j):\n";
    std::cout << p_j << ", " << *p_j << "\n";

    // swap the values of i and j, using only pointers!
    *p_k = *p_i;
    *p_i = *p_j;
    *p_j = *p_k;

    // check if it works
    std::cout << "after swapping values:\n";
    std::cout << "p_i and what it points to (i):\n";
    std::cout << p_i << ", " << *p_i << "\n";
    std::cout << "p_j and what it points to (j):\n";
    std::cout << p_j << ", " << *p_j << "\n";

    return 0;
}