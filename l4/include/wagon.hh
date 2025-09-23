#pragma once
#include "carrier.hh"

namespace carriers {
class Wagon : public Carrier {
   public:
    inline static const double speed = 10;
    inline static const double pricePerKm = 0.6;
    inline static const size_t seats = 8;
    inline static const double cargoCapacity = 20;
    Wagon();
    const char* name() const override;
};
}  // namespace carriers
