#include <consoleUtils.hh>
#include <fstream>
#include <functional>
#include <l5/include/vector.hh>
#include <l7/include/busService.hh>
#include <l7/include/screens.hh>
#include <memory>

using namespace std;
using namespace console_utils;
using namespace screens;
using namespace bus_service;

int main(void) {
    std::ifstream in("data.bin", ios::binary);
    if (!in.is_open()) {
        cout << "No data file provided. Please place one near executable" << endl;
        return 1;
    }
    size_t num;
    in >> num;
    if (in.fail()) {
        cout << "Data file is not valid." << endl;
        return 1;
    }
    vec::Vector<BusService> vec{num};
    static array<function<bool()>, 4> actions = {
        [&vec]() { return printFlights(vec); },
        []() { return getByDepartureTime(); },
        []() { return false; },
    };

    for (size_t i = 0; i < num; ++i) {
        in >> vec[i];
    }
    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int numb) { return numb > 0 && numb <= 3; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1]());
    in.close();
    return 0;
}
