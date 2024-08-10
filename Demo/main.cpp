#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class SentenceShifter {
    typedef vector<string> WordData;

    WordData data;

public:
    SentenceShifter(WordData data) : data(data) {}

    SentenceShifter() {
        data = WordData{};
    }

    void pushData(string word) {
        this->data.push_back(word);
    }

    void shiftData(int times) {
        while (times--) {
            string curr = this->data.back();
            this->data.pop_back();
            this->data.insert(this->data.begin(), curr);
        }
    }

    string printData() {
        ostringstream os;
        bool bFirst = true;
        for (string el : this->data) {
            if (bFirst) {
                os << el;
                bFirst = false;
            }
            else {
                os << endl << el;
            }
        }
        return os.str();
    }


};

int main() {

    SentenceShifter sh;
    string text;
    getline(cin, text);
    istringstream istr(text);
    string word;
    while (istr >> word)
        sh.pushData(word);

    int num;
    cin >> num;
    sh.shiftData(num);
    cout << sh.printData();

}