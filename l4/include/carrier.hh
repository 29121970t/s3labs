#pragma once
#include <cmath>
#include <format>
#include <iostream>
#include <stdexcept>

namespace carriers {
class Carrier {
   private:
    double speed_;
    double pricePerKm_;
    size_t peopleCapacity_;
    double cargoCapacity_;

   private:
    friend std::ostream& operator<<(std::ostream& os, const Carrier& carry) {
        os << std::format("{}: [speed: {}, price per km: {}, people capacity: {}, cargo capacity: {}]", carry.name(), carry.speed_,
                          carry.pricePerKm_, carry.peopleCapacity_, carry.cargoCapacity_)
           << std::endl;
        return os;
    }

   public:
    Carrier(double speed, double pricePerKm, size_t peopleCapacity, double cargoCapacity);
    virtual ~Carrier();
    virtual double getTime(double distance) const;
    virtual double getPriceForPeople(double distance, size_t ammount) const;
    virtual double getPriceForCargo(double distance, double ammount) const;
    virtual const char* name() const = 0;
};

}  // namespace carriers
