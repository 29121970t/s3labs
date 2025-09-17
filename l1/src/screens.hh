#pragma once

#include "matrix.hh"

namespace screen_handlers {
void inputMatrix(mat::Matrix& mat);
void printMatrix(const mat::Matrix& mat);
void subtractFromElement(mat::Matrix& mat);
void printMainScreen();
}  // namespace screen_handlers