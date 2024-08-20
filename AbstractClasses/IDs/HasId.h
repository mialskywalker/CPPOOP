//
// Created by uchih on 20/08/2024.
//

#ifndef HASID_H
#define HASID_H

struct HasId {
    virtual int getId() const = 0;
    virtual ~HasId() = default;
};

#endif //HASID_H
