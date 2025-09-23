#include <l4/include/carrier.hh>
namespace carriers {

Carrier::Carrier(double speed, double people_price_per_km_, double cargo_price_per_km_)
    : speed_{speed}, people_price_per_km_{people_price_per_km_}, cargo_price_per_km_{cargo_price_per_km_} {
    if (speed_ <= 0) throw std::invalid_argument("speed should be > 0");
}

double Carrier::getTime(double distance) const { return distance / speed_; }
double Carrier::getPriceForPeople(double distance) const { return distance * people_price_per_km_; }
double Carrier::getPriceForCargo(double distance) const { return distance * cargo_price_per_km_; }

}  // namespace carriers