#include <l4/include/car.hh>

namespace carriers {
Car::Car() : Carrier(speed, pricePerKm, seats, cargoCapacity){};
const char* Car::name() const { return "Car"; }
}  // namespace carriers
