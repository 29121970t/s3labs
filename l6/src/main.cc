#include <functional>
#include <l3/include/carrier.hh>
#include <l6/include/screens.hh>
#include <l6/include/throwingConsoleUtils.hh>
#include <memory>

using namespace std;
using namespace carriers;
using namespace console_utils;
using namespace screens;

int main(void) {
    unique_ptr<Carrier> carry_ptr;
    static array<function<bool()>, 4> actions = {
        [&carry_ptr]() { return createCarrier(carry_ptr); },
        [&carry_ptr]() { return printCarrier(carry_ptr.get()); },
        [&carry_ptr]() { return calculate(carry_ptr.get()); },
        []() { return false; },

    };

    unsigned int response;
    do {
        bool failed;
        printMainScreen();
        do  {
            failed = false;
            try {
                readT(response, ">", [](unsigned int number) { return number > 0 && number <= 4; });
            } catch (const std::runtime_error& e) {
                std::cerr << e.what() << '\n';
                failed = true;
            }
        }while (failed);
        cout << "\x{1B}[2J\x{1B}[H\n";

    } while (actions[response - 1]());

    return 0;
}