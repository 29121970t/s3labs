#pragma once
#include "carrier.hh"

namespace carriers {
class Airplane : public Carrier {
   public:
    inline static const double kDefaultSpeed = 880;
    inline static const double kDefaultPricePerKm = 1;
    Airplane();
    const char* name() const override;
};
}  // namespace carriers
