#include <iostream>
#include <sstream>

using namespace std;

class Person {

    class Body {
    public:
        double height = 0;
        double weight = 0;

        Body(double height, double weight) :
            height(height),
            weight(weight) {}

        Body() {}
    };

public:
    string name;
    int age = 0;
    Body body;

    // Person(string name, int age) {
    //     this->name = name;
    //     this->age = age;
    // }
    // Same as:
    Person(string name, int age, double height, double weight) :
        name(name),
        age(age),
        body(height, weight) {}

    // Default constructor --- can call Person p without parameters
    Person() {
        name = "<unknown>";
    }

    // Method inside the class
    string getInfo() {
        ostringstream os;
        os << this->name << ": " << this->age << " years old, " << this->body.height << "cm tall, " << this->body.weight << "kgs." << endl;
        return os.str();
    }

    void makeOlder(int years) {
        this->age += years;
    }
};



int main() {
    Person p("Gosho", 12, 171, 65);
    Person gosho;
    cout << "Before: " << p.getInfo();
    p.makeOlder(1);
    cout << "After: " << p.getInfo();
    cout << "Before: " << gosho.getInfo();
    gosho.makeOlder(15);
    cout << "After: " << gosho.getInfo();

    return 0;
}
