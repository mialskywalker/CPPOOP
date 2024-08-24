//
// Created by uchih on 23/08/2024.
//
#include "Range.h"
#include <algorithm>

Range::Range() : rangeFirst(0), rangeLength(0), valueCounts(nullptr) {}

Range::~Range() {
    clear();
}

bool Range::empty() const {
    return valueCounts == nullptr;
}

Range::Range(const Range &other) : Range() {
    *this = other;
}

void Range::clear() {
    if (!empty()) {
        delete[] valueCounts;
        valueCounts = nullptr;
        rangeFirst = rangeLength = 0;
    }
}

size_t Range::getIndex(T value) const {
    return value - rangeFirst;
}


void Range::add(T value) {
    T first = rangeFirst;
    T last = rangeFirst + rangeLength - 1;

    if (empty())
        resize(value, value);
    else if (value < first)
        resize(value, last);
    else if (value > last)
        resize(first, value);

    valueCounts[getIndex(value)]++;
}

size_t Range::getCount(T value) const {
    if (value >= rangeFirst && value < (rangeFirst + rangeLength))
        return valueCounts[getIndex(value)];
    else
        return 0;
}

Range &Range::operator=(const Range &other) {
    clear();
    this->rangeFirst = other.rangeFirst;
    this->rangeLength = other.rangeLength;
    this->valueCounts = copyValues(other);
    return *this;
}



void Range::resize(T first, T last) {
    T newFirst = first;
    T newLength = last - first + 1;

    size_t * newCounts = new size_t[newLength] {0};

    if (!empty()) {
        std::copy(
            valueCounts,
            valueCounts + rangeLength,
            newCounts + (rangeFirst - first)
            );
        clear();
    }

    rangeFirst = newFirst;
    rangeLength = newLength;
    valueCounts = newCounts;
}






