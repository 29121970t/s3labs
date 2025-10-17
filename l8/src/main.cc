#include <consoleUtils.hh>
#include <iostream>
#include <l8/include/list.hh>
#include <l8/include/list_algorithm.hh>
#include <l8/include/screens.hh>
#include <functional>

using namespace std;
using namespace screens;
using namespace console_utils;
int main(void) {

    cList::CircleList<double> list;

    static array<function<bool()>, 7> actions = {
        [&list]() { return inputList(list); },
        [&list]() { return addElement(list); },
        [&list]() { return clearList(list); },
        [&list]() { return sortList(list); },
        [&list]() { return findElement(list); },
        [&list]() { return printList(list); },

        []() { return false; },

    };
    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 7; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1]());


    return 0;
}
