#include <gtest/gtest.h>
#include "../src/matrixV.hh"

TEST(Creation, Subtest_1) {
    mat::matrix<double> mat1;
    mat::matrix<float> mat2{2 ,3};
}


