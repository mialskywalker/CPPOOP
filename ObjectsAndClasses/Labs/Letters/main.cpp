#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

class Words {
public:
    typedef set<string> WordData;
private:
    WordData data;

public:

    Words(istream & istr) {
        string buf;
        getline(istr, buf);

        for (char & c : buf)
            if (ispunct(c))
                c = ' ';

        istringstream lineStr(buf);
        string tmp;

        while(lineStr >> tmp)
            data.insert(tmp);
    }

    const WordData & getData(void) { return data; }
};

int main() {

    Words words(cin);

    while(true) {

        char c;
        cin >> c;

        if (c == '.')
            break;

        c = ::tolower(c);
        bool bFound = false;

        const Words::WordData & wordRef = words.getData();
        for (const string & curr : wordRef) {
            string transformed = curr;
            transform(transformed.begin(), transformed.end(), transformed.begin(), ::tolower);

            if (transformed.find(c) != string::npos) {
                bFound = true;
                cout << curr << " ";
            }
        }

        if (!bFound)
            cout << "---";

        cout << endl;
    }

    return 0;
}
