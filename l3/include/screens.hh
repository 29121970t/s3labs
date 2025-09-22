#pragma once
#include <memory>

#include "carrier.hh"

namespace screens {
void printMainScreen();
bool createCarrier(std::unique_ptr<carriers::Carrier> &carry_ptr);
bool printCarrier(std::unique_ptr<const carriers::Carrier> &carry_ptr);
bool calculate(std::unique_ptr<const carriers::Carrier> &carry_ptr);
}  // namespace screens
