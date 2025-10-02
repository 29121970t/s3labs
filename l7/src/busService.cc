#include <chrono>
#include <l7/include/busService.hh>
#include <utility>

using namespace vec;
using namespace std;
namespace bus_service {

BusService::BusService() : BusService("UNKNOWN", 0, 0, 0){};
BusService::BusService(const str::String &destination, time_t departureTime, time_t arrivalTime, size_t number,
                       BusType type)
    : number_{number},
      type_{type},
      destination_{destination},
      departureTime_{departureTime},
      arrivalTime_{arrivalTime} {};
BusService::BusService(const char destination[], time_t departureTime, time_t arrivalTime, size_t number, BusType type)
    : BusService(str::String(destination), departureTime, arrivalTime, number, type){};

Vector<BusService const *> BusService::getByDepartureTime(time_t departureTime, Vector<BusService> &vec) {
    Vector<BusService const *> res;
    for (size_t i = 0, count = vec.count(); i < count; ++i) {
        time_t epsilon = vec[i].departureTime_ > departureTime ? vec[i].departureTime_ - departureTime
                                                                : departureTime - vec[i].departureTime_;
        if (epsilon <= 60) {
            res.pushBack(&vec[i]);
        }
    }
    return res;
}
std::string BusService::getTypeString(BusType type) {
    static const array<std::string, to_underlying(BusType::TYPE_COUNT)> strings = {"Transit", "Double deck",
                                                                                   "Mini bus"};
    return strings[std::to_underlying(type)];
}
std::string BusService::dump() const {
    using namespace std::chrono;

    std::stringstream stream;
    time_point tp1 = system_clock::from_time_t(departureTime_);
    time_point tp2 = system_clock::from_time_t(arrivalTime_);
    stream << std::format(
        "Bus: [number: {}, type: {}, destination: {}, departure time: {:%d-%m-%Y %H:%M}, arrival time: "
        "{:%d-%m-%Y %H:%M}]",
        number_, getTypeString(type_), destination_.getRaw(), tp1, tp2);
    return stream.str();
};

}  // namespace bus_service
