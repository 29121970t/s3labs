#include <consoleUtils.hh>
#include <ctime>
#include <iomanip>
#include <l5/include/vector.hh>
#include <l7/include/busService.hh>
#include <print>
#include <chrono>

using namespace std;
using namespace vec;
using namespace str;
using namespace bus_service;
using namespace console_utils;

namespace screens {
void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 5\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Print bus services");
    println("    2.Find service by departure time");
    println("    3.Exit");
}
bool printFlights(vec::Vector<BusService> &vec) {
    for (size_t i = 0, count = vec.count(); i < count; ++i) {
        cout << vec[i].dump() << endl;
    }
    return true;
}
bool getByDepartureTime(Vector<BusService> &buses) {
    String str;
    std::chrono::sys_seconds timePoint = {};
    readT(timePoint, "Please enter time in DD-MM-YYYY HH:MM UTC+3 format: ", "%d-%m-%Y %H:%M");  
    time_t departure = std::chrono::system_clock::to_time_t(timePoint);
    auto vec = BusService::getByDepartureTime(departure, buses);
    print("Found {} Buses:\n", vec.count());
    for (size_t i = 0, count = vec.count(); i < count; ++i)
    {
        cout << vec[i]->dump() << endl;
    }
    cout << endl;
    
    return true;
}
}  // namespace screens
