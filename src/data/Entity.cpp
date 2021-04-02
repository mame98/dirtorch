/**
 *     == D I R T O R C H ==
 *
 *      Entity.cpp
 *      Copyright (C) 2021 - Marius Messerschmidt
 */

#include "Entity.h"

#include <utility>

const std::string &Entity::getName() const {
    return name;
}

Entity::Entity(Entity *parent, const std::string &name, Layer* currentLayer) {
    this->name = name;
    this->path = parent ? parent->getPath() + "/" + name : name;
    this->parent = parent;
    currentLayer->addEntity(this);
}

Entity* Entity::getParent() const {
    return parent;
}

const std::string &Entity::getPath() const {
    return path;
}
