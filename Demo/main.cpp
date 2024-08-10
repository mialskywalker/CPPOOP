#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Student {
    string name;
    string surname;
    double average;

public:
    Student(string name, string surname, double average) :
        name(name),
        surname(surname),
        average(average) {}

    double getAverage() { return this->average; }

    string printInfo() {
        ostringstream os;
        os << this->name << ' ' << this->surname << ' ' << this->average << endl;
        return os.str();
    }
};

int main() {
    vector<Student> students;

    int n;
    cin >> n;
    if (n < 1) {
        cout << "Invalid input" << endl;
        return 0;
    }

    string name, surname;
    double avg;
    while (n--) {
        cin >> name >> surname >> avg;
        students.push_back(Student(name, surname, avg));
    }

    double total = 0;
    for (Student s : students) {
        cout << s.printInfo();
        total += s.getAverage();
    }

    total /= students.size();
    cout << total << endl;

}
