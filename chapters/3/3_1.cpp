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

    // 4:Amend the program so that it does not automatically create a fresh
    // file x_and_y.dat every time it is run. Have the program first attempt to
    // open the file x_and_y.dat as an ifstream for reading. If the file can be
    // successfully opened then, after closing the ifstream, warn the user.
    // Have the program prompt the user as to whether it should erase the
    // existing file or append to the existing file.

    std::ifstream read_file("x_and_y.dat");
    bool exists = read_file.is_open();
    read_file.close();

    int ans;
    if (exists)
    {
        std::cout << "file already exists. Erase (1) or append (2)?\n";
        std::cin >> ans;
    }

    std::ofstream write_output; // Declare the ofstream, but don't open it yet.
    if (ans == 1)
    {
        std::cout << "Erasing\n";
        write_output.open("x_and_y.dat"); // open the ofstream in erase mode
    }
    else if (ans == 2)
    {
        std::cout << "Appending\n";
        write_output.open("x_and_y.dat", std::ios::app); // append
    }
    else
    {
        std::cout << "Didn't recognize. Erasing. \n";
        write_output.open("x_and_y.dat"); // erase
    }

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