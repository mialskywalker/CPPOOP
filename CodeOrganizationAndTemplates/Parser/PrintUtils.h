//
// Created by uchih on 19.7.2024 г..
//

#ifndef PRINTUTILS_H
#define PRINTUTILS_H

template<typename T>
void printVector(T & v) {

    typename T::iterator counter = v.begin();

    for(; counter != v.end(); counter++)
        std::cout << *counter << ' ';
}

#endif //PRINTUTILS_H
