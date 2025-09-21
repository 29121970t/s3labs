#include <l3/include/airplane.hh>

namespace carriers
{
    Airplane::Airplane(double speed, double price_per_km) : Carrier{speed, price_per_km} {};
    const char* Airplane::name() const { return "Airplane"; }
} // namespace carriers
