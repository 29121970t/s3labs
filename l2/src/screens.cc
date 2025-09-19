#include <consoleUtils.hh>
#include <iostream>
#include <print>
#include <l2/include/screens.hh>

using namespace std;
namespace screen_handlers {
void printMainScreen() {
    auto [cols, rows] = console_utils::getConsoleDimensions();
    println("{:^{}}", "\x{1B}[48;5;35mLab 2\x{1B}[0m", cols);
    println("Please select action:\n");
    println("    1.Input 2 strings");
    println("    2.Print strings");
    println("    3.Check operators");
    println("    4.Exit");
}
bool inputStrings(str::String &str1, str::String &str2) {
    cout << "Please enter first string:";
    cin >> str1;
    cout << "Please enter second string:";
    cin >> str2;
    return true;
}
bool printStrings(const str::String &str1, const str::String &str2) {
    cout << "First string: " << str1 << std::endl;
    cout << "Second string: " << str2 << std::endl;
    return true;
}
bool checkOperators(const str::String &str1, const str::String &str2) {
    println("str1 < str2: {}", str1 < str2);
    println("str1 > str2: {}", str1 > str2);
    println("str1 <= str2: {}", str1 <= str2);
    println("str1 >= str2: {}", str1 >= str2);
    println("str1 != str2: {}", str1 != str2);
    return true;
}
}  // namespace screen_handlers
