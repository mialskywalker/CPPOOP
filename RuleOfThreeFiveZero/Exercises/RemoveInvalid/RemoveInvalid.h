//
// Created by uchih on 1.8.2024 г..
//

#ifndef REMOVEINVALID_H
#define REMOVEINVALID_H

#include "Company.h"
#include <list>

void removeInvalid(std::list<Company*> & companies) {
    // for (Company* c : companies) {
    //     if (c->getId() < 0)
    //         companies.remove(c);
    // }
    std::list<Company*>::iterator it = companies.begin();
    for (; it != companies.end();) {
        if ((*it)->getId() < 0) {
            delete *it;
            it = companies.erase(it);
        }
        else
            it++;
    }

}

#endif //REMOVEINVALID_H
