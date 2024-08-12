#include <iostream>
#include <vector>

using namespace std;

class Company {
    string id;
    int capital = 0;

public:
    Company() {
        id = "<unknown>";
    }

    Company(string id, int capital) :
        id(id),
        capital(capital) {}

    void print() const {
        cout << this->id << " (" << this->capital << ")" << endl;
    }

    friend void getCompany(istream& in, Company& c);
    friend class MyClass;
};

class MyClass {
    string id;

public:

    void testFriendship(Company& c) {
        id = c.id;
    }

    void print() const {
        cout << this->id << endl;
    }

};

void getCompany(istream &in, Company &c) {
    in >> c.id >> c.capital;
}


int main() {
    Company c;
    c.print();
    getCompany(cin, c);
    c.print();

    MyClass mc;
    mc.print();
    mc.testFriendship(c);
    mc.print();

}
