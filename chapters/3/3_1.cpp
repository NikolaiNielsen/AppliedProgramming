#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char *argv[])
{
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    // 1: Extend the code above to print the arrays x and y to a file called 
    // x_and_y.dat so that the data file has the four elements of x on the top 
    // line, and the four elements of y on the next line.

    // 2: Extend the code so that the output stream is flushed immediately after
    // each line of the file is written.

    // 3: Extend the code so that the precision is set to 10 significant
    // figures, the output is in scientific notation, and plus signs are shown
    // for positive numbers.


    std::ofstream write_output("x_and_y.dat");
    write_output.setf(std::ios::scientific);    // 3.1.3
    write_output.setf(std::ios::showpos);       // 3.1.3
    write_output.precision(10);                 // 3.1.3

    assert(write_output.is_open());  

    // write the first line and add a new line
    for (int i = 0; i<4; i++)
    {
        write_output << x[i] << " ";
    }
    write_output << "\n";
    write_output.flush(); // 3.1.2

    // write second line
    for (int i = 0; i < 4; i++)
    {
        write_output << y[i] << " ";
    }
    write_output << "\n";
    write_output.flush(); // 3.1.2

    write_output.close();
    return 0;
}