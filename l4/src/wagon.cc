#include <l4/include/wagon.hh>

namespace carriers
{
    Wagon::Wagon(double speed, double people_price_per_km_, double cargo_price_per_km_) : Carrier(speed, people_price_per_km_, cargo_price_per_km_) {};
    const char* Wagon::name() const { return "Bicycle"; }
} // namespace carriers
