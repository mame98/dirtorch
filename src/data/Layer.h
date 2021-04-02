/**
 *    == D I R T O R C H ==
 *
 *      Layer.h
 *      Copyright (C) 2021 - Marius Messerschmidt
 */
#ifndef DIRTORCH_LAYER_H
#define DIRTORCH_LAYER_H


#include <memory>
#include <list>

class Entity;

class Layer {
public:
    Layer* getPrevious() const;
    Layer* getNext();
    bool hasNext() const;

    size_t getSize() const;
    const std::list<Entity*>& getEntities() const;
    void addEntity(Entity* entity);
    int getId() const;

private:
    Layer* next = nullptr;
    Layer* prev = nullptr;
    std::list<Entity*> entities{};
    int id{0};
};


#endif //DIRTORCH_LAYER_H
