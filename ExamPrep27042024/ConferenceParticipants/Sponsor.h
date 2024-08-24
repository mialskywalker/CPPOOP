//
// Created by uchih on 23/08/2024.
//

#ifndef SPONSOR_H
#define SPONSOR_H

#include "Participant.h"

class Sponsor : public Participant {
public:
    static Participant::Vector all;

    Sponsor(std::istream& istr) : Participant(istr) {
        istr >> company;
        all.push_back(this);
    }

protected:

    std::string company;
};

#endif //SPONSOR_H
