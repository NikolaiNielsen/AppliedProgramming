#include <iostream>
#include <fstream>
#include <cassert>
#include "armadillo.hpp"
#include <cmath>

arma::colvec grad(arma::mat data, arma::colvec w, arma::colvec labels);

int main()
{
    arma::vec yData;
    arma::mat xData;
    arma::mat xTest;

    // import the data
    yData.load("./dataY.dat", arma::raw_ascii);
    xData.load("./dataX.dat", arma::raw_ascii);
    xTest.load("./dataXtest.dat", arma::raw_ascii);

    // Create initial w
    arma::colvec w;
    w.zeros(34);

    arma::colvec g1 = grad(xData, w, yData);
    
    arma::colvec g2;
    g2.zeros(34);
    for (int i = 0; i < xData.n_rows; i++)
    {
        g2 += yData[i] * 0.5 * xData.row(i).t();
    }
    g2 = -g2/xData.n_rows;

    for (int i=0; i< 34; i++)
    {
        std::cout << g1[i] - g2[i] << "\n";
    }

    return 0;
}

arma::colvec grad(arma::mat data, arma::colvec w, arma::colvec labels)
{
    // Initialize result to 0
    arma::colvec res(w.n_rows);
    res.zeros(w.n_rows);
    
    for (int i=0; i<data.n_rows; i++)
    {
        auto factor = 1.0/(1+exp(labels[i] * arma::dot(w, data.row(i))));
        res += labels[i] * factor * data.row(i).t();
    }

    return -res/data.n_rows;
}