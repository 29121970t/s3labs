#include <l4/include/wagon.hh>

namespace carriers
{
    Wagon::Wagon() : Carrier(kSpeed, kPricePerKm, kSeats, kCargoCapacity) {};
    const char* Wagon::name() const { return "Wagon"; }
} // namespace carriers
