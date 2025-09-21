#include <l3/include/car.hh>

namespace carriers
{
    Car::Car(double speed, double price_per_km) : Carrier{speed, price_per_km} {};
    const char* Car::name() { return "Car"; }
} // namespace carriers

    