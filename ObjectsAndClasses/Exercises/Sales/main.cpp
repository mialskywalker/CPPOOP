#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class Sale {
    string town;
    string product;
    double price = 0;
    double quantity = 0;

public:
    Sale(istream &istr) {
        string row;
        getline(istr, row);
        istringstream line(row);
        line >> town >> product >> price >> quantity;
    }

    string getTown() { return this->town; }
    double getTotal() { return this->price * this->quantity; }
};

class Sales {
public:
    typedef vector<Sale> SalesData;

private:
    SalesData data;
    map<string, double> salesByTown;

public:
    Sales(istream &istr) {
        int salesNum;
        istr >> salesNum;
        istr.ignore();

        data.reserve(salesNum);

        while (salesNum--)
            data.push_back(Sale(istr));
    }

    void calculate();

    void print(ostream &ostr) {
        ostr << fixed << setprecision(2);
        for (pair<string, double> c: salesByTown) {
            ostr << c.first << " -> " << c.second << endl;
        }
    }
};

void Sales::calculate() {
    salesByTown.clear();

    for (Sale &curr: data) {
        const string &town = curr.getTown();
        salesByTown[town] += curr.getTotal();
    }
}


int main() {
    Sales sales(cin);
    sales.calculate();
    sales.print(cout);

    return 0;
}
