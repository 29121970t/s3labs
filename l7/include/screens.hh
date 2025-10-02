#pragma once
#include <memory>
#include <l5/include/vector.hh>
#include "busService.hh"
namespace screens {
void printMainScreen();
bool printFlights(vec::Vector<bus_service::BusService> &vec);
bool getByDepartureTime(vec::Vector<bus_service::BusService> &vec);
}  // namespace screens
