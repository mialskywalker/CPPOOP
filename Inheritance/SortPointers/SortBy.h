//
// Created by uchih on 17/08/2024.
//

#ifndef SORTBY_H
#define SORTBY_H

#include "Company.h"
#include <algorithm>

void sortBy(Company** from, Company** to, bool (*func)(const Company& a, const Company& b)) {
    struct SortF {
        bool(*func)(const Company& a, const Company& b);
        SortF(bool(*func)(const Company& a, const Company& b)) : func(func) {}

        bool operator()(Company *first, Company *second) {
            return func(*first, *second);
        }
    };
    std::sort(from, to, SortF(func));
}

#endif //SORTBY_H
