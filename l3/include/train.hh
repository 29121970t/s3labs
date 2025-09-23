#pragma once
#include <l3/include/carrier.hh>
namespace carriers {
class Train : public Carrier {
   public:
    inline static const double kDefaultSpeed = 120;
    inline static const double kDefaultPricePerKm = 0.01;
    Train();
    const char* name() const override;
};
}  // namespace carriers
