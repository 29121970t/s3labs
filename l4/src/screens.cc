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
    auto [colss, rows] = getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 4\x{1B}[0m", colss);
    println("Please select action:\n");
    println("    1. Create carrier");
    println("    2. Print carrier");
    println("    3. Calculate");
    println("    4. Exit");
}

bool createCarrier(unique_ptr<Carrier> &carryPtr) {
    unsigned int response;
    println("What type of carrier to create?");
    println("   1. Wagon");
    println("   2. Car");
    println("   3. Bicycle");
    readT(response, ">", [](unsigned int num) { return num > 0 && num <= 3; });

    switch (response) {
        case 1:
            carryPtr = make_unique<Wagon>();
            break;
        case 2:
            carryPtr = make_unique<Car>();
            break;
        case 3:
            carryPtr = make_unique<Bicycle>();
            break;
        default:
            break;
    }
    return true;
}
bool printCarrier(const Carrier *carryPtr) {
    if (!carryPtr) {
        cout << "None, please create one first" << endl;
        return true;
    }
    cout << *carryPtr;
    return true;
}
bool calculate(const Carrier *carryPtr) {
    if (!carryPtr) {
        cout << "No carrier, please create one first" << endl;
        return true;
    }
    double distance;
    size_t numberOfPeople;
    double cargoVolume;
    readT(distance, "Pleaes enter distance: ");
    readT(numberOfPeople, "Pleaes enter number of people: ");
    readT(cargoVolume, "Pleaes enter cargo volume: ");


    cout << format("time: {:.2f}, price for people: {:.2f}, price for cargo: {:.2f}", carryPtr->getTime(distance),
                   carryPtr->getPriceForPeople(distance, numberOfPeople), carryPtr->getPriceForCargo(distance, cargoVolume))
         << endl;

    return true;
}
}  // namespace screens
