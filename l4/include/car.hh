#pragma once
#include "carrier.hh"

namespace carriers {
class Car : public Carrier {
   public:
    inline static const double speed = 80;
    inline static const double pricePerKm = 0.4;
    inline static const size_t seats = 5;
    inline static const double cargoCapacity = 5;
    Car();
    const char* name() const override;
};
}  // namespace carriers
