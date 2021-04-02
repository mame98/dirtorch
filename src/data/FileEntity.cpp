/**
 *     == D I R T O R C H ==
 *
 *      FileEntity.cpp
 *      Copyright (C) 2021 - Marius Messerschmidt
 */

#include "FileEntity.h"

#include <utility>
#include <sys/stat.h>

FileEntity::FileEntity(Entity* parent, const std::string &name, Layer* currentLayer)
    : Entity(parent, name, currentLayer) {

    struct stat stat_buffer;
    stat(getPath().c_str(), &stat_buffer);
    size = stat_buffer.st_size;
}

size_t FileEntity::getSize() const {
    return size;
}
