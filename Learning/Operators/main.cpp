#include <iostream>
#include <sstream>

using namespace std;

class Price {
    int cents;

public:
    Price(int cents) : cents(cents) {}

    Price operator+(const Price& other) const {
        return Price{ this->cents + other.cents };
    }

    friend istream& operator>>(istream& in, Price& p);

    bool operator<(const Price& other) const {
        return this->cents < other.cents;
    }

    void print() {
        cout << this->cents << endl;
    }

    int getCents() const { return this->cents; }
};

string operator+(const string& s, const Price& p) {
    ostringstream out;
    out << p.getCents() << ' ' << s << endl;
    return out.str();
}

istream& operator>> (istream& in, Price& p) {
    return in >> p.cents;
}

ostream& operator<<(ostream& out, const Price& p) {
    return out << p.getCents() << endl;
}

int main() {
    Price a { 499 };
    Price b { 1000 };
    Price sum = a + b;
    sum.print();
    string s = "USD";
    cout << "Sum is: " << s + sum;
    cin >> a;
    cout << a;
    if (a < b)
        cout << "Bigger: " << b;
    else
        cout << "Bigger: " << a;
    cout << endl;
}
