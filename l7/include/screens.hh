#pragma once
#include <memory>
#include "vector.hh"
namespace screens {
void printMainScreen();
bool inputVector(vec::Vector<double> &vec);
bool addVectors(const vec::Vector<double> &vec1,const vec::Vector<double> &vec2);
bool printVectors(const vec::Vector<double> &vec1,const vec::Vector<double> &vec2);
}  // namespace screens
