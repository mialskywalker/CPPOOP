#include "Company.h"
#include <sstream>

Company::Company(int id, std::string name) :
id(id),
name(name) {}

int Company::getId() const {
    return this->id;
}

std::string Company::getName() const {
    return this->name;
}

std::string Company::toString() const {
    std::ostringstream stream;
    stream << id << ' ' << name << std::endl;
    return stream.str();
}

std::string Company::operator+(const std::string &s) {
    return this->toString() + s;
}

bool Company::operator==(const Company &other) const {
    return this->id == other.id;
}