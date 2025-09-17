#include <functional>

#include "../../lib/consoleUtils.hh"
#include "screens.hh"
#include "string.hh"

using namespace std;
using namespace console_utils;
using namespace screen_handlers;

int main(void) {
    str::string str1;
    str::string str2;
    array<function<bool(str::string &, str::string &)>, 4> actions = {
        inputStrings, printStrings, checkOperators, [](const str::string &, const str::string &) { return 0; }};

    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1](str1, str2));

    return 0;
}