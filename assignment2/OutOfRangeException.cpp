#include <iostream>
#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string probString) : Exception("RANGE", probString)
{
    setProb(probString);
    setTag("RANGE");
}