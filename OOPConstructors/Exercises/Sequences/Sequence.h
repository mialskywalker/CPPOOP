//
// Created by uchih on 30.7.2024 г..
//

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <algorithm>

template<typename T, typename Generator>
class Sequence {
    Generator gen;
    typedef std::vector<T> Data;
    Data data;

public:
    void generateNext(size_t num) {
        while(num--)
            data.push_back(gen());
    }

    class Iterator {
        Data & data;
        size_t idx;

    public:
        Iterator(Data & data, size_t idx) : data(data), idx(idx) {}

        static Iterator getBegin(Data & data) { return Iterator(data, 0); }
        static Iterator getEnd(Data & data) { return Iterator(data, SIZE_MAX); }

        bool operator != (const Iterator & other) const {
            if ((&data) != (&other.data))
                return true;

            if (idx == other.idx)
                return false;

            if (idx >= data.size() && other.idx >= other.data.size())
                return false;

            return true;
        }

        Iterator & operator ++ () {
            idx++;
            return *this;
        }

        T & operator *() {
            return data[idx];
        }
    };

    Iterator begin() { return Iterator::getBegin(data); }
    Iterator end() { return Iterator::getEnd(data); }

};

#endif //SEQUENCE_H
