//
// Created by uchih on 23/08/2024.
//

#ifndef CITYUTILS_H
#define CITYUTILS_H
#include <algorithm>
#include <map>

City* initCity(std::string& name, size_t population) {
    City* c = new City(name, population);
    return c;
}

std::map<size_t, const City*> groupByPopulation(std::vector<const City*> cities, size_t &total) {
    total = 0;
    std::map<size_t, const City*> city;
    std::sort(cities.begin(), cities.end(),
        [] (const City* a, const City* b) { return a->getPopulation() < b->getPopulation(); });

    for (auto it = cities.begin(); it != cities.end(); it++) {
        total += (*it)->getPopulation();
        city[(*it)->getPopulation()] = *it;
    }

    return city;
}

#endif //CITYUTILS_H
