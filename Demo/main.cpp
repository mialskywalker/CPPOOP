#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class SentenceShifter {
private:
    typedef vector<string> WordData;
    WordData data;

public:
    void readData(istream & is);
    void getShiftedSentence(int n);
    void outData(ostream & os);

};

void SentenceShifter::readData(istream &is) {
    string buff;
    getline(cin, buff);
    istringstream istr(buff);
    while(istr >> buff) {
        data.push_back(buff);
    }
}

void SentenceShifter::outData(ostream &os) {
    for (string el : data)
        os << el << endl;
}

void SentenceShifter::getShiftedSentence(int n) {
    for (int i = 0; i < n; i++) {
        string word = data.back();
        data.pop_back();
        data.insert(data.begin(), word);
    }
}




int main() {
    SentenceShifter sh;
    sh.readData(cin);
    int times;
    cin >> times;
    sh.getShiftedSentence(times);
    sh.outData(cout);
}