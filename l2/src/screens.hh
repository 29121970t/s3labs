#pragma once

#include "string.hh"

namespace screen_handlers {
void printMainScreen();
bool inputStrings(str::string &str1, str::string &str2);
bool printStrings(const str::string &str1, const str::string &str2);
bool checkOperators(const str::string &str1, const str::string &str2);
}  // namespace screen_handlers
