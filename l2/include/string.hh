#pragma once
#include <memory>
#include <type_traits>

namespace str {
class String {
   private:
    size_t length_;
    std::unique_ptr<char[]> dataPtr_;

    void resizeD_(size_t newLen);
    void resize_(size_t newLen);
    void readFromStream_(std::istream& is);

    friend std::ostream& operator<<(std::ostream& os, const String& obj) {
        os << obj.dataPtr_.get();
        return os;
    };

    friend std::istream& operator>>(std::istream& is, String& obj) {
        obj.readFromStream_(is);
        return is;
    }

   public:
    explicit String(const char* str);

    String();
    String(const String& other);
    String(String&& other) noexcept;
    ~String() { dataPtr_.release(); }
    size_t getLen() const;

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    const char* getRaw() const;

    auto operator<=>(const String& other) const { return length_ <=> other.length_; }

    friend void printString(const String& str);
    friend void readString(String& str);
    friend bool operator!=(const String& str1, const String& str2);
};
void printString(const String& str);
void readString(String& str);
}  // namespace str
