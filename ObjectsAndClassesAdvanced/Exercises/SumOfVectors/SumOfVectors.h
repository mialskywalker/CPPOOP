//
// Created by uchih on 10.7.2024 г..
//

#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H
#include <string>
#include <vector>

inline std::vector<std::string> operator+ (std::vector<std::string>& v1, std::vector<std::string>& v2) {
    std::vector<std::string> v3;

    for (int i = 0; i < v1.size(); i++) {
        v3.push_back(v1[i] + " " + v2[i]);
    }
    return v3;
};

#endif //SUMOFVECTORS_H
