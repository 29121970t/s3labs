#include <l4/include/car.hh>

namespace carriers
{
    Car::Car(double speed, double people_price_per_km_, double cargo_price_per_km_) : Carrier(speed, people_price_per_km_, cargo_price_per_km_) {};
    const char* Car::name() const { return "Car"; }
} // namespace carriers

    