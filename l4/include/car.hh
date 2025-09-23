#pragma once
#include "carrier.hh"

namespace carriers {
class Car : public Carrier {
   public:
    inline static const double kSpeed = 80;
    inline static const double kPricePerKm = 0.4;
    inline static const size_t kSeats = 5;
    inline static const double kCargoCapacity = 5;
    Car();
    const char* name() const override;
};
}  // namespace carriers
