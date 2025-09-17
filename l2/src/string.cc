#include "string.hh"
namespace str {

string::string(const char* str) : length_{0}, dataPtr_{nullptr} {
    for (; str[length_]; length_++);
    ++length_;
    dataPtr_ = std::make_unique_for_overwrite<char[]>(length_);
    std::ranges::copy(str, str + length_, dataPtr_.get());
}

string::string() : length_{2}, dataPtr_{new char[length_]} {};

string::string(const string& other) : length_{other.length_}, dataPtr_{new char[length_]} {
    std::ranges::copy(other.dataPtr_.get(), other.dataPtr_.get() + length_, dataPtr_.get());
};

string::string(string&& other) : length_{other.length_}, dataPtr_{std::move(other.dataPtr_)} {};

string& string::operator=(const string& other) {
    length_ = other.length_;
    resizeD_(length_);
    std::ranges::copy(other.dataPtr_.get(), other.dataPtr_.get() + length_, dataPtr_.get());
    return *this;
};

size_t string::getLen() { return length_; }

string& string::operator=(string&& other) {
    length_ = other.length_;
    dataPtr_ = std::move(other.dataPtr_);
    return *this;
};

bool operator<(const string& str1, const string& str2) { return str1.length_ < str2.length_; }
bool operator>(const string& str1, const string& str2) { return str1.length_ > str2.length_; }
bool operator!=(const string& str1, const string& str2) {
    if (str1.length_ != str2.length_) return true;
    for (size_t i = 0; i < str1.length_; i++) {
        if (str1.dataPtr_[i] != str2.dataPtr_[i]) return true;
    }
    return false;
}
bool operator<=(const string& str1, const string& str2) { return str1.length_ <= str2.length_; }
bool operator>=(const string& str1, const string& str2) { return str1.length_ >= str2.length_; }
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
    char tmp;
    size_t counter = 0;
    for (; is.get(tmp) && tmp != '\n'; counter++) {
        if (counter >= obj.length_ - 1) {
            obj.resize_(obj.length_ * 2);
        }
        obj.dataPtr_[counter] = tmp;
    }
    obj.resize_(counter + 1);
    obj.dataPtr_[counter] = '\0';

    is.clear();
    return is;
}

void string::resizeD_(size_t newLen) {
    length_ = newLen;
    std::unique_ptr<char[]> tmp{new char[length_]};
    dataPtr_ = std::move(tmp);
}
void string::resize_(size_t newLen) {
    length_ = newLen;
    std::unique_ptr<char[]> tmp{new char[length_]};
    std::ranges::copy(dataPtr_.get(), dataPtr_.get() + length_, tmp.get());
    dataPtr_ = std::move(tmp);
}
void printString(const string& str){
    std::cout << str.dataPtr_.get();
}
string readString(void){
    string str;
    char tmp;
    size_t counter = 0;
    for (; std::cin.get(tmp) && tmp != '\n'; counter++) {
        if (counter >= str.length_ - 1) {
            str.resize_(str.length_ * 2);
        }
        str.dataPtr_[counter] = tmp;
    }
    str.resize_(counter + 1);
    str.dataPtr_[counter] = '\0';
    return str;
}
}  // namespace str
