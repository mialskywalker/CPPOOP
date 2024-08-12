#include <iostream>
#include <vector>

using namespace std;

class Company {
    string name;
    mutable int capital;

public:
    Company(string name, int capital) :
        name(name),
        capital(capital) {}

    void addCapital (int dollars) const {
        this->capital += dollars;
    }

    void print() const {
        cout << this->name << " " << this->capital << endl;
    }
};


int main() {
    Company c {"Gosho", 999};
    c.print();
    c.addCapital(12);
    c.print();

    const Company& ref = c;
    ref.print();
    ref.addCapital(1);
    ref.print();
}
