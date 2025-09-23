#pragma once
#include <memory>
#include "carrier.hh"
namespace screens {
void printMainScreen();

bool createCarrier(std::unique_ptr<carriers::Carrier> &carryPtr);
bool printCarrier(const carriers::Carrier *carryPtr);
bool calculate(const carriers::Carrier *carryPtr);
}  // namespace screens
