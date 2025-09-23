#pragma once
#include "carrier.hh"
namespace carriers {
class Bicycle : public Carrier {
   public:
    inline static const double kSpeed = 20;
    inline static const double kPricePerKm = 0.5;
    inline static const size_t kSeats = 2;
    inline static const double kCargoCapacity = 1;
    Bicycle();
    const char* name() const override;
};
}  // namespace carriers
