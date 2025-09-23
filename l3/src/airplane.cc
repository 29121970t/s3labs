#include <l3/include/airplane.hh>

namespace carriers
{
    Airplane::Airplane() : Carrier{kDefaultSpeed, kDefaultPricePerKm} {};
    const char* Airplane::name() const { return "Airplane"; }
} // namespace carriers
