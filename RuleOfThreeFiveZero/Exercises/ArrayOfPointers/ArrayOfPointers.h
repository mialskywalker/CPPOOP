//
// Created by uchih on 16/08/2024.
//

#ifndef ARRAYOFPOINTERS_H
#define ARRAYOFPOINTERS_H
#include "Company.h"
#include <vector>
#include <memory>


class ArrayOfPointers {
    std::vector<std::unique_ptr<Company>> data;

public:

    void add(Company * c) {
        data.push_back(std::unique_ptr<Company>(c));
    }

    size_t getSize() const {
        return data.size();
    }

    Company * get(size_t id) const {
        return data[id].get();
    }

};

#endif //ARRAYOFPOINTERS_H
