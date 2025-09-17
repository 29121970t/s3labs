#pragma once

#include <memory>

namespace str {
class string {
   private:
    size_t length_;
    std::unique_ptr<char[]> dataPtr_;

    void resizeD_(size_t newLen);
    void resize_(size_t newLen);
    void readFromStream_(std::istream& is);

    friend std::ostream& operator<<(std::ostream& os, const string& obj);
    friend std::istream& operator>>(std::istream& is, string& obj);

   public:
    explicit string(const char* str);
    string(const char*&& str);

    string();
    string(const string& other);
    string(string&& other) noexcept;

    size_t getLen() const;

    string& operator=(const string& other);
    string& operator=(string&& other) noexcept;

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    auto operator<=>(const string& other) const { return length_ <=> other.length_; }

    friend void printString(const string& str);
    friend void readString(string& str);
    friend bool operator!=(const string& str1, const string& str2);
};
void printString(const string& str);
void readString(string& str);
}  // namespace str
