#include <functional>
#include <iostream>
#include <limits>
#include <print>

#include "screens.hh"
#include "string.hh"
#include "consoleUtils.hh"

using namespace std;
using namespace console_utils;
using namespace screen_handlers;

int main(void) {
    str::string str1;
    str::string str2;
    array<function<void(str::string &, str::string &)>, 4> actions = {
        inputStrings, printStrings, checkOperators, [](const str::string &, const str::string &) { exit(0); }};
    while (true) {
        printMainScreen();
        unsigned int response;
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
        actions[response - 1](str1, str2);
    }

    return 0;
}