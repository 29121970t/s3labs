#pragma once
#include <cmath>
#include <format>
#include <iostream>
#include <stdexcept>

namespace carriers {
class Carrier {
   protected:
    double speed_;
    double price_per_km_;
   private:
    friend std::ostream& operator<<(std::ostream& os, Carrier& carry);

   public:
    Carrier(double speed, double price_per_km);

   public:
    virtual double getTime(double distance);
    virtual double getPrice(double distance);
    virtual const char* name() = 0;
};
std::ostream& operator<<(std::ostream& os, carriers::Carrier& carry);

}  // namespace carriers

