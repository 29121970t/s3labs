#pragma once
#include <l3/include/carrier.hh>
namespace carriers {
class Train : public Carrier {
   public:
    Train(double speed, double price_per_km);
    const char* name() const override;
};
}  // namespace carriers
