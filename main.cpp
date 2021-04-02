#include <iostream>
#include "DirectoryEntity.h"

int main() {
    Layer topLevel;
    DirectoryEntity entity(nullptr, "./", &topLevel);
    std::cout << entity.getSize() << std::endl;

    Layer *iter = &topLevel;
    do {
        std::cout << ":: Layer " << iter->getId() << " ==> " << iter->getSize() << std::endl;

        for(const auto& entity : iter->getEntities()) {
            std::cout << "      - " << entity->getName() << " => " << entity->getSize() << std::endl;
        }

        iter = iter->getNext();
    } while(iter->hasNext());

    for(const auto& ent : entity.getChildren()) {
        std::cout << ent->getName() << " => " << ent->getSize() << std::endl;
    }
}
