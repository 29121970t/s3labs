#pragma once
#include <format>
#include <iostream>
#include <limits>
namespace console_utils {

std::pair<int, int> getConsoleDimensions();

template <typename T, typename CT>
void readT(T& data, const std::string& massage, CT bound) {
    std::cout << massage;
    std::cin >> data;
    if (std::cin.fail() || !bound(data)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::runtime_error("Invalid input.");
    }
}
template <typename T>
void readT(T& data, const std::string& massage) {
    std::cout << massage;
    std::cin >> data;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
        std::cin.clear();
        throw std::runtime_error("Invalid input.");
    }
}
}  // namespace console_utils
