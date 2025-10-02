#include <iostream>
#include <l2/include/screens.hh>
#include <limits>

using namespace std;
namespace str {
String::String(const char* str) : length_{0} {
    for (; str[length_]; length_++);
    ++length_;
    dataPtr_ = make_unique_for_overwrite<char[]>(length_);
    ranges::copy(str, str + length_, dataPtr_.get());
}

String::String() : length_{1}, dataPtr_{make_unique<char[]>(length_)} {};

String::String(const String& other) : length_{other.length_}, dataPtr_{make_unique<char[]>(length_)} {
    ranges::copy(other.dataPtr_.get(), other.dataPtr_.get() + length_, dataPtr_.get());
};
String::String(String&& other) : length_{other.length_}, dataPtr_{make_unique_for_overwrite<char[]>(length_)} {
    dataPtr_ = std::move(other.dataPtr_);
};

String& String::operator=(const String& other) {
    length_ = other.length_;
    resizeD_(length_);
    ranges::copy(other.dataPtr_.get(), other.dataPtr_.get() + length_, dataPtr_.get());
    return *this;
};
String& String::operator=(String&& other) {
    length_ = other.length_;
    dataPtr_ = std::move(other.dataPtr_);
    return *this;
};

size_t String::getLen() const { return length_; }

char& String::operator[](size_t index) {
    if (index >= length_) throw invalid_argument("Index out of range");
    return dataPtr_[index];
}
const char& String::operator[](size_t index) const {
    if (index >= length_) throw invalid_argument("Index out of range");
    return dataPtr_[index];
}

void String::resizeD_(size_t newLen) {
    length_ = newLen;
    auto tmp = make_unique<char[]>(length_);
    dataPtr_ = std::move(tmp);
}
void String::resize_(size_t newLen) {
    length_ = newLen;
    auto tmp = make_unique<char[]>(length_);
    std::ranges::copy(dataPtr_.get(), dataPtr_.get() + length_, tmp.get());
    dataPtr_ = std::move(tmp);
}
void String::readFromStream_(istream& is) {
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
}
const char* String::getRaw() const { return dataPtr_.get(); }
bool operator!=(const String& str1, const String& str2) { return str1.length_ != str2.length_; }

void printString(const String& str) { cout << str.dataPtr_.get(); }
void readString(String& str) { str.readFromStream_(cin); }
}  // namespace str
