//
// Created by uchih on 16/08/2024.
//

#ifndef PARSECOMPANIES_H
#define PARSECOMPANIES_H

#include "Company.h"
#include <sstream>
#include <set>

Company* parseUniqueCompanies(const std::string & input, int & number, std::string (*func)(const Company& c)) {
    std::list<Company> companies;
    std::istringstream istr(input);
    std::set<std::string> ids;

    int id;
    while (istr >> id) {
        std::string name;
        istr >> name;

        Company cur(id, name);
        std::string curId = func(cur);

        if (ids.find(curId) == ids.end()) {
            companies.push_back(cur);
            ids.insert(curId);
        }
    }

    Company * result = new Company[companies.size()];
    number = 0;
    for (auto & c : companies)
        result[number++] = c;
    return result;


}

#endif //PARSECOMPANIES_H
