#include <l4/include/wagon.hh>

namespace carriers
{
    Wagon::Wagon() : Carrier(defaultSpeed, defaultPeoplePricePerKm, defaultPeoplePricePerKm) {};
    const char* Wagon::name() const { return "Wagon"; }
} // namespace carriers
