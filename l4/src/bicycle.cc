#include <l4/include/bicycle.hh>

namespace carriers {
Bicycle::Bicycle() : Carrier(kSpeed, kPricePerKm, kSeats, kCargoCapacity){};
const char* Bicycle::name() const { return "Bicycle"; }
}  // namespace carriers
