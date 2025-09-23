#pragma once
#include "carrier.hh"

namespace carriers {
class Wagon : public Carrier {
   public:
    inline static const double kSpeed = 10;
    inline static const double kPricePerKm = 0.6;
    inline static const size_t kSeats = 8;
    inline static const double kCargoCapacity = 20;
    Wagon();
    const char* name() const override;
};
}  // namespace carriers
