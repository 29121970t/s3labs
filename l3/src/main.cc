#include <consoleUtils.hh>
#include <format>
#include <functional>
#include <iostream>
#include <l3/include/airplane.hh>
#include <l3/include/car.hh>
#include <l3/include/train.hh>
#include <memory>
#include <print>

using namespace std;
using namespace carriers;
using namespace console_utils;

void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 3\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Create carrier");
    println("    2.Print carrier");
    println("    3.Calculate");
    println("    4.Exit");
}

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
    if(!carry_ptr){
        cout << "None, please create one first" << endl;
        return 1;
    }
    cout << *carry_ptr;
    return true;
}
bool calculate(unique_ptr<Carrier> &carry_ptr) {
    if(!carry_ptr.get()){
        cout << "No carrier, please create one first" << endl;
        return 1;
    }
    Carrier &carry = *carry_ptr.get();
    size_t distance;
    readT(distance, "Pleaes enter distance: ");
    cout << format("time: {:.2f} cost: {:.2f}", carry.getTime(distance), carry.getPrice(distance)) << endl;

    return true;
}

int main(void) {
    unique_ptr<Carrier> carry_ptr;
    static array<function<bool(unique_ptr<Carrier> &)>, 4> actions = {createCarrier, printCarrier, calculate,
                                                                      [](const unique_ptr<Carrier> &) { return 0; }};
    unsigned int response;
    do {
        printMainScreen();
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 4; });
        cout << "\x{1B}[2J\x{1B}[H\n";
    } while (actions[response - 1](carry_ptr));

    return 0;
}