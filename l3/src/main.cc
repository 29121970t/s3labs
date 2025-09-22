#include <consoleUtils.hh>
#include <format>
#include <functional>
#include <iostream>
#include <l3/include/airplane.hh>
#include <l3/include/car.hh>
#include <l3/include/screens.hh>
#include <l3/include/train.hh>
#include <memory>
#include <print>

using namespace std;
using namespace carriers;
using namespace console_utils;
using namespace screens;

int main(void) {
    unique_ptr<Carrier> carry_ptr;
    static array<function<bool(unique_ptr<Carrier> &)>, 4> actions = {createCarrier, printCarrier, calculate,
                                                                      [](const unique_ptr<Carrier> &) { return 0; }};
    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1](carry_ptr));

    return 0;
}