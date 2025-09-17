#pragma once
#include <execution>
#include <iostream>
#include <limits>
#include <memory>
#include <ranges>
#include <vector>

namespace str {
class string {
   private:
    size_t length_;
    std::unique_ptr<char[]> dataPtr_;

    void resizeD_(size_t newLen);
    void resize_(size_t newLen);

   public:
    string(const char* str);
    string();
    string(const string& other);
    string(string&& other);
    ~string() = default;

    size_t getLen();

    string& operator=(const string& other);
    string& operator=(string&& other);

    

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    friend bool operator<(const string& str1, const string& str2);
    friend bool operator>(const string& str1, const string& str2);
    friend bool operator!=(const string& str1, const string& str2);
    friend bool operator<=(const string& str1, const string& str2);
    friend bool operator>=(const string& str1, const string& str2);

    friend std::ostream& operator<<(std::ostream& os, const string& obj);
    friend std::istream& operator>>(std::istream& is, string& obj);
    
    friend void printString(const string& str);
    friend string readString(void);
};
void printString(const string& str);
string readString(void);
}  // namespace str

