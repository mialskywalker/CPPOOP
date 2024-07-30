#include <iostream>
#include "BigInt.h"

using namespace std;

bool divisibleBy9(const BigInt & num) {
    string digits = num.getDigits();

    size_t sumOfDigits = 0;
    for (char c : digits)
        sumOfDigits += (c - '0');

    return (sumOfDigits % 9 == 0);
}

bool divisibleBy5(const BigInt & num) {
    string digits = num.getDigits();
    char last = digits[digits.length()-1];

    return last == '0' || last == '5';
}

bool divisibleBy45(const BigInt & num) {
    return divisibleBy5(num) && divisibleBy9(num);
}

int main() {

    string first, second;
    cin >> first >> second;
    BigInt from(first), to(second);

    for (;from < to;) {
        if (divisibleBy45(from))
            cout << from << endl;
        from += 1;
    }

    return 0;
}
