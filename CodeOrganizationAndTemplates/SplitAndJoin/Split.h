//
// Created by uchih on 19.7.2024 г..
//

#ifndef SPLIT_H
#define SPLIT_H

#include <istream>
#include <string>
#include <vector>
#include <sstream>

template <class T>
std::vector<T> split(const std::string & line, char separator) {
    std::istringstream is(line);
    std::vector<T> res;

    while(true) {
        std::string buffer;
        getline(is, buffer, separator);
        if (!is)
            break;

        std::istringstream eltS(buffer);
        T t;
        eltS >> t;
        res.push_back(t);
    }
    std::string buffer;
    return res;
}


#endif //SPLIT_H
