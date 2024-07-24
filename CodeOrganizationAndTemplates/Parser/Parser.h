//
// Created by uchih on 19.7.2024 г..
//

#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include <string>
#include <sstream>

template<typename T>
class Parser {
    std::istream & in;
    std::string stopLine;

public:
    Parser(std::istream & in, std::string stopLine) : in(in), stopLine(stopLine) {}

    bool readNext(T & t) {
        std::string line;
        getline(in, line);
        if (line == stopLine)
            return false;

        std::istringstream istr(line);
        istr >> t;

        return true;
    }

};

#endif //PARSER_H
