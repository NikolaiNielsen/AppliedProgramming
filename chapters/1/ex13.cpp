#include <iostream>
#include <cmath>

double dot_product(double v1[3], double v2[3]);

int main() {

    double v1[3], v2[3];
    double dot_prod, norm1, norm2;
    
    std::cout << "Input coordinates for v1\n";
    std::cin >> v1[0] >> v1[1] >> v1[2];
    std::cout << "And for v2\n";
    std::cin >> v2[0] >> v2[1] >> v2[2];

    std::cout << "Scalar product is\n";
    dot_prod = dot_product(v1, v2);
    norm1 = sqrt(v1[0]*v1[0] + v1[1]*v1[1] + v1[2]*v1[2]);
    norm2 = sqrt(v2[0]*v2[0] + v2[1]*v2[1] + v2[2]*v2[2]);
    std::cout << dot_prod << "\nNorm 1 and 2 is\n";
    std::cout << norm1 << "\n" << norm2 << "\n";
    return 0;
};

double dot_product(double v1[3], double v2[3]) {
    double result = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    return result;
};
