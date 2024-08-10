#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class EuclideanDistance {

    int x1;
    int y1;
    int x2;
    int y2;

public:
    EuclideanDistance(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    double calculateDistance() {
        return sqrt(pow(x2-x1, 2)+ pow(y2-y1, 2));
    }

    void getDistance() {
        cout.setf(ios::fixed);
        cout.precision(3);
        cout << calculateDistance() << endl;
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    EuclideanDistance ed(x1, y1, x2, y2);
    ed.getDistance();
}