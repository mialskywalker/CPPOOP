#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkValid(stack<char> &st, char expected) {
    if (st.size() == 0)
        return false;
    if (st.top() != expected)
        return false;
    st.pop();
    return true;
}

int main() {
    stack<char> st;
    string line;
    getline(cin, line);

    bool isValid = true;

    string::iterator itS = line.begin();

    for (; isValid && itS != line.end(); itS++) {
        switch (*itS) {
            case '(':
            case '[':
            case '{':
                st.push(*itS);
                break;
            case ')':
                if (!checkValid(st, '('))
                    isValid = false;
                break;
            case ']':
                if (!checkValid(st, '['))
                    isValid = false;
                break;
            case '}':
                if (!checkValid(st, '{'))
                    isValid = false;
                break;
        }
    }

    if (isValid) {
        if (st.size() != 0)
            isValid = false;
    }

    cout << (isValid ? "Yes" : "No") << endl;
}
