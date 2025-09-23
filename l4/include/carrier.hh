#pragma once
#include <cmath>
#include <format>
#include <iostream>
#include <stdexcept>

namespace carriers {
class Carrier {
   private:
    double speed_;
    double people_price_per_km_;
    double cargo_price_per_km_;

   private:
    friend std::ostream& operator<<(std::ostream& os, const Carrier& carry) {
        os << std::format("{}: [speed: {}, price for people: {} price for cargo: {}]", carry.name(), carry.speed_,
                          carry.people_price_per_km_, carry.cargo_price_per_km_)
           << std::endl;
        return os;
    }

   public:
    Carrier(double speed, double people_price_per_km_, double cargo_price_per_km_);
    virtual double getTime(double distance) const;
    virtual double getPriceForPeople(double distance) const;
    virtual double getPriceForCargo(double distance) const;
    virtual const char* name() const = 0;
};

}  // namespace carriers
