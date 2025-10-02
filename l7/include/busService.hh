#pragma once
#include <ctime>
#include <l2/include/string.hh>
#include <l5/include/vector.hh>
#include <utility>
namespace bus_service {
enum class BusType { TRANSIT = 0, DOUBLEDECK, MINIBUS, TYPE_COUNT };
class BusService {
   private:
    size_t number_;
    BusType type_;
    str::String destination_;
    time_t departureTime_;
    time_t arrivalTime_;

    friend std::ostream &operator<<(std::ostream &os, const BusService &obj) {
        os.write(reinterpret_cast<const std::istream::char_type *>(&obj.number_), sizeof(obj.number_));
        os.write(reinterpret_cast<const std::istream::char_type *>(&obj.type_), sizeof(obj.type_));

        size_t destinationLen = obj.destination_.getLen();
        os.write(reinterpret_cast<const std::istream::char_type *>(&destinationLen), sizeof(destinationLen));
        os.write(obj.destination_.getRaw(), destinationLen);

        os.write(reinterpret_cast<const std::istream::char_type *>(&obj.departureTime_), sizeof(obj.departureTime_));
        os.write(reinterpret_cast<const std::istream::char_type *>(&obj.arrivalTime_), sizeof(obj.arrivalTime_));
        return os;
    };
    friend std::istream &operator>>(std::istream &is, BusService &obj) {
        is.read(reinterpret_cast<std::istream::char_type *>(&obj.number_), sizeof(obj.number_));
        is.read(reinterpret_cast<std::istream::char_type *>(&obj.type_), sizeof(obj.type_));

        size_t destinationLen;
        is.read(reinterpret_cast<std::istream::char_type *>(&destinationLen), sizeof(destinationLen));
        auto destination = std::make_unique_for_overwrite<char[]>(destinationLen);
        is.read(destination.get(), destinationLen);
        obj.destination_ = str::String(destination.get());

        is.read(reinterpret_cast<std::istream::char_type *>(&obj.departureTime_), sizeof(obj.departureTime_));
        is.read(reinterpret_cast<std::istream::char_type *>(&obj.arrivalTime_), sizeof(obj.arrivalTime_));
        return is;
    };

   public:
    BusService();
    BusService(const str::String &destination, time_t departureTime, time_t arrivalTime, size_t number,
               BusType type = BusType::TRANSIT);
    BusService(const char destination[], time_t departureTime, time_t arrivalTime, size_t number,
               BusType type = BusType::TRANSIT);
    BusService(BusService &) = delete;

    BusService &operator=(BusService &other) = delete;

    static vec::Vector<BusService const *> getByDepartureTime(time_t departureTime, vec::Vector<BusService> &vec);
    static std::string getTypeString(BusType type);
    std::string dump() const;
};

}  // namespace bus_service
