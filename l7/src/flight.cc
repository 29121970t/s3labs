#include <chrono>
#include <l7/include/flight.hh>
namespace flight {
vec::Vector<Flight *> Flight::instanses_;
size_t Flight::counter_ = 0;

Flight::Flight(str::String destination, time_t departureTime, time_t arrivalTime, BusType type)
    : number_{++counter_},
      type_{type},
      destination_{std::move(destination)},
      departureTime_{departureTime},
      arrivalTime_{arrivalTime} {
    instanses_.pushBack(this);
};
Flight::~Flight() {
    size_t index;
    for (index = 0; instanses_[index] != this; ++index);
    instanses_.erase(index);
}
vec::Vector<Flight *> Flight::getByDepartureTime(time_t departureTime) {
    vec::Vector<Flight *> vec;
    for (size_t i = 0, count = instanses_.count(); i < count; ++i) {
        if (instanses_[i]->departureTime_ == departureTime) {
            vec.pushBack(instanses_[i]);
        }
    }
    return vec;
}
std::string Flight::dump() const {
    std::stringstream stream;
    std::chrono::time_point tp = std::chrono::system_clock::from_time_t(departureTime_);

    stream << std::format("flight: [\nnumber: {}\ntype code: {}\ndestination: {}\n departure time: {:%m.%d: %H:%M}]",
                          number_, static_cast<int>(type_), destination_.getRaw(), tp);
    return stream.str();
};
}  // namespace flight
