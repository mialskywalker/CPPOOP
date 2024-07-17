//
// Created by uchih on 17.7.2024 г..
//

#ifndef LECTURES_H
#define LECTURES_H

#include "Resource.h"

namespace SoftUni {
    class Lecture {
    public:
        typedef std::set<Resource> ResourceSet;
        typedef std::map<ResourceType, int> ResourcesCount;

    private:
        ResourceSet resources;
        ResourcesCount count;

    public:

        ResourceSet::iterator begin() { return resources.begin(); }
        ResourceSet::iterator end() { return resources.end(); }

        Lecture & operator << (const Resource & r) {
            ResourceSet::iterator itFound = resources.find(r);
            if (itFound != resources.end()) {
                resources.erase(itFound);
                ResourceType rt = r.getType();
                count[rt]--;
                if (count[rt] == 0)
                    count.erase(rt);
            }
            resources.insert(r);
            count[r.getType()]++;
            return *this;
        }

        int operator [](ResourceType rt) {
            return count[rt];
        }

        friend std::vector<ResourceType> operator << (std::vector<ResourceType>& vec, Lecture & l);
    };

    std::vector<ResourceType> operator << (std::vector<ResourceType>& vec, Lecture & l) {
        for (auto curr : l.count) {
            vec.push_back(curr.first);
        }
        return vec;
    }

}

#endif //LECTURES_H
