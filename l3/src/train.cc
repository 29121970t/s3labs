#include <l3/include/train.hh>
namespace carriers
{
    Train::Train() : Carrier{kDefaultSpeed, kDefaultPricePerKm} {};
    const char* Train::name() const { return "Train"; }
} // namespace carriers
