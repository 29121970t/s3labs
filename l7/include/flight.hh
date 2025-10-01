#pragma once
#include <ctime>
#include <format>
#include <fstream>
#include <iostream>
#include <l2/include/string.hh>
#include <l5/include/vector.hh>
#include <sstream>
namespace flight {
enum class BusType {
    TRANSIT = 0,
    DOUBLEDECK,
    MINIBUS,
};

class Flight {
   private:
    static vec::Vector<Flight *> instanses_;
    static size_t counter_;
    size_t number_ = ++counter_;
    BusType type_;
    str::String destination_;
    time_t departureTime_;
    time_t arrivalTime_;

    // rewrite
    friend std::ostream &operator<<(std::ostream &os, const Flight &obj) {
        auto ptr = reinterpret_cast<const char *>(&obj);
        os.write(ptr, sizeof(obj));
        return os;
    };
    friend std::istream &operator>>(std::istream &is, Flight &obj) {
        auto ptr = reinterpret_cast<char *>(&obj);
        is.read(ptr, sizeof(obj));
        return is;
    };

   public:
    Flight(str::String destination, time_t departureTime, time_t arrivalTime, BusType type = BusType::TRANSIT);
    Flight(const char destination[], time_t departureTime, time_t arrivalTime, BusType type = BusType::TRANSIT);
    Flight(Flight &) = delete;

    ~Flight();
    Flight &operator=(Flight &other) = delete;

    static vec::Vector<Flight *> getByDepartureTime(time_t departureTime);
    std::string dump() const;
};

}  // namespace flight
