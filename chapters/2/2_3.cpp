#include <iostream>
#include <cassert>

int main()
{

    int total=0, count=0, input=0;

    while (true)
    {
        std::cin >> input;
        if (input == -1)
        {
            break;
        }
        total += input;
        count ++;
    };

    assert(count>0);
    std::cout << "total: " << total << " count: " << count << "\n";
    std::cout << "average is " << (double (total)) / (double (count)) << "\n";
    return 0;
}