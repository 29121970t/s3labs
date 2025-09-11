#include <functional>
#include <iostream>
#include <limits>

#include "matrix.hh"
#include "stringUtils.hh"

using namespace std;
using namespace strUtils;
void inputMatrix(mat::matrix<double>& mat) {
    size_t rows, cols;
    auto check = [](size_t num) { return num > 0; };
    readT(rows, "Please enter number of matrix rows: ", check);
    readT(cols, "Please enter number of matrix collumns: ", check);

    mat.resize(rows, cols);
    cout << rows << " " << cols;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            double element;
            stringstream strNumStream;
            strNumStream << "Please enter element with index [" << i + 1 << ']' << '[' << j + 1 << "]:";
            readT(element, strNumStream.str());
            mat.setElement(i, j, element);
        }
    }
}
void printMatrix(const mat::matrix<double>& mat) { mat.print(); }

void subtractFromElement(mat::matrix<double>& mat) {
    auto check = [](size_t num) { return num > 0; };
    size_t row, col;
    double op;
    readT(
        row, "Please enter elemet row: ", [&mat](size_t& num) { return num > 0 && num <= mat.getRows(); },
        "Invalid value\n");
    readT(
        col, "Please enter elemet collumn: ", [&mat](size_t& num) { return num > 0 && num <= mat.getCols(); },
        "Invalid value\n");
    readT(op, "Please enter number to subtruct: ");
    mat.subtractFromElement(row - 1, col - 1, op);
}

void printCentered(const string& str) {
    pair<int, int> dimensions = getConsoleDimensions();
    cout << string((dimensions.first - str.length()) / 2, ' ') << str << endl;
}
string offest(size_t offset) { return string(offset, ' '); }
void printMainScreen() {
    printCentered("\x1b[48;5;35mLab 1\x1b[0m");
    cout << "Please select action:" << endl << endl;
    cout << offest(4) << "1.Input matrix" << endl;
    cout << offest(4) << "2.Print matrix" << endl;
    cout << offest(4) << "3.Subtruct from matrix element" << endl;
    cout << offest(4) << "4.Exit" << endl;
}

int main(void) {
    mat::matrix<double> matrix;
    array<function<void(mat::matrix<double>&)>, 4> actions = {inputMatrix, printMatrix, subtractFromElement,
                                                              [](mat::matrix<double>& a) { exit(0); }};
    while (true) {
        printMainScreen();
        unsigned int response;
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x1b[2J\x1b[H";
        actions[response - 1](matrix);
    }
}