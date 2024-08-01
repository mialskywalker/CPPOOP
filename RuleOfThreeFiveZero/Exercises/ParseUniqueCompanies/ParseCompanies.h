#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"
#include <memory>
#include <sstream>
#include <string>
#include <list>
#include <set>

Company* parseUniqueCompanies(const std::string & input, int & numCompanies, std::string (*func)(const Company& c)) {

    std::istringstream istr(input);
    std::list<Company> companies;
    std::set<std::string> ids;

    int id;
    while (istr >> id) {
        std::string name;
        istr >> name;

        Company curr(id, name);
        std::string currId = func(curr);

        if (ids.find(currId) == ids.end()) {
            companies.push_back(curr);
            ids.insert(currId);
        }
    }

    Company * result = new Company[companies.size()];
    numCompanies = 0;
    for (auto & c : companies)
        result[numCompanies++] = c;
    return result;
}


#endif // !PARSE_COMPANIES_H
