#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

typedef int PointData;

class EuclideanDistance {
    PointData x, y;

public:
    EuclideanDistance() : x(0), y(0) {
    }

    EuclideanDistance(istream &istr) {
        string row;
        getline(istr, row);
        istringstream buff(row);
        buff >> x >> y;
    }

    double getEuclideanDistance(const EuclideanDistance &other) {
        double result, dx, dy;
        dx = this->x - other.x;
        dx *= dx;
        dy = this->y - other.y;
        dy *= dy;
        result = dx + dy;
        return sqrt(result);
    }
};


int main() {
    EuclideanDistance a(cin), b(cin);

    cout << fixed << setprecision(3) << a.getEuclideanDistance(b) << endl;

    return 0;
}
