#include <iostream>
#include <vector>

using namespace std;

void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            result.push_back(arr[i]);
            result.push_back(0);
        }
        else {
            result.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }

}

int main() {
    vector<int> arr {1,0,2,3,0,4,5,0};
    duplicateZeros(arr);
}
