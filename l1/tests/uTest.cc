#include <gtest/gtest.h>

#include <iostream>

#include "../src/matrix.hh"

using namespace std;
TEST(Creation_Test, Subtest_1) { mat::Matrix mat; }

TEST(Creation_Test, Subtest_3) {
    mat::Matrix mat = {{1, 2, 4}, {4, 1, 3}};
    array<array<double, 3>, 2> arr = {{{1, 2, 4}, {4, 1, 3}}};
    for (size_t i = 0; i < mat.getRows(); i++) {
        for (size_t j = 0; j < mat.getCols(); j++) {
            ASSERT_EQ(mat.getElement(i, j), arr[i][j]);
        }
    }
}
TEST(Creation_Test, Subtest_4) {
    mat::Matrix mat{2, 3};
    mat = {{1, 2, 4}, {4, 1, 3}};
    array<array<double, 3>, 2> arr = {{{1, 2, 4}, {4, 1, 3}}};
    for (size_t i = 0; i < mat.getRows(); i++) {
        for (size_t j = 0; j < mat.getCols(); j++) {
            ASSERT_EQ(mat.getElement(i, j), arr[i][j]);
        }
    }
}
TEST(Creation_Test, Subtest_5) {
    mat::Matrix mat{2, 3};
    EXPECT_THROW((mat = {{1, 2, 4}, {4, 1}}), std::invalid_argument);
}

TEST(Insetrion_Tests, Subtest_1) {
    mat::Matrix mat;
    mat.insert({{1, 312, 4, 54, 32}, {213, 4, 42, 1, 2}});
    array<array<double, 5>, 2> arr = {{{1, 312, 4, 54, 32}, {213, 4, 42, 1, 2}}};
    for (size_t i = 0; i < mat.getRows(); i++) {
        for (size_t j = 0; j < mat.getCols(); j++) {
            ASSERT_EQ(mat.getElement(i, j), arr[i][j]);
        }
    }
}
TEST(Insetrion_Tests, Subtest_2) {
    mat::Matrix mat;
    EXPECT_THROW((mat.insert({{1, 312}, {213, 4, 42, 1, 2}})), std::invalid_argument);
}

TEST(Printing_Tests, Subtest_1) {
    mat::Matrix mat = {{1, 2, 5}, {7, 7, 7}, {9, 0, 1}};
    testing::internal::CaptureStdout();
    mat.print();
    string out = testing::internal::GetCapturedStdout();
    EXPECT_EQ(out, "|1 2 5|\n|7 7 7|\n|9 0 1|\n");
}

TEST(Subtraction_test, 1) {
    mat::Matrix mat = {{1, 2, 5}, {7, 7, 7}, {9, 0, 1}};
    array<array<double, 3>, 3> arr = {{{0, 2, 5}, {7, 5, 7}, {9, 1, 1}}};
    mat.subtractFromElement(0, 0, 1);
    mat.subtractFromElement(1, 1, 2);
    mat.subtractFromElement(2, 1, -1);
    for (size_t i = 0; i < mat.getRows(); i++) {
        for (size_t j = 0; j < mat.getCols(); j++) {
            ASSERT_EQ(mat.getElement(i, j), arr[i][j]);
        }
    }
}