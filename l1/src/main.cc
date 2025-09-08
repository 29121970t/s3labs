#include "matrixV.hh"
#include <vector>
#include <iostream>

int main(int argc, char const* argv[]) {
    mat::matrix<unsigned> mat{2, 3};
    mat = { {1, 2, 4}, {4, 1, 3} };
    std::vector<unsigned> p = mat[1];
    
    return 0;
}