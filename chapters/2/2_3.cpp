#include <iostream>
#include <cassert>

int main()
{
    // initialize total to 1 and count to -1 to offset for the exit statement
    int total=1, count=-1, input=0;

    while (input != -1)
    {
        std::cin >> input;
        total += input;
        count ++;
    };

    assert(count>0);
    std::cout << "total: " << total << " count: " << count << "\n";
    std::cout << "average is " << (double (total)) / (double (count)) << "\n";
    return 0;
}