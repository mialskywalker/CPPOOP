//
// Created by uchih on 1.8.2024 г..
//

#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <climits>

template <typename T>
class SmartArray {
public:
    SmartArray(size_t size) : _size(size), _data(_size ? new T[_size]{} : nullptr) {}

    SmartArray(const SmartArray &other) = delete;
    SmartArray(SmartArray && ) = delete;
    SmartArray & operator=(const SmartArray &) = delete;
    SmartArray & operator=(SmartArray &&) = delete;

    void resize(size_t newSize, const T * _newData = nullptr) {
        std::unique_ptr<T[]> _dataNew(new T[newSize]);

        size_t dataSize;
        if (_newData != nullptr)
            dataSize = newSize;
        else {
            _newData = _data.get();
            dataSize = newSize < _size ? newSize : _size;
        }

        // for (size_t curIdx = 0; curIdx < newSize; curIdx++)
        //     _newData[curIdx] = _data[curIdx];
        std::copy(_newData, _newData + dataSize, _dataNew.get());

        _data = std::move(_dataNew);
        _size = newSize;
    }

    T &operator[](size_t index) {
        return _data[index];
    }

    void print() const {
        for (size_t i = 0; i < _size; ++i)
            std::cout << _data[i] << ' ';
        std::cout << std::endl;
    }

    class Iterator {
        T * data;
        size_t size;
        size_t idx;

    public:
        Iterator(size_t idx, SmartArray & parent) : idx(idx), data(parent._data.get()), size(parent._size) {}

        T & operator *() {
            static T nullValue(0);
            if (idx < size)
                return data[idx];
            else
                return nullValue;
        }

        Iterator & operator++(int) {
            idx++;
            return *this;
        }

        bool operator != (const Iterator & other) {
            if (data != other.data || size != other.size)
                return true;
            if (idx >= size && other.idx >= other.size)
                return false;

            return idx != other.idx;
        }
    };

    Iterator begin() { return Iterator(0, *this); }
    Iterator end() { return Iterator(SIZE_MAX, *this); }

private:
    size_t _size;
    std::unique_ptr<T[]> _data;
};

#endif //SMARTARRAY_H
