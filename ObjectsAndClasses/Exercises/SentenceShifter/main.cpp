#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

typedef list<string> ShiftData;

class SentenceShifter {
    ShiftData data;

public:
    void readData(istream &istr);

    void shiftData(int times);

    void printData(ostream &ostr);
};

void SentenceShifter::readData(istream &istr) {
    string buf;
    getline(istr, buf);

    istringstream bufStr(buf);

    while (bufStr >> buf)
        data.push_back(buf);
}

void SentenceShifter::shiftData(int times) {
    while (times--) {
        data.push_front(data.back());
        data.erase(--data.end());
    }
}

void SentenceShifter::printData(ostream &ostr) {
    for (string &entry: data)
        ostr << entry << endl;
}


int main() {
    SentenceShifter sh;

    sh.readData(cin);

    int times;
    cin >> times;
    sh.shiftData(times);

    sh.printData(cout);


    return 0;
}
