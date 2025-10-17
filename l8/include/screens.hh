#pragma once
#include <l8/include/list.hh>
#include <memory>

namespace screens {
void printMainScreen();
bool inputList(cList::CircleList<double> &list);
bool addElement(cList::CircleList<double> &list);
bool clearList(cList::CircleList<double> &list);
bool sortList(cList::CircleList<double> &list);
bool findElement(cList::CircleList<double> &list);
bool printList(cList::CircleList<double> &list);
}  // namespace screens
