#pragma once
#include <ctime>
#include <format>
#include <fstream>
#include <iostream>
#include <l2/include/string.hh>
#include <l5/include/vector.hh>
#include <sstream>
namespace flight {
namespace bus_types {
enum BusType {
    TRANSIT = 0,
    DOUBLEDECK,
    MINIBUS,
};
}  // namespace buss_types
class Flight {
   private:
    static vec::Vector<Flight *> instanses_;
    static size_t counter_;
    size_t number_;
    bus_types::BusType type_;
    str::String destination_;
    time_t departureTime_;
    time_t arrivalTime_;

    // rewrite
    friend std::ostream &operator<<(std::ostream &os, Flight &obj) {
        os.write(reinterpret_cast<const char *>(&obj), sizeof(obj));
        return os;
    };
    friend std::istream &operator>>(std::istream &is, Flight &obj) {
        is.read(reinterpret_cast<char *>(&obj), sizeof(obj));
        return is;
    };

   public:
    Flight(str::String destination, time_t departureTime, time_t arrivalTime, bus_types::BusType type = bus_types::TRANSIT);
    Flight(Flight &) = delete;
    Flight(Flight &&) = default;

    ~Flight();
    Flight &operator=(Flight &other) = delete;
    Flight &operator=(Flight &&other) = default;

    static vec::Vector<Flight *> getByDepartureTime(time_t departureTime);
    std::string dump();
};

}  // namespace flight
