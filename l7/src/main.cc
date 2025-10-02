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
    auto tp = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(tp);
    ofstream out("data.bin", std::ios::binary);
    if (!out.is_open()) {
        cout << "Cannot create data file" << endl;
        return 1;
    }
    out << 3;
    BusService b1{"Brest", time, time + 60 * 60 * 3, 1};
    BusService b2{"Hrodno", time, time + 60 * 60, 2};
    BusService b3{"Hrodno", time + 60 * 20, time + 60 * 30, 3};
    out << b1 << b2 << b3;
    out.close();
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
        [&vec]() { return getByDepartureTime(vec); },
        []() { return false; },
    };

    for (size_t i = 0; i < num; ++i) {
        in >> vec[i];
        if (in.fail()) {
            cout << "Data file is not valid." << endl;
            return 1;
        }
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
