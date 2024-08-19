//
// Created by uchih on 17/08/2024.
//

#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array {
    T* data;
    size_t size;

public:
    Array(size_t size) : data(new T[size]{}), size(size) {}

    Array() = default;

    ~Array() {
        delete[] this->data;
    }

    Array(const Array& other) : data(nullptr), size(0) {
        this->resetData(other.data, other.size);
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            this->resetData(other.data, other.size);
        }
        return *this;
    }

    int& operator[] (size_t id) {
        return data[id];
    }

    size_t getSize() const { return this->size; }

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = int*;
        using reference         = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&data[0]); }
    Iterator end()   { return Iterator(&data[size]); }


private:
    void resetData(T* otherData, size_t otherSize) {
        T* copyData = new T[otherSize];
        for (size_t i = 0; i < otherSize; i++)
            copyData[i] = otherData[i];

        if (this->data != nullptr)
            delete[] this->data;

        this->data = copyData;
        this->size = otherSize;
    }

};

#endif //ARRAY_H
