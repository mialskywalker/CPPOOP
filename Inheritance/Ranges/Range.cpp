//
// Created by uchih on 17/08/2024.
//

#include "Range.h"

Range::Range(int from, int to) : from(from), to(to) {}

bool Range::isInRange(int number) {
    return this->from <= number && this->to >= number;
}



