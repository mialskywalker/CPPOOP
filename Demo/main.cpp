#include <iostream>

#include "Fraction.h"

using namespace std;

int main(){
    Fraction a(2,4);
    cout << a.getNumerator() << '/' << a.getDenominator() << endl;
}
