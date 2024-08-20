//
// Created by uchih on 20/08/2024.
//

#ifndef BYTECONTAINER_H
#define BYTECONTAINER_H

#include <string>

class ByteContainer {

    std::string contents;

public:

    ByteContainer(const std::string & contents) :contents(contents) {};
    virtual ~ByteContainer() {};

    const std::string & getBytes(void) const {
        return contents;
    };

};


#endif //BYTECONTAINER_H
