#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main(){
    unique_ptr<int> first(new int(42));
    unique_ptr<int> second(new int(64));

    // first = second -> gives compilation error: unique_ptr cannot give its reference to other

    // first takes second parameters and second becomes null
    first = move(second);
    cout << *first << endl;

    vector<unique_ptr<int>> pointers;

    // pointers.push_back(first) -> gives compilation error

    pointers.push_back(move(first));

    cout << *pointers.back() << endl;

    return 0;
}
