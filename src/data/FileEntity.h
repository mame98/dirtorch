/**
 *     == D I R T O R C H ==
 *
 *      FileEntity.h
 *      Copyright (C) 2021 - Marius Messerschmidt
 */

#ifndef DIRTORCH_FILEENTITY_H
#define DIRTORCH_FILEENTITY_H


#include "Entity.h"

#include <utility>

class FileEntity : public Entity {
public:
    FileEntity(Entity* parent, const std::string &name, Layer* currentLayer);

    size_t getSize() const override;
private:
    size_t size;
};


#endif //DIRTORCH_FILEENTITY_H
