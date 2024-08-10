#include <iostream>
#include <sstream>

using namespace std;

class Person {
private:
    string name;
    int age = 0;

public:

    Person(string name, int age) :
        name(name),
        age(age) {}

    Person() {
        name = "<unknown>";
    }

    // Getters
    string getName() { return this->name; }
    int getAge() { return this->age; }

    // Setters
    void changeName(string newName) {
        this->name = newName;
    }
    void changeAge(int newAge) {
        this->age = newAge;
    }

    // Print info
    string getInfo() {
        ostringstream os;
        os << this->name << ": " << this->age << " years old." << endl;
        return os.str();
    }
};

int main() {

    Person p;
    cout << "Before: " << p.getInfo();
    p.changeName("<known>");
    p.changeAge(12);
    cout << "After: " << p.getInfo();

    Person gosho("Gosho", 12);
    cout << "Before: " << gosho.getInfo();
    gosho.changeName("Sasho");
    gosho.changeAge(22);
    cout << "After: " << gosho.getInfo();



    return 0;
}
