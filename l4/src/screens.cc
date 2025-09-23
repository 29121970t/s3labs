#include <consoleUtils.hh>
#include <l4/include/bicycle.hh>
#include <l4/include/car.hh>
#include <l4/include/wagon.hh>
#include <memory>
#include <print>
using namespace std;
using namespace carriers;
using namespace console_utils;

namespace screens {
void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 4\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Create carrier");
    println("    2.Print carrier");
    println("    3.Calculate");
    println("    4.Exit");
}

bool createCarrier(unique_ptr<Carrier> &carry_ptr) {
    unsigned int response;
    double speed;
    double cost_p;
    double cost_c;
    println("What type of carrier to create?");
    println("   1. Wagon");
    println("   2. Car");
    println("   3. Bicycle");
    readT(response, ">", [](unsigned int num) { return num > 0 && num <= 3; });
    readT(speed, "Please enter speed (speed > 0): ", [](double num) { return num > 0; });
    readT(cost_p, "Please enter cost per km for people: ");
    readT(cost_c, "Please enter cost per km for cargo: ");


    switch (response) {
        case 1:
            carry_ptr = make_unique<Wagon>(speed, cost_p, cost_c);
            break;
        case 2:
            carry_ptr = make_unique<Car>(speed, cost_p, cost_c);
            break;
        case 3:
            carry_ptr = make_unique<Bicycle>(speed, cost_p, cost_c);
            break;
        default:
            break;
    }
    return true;
}
bool printCarrier(const Carrier *carry_ptr) {
    if (!carry_ptr) {
        cout << "None, please create one first" << endl;
        return true;
    }
    cout << *carry_ptr;
    return true;
}
bool calculate(const Carrier *carry_ptr) {
    if (!carry_ptr) {
        cout << "No carrier, please create one first" << endl;
        return true;
    }
    size_t distance;
    readT(distance, "Pleaes enter distance: ");
    cout << format("time: {:.2f} price for people: {:.2f} price for cargo: {:.2f}", carry_ptr->getTime(distance),
                   carry_ptr->getPriceForPeople(distance), carry_ptr->getPriceForCargo(distance))
         << endl;

    return true;
}
}  // namespace screens
