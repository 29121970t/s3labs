#include <consoleUtils.hh>
#include <functional>
#include <l3/include/airplane.hh>
#include <l3/include/car.hh>
#include <l3/include/screens.hh>
#include <l3/include/train.hh>
#include <memory>

using namespace std;
using namespace carriers;
using namespace console_utils;
using namespace screens;

int main(void) {
    unique_ptr<Carrier> carry_ptr;
    static array<move_only_function<bool()>, 4> actions = {
        [&carry_ptr]() { return createCarrier(carry_ptr); },
        [&carry_ptr]() { return printCarrier(carry_ptr.get()); },
        [&carry_ptr]() { return calculate(carry_ptr.get()); },
        []() { return false; },

    };

    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1]());

    return 0;
}