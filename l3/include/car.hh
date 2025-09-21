#pragma once
#include "carrier.hh"

namespace carriers {
class Car : public Carrier {
   public:
    Car(double speed, double price_per_km);
    virtual const char* name() override;
};
}  // namespace carriers
