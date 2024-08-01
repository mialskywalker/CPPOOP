//
// Created by uchih on 1.8.2024 г..
//

#ifndef MAKECOMPANY_H
#define MAKECOMPANY_H

#include "Company.h"
#include <vector>
#include <memory>
#include <string>

std::shared_ptr<Company> makeCompany(const std::vector<std::string> & properties) {

    std::vector<std::pair<char, char>> a;
    if (properties.size() > 2) {
        for (int i = 2; i < properties.size(); i++) {
            a.push_back(std::pair<char, char>(properties[i][0], properties[i][1]));
        }
    }

    return std::make_shared<Company>(stoi(properties[0]), properties[1], a);

}


#endif //MAKECOMPANY_H
