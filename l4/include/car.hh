#pragma once
#include "carrier.hh"

namespace carriers {
class Car : public Carrier {
   public:
    inline static const double defaultSpeed = 80;
    inline static const double defaultPeoplePricePerKm = 0.3;
    inline static const double defaultCargoPricePerKm = 0.2;
    Car();
    const char* name() const override;
};
}  // namespace carriers
