#include <l3/include/airplane.hh>
#include <l3/include/car.hh>
#include <l3/include/train.hh>
#include <l6/include/throwingConsoleUtils.hh>
#include <memory>
#include <print>
using namespace std;
using namespace carriers;
using namespace console_utils;

namespace screens {
void printMainScreen() {
    auto [cols, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 6\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1. Create carrier");
    println("    2. Print carrier");
    println("    3. Calculate");
    println("    4. Exit");
}

bool createCarrier(unique_ptr<Carrier> &carry_pt) {
    unsigned int response;
    println("What type of carrier to create?");
    println("   1. Airplane");
    println("   2. Car");
    println("   3. Train");
    try {
        readT(response, ">", [](unsigned int num) { return num > 0 && num <= 3; });
    } catch (const console_utils::invalid_input_error &) {
        std::cerr << "Invalid input" << '\n';

        return true;
    }

    switch (response) {
        case 1:
            carry_pt = make_unique<Airplane>();
            break;
        case 2:
            carry_pt = make_unique<Car>();
            break;
        case 3:
            carry_pt = make_unique<Train>();
            break;
        default:
            break;
    }
    return true;
}
bool printCarrier(const Carrier *carry_pt) {
    if (!carry_pt) {
        cout << "None, please create one first" << endl;
        return true;
    }
    cout << *carry_pt;
    return true;
}
bool calculate(const Carrier *carry_pt) {
    if (!carry_pt) {
        cout << "No carrier, please create one first" << endl;
        return true;
    }
    size_t distance;
    try {
        readT(distance, "Pleaes enter distance: ");
    } catch (const console_utils::invalid_input_error &) {
        std::cerr << "Invalid input" << '\n';
        return true;
    }

    cout << format("time: {:.2f} cost: {:.2f}", carry_pt->getTime(distance), carry_pt->getPrice(distance)) << endl;

    return true;
}
}  // namespace screens
