#pragma once

#include "string.hh"

namespace screen_handlers {
void printMainScreen();
bool inputStrings(str::String &str1, str::String &str2);
bool printStrings(const str::String &str1, const str::String &str2);
bool checkOperators(const str::String &str1, const str::String &str2);
}  // namespace screen_handlers
