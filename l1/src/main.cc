#include "matrixV.hh"
#include <vector>
#include <iostream>

int main(int argc, char const* argv[]) {
    mat::matrix<double> mat1 = {{1}, {2}};

    mat1 = {{1, 2, 3}, {1, 2, 3}};
    mat1.print();
    mat1.getElement(1, 1) = 0;
    mat1.print();


    return 0;
}