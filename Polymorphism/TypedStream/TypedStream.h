//
// Created by uchih on 19/08/2024.
//

#ifndef TYPEDSTREAM_H
#define TYPEDSTREAM_H

#include <sstream>
#include <vector>

template<typename T>
class TypedStream {
protected:
    std::istringstream stream;

public:
    TypedStream(const std::string& input) :stream(input) {}
    virtual ~TypedStream() = default;

    virtual TypedStream<T> & operator>>(T & i) {
        return *this;
    }

    std::vector<T> readToEnd() {
        std::vector<T> res;

        T curr;
        while (true) {
            *this >> curr;
            if ((bool)stream == false)
                break;
            res.push_back(curr);
        }

        return res;
    }
};

#endif //TYPEDSTREAM_H
