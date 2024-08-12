#include <iostream>

#include "Fraction.h"

using namespace std;

int main(){
    Fraction a(2,4);
    Fraction b(2, 4);
    Fraction sum = a + b;
    cout << sum << endl;
    Fraction c;
    cin >> c;
    cout << c << endl;
    c++;
    cout << c << endl;
}
