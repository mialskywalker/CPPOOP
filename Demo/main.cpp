#include <iostream>

using namespace std;

int main() {

    string text;
    cout << "Emche kaji Stitch." << endl;

    bool isStitch = false;
    while(true) {
        cin >> text;
        if (text == "stitch" || text == "Stitch") {
            isStitch = true;
            break;
        }


        if (!isStitch) {
            cout << "Nee, kaji Stitch!!!" << endl;
        }

    }

    if (isStitch) {
        cout << "Nyama da poluchish glitch!" << endl;
    }

    cout << "Emche, kaji shevrolet!" << endl;
    isStitch = false;
    while(true) {
        cin >> text;
        if (text == "shevrolet" || text == "Shevrolet") {
            isStitch = true;
            break;
        }


        if (!isStitch) {
            cout << "Nee, kaji Shevrolet!!!" << endl;
        }

    }

    if (isStitch) {
        cout << "Shte stanesh milioner!" << endl;
    }





    return 0;
}
