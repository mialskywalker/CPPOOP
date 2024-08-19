#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Range.h"

using namespace std;

int main() {

    vector<Range> ranges;

    string input;
    cin >> input;

    int n1, n2;

    while(input != ".") {
        n1 = stoi(input);
        cin >> input;
        n2 = stoi(input);
        cin >> input;

        Range r(n1, n2);
        ranges.push_back(r);
    }

    cin >> input;
    bool isIn = false;
    while (input != ".") {
        n1 = stoi(input);
        isIn = false;
        for (auto el : ranges) {
            if (el.isInRange(n1)) {
                cout << "in" << endl;
                isIn = true;
                break;
            }
        }
        if (!isIn)
            cout << "out" << endl;
        cin >> input;
    }

    return 0;
}
