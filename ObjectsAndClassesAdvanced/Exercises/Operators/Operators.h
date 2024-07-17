//
// Created by uchih on 10.7.2024 г..
//

#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> & operator<< (std::vector<std::string>& v, std::string& s) {
    v.push_back(s);
    return v;
}

std::string operator+(std::string& s, int& i) {
    s = std::to_string(i);
    return s;
}

std::string operator+(std::string& s, std::string::size_type size) {
    s += std::to_string(size);
    return s;
}

std::ostream& operator<<(std::ostream& out, std::vector<std::string>& v) {
    bool bFirst = true;
    for (std::string& el : v) {
        if (bFirst) {
            out << el;
            bFirst = false;
        }
        else
            out << std::endl << el;
    }
    return out;
}

#endif //OPERATORS_H
