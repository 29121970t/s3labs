#include <l3/include/train.hh>
namespace carriers
{
    Train::Train(double speed, double price_per_km) : Carrier{speed, price_per_km} {};
    const char* Train::name() { return "Train"; }
} // namespace carriers
