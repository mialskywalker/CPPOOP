//
// Created by uchih on 11.7.2024 г..
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

namespace SoftUni {
    class Resource {
        int id;
        ResourceType rtype;
        std::string  link;

    public:

        int getId(void) const { return id; }
        ResourceType getType(void) const { return rtype; }
        const std::string & getLink(void) const { return link; }

        bool operator < (const Resource & other) const {
            return this->id < other.id;
        }

        friend std::istream & operator >> (std::istream & istr, Resource & r);

    };

    std::istream& operator>>(std::istream& in, enum ResourceType & rt) {
        std::string buf;
        in >> buf;
        if (buf == "Demo")
            rt = ResourceType::DEMO;
        else if (buf == "Presentation")
            rt = ResourceType::PRESENTATION;
        else if (buf == "Video")
            rt = ResourceType::VIDEO;

        return in;
    }

    std::istream & operator >> (std::istream & istr, Resource & r) {
        istr >> r.id;
        istr >> r.rtype;
        istr.ignore();
        getline(istr, r.link);

        return istr;
    }

    std::ostream & operator << (std::ostream & out, const Resource & r) {
        out << r.getId() << ' ' << r.getType() << ' ' << r.getLink();
        return out;
    }



}



#endif //RESOURCE_H
