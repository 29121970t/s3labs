#include <l7/include/flight.hh>

namespace flight {
vec::Vector<Flight *> Flight::instanses_;
size_t Flight::counter_ = 0;

Flight::Flight(str::String destination, time_t departureTime, time_t arrivalTime, bus_types::BusType type)
    : destination_{std::move(destination)},
      departureTime_{departureTime},
      arrivalTime_{arrivalTime},
      type_{type},
      number_{++counter_} {
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
std::string Flight::dump() {
    std::stringstream stream;
    stream << "flight: {\nnumber: " << number_
           << "\n"
              "type code: "
           << type_
           << "\n"
              "destination: "
           << destination_
           << "\n"
              "departure time: "
           << std::ctime(&departureTime_) << "arrival time: " << std::ctime(&arrivalTime_) << "}\n";
    return stream.str();
};
}  // namespace flight
