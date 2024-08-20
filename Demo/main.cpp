#include <iostream>

using namespace std;

int subtractProductAndSum(int n) {
    int sum = 0;
    int multi = 1;

    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        sum += digit;
        multi *= digit;
    }

    return multi - sum;
}

int main() {
    cout << subtractProductAndSum(4421) << endl;
    return 0;
}
