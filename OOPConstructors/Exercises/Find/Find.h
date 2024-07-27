//
// Created by uchih on 27.7.2024 г..
//

#ifndef FIND_H
#define FIND_H

Company* find(std::vector<Company*> & companies, int searchId) {
    for (auto c : companies) {
        if (c->getId() == searchId)
            return c;
    }
    return nullptr;
}


#endif //FIND_H
