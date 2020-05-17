#include <iostream>
#include <fstream>
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

    // Learning rate
    double alpha = 0.5;

    // cutoff
    double epsilon = 1e-7;
    int N=1000000;

    // Run gradient descent
    for (int i=0; i<N; i++)
    {
        arma::colvec g = grad(xData, w, yData);
        auto norm = arma::norm(g);
        if ((double)(norm) < epsilon)
        {
            // std::cout << "epsilon reached. i=" << i << "\n";
            break;
        }
        w = w - alpha*g;
    }
    
    // Collect results
    std::ofstream out_file("./LogReg.dat");
    for (int i=0; i<xTest.n_rows; i++)
    {
        auto f = arma::dot(w, xTest.row(i));
        if (f>0)
        {
            out_file << 1 << "\n";
        }
        else
        {
            out_file << -1 << "\n";
        }
        
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