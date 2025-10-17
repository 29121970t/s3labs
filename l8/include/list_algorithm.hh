#pragma once
#include <optional>

#include "list.hh"
namespace cList {
template <class U>
CircleList<U>::const_iterator find(typename CircleList<U>::iterator begin,
                                   typename CircleList<U>::iterator end, U& data) {
    for (; begin != end; ++begin) {
        if (*begin == data) break;
    }
    return begin;
}
template <typename T>
void swap(typename CircleList<T>::iterator a, typename CircleList<T>::iterator b) {
    typename CircleList<T>::iterator t = a;
    *a = *b;
    *b = t;
}

template<typename Iter>
void print(const Iter& beg, const Iter& end)
{
    std::for_each(beg, end, [](auto& i) { std::cout << i << " "; });
    std::cout << std::endl;
}

template <typename ForwardIterator>
void bubbleSort(ForwardIterator first, ForwardIterator last) {
    if (first == last) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        ForwardIterator current = first;
        ForwardIterator next_it = std::next(current);

        while (next_it != last) {
            if (*next_it < *current) {
                std::iter_swap(current, next_it);
                swapped = true;
            }
            ++current;
            ++next_it;
        }
    } while (swapped);
}
}  // namespace cList
