#include <l3/include/car.hh>

namespace carriers
{
    Car::Car() : Carrier{defaultSpeed, defaultPricePerKm} {};
    const char* Car::name() const { return "Car"; }
} // namespace carriers

    