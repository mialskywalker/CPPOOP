#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>

void sortBy(Company** start, Company** end, bool (*func)(const Company& a, const Company& b)) {
    struct SortFunc {
        bool(*func)(const Company& a, const Company& b);
        SortFunc(bool(*func)(const Company& a, const Company& b)) : func(func) {}

        bool operator()(Company *first, Company *second) {
            return func(*first, *second);
        }
    };
    std::sort(start, end, SortFunc(func));
}

#endif // !SORT_BY_H
