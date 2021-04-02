/**
 *     == D I R T O R C H ==
 *
 *      DirectoryEntity.cpp
 *      Copyright (C) 2021 - Marius Messerschmidt
 */

#include "DirectoryEntity.h"
#include "FileEntity.h"

#include <dirent.h>
#include <cstring>
#include <iostream>

DirectoryEntity::DirectoryEntity(Entity* parent, const std::string &name, Layer* currentLayer)
: Entity(parent, name, currentLayer) {

    DIR *dir;
    struct dirent *dirEntry;
    dir = opendir(getPath().c_str());
    if(dir == nullptr) {
        std::cerr << "Failed to open " << name << ": " << strerror(errno) << std::endl;
    }
    while((dirEntry = readdir(dir)) != nullptr) {
        if(strcmp(dirEntry->d_name, ".") == 0
                || strcmp(dirEntry->d_name, "..") == 0) {
            continue;
        }
        if(dirEntry->d_type == DT_DIR) {
            addChild(std::make_shared<DirectoryEntity>(this, dirEntry->d_name, currentLayer->getNext()));
        } else {
            addChild(std::make_shared<FileEntity>(this, dirEntry->d_name, currentLayer->getNext()));
        }
    }
}

const std::list<std::shared_ptr<Entity>> &DirectoryEntity::getChildren() const {
    return children;
}

void DirectoryEntity::addChild(const std::shared_ptr<Entity>& child) {
    this->children.push_back(child);
}

size_t DirectoryEntity::getSize() const {
    size_t size{0};
    for(const auto& child : children) {
        size += child->getSize();
    }
    return size;
}
