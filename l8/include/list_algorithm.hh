#pragma once
#include <optional>

#include "list.hh"
namespace cList {
template <typename U, typename Iter = CircleList<U>::iterator>
Iter find(Iter begin, Iter end, U& data) {
    for (; begin != end; ++begin) {
        if (*begin == data) break;
    }
    return begin;
}

template <std::input_iterator ForwardIterator>
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
