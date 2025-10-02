#include <chrono>
#include <l7/include/busService.hh>
#include <utility>

using namespace vec;
using namespace std;
namespace bus_service {
vec::Vector<BusService *> BusService::instanses_;

BusService::BusService() : BusService("UNKNOWN", 0, 0, 0){};
BusService::BusService(const str::String &destination, time_t departureTime, time_t arrivalTime, size_t number,
                       BusType type)
    : number_{number},
      type_{type},
      destination_{destination},
      departureTime_{departureTime},
      arrivalTime_{arrivalTime} {
    instanses_.pushBack(this);
};
BusService::BusService(const char destination[], time_t departureTime, time_t arrivalTime, size_t number, BusType type)
    : BusService(str::String(destination), departureTime, arrivalTime, number, type){};

BusService::~BusService() {
    size_t index;
    for (index = 0; instanses_[index] != this; ++index);
    instanses_.erase(index);
}
Vector<BusService *> BusService::getByDepartureTime(time_t departureTime) {
    Vector<BusService *> vec;
    for (size_t i = 0, count = instanses_.count(); i < count; ++i) {
        time_t epsilon = instanses_[i]->departureTime_ > departureTime ? instanses_[i]->departureTime_ - departureTime
                                                                       : departureTime - instanses_[i]->departureTime_;
        if (epsilon <= 60) {
            vec.pushBack(instanses_[i]);
        }
    }
    return vec;
}
const char *BusService::getTypeString(BusType type) {
    static const char strings[][30] = {"Transit", "Double deck", "Mini bus"};
    return strings[std::to_underlying(type)];
}
std::string BusService::dump() const {
    using namespace std::chrono;

    std::stringstream stream;
    time_point tp1 = system_clock::from_time_t(departureTime_);
    time_point tp2 = system_clock::from_time_t(arrivalTime_);
    stream << std::format(
        "flight: [number: {}, type: {}, destination: {}, departure time: {:%d-%m-%Y %H:%M}, arrival time: "
        "{:%d-%m-%Y %H:%M}]",
        number_, getTypeString(type_), destination_.getRaw(), tp1, tp2);
    return stream.str();
};

}  // namespace bus_service
