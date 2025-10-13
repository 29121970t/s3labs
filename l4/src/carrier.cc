#include <cmath>
#include <l4/include/carrier.hh>
namespace carriers {

Carrier::Carrier(double speed, double pricePerKm, size_t peopleCapacity, double cargoCapacity)
    : speed_{speed}, pricePerKm_{pricePerKm}, peopleCapacity_{peopleCapacity}, cargoCapacity_{cargoCapacity} {
    if (speed_ <= 0) throw std::invalid_argument("speed should be > 0");
    if (peopleCapacity_ <= 0) throw std::invalid_argument("people capacity should be > 0");
    if (cargoCapacity_ <= 0) throw std::invalid_argument("cargo capacity should be > 0");
}
Carrier::~Carrier() = default;
double Carrier::getTime(double distance) const { return distance / speed_; }
double Carrier::getPriceForPeople(double distance, size_t ammount) const {
    return ceil(static_cast<double>(ammount) / peopleCapacity_) * distance * pricePerKm_;
}
double Carrier::getPriceForCargo(double distance, double ammount) const {
    return ceil(ammount / cargoCapacity_) * distance * pricePerKm_;
}

}  // namespace carriers