#include <l4/include/wagon.hh>

namespace carriers
{
    Wagon::Wagon() : Carrier(speed, pricePerKm, seats, cargoCapacity) {};
    const char* Wagon::name() const { return "Wagon"; }
} // namespace carriers
