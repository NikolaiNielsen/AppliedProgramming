#include <iostream>

int main()
{
    int i = 5;
    int* p_j = &i;

    std::cout << i << "\n" << p_j << "\n";

    *p_j = *p_j * 5;
    std::cout << i << "\n";

    int* p_k;
    p_k = new int;

    *p_k = i;

    std::cout << p_k << "\n" << *p_k << "\n";

    return 0;
}