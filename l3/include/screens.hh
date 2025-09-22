#pragma once
#include <memory>

#include "carrier.hh"

namespace screens {
void printMainScreen();
bool createCarrier(std::unique_ptr<carriers::Carrier> &carry_ptr);
bool printCarrier(const std::unique_ptr<carriers::Carrier> &carry_ptr);
bool calculate(const std::unique_ptr<carriers::Carrier> &carry_ptr);
}  // namespace screens
