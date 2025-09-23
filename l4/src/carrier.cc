#include <l4/include/carrier.hh>
namespace carriers {

Carrier::Carrier(double speed, double peoplePricePerKm, double cargoPricePerKm)
    : speed_{speed}, peoplePricePerKm_{peoplePricePerKm}, cargoPricePerKm_{cargoPricePerKm} {
    if (speed_ <= 0) throw std::invalid_argument("speed should be > 0");
}

double Carrier::getTime(double distance) const { return distance / speed_; }
double Carrier::getPriceForPeople(double distance) const { return distance * peoplePricePerKm_; }
double Carrier::getPriceForCargo(double distance) const { return distance * cargoPricePerKm_; }

}  // namespace carriers