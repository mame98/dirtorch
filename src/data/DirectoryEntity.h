/**
 *     == D I R T O R C H ==
 *
 *      DirectoryEntity.h
 *      Copyright (C) 2021 - Marius Messerschmidt
 */

#ifndef DIRTORCH_DIRECTORYENTITY_H
#define DIRTORCH_DIRECTORYENTITY_H


#include "Entity.h"
#include <list>

class DirectoryEntity : public Entity {
public:
    DirectoryEntity(Entity* parent, const std::string &name, Layer* currentLayer);
    const std::list<std::shared_ptr<Entity>>& getChildren() const;
    void addChild(const std::shared_ptr<Entity>& child);

    size_t getSize() const override;

private:
    std::list<std::shared_ptr<Entity>> children{};

};


#endif //DIRTORCH_DIRECTORYENTITY_H
