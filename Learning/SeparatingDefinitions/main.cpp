#include <iostream>
#include "Company.h"

using namespace std;

int main() {
    const Company c(42, "TheAnswer Inc.");
    cout << c.toString();
}
