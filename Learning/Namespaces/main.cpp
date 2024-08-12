#include <iostream>
#include <vector>

using namespace std;

namespace VideoPlatform {
    namespace YouTube {
        vector<string> videos {"Space", "Asteroids", "Planets"};
        void print() {
            cout << "Welcome to my YouTube channel!" << endl;
        }
    }
    namespace TikTok {
        vector<string> videos {"Game", "Coding"};
        void print() {
            cout << "Welcome to my TikTok!" << endl;
        }
    }
}


int main() {
    VideoPlatform::YouTube::print();
    bool bFirst = true;
    for (string el : VideoPlatform::YouTube::videos) {
        if (bFirst) {
            cout << el;
            bFirst = false;
        }
        else {
            cout << ", " << el;
        }
    }
    cout << endl;

    VideoPlatform::TikTok::print();
    bFirst = true;
    for (string el : VideoPlatform::TikTok::videos) {
        if (bFirst) {
            cout << el;
            bFirst = false;
        }
        else {
            cout << ", " << el;
        }
    }
    cout << endl;
}
