//
// Created by uchih on 17/08/2024.
//

#ifndef RANGES_H
#define RANGES_H

#include <string>


class Range {
    int from;
    int to;

public:
    Range(int from, int to);

    bool isInRange(int number);

};

#endif //RANGES_H
