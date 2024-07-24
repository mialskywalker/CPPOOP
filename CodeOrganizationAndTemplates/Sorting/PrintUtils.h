//
// Created by uchih on 19.7.2024 г..
//

#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>

template<typename T>
void printContainer(typename T::iterator itB, typename T::iterator itE) {

    for (; itB != itE; itB++)
        std::cout << *itB << ' ';
    std::cout << std::endl;
}

#endif //PRINTUTILS_H
