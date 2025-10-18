#include <consoleUtils.hh>
#include <l8/include/list.hh>
#include <l8/include/list_algorithm.hh>
#include <print>

using namespace std;

using namespace console_utils;

namespace screens {
void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 8\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Input List");
    println("    2.Add element");
    println("    3.Clear List");
    println("    4.Sort List");
    println("    5.Find element");
    println("    6.Print list");
    println("    7.Exit");
}
bool inputList(cList::CircleList<double> &list) {
    list.erase();
    size_t num;
    readT(num, "Plese enter list length:", [](size_t number) { return number > 0; }, "Number should be > 0\n");
    for (size_t i = 0; i < num; i++) {
        double data;
        readT(data, "Plese enter list element:");
        list.pushBack(data);
    }
    return true;
}
bool addElement(cList::CircleList<double> &list) {
    double data;
    readT(data, "Plese enter list element:");
    list.pushBack(data);
    return true;
}
bool clearList(cList::CircleList<double> &list) {
    list.erase();
    return true;
}
bool sortList(cList::CircleList<double> &list) {
    cList::bubbleSort(list.begin(), list.end());
    return true;
}
bool findElement(cList::CircleList<double> &list) {
    double data;
    readT(data, "Plese enter list element:");
    
    if (auto res = cList::find(list.begin(), list.end(), data); res == list.end()) {
        std::cout << "No such element\n";
    } else {
        std::cout << "List contains element\n";
    }
    return true;
}
bool printList(const cList::CircleList<double> &list) {
    std::cout << list << '\n';

    return true;
}
}  // namespace screens
