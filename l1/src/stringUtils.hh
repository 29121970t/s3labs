#pragma once
#include <iostream>
#include <limits>

#ifdef __linux__

#include <sys/ioctl.h>
#include <unistd.h>

#endif

#ifdef _WIN32
#include <windows.h>
#endif

namespace strUtils {

#ifdef _WIN32
std::pair<int, int> getConsoleDimensions() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return std::make_pair(csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
}
#endif

#ifdef __linux__

#include <sys/ioctl.h>
#include <unistd.h>
std::pair<int, int> getConsoleDimensions() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return std::make_pair(w.ws_col, w.ws_row);
}

#endif

template <typename T, typename CT>
void readT(T& data, const std::string& massage, CT bound) {
    std::cout << massage;
    while (((std::cin >> data).fail()) || !bound(data)) {
        std::cout << "Invalid input. Reread input requierments\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << massage;
    }
}
template <typename T>
void readT(T& data, const std::string& massage) {
    std::cout << massage;
    while (((std::cin >> data).fail())) {
        std::cout << "Invalid input. Reread input requierments\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << massage;
    }
}
template <typename T, typename CT>
void readT(T& data, const std::string& message, CT bound, const std::string& errmess) {
    std::cout << message;
    while (((std::cin >> data).fail()) || !bound(data)) {
        std::cout << errmess;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << message;
    }
}
}  // namespace strUtils
