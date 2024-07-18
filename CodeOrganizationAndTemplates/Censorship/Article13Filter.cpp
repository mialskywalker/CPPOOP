//
// Created by uchih on 18.7.2024 г..
//

#ifndef ARTICLE_FILTER_CPP
#define ARTICLE_FILTER_CPP

#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted) : copyrighted(copyrighted), blocked(blocked) {}

bool Article13Filter::blockIfCopyrighted(std::string s) {
    if (isCopyrighted(s)) {
        blocked.push_back(s);
        return true;
    }
    return false;


}

bool Article13Filter::isCopyrighted(std::string s) {
    return copyrighted.find(s) != copyrighted.end();
}

std::vector<std::string> Article13Filter::getBlocked() {
    return blocked;
}

#endif
