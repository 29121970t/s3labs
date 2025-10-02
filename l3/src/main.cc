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
    unique_ptr<Carrier> carry_pt;
    static array<function<bool()>, 4> actions = {
        [&carry_pt]() { return createCarrier(carry_pt); },
        [&carry_pt]() { return printCarrier(carry_pt.get()); },
        [&carry_pt]() { return calculate(carry_pt.get()); },
        []() { return false; },

    };

    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int number) { return number > 0 && number <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1]());

    return 0;
}