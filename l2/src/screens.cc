#include <iostream>
#include <print>

#include "string.hh"
#include "consoleUtils.hh"


namespace screen_handlers {
void printMainScreen() {
    auto [cols, rows] = console_utils::getConsoleDimensions();
    std::println("{:^{}}", "\x{1B}[48;5;35mLab 2\x{1B}[0m", cols);
    std::println("Please select action:\n");
    std::println("    1.Input 2 strings");
    std::println("    2.Print strings");
    std::println("    3.Check operators");
    std::println("    4.Exit");
}
void inputStrings(str::string &str1, str::string &str2) {
    std::cout << "Please enter first string:";
    std::cin >> str1;
    std::cout << "Please enter second string:";
    std::cin >> str2;
}
void printStrings(const str::string &str1, const str::string &str2) {
    std::cout << "First string: " << str1 << std::endl;
    std::cout << "Second string: " << str2 << std::endl;
}
void checkOperators(const str::string &str1, const str::string &str2) {
    std::println("str1 < str2: {}", str1 < str2);
    std::println("str1 > str2: {}", str1 > str2);
    std::println("str1 <= str2: {}", str1 <= str2);
    std::println("str1 >= str2: {}", str1 >= str2);
    std::println("str1 != str2: {}", str1 != str2);
}
}  // namespace screen_handlers
