#include <l3/include/carrier.hh>
namespace carriers {

Carrier::Carrier(double speed, double price_per_km) : speed_{speed}, price_per_km_{price_per_km} {
    if (speed_ <= 0) throw std::invalid_argument("speed should be > 0");
}

double Carrier::getTime(double distance) const { return distance / speed_; }
double Carrier::getPrice(double distance) const { return distance * price_per_km_; }

}  // namespace carriers