//
// Created by uchih on 23/08/2024.
//

#ifndef INCLUDES_H
#define INCLUDES_H

#include<iostream>
#include <vector>
#include <sstream>
#include "City.h"

std::istream& operator>>(std::istream& is, City& city) {
    unsigned int censusYear;
    std::string name;
    size_t population;
    is >> name >> population >> censusYear;
    City c(censusYear, name, population);
    city = c;
    return is;
}

typedef std::string CityDiff;

CityDiff operator-(City& c1, City& c2) {
    std::ostringstream os;
    if (c1.getName() == c2.getName()) {
        os << c1.getName() << " (" << c1.getCensusYear() << " vs. " << c2.getCensusYear() << ")" << std::endl;
    }
    else {
        os << c1.getName() << " (" << c1.getCensusYear() << ") vs. " << c2.getName() << " (" << c2.getCensusYear() << ")" << std::endl;
    }

    size_t population = abs(c1.getPopulation() - c2.getPopulation());

    os << "population: ";
    if (c1.getPopulation() >= c2.getPopulation())
        os << '+';
    else
        os << '-';
    os << population << std::endl;

    return os.str();
}

#endif //INCLUDES_H
