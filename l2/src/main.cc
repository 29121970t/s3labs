#include <consoleUtils.hh>
#include <functional>
#include <l2/include/screens.hh>
#include <l2/include/string.hh>

using namespace std;
using namespace console_utils;
using namespace screen_handlers;

int main(void) {
    str::String str1;
    str::String str2;
    array<function<bool(str::String &, str::String &)>, 4> actions = {
        inputStrings, printStrings, checkOperators, [](const str::String &, const str::String &) { return 0; }};

    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1](str1, str2));

    return 0;
}