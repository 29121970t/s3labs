#include <l3/include/carrier.hh>
namespace carriers {

Carrier::Carrier(double speed, double pricePerKm) : speed_{speed}, pricePerKm_{pricePerKm} {
    if (speed_ <= 0) throw std::invalid_argument("speed should be > 0");
}

double Carrier::getTime(double distance) const { return distance / speed_; }
double Carrier::getPrice(double distance) const { return distance * pricePerKm_; }

}  // namespace carriers