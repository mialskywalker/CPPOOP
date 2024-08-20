//
// Created by uchih on 20/08/2024.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemObjectsContainer.h"

#include <list>

class Directory: public FileSystemObject, public FileSystemObjectsContainer {

    std::list<std::shared_ptr<FileSystemObject>> contents;

public:
    Directory(std::string name) : FileSystemObject(name) {};


    virtual size_t getSize() const {

        size_t size=0;

        for (std::shared_ptr<FileSystemObject> curr : contents) {
            size+=curr->getSize();
        };
        return size;
    };


    virtual void add(const std::shared_ptr<FileSystemObject>& obj) {
        contents.push_back(obj);
    };

};

#endif //DIRECTORY_H
