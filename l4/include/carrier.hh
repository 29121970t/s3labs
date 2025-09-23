#pragma once
#include <cmath>
#include <format>
#include <iostream>
#include <stdexcept>

namespace carriers {
class Carrier {
   private:
    double speed_;
    double peoplePricePerKm_;
    double cargoPricePerKm_;

   private:
    friend std::ostream& operator<<(std::ostream& os, const Carrier& carry) {
        os << std::format("{}: [speed: {}, price for people: {} price for cargo: {}]", carry.name(), carry.speed_,
                          carry.peoplePricePerKm_, carry.cargoPricePerKm_)
           << std::endl;
        return os;
    }

   public:
    Carrier(double speed, double peoplePricePerKm, double cargoPricePerKm);
    virtual double getTime(double distance) const;
    virtual double getPriceForPeople(double distance) const;
    virtual double getPriceForCargo(double distance) const;
    virtual const char* name() const = 0;
};

}  // namespace carriers
