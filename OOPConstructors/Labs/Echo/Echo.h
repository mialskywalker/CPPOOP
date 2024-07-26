//
// Created by uchih on 26.7.2024 г..
//

#ifndef ECHO_H
#define ECHO_H

#include <iostream>

static bool echoOn = true;

inline void echo(const std::string & echo) {
    if (echoOn) {
        std::cout << echo << std::endl;
    }
}

#endif //ECHO_H
