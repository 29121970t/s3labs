#include <consoleUtils.hh>
#include <l3/include/airplane.hh>
#include <l3/include/car.hh>
#include <l3/include/carrier.hh>
#include <l3/include/screens.hh>
#include <l3/include/train.hh>
#include <print>

using namespace console_utils;
using namespace std;
using namespace carriers;

namespace screens {
void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 3\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Create carrier");
    println("    2.Print carrier");
    println("    3.Calculate");
    println("    4.Exit");
}  // namespace

bool createCarrier(unique_ptr<Carrier> &carry_ptr) {
    unsigned int response;
    double speed;
    double cost;
    println("What type of carrier to create?");
    println("   1. Airplane");
    println("   2. Car");
    println("   3. Train");
    readT(response, ">", [](unsigned int num) { return num > 0 && num <= 3; });
    readT(speed, "Please enter speed (speed > 0): ", [](double num) { return num > 0; });
    readT(cost, "Please enter cost per km: ");

    switch (response) {
        case 1:
            carry_ptr = make_unique<Airplane>(speed, cost);
            break;
        case 2:
            carry_ptr = make_unique<Car>(speed, cost);
            break;
        case 3:
            carry_ptr = make_unique<Train>(speed, cost);
            break;
        default:
            break;
    }
    return true;
}
bool printCarrier(unique_ptr<Carrier> &carry_ptr) {
    if (!carry_ptr.get()) {
        cout << "None, please create one first" << endl;
        return true;
    }
    cout << *carry_ptr.get();
    return true;
}
bool calculate(unique_ptr<Carrier> &carry_ptr) {
    if (!carry_ptr.get()) {
        cout << "No carrier, please create one first" << endl;
        return true;
    }
    const Carrier &carry = *carry_ptr.get();
    size_t distance;
    readT(distance, "Pleaes enter distance: ");
    cout << format("time: {:.2f} cost: {:.2f}", carry.getTime(distance), carry.getPrice(distance)) << endl;

    return true;
}

}  // namespace screens