#include "string.hh"
#include <iostream>
namespace str {

string::string(const char* str) : length_{0}, dataPtr_{nullptr} {
    for (; str[length_]; length_++);
    ++length_;
    dataPtr_ = std::make_unique_for_overwrite<char[]>(length_);
    std::ranges::copy(str, str + length_, dataPtr_.get());
}

string::string(const char*&& str) : length_{0}, dataPtr_{nullptr} {
    for (; str[length_]; length_++);
    ++length_;
    dataPtr_ = std::make_unique_for_overwrite<char[]>(length_);
    std::ranges::copy(str, str + length_, dataPtr_.get());
}

string::string() : length_{2}, dataPtr_{std::make_unique<char[]>(length_)} {};

string::string(const string& other) : length_{other.length_}, dataPtr_{std::make_unique<char[]>(length_)} {
    std::ranges::copy(other.dataPtr_.get(), other.dataPtr_.get() + length_, dataPtr_.get());
};

string::string(string&& other) noexcept : length_{other.length_}, dataPtr_{std::move(other.dataPtr_)} {};

string& string::operator=(const string& other) {
    length_ = other.length_;
    resizeD_(length_);
    std::ranges::copy(other.dataPtr_.get(), other.dataPtr_.get() + length_, dataPtr_.get());
    return *this;
};

size_t string::getLen() const { return length_; }

string& string::operator=(string&& other) noexcept {
    length_ = other.length_;
    dataPtr_ = std::move(other.dataPtr_);
    return *this;
};

char& string::operator[](size_t index) {
    if (index >= length_) throw std::invalid_argument("Index out of range");
    return dataPtr_[index];
}
const char& string::operator[](size_t index) const {
    if (index >= length_) throw std::invalid_argument("Index out of range");
    return dataPtr_[index];
}

std::ostream& operator<<(std::ostream& os, const string& obj) {
    os << obj.dataPtr_.get();
    return os;
};

std::istream& operator>>(std::istream& is, string& obj) {
    obj.readFromStream_(is);
    return is;
}

void string::resizeD_(size_t newLen) {
    length_ = newLen;
    std::unique_ptr<char[]> tmp = std::make_unique<char[]>(length_);
    dataPtr_ = std::move(tmp);
}
void string::resize_(size_t newLen) {
    length_ = newLen;
    std::unique_ptr<char[]> tmp = std::make_unique<char[]>(length_);
    std::ranges::copy(dataPtr_.get(), dataPtr_.get() + length_, tmp.get());
    dataPtr_ = std::move(tmp);
}
void string::readFromStream_(std::istream& is) {
    char tmp;
    size_t counter = 0;
    while (is.get(tmp) && tmp != '\n') {
        if (counter >= length_ - 1) {
            resize_(length_ * 2);
        }
        dataPtr_[counter] = tmp;
        counter++;
    }
    resize_(counter + 1);
    dataPtr_[counter] = '\0';
    is.clear();
}

bool operator!=(const string& str1, const string& str2) {
    if (str1.length_ != str2.length_) return true;
    for (size_t i = 0; i < str1.length_; i++) {
        if (str1.dataPtr_[i] != str2.dataPtr_[i]) return true;
    }
    return false;
}

void printString(const string& str) { std::cout << str.dataPtr_.get(); }
void readString(string& str) { str.readFromStream_(std::cin); }
}  // namespace str
