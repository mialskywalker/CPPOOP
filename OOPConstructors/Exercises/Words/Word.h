//
// Created by uchih on 30.7.2024 г..
//

#ifndef WORD_H
#define WORD_H

class Word {
    mutable int count;
    std::string name;

public:
    Word(std::string name) : name(name), count(1) {}

    const std::string &  getWord() const {
        return name;
    }

    bool operator < (const Word & other) const {
        if (other.name == name)
            count++;
        return name < other.name;
    }

    int getCount() const {
        return count;
    }
};

#endif //WORD_H
