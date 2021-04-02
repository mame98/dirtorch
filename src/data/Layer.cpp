/**
 *    == D I R T O R C H ==
 *
 *      Layer.cpp
 *      Copyright (C) 2021 - Marius Messerschmidt
 */

#include "Layer.h"
#include "Entity.h"
Layer* Layer::getPrevious() const {
    return prev;
}

Layer* Layer::getNext() {
    if(!next) {
        next = new Layer();
        next->prev = this;
        next->id = id + 1;
    }
    return next;
}

size_t Layer::getSize() const {
    size_t size{0};
    for(const auto& entity : entities) {
        size += entity->getSize();
    }
    return size;
}

const std::list<Entity*>& Layer::getEntities() const {
    return entities;
}

void Layer::addEntity(Entity* entity) {
    entities.push_back(entity);
}

bool Layer::hasNext() const {
    return next != nullptr;
}

int Layer::getId() const {
    return id;
}
