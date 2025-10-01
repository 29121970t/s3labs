#pragma once
#include <format>
#include <iostream>
#include <limits>
#include <exception>
namespace console_utils {

std::pair<int, int> getConsoleDimensions();
struct invalid_input_error : public std::exception {};
template <typename T, typename CT>
void readT(T& data, const std::string& massage, CT bound) {
    std::cout << massage;
    std::cin >> data;
    if (std::cin.fail() || !bound(data)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw invalid_input_error();
    }
}
template <typename T>
void readT(T& data, const std::string& massage) {
    std::cout << massage;
    std::cin >> data;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
        std::cin.clear();
        throw invalid_input_error();
    }
}
}  // namespace console_utils
