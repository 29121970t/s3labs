#include <consoleUtils.hh>
#include <functional>
#include <l5/include/vector.hh>
#include <l5/include/screens.hh>


#include <iostream>
#include <memory>


using namespace std;
using namespace console_utils;
using namespace screens;

int main(void) {
    vec::Vector<double> vec1;
    vec::Vector<double> vec2;
    static array<function<bool()>, 5> actions = {
        [&vec1]() { return inputVector(vec1); },
        [&vec2]() { return inputVector(vec2); },
        [&vec1, &vec2]() { return printVectors(vec1, vec2); },
        [&vec1, &vec2]() { return addVectors(vec1, vec2); },
        []() { return false; },

    };
    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 5; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1]());

    return 0;
}
