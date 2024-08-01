//
// Created by uchih on 1.8.2024 г..
//

#ifndef MINBY_H
#define MINBY_H

std::string minBy(std::vector<std::string> &values, bool func(const std::string &a, const std::string &b)) {
    std::string result = values[0];
    for (int i = 1; i < values.size(); i++) {
        if (func(values[i], result))
            result = values[i];
    }

    return result;
}

#endif //MINBY_H
