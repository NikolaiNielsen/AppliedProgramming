#include <iostream>
#include <fstream>
#include <cassert>
#include "armadillo.hpp"

int classifyPoint(arma::mat data, arma::rowvec point, arma::vec labels, 
                  int k=5);

int main()
{   
    arma::vec yData;
    arma::mat xData;
    arma::mat xTest;

    // import the data
    yData.load("./dataY.dat", arma::raw_ascii);
    xData.load("./dataX.dat", arma::raw_ascii);
    xTest.load("./dataXtest.dat", arma::raw_ascii);

    // Create
    std::ofstream out_file("./NN.dat");
    assert(out_file.is_open());
    for (int i=0; i<xTest.n_rows; i++)
    {
        int res = classifyPoint(xData, xTest.row(i), yData);
        out_file << res << "\n";
    }
    out_file.close();
    

    return 0;
}

int classifyPoint(arma::mat data, arma::rowvec point, arma::vec labels, int k)
{
    // Subract point from each row
    arma::mat diff(data);
    for (int i=0; i<data.n_rows; i++)
    {
        diff.row(i) -= point;
    }

    // square each element
    arma::mat prod = diff % diff;
    
    // sum of each row
    arma::vec dist = arma::sum(prod, 1);

    // Square root of each element
    dist.for_each( [](arma::mat::elem_type& val) {sqrt(val);});

    // Allocate matrix of pairs. 
    arma::vec sorted_labels(labels.n_rows);

    // the first element of indices is the index of the lowest element in
    // dist. So if indices[0] = 94, then the smallest element in dist is
    // dist[94].
    arma::uvec indices = arma::sort_index(dist);

    // To get the label for the point, we sum up the first k labels (sorted
    // ascending, according to dist), and take the sign of the result as the
    // label. This can be done since the labels are either 1 or -1.
    double summer = 0;
    for (int i=0; i<k; i++)
    {
        summer += labels[indices[i]];
    }
    if (summer > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}