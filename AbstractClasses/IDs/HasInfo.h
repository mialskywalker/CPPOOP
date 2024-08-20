//
// Created by uchih on 20/08/2024.
//

#ifndef HASINFO_H
#define HASINFO_H

#include <string>

struct HasInfo {
    virtual std::string getInfo() const = 0;
    virtual ~HasInfo() = default;
};

#endif //HASINFO_H
