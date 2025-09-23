#include <l4/include/car.hh>

namespace carriers {
Car::Car() : Carrier(defaultSpeed, defaultPeoplePricePerKm, defaultCargoPricePerKm){};
const char* Car::name() const { return "Car"; }
}  // namespace carriers
