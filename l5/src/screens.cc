#include <consoleUtils.hh>
#include <l5/include/vector.hh>
#include <limits>
#include <memory>
#include <print>
#include <sstream>

using namespace std;
using namespace vec;
using namespace console_utils;

namespace screens {
void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 5\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Input first vector");
    println("    2.Input second vector");
    println("    3.Print vectors");
    println("    4.Add");
    println("    5.Exit");
}

bool inputVector(Vector<double> &vec) {
    string line;
    print("Please enter vector (numbers separated by spaces): ");
    getline(std::cin, line);
    istringstream iss(line);
    double num;
    vec::Vector<double> tmpVec;
    while (iss >> num) {
        tmpVec.pushBack(num);
    }
    cin.clear();
    cout << tmpVec;
    vec = std::move(tmpVec);
    return true;
}
bool addVectors(Vector<double> &vec1, Vector<double> &vec2) {
    print("addition result: ");
    try {
        cout << vec1 + vec2 << endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return true;
}
bool printVectors(Vector<double> &vec1, Vector<double> &vec2) {
    cout << vec1 << endl;
    cout << vec2 << endl;
    return true;
}
}  // namespace screens
