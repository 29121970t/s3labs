#include <iostream>
#include <limits>
#include <vector>

#include "matrix.hh"

size_t readSize_t(const std::string & massage) {
    std::cout << massage;
    size_t resp;
    while (!(std::cin >> resp) || resp == 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer graeter then 0: ";
    }
    return resp;
}

int main(int argc, char const* argv[]) {
    std::string mainScreenText =
        "Lab 1\nPlease select action:\n1.Input matrix\n2.Print matrix\n3.Subtruct from matrix element\n:";

    std::cout << mainScreenText;

    size_t resp;

    size_t rowCount = readSize_t("Please enter row count:");
    size_t colCount = readSize_t("Please enter collumn count:");

    mat::matrix<double> matrix{rowCount, colCount};

    for (size_t i = 0; i < rowCount; i++)
    {
        std::cout << "Please enter " << i+1 << "-th line of matrix:";
        for (size_t j = 0; j < colCount; j++)
        {
            std::cin >> matrix.getElement(i, j);
        }
    }
    


    switch (resp) {
        case 1:
            /* code */
            break;

        default:
            break;
    }

    return 0;
}