#pragma once
#include "carrier.hh"
namespace carriers {
class Bicycle : public Carrier {
   public:
    inline static const double speed = 20;
    inline static const double pricePerKm = 0.5;
    inline static const size_t seats = 2;
    inline static const double cargoCapacity = 1;
    Bicycle();
    const char* name() const override;
};
}  // namespace carriers
