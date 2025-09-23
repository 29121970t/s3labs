#pragma once
#include <memory>
#include "carrier.hh"
namespace screens {
void printMainScreen();

bool createCarrier(std::unique_ptr<carriers::Carrier> &carry_ptr);
bool printCarrier(const carriers::Carrier *carry_ptr);
bool calculate(const carriers::Carrier *carry_ptr);
}  // namespace screens
