#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s = "A man, a plan, a canal: Panama";
    string newString;

    for (char l : s)
        if (isalnum(l))
            newString += tolower(l);

    int k = newString.length() - 1;
    for (int i = 0; i < newString.length() / 2; i++) {
        if (newString[i] != newString[k]) {
            cout << "false" << endl;
            break;
        }
        k--;
    }


    cout << "true";
}