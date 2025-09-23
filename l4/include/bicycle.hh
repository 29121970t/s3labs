#pragma once
#include "carrier.hh"
namespace carriers {
class Bicycle : public Carrier {
   public:
    inline static const double defaultSpeed = 20;
    inline static const double defaultPeoplePricePerKm = 3;
    inline static const double defaultCargoPricePerKm = 1;
    Bicycle();
    const char* name() const override;
};
}  // namespace carriers
