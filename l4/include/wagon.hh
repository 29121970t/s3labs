#pragma once
#include "carrier.hh"

namespace carriers {
class Wagon : public Carrier {
   public:
    inline static const double defaultSpeed = 10;
    inline static const double defaultPeoplePricePerKm = 0.1;
    inline static const double defaultCargoPricePerKm = 0.05;
    Wagon();
    const char* name() const override;
};
}  // namespace carriers
