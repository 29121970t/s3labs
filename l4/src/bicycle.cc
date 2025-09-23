#include <l4/include/bicycle.hh>

namespace carriers {
Bicycle::Bicycle() : Carrier(defaultSpeed, defaultPeoplePricePerKm, defaultCargoPricePerKm){};
const char* Bicycle::name() const { return "Bicycle"; }
}  // namespace carriers
