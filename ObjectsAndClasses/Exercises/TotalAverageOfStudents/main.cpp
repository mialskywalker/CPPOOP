#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    string surname;
    double average = 0;

    Student() {
        this->name = name;
        this->surname = surname;
        this->average = average;
    }
};

int main() {
    vector<Student> students;
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }


    while (n--) {
        string name, surname;
        double grade;
        cin >> name >> surname >> grade;

        Student student;
        student.name = name;
        student.surname = surname;
        student.average = grade;

        students.push_back(student);
    }

    double avg;
    for (Student s: students) {
        avg += s.average;
        cout << s.name << " " << s.surname << " " << s.average << endl;
    }
    avg /= students.size();
    cout << avg << endl;


    return 0;
}
