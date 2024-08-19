//
// Created by uchih on 19/08/2024.
//

#ifndef REMOVEDUPLICATES_H
#define REMOVEDUPLICATES_H

#include "Company.h"
#include <set>

void removeDuplicates(std::list<Company*>::iterator it, std::list<Company*>& list) {
    std::set<Company*> toDelete;
    Company * theCompany = *it;
    std::string theName = theCompany->getName();
    it++;
    while(it != list.end()) {
        if (*it == theCompany) {
            it = list.erase(it);
        }
        else if ((*it)->getName() == theName) {
            toDelete.insert(*it);
            it = list.erase(it);
        }
        else
            it++;
    }

    for (auto c : toDelete)
        delete c;
}

void removeDuplicates(std::list<Company*>& list) {
    std::list<Company*>::iterator it = list.begin();

    while(it != list.end()) {
        removeDuplicates(it, list);
        it++;
    }
}

#endif //REMOVEDUPLICATES_H
