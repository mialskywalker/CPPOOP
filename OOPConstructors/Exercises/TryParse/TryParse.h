//
// Created by uchih on 27.7.2024 г..
//

#ifndef TRYPARSE_H
#define TRYPARSE_H

#include <sstream>

inline bool tryParse(std::string & s, int & num) {
    std::istringstream istr(s);
    istr >> num;
    return num;
}

#endif //TRYPARSE_H
