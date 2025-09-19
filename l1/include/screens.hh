#pragma once

#include "matrix.hh"

namespace screen_handlers {
bool inputMatrix(mat::Matrix& mat);
bool printMatrix(const mat::Matrix& mat);
bool subtractFromElement(const mat::Matrix& mat);
void printMainScreen();
}  // namespace screen_handlers