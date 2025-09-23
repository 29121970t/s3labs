#include <consoleUtils.hh>
#include <l3/include/airplane.hh>
#include <l3/include/car.hh>
#include <l3/include/train.hh>
#include <memory>
#include <print>
using namespace std;
using namespace carriers;
using namespace console_utils;

namespace screens {
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


    switch (response) {
        case 1:
            carry_ptr = make_unique<Airplane>();
            break;
        case 2:
            carry_ptr = make_unique<Car>();
            break;
        case 3:
            carry_ptr = make_unique<Train>();
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
    cout << format("time: {:.2f} cost: {:.2f}", carry_ptr->getTime(distance), carry_ptr->getPrice(distance)) << endl;

    return true;
}
}  // namespace screens
