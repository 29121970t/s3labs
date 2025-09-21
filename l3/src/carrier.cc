#include <l3/include/carrier.hh>
namespace carriers {

Carrier::Carrier(double speed, double price_per_km) : speed_{speed}, price_per_km_{price_per_km} {
    if (speed_ <= 0) throw std::invalid_argument("speed should be > 0");
}

// add amount into account
double Carrier::getTime(double distance) { return distance / speed_; }
// add amount into account
double Carrier::getPrice(double distance) { return distance * price_per_km_; }
std::ostream& operator<<(std::ostream& os, Carrier& carry) {
    os << std::format("{}: [speed: {}, price: {}]", carry.name(), carry.speed_, carry.price_per_km_) << std::endl;
    return os;
}
}  // namespace carriers