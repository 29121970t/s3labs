#include <gtest/gtest.h>
#include "../src/matrixV.hh"
#include <iostream>

TEST(Creation_Test, Subtest_1) {
    mat::matrix<double> mat;
}
TEST(Creation_Test, Subtest_2) {
    mat::matrix<int> mat{ 100, 22 };
    ASSERT_EQ(mat.getRows(), 100);
    ASSERT_EQ(mat.getCols(), 22);
    for (size_t i = 0; i < mat.getRows(); i++) {
        ASSERT_EQ(mat[i].size(), 22);
    }
}
TEST(Creation_Test, Subtest_3) {
    mat::matrix<float> mat = { {1, 2, 4}, {4, 1, 3} };
    std::array<std::array<float, 3>, 2> arr = {{ {1, 2, 4}, {4, 1, 3} }};
    for (size_t i = 0; i < mat.getRows(); i++) {
        for (size_t j = 0; j < mat.getCols(); j++) {
            ASSERT_EQ(mat[i][j], arr[i][j]);
        }
    }
}
TEST(Creation_Test, Subtest_4) {
    mat::matrix<unsigned> mat{ 2, 3 };
    mat = { {1, 2, 4}, {4, 1, 3} };
    std::array<std::array<unsigned, 3>, 2> arr = {{ {1, 2, 4}, {4, 1, 3} }};
    for (size_t i = 0; i < mat.getRows(); i++) {
        for (size_t j = 0; j < mat.getCols(); j++) {
            ASSERT_EQ(mat[i][j], arr[i][j]);
        }
    }
}
TEST(Creation_Test, Subtest_5) {
    mat::matrix<unsigned> mat{ 2, 3 };
    EXPECT_THROW((mat = { {1, 2, 4}, {4, 1} }), std::invalid_argument);
}

TEST(Insetrion_Tests, Subtest_1) {
    mat::matrix<long> mat;
    mat.insert({ {1, 312, 4, 54, 32}, {213, 4, 42, 1, 2} });
    std::array<std::array<long, 5>, 2> arr = {{ {1, 312, 4, 54, 32}, {213, 4, 42, 1, 2} }};
    for (size_t i = 0; i < mat.getRows(); i++) {
        for (size_t j = 0; j < mat.getCols(); j++) {
            ASSERT_EQ(mat[i][j], arr[i][j]);
        }
    }

}
TEST(Insetrion_Tests, Subtest_2) {
    mat::matrix<long> mat;
    EXPECT_THROW((mat.insert({ {1, 312}, {213, 4, 42, 1, 2} })), std::invalid_argument);
}

TEST(Printing_Tests, Subtest_1) {
    mat::matrix<long> mat = { {1, 2, 5}, {7, 7, 7}, {9, 0, 1} };
    testing::internal::CaptureStdout();
    mat.print();
    std::string out = testing::internal::GetCapturedStdout();
    EXPECT_EQ(out, "1 2 5 \n7 7 7 \n9 0 1 \n");
}






