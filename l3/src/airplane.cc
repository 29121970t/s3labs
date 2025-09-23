#include <l3/include/airplane.hh>

namespace carriers
{
    Airplane::Airplane() : Carrier{defaultSpeed, defaultPricePerKm} {};
    const char* Airplane::name() const { return "Airplane"; }
} // namespace carriers
