#include <functional>
#include <iostream>
#include <limits>
#include <print>
#include "matrix.hh"
#include "stringUtils.hh"

using namespace std;
using namespace strUtils;
void inputMatrix(mat::matrix<double>& mat) {
    size_t rows;
    size_t cols;
    auto check = [](size_t num) { return num > 0; };
    readT(rows, "Please enter number of matrix rows: ", check);
    readT(cols, "Please enter number of matrix collumns: ", check);

    mat.resize(rows, cols);
    cout << rows << " " << cols;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            double element;
            readT(element, format("Please enter element with index [{}][{}]",i + 1, j+1 ));
            mat.setElement(i, j, element);
        }
    }
}
void printMatrix(const mat::matrix<double>& mat) { mat.print(); }

void subtractFromElement(mat::matrix<double>& mat) {
    size_t row;
    size_t col;
    double op;
    readT(
        row, "Please enter elemet row: ", [&mat](const size_t& num) { return num > 0 && num <= mat.getRows(); },
        "Invalid value\n");
    readT(
        col, "Please enter elemet collumn: ", [&mat](const size_t& num) { return num > 0 && num <= mat.getCols(); },
        "Invalid value\n");
    readT(op, "Please enter number to subtruct: ");
    mat.subtractFromElement(row - 1, col - 1, op);
}

string offest(size_t offset) { return string(offset, ' '); }
void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 1\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Input matrix");
    println("    2.Print matrix");
    println("    3.Subtruct from matrix element");
    println("    4.Exit");
}

int main(void) {
    mat::matrix<double> matrix;
    array<function<void(mat::matrix<double>&)>, 4> actions = {inputMatrix, printMatrix, subtractFromElement,
                                                              [](mat::matrix<double>&) { exit(0); }};
    while (true) {
        printMainScreen();
        unsigned int response;
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
        actions[response - 1](matrix);
    }
}