#pragma once
#include "carrier.hh"

namespace carriers {
class Airplane : public Carrier {
   public:
    Airplane(double speed, double price_per_km);
    const char* name() const override;
};
}  // namespace carriers
