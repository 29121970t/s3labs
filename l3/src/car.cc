#include <l3/include/car.hh>

namespace carriers
{
    Car::Car() : Carrier{kDefaultSpeed, kDefaultPricePerKm} {};
    const char* Car::name() const { return "Car"; }
} // namespace carriers

    