#include <iostream>
#include <fstream>
#include <cassert>
#include "armadillo.hpp"

int classifyPoint(arma::mat data, arma::rowvec point, int k=5);

int main()
{   
    int n_rows = 200;
    int n_cols = 34;
    arma::vec yData;
    arma::mat xData;
    arma::mat xTest;

    yData.load("/home/niko/Dropbox/KU/5 Year/AppliedProgramming/assignment4/dataY.dat", arma::raw_ascii);
    xData.load("/home/niko/Dropbox/KU/5 Year/AppliedProgramming/assignment4/dataX.dat", arma::raw_ascii);
    xTest.load("/home/niko/Dropbox/KU/5 Year/AppliedProgramming/assignment4/dataXtest.dat", arma::raw_ascii);

    classifyPoint(xData, xTest.row(0), 5);
    return 0;
}

int classifyPoint(arma::mat data, arma::rowvec point, int k)
{
    arma::mat diff(data);
    for (int i=0; i<data.n_rows; i++)
    {
        diff.row(i) -= point;
    }

    for (int i=0; i<34; i++)
    {
        std::cout << data.row(0)[i] << " - " << point[i] << " = "
                  << diff.row(0)[i]
                  << "\n";
    }
    return 0;
}