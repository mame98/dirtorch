/**
 *     == D I R T O R C H ==
 *
 *      Entity.h
 *      Copyright (C) 2021 - Marius Messerschmidt
 */

#ifndef DIRTORCH_ENTITY_H
#define DIRTORCH_ENTITY_H


#include <memory>
#include <string>
#include "Layer.h"

class Entity {
public:
    Entity(Entity *parent, const std::string &name, Layer* currentLayer);

    virtual size_t getSize() const = 0;
    const std::string& getName() const;
    Entity* getParent() const;
    const std::string& getPath() const;

private:
    std::string name;
    std::string path;
    Entity* parent;
};


#endif //DIRTORCH_ENTITY_H
