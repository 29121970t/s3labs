#include <l4/include/bicycle.hh>

namespace carriers {
Bicycle::Bicycle() : Carrier(speed, pricePerKm, seats, cargoCapacity){};
const char* Bicycle::name() const { return "Bicycle"; }
}  // namespace carriers
