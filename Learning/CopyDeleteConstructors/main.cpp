#include <iostream>
#include <string>

using namespace std;

class Lesson {
    string subject;
    int numStudents;

public:
    // Normal Constructor -> called when given parameters: Lesson l("some subject", 24);
    Lesson(string subject, int numStudents)
        : subject(subject), numStudents(numStudents) {}

    // Default Constructor -> called when no parameters are given: Lesson l;
    Lesson() {} // same as Lesson() = default;

    // Copy Constructor -> called when using a copy of the class: not & reference
    Lesson(const Lesson& other)
        : subject(other.subject), numStudents(other.numStudents) {}

    // Copy Assign Operator -> called when assigning 1 object to other: Lesson c = Lesson a;
    Lesson& operator=(const Lesson& other) {
        this->subject = other.subject;
        this->numStudents = other.numStudents;
        return *this;
    }

    const string& getSubject() const { return this->subject; }
    int getNumStudents() const { return this->numStudents; }

};

class IntArray {
    int* data;
    int size;

public:
    IntArray(int size) : data(new int[size]), size(size) {}

    // Destructor -> called when the object's lifetime ends
    ~IntArray() {
        delete[] this->data;
    }

    int getSize() const { return this->size; }


    // Disables Copy Constructor and Copy Assignment -> to avoid memory issues when using Delete Constructor to delete the int* data array
    IntArray(const IntArray& other) = delete;
    IntArray& operator=(const IntArray& other) = delete;
};

void printLesson(Lesson lessonCopy) {
    cout << lessonCopy.getSubject() << ": "
    << "attended by " << lessonCopy.getNumStudents() << " students." << endl;
}

int main(){
    Lesson lesson1("Pointers and References", 5);
    Lesson copy = lesson1; // called Copy Assign Operator
    printLesson(lesson1); // called Copy Constructor -> object not given by reference
    return 0;
}
