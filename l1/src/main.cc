#include <functional>

#include "../../lib/consoleUtils.hh"
#include "matrix.hh"
#include "screens.hh"

using namespace std;
using namespace console_utils;
using namespace screen_handlers;

int main(void) {
    mat::Matrix matrix;
    array<function<bool(mat::Matrix&)>, 4> actions = {inputMatrix, printMatrix, subtractFromElement,
                                                      [](const mat::Matrix&) { return 0; }};
    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1](matrix));
    return 0;
}