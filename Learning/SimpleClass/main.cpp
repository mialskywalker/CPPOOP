#include <iostream>
#include <sstream>

using namespace std;

class Person {
    class Body {
    public:
        double height;
        double weight;
    };

public:
    string name;
    int age;

    Body body;

};

string printPersonInfo(const Person &p) {
    ostringstream os;
    os << p.name << ' ' << p.age << ' ' << p.body.height << ' ' << p.body.weight << endl;
    return os.str();
}

void makePersonOlder(Person& p, int years) {
    p.age += years;
}

void changeName(Person& p, string name) {
    p.name = name;
}

void growTaller(Person& p, int height) {
    p.body.height += height;
}

void gainWeight(Person& p, int weight) {
    p.body.weight += weight;
}

int main() {
    Person p;
    p.name = "Gosho";
    p.age = 16;
    p.body.height = 172;
    p.body.weight = 62;

    cout << printPersonInfo(p);

    changeName(p, "Petar");
    makePersonOlder(p, 3);
    growTaller(p, 4);
    gainWeight(p, 12);

    cout << printPersonInfo(p);

    Person * newPerson = new Person();

    newPerson->name = "Sasho";
    newPerson->age = 21;
    newPerson->body.height = 162;
    newPerson->body.weight = 71;

    cout << printPersonInfo(*newPerson);

    changeName(*newPerson, "Simon");
    makePersonOlder(*newPerson, 1);
    growTaller(*newPerson, 2);
    gainWeight(*newPerson, 2);

    cout << printPersonInfo(*newPerson);
    delete newPerson;
}