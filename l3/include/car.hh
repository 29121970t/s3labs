#pragma once
#include "carrier.hh"

namespace carriers {
class Car : public Carrier {
   public:
    Car(double speed, double price_per_km);
    const char* name() const override;
};
}  // namespace carriers
