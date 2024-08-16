#include <iostream>
#include <string>

class IntArray {
    int* data;
    int size;

public:
    // Constructs array of int with specified size
    IntArray(int size) : data(new int[size]{}), size(size) {}

    // Destroys the array to prevent memory leak
    ~IntArray() {
        delete[] this->data;
    }

    // Copy Constructor which sets current array data to nullptr to prevent memory leak
    IntArray(const IntArray& other) : data(nullptr), size(0) {
        this->resetData(other.data, other.size);
    }

    // Copy Assignment operator which resets current data to prevent memory leak
    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            this->resetData(other.data, other.size);
        }
        return *this;
    }

    int getSize() const {
        return this->size;
    }

    int& operator[](const int index) const {
        return this->data[index];
    }


    // function which handles the correct copying of arrays without leaving memory leak
private:
    void resetData(int* otherData, int otherSize) {
        int* copyData = new int[otherSize];

        for (int i = 0; i < otherSize; i++)
            copyData[i] = otherData[i];

        if (this->data != nullptr)
            delete[] this->data;

        this->data = copyData;
        this->size = otherSize;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
