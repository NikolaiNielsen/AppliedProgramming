#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char *argv[])
{
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    // Extend the code above to print the arrays x and y to a file called x_and_y.dat so that the data file has the four elements of x on the top line, and the four elements of y on the next line.

    std::ofstream write_output("x_and_y.dat");
    assert(write_output.is_open());  

    // write the first line and add a new line
    for (int i = 0; i<4; i++)
    {
        write_output << x[i] << " ";
    }
    write_output << "\n";

    // write second line
    for (int i = 0; i < 4; i++)
    {
        write_output << y[i] << " ";
    }
    write_output << "\n";

    return 0;
}