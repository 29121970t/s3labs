#pragma once
#include <memory>
#include "vector.hh"
namespace screens {
void printMainScreen();
bool inputVector(vec::Vector<double> &vec);
bool addVectors(vec::Vector<double> &vec1, vec::Vector<double> &vec2);
bool printVectors(vec::Vector<double> &vec1, vec::Vector<double> &vec2);
}  // namespace screens
