#include <l4/include/car.hh>

namespace carriers {
Car::Car() : Carrier(kSpeed, kPricePerKm, kSeats, kCargoCapacity){};
const char* Car::name() const { return "Car"; }
}  // namespace carriers
