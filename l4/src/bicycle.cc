#include <l4/include/bicycle.hh>

namespace carriers
{
    Bicycle::Bicycle(double speed, double people_price_per_km_, double cargo_price_per_km_) : Carrier(speed, people_price_per_km_, cargo_price_per_km_) {};
    const char* Bicycle::name() const { return "Bicycle"; }
} // namespace carriers
