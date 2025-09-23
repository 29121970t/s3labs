#include <consoleUtils.hh>
#include <functional>
#include <l4/include/carrier.hh>
#include <l4/include/screens.hh>
#include <memory>

using namespace std;
using namespace console_utils;
using namespace screens;

int main(void) {
    unique_ptr<carriers::Carrier> carryPtr;
    static array<function<bool()>, 4> actions = {
        [&carryPtr]() { return createCarrier(carryPtr); },
        [&carryPtr]() { return printCarrier(carryPtr.get()); },
        [&carryPtr]() { return calculate(carryPtr.get()); },
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