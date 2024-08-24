//
// Created by uchih on 22/08/2024.
//

#ifndef SOLUTION_H
#define SOLUTION_H

#include "storage.h"

inline bool Storage::operator<=(Store &contents) {
    Store::iterator it = contents.begin();
    for (; it != contents.end(); it++) {
        if (storage.find(it->first) == storage.end()) {
            return false;
        }
    }
    return true;
}

inline Storage &Storage::operator>>(Store &contents) {
    // Store s;
    Storage ss;
    // return ss;

    while(contents.size()) {
        // storage.erase(storage.find(contents.begin()->first));
        // contents.erase(contents.begin());
        if (contents.begin()->second >= 1) {
            storage[contents.begin()->first]--;
            contents.begin()->second--;
        }
        else {
            if (storage[contents.begin()->first] == 0) {
                storage.erase(storage.find(contents.begin()->first));
            }
            contents.erase(contents.begin());
        }
    }
    return ss;
}

std::ostream& operator<<(std::ostream& os, Storage& s) {
    if (s.begin() == s.end()) {
        os << "Empty";
    }
    else {
        os << "Storage: ";
        bool bFirst = true;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (bFirst) {
                os << it->first << ": " << it->second;
                bFirst = false;
            }
            else {
                os << ", " << it->first << ": " << it->second;
            }
        }
    }
    return os;
}

// Sand
// Sand
// Bricks Sand Sand
// Cement
// Cement
// Water
// Water
// Water
// Concrete Cement Water Water
// Wall Concrete Bricks Cement
// end


// Wood
// Wood
// Iron
// Nails Iron
// Nails Iron
// Bracket Nails Wood
// end


#endif //SOLUTION_H
