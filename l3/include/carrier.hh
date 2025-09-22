#pragma once
#include <cmath>
#include <format>
#include <iostream>
#include <stdexcept>

namespace carriers {
class Carrier {
   private:
    double speed_;
    double price_per_km_;

   private:
    friend std::ostream& operator<<(std::ostream& os, const Carrier& carry) {
        os << std::format("{}: [speed: {}, price: {}]", carry.name(), carry.speed_, carry.price_per_km_) << std::endl;
        return os;
    }

   public:
    Carrier(double speed, double price_per_km);
    virtual double getTime(double distance) const;
    virtual double getPrice(double distance) const;
    virtual const char* name() const = 0;
};

}  // namespace carriers
