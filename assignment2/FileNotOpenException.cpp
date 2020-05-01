#include <iostream>
#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string probString) : Exception("FILE", probString)
{
    setProb(probString);
    setTag("FILE");
}