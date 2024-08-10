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
};

string printPersonInfo(Person& p) {
    ostringstream os;
    os << p.name << ": " << p.age << " years old, " << p.body.height << "cm tall, " << p.body.weight << "kgs." << endl;
    return os.str();
}

int main() {
    Person p("Gosho", 12, 171, 65);
    Person gosho;
    cout << printPersonInfo(p);
    cout << printPersonInfo(gosho);

    return 0;
}
