//
// Created by uchih on 19.7.2024 г..
//

#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <vector>
#include <sstream>

template<class T>
std::string join(const std::vector<T>& v, const std::string & joinStr) {
    std::ostringstream ostr;
    bool bFirst = true;
    for (const T & curr : v) {
        if (bFirst) {
            ostr << curr;
            bFirst = false;
        }
        else {
            ostr << joinStr << curr;
        }
    }
    return ostr.str();
}

#endif //JOIN_H
