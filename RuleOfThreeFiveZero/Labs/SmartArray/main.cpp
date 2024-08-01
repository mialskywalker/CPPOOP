#include <iostream>
#include <algorithm>
#include <cstddef>
#include "SmartArray.h"

int main() {
    SmartArray<int> arr(5);
    arr[2] = 42;

    // SmartArray<int> arr2 = std::move(arr);
    // std::cout << arr2[2] << std::endl;
    //
    // SmartArray<int> arr3(10);
    // arr3[2] = 1337;
    // arr3 = std::move(arr2);
    // std::cout << arr3[2] << std::endl;

    return 0;
}
