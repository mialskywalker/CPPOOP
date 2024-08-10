#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Sale {
    string town;
    string product;
    double price;
    double quantity;

public:
    Sale(string town, string product, double price, double quantity):
        town(town),
        product(product),
        price(price),
        quantity(quantity) {}

    string getTown() { return this->town; }
    double getProductPrice() { return this->price * this->quantity; }
};

class Sales {
    typedef vector<Sale> SaleData;
    SaleData data;
    map<string, double> salesByTown;

public:
    Sales(istream & istr) {
        int n;
        istr >> n;
        istr.ignore();

        string town, product;
        double price;
        double quantity;

        while(n--) {
            istr >> town >> product >> price >> quantity;
            data.push_back(Sale(town, product, price, quantity));
        }
    }

    void calculateByTown() {
        salesByTown.clear();
        for (Sale & cur : data) {
            const string & town = cur.getTown();
            salesByTown[town] += cur.getProductPrice();
        }
    }

    string printSales(){
        ostringstream os;
        os << fixed << setprecision(2);
        for (pair<string, double> c: salesByTown)
            os << c.first << " -> " << c.second << endl;
        return os.str();
    }

};

int main() {
    Sales sales(cin);
    sales.calculateByTown();
    cout << sales.printSales();

}
