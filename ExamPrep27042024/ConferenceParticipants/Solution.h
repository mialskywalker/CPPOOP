//
// Created by uchih on 23/08/2024.
//

#ifndef SOLUTION_H
#define SOLUTION_H

template<class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> part) {
    if (part.begin() == part.end()) {
        os << "- none" << std::endl;
    }
    else {
        auto it = part.begin();

        for (; it != part.end(); it++) {
            //std::cout << (*it)->print() << std::endl;
            os << "- " << (*it)->print() << std::endl;
        }
    }
    return os;
}

#endif //SOLUTION_H
