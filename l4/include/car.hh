#pragma once
#include "carrier.hh"

namespace carriers {
class Car : public Carrier {
   public:
    Car(double speed, double people_price_per_km_, double cargo_price_per_km_);
    const char* name() const override;
};
}  // namespace carriers
