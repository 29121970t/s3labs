#pragma once
#include "carrier.hh"

namespace carriers {
class Airplane : public Carrier {
   public:
    inline static const double defaultSpeed = 880;
    inline static const double defaultPricePerKm = 1;
    Airplane();
    const char* name() const override;
};
}  // namespace carriers
