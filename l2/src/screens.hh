#pragma once

#include "string.hh"

namespace screen_handlers {
void printMainScreen();
void inputStrings(str::string &str1, str::string &str2);
void printStrings(const str::string &str1, const str::string &str2);
void checkOperators(const str::string &str1, const str::string &str2);
}  // namespace screen_handlers
