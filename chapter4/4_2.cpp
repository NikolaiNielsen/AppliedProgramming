#include <iostream>

int main()
{
    int i=5, j=2;

    int *p_i=&i, *p_j=&j, *p_k;
    p_k = new int;
    std::cout << p_i << "\n" << *p_i << "\n" << p_j << "\n" << *p_j << "\n";
    *p_k = *p_i;
    *p_i = *p_j;
    *p_j = *p_k;
    std::cout << p_i << "\n" << *p_i << "\n" << p_j << "\n" << *p_j << "\n";

    return 0;
}