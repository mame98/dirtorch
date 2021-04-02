#include <iostream>
#include <termbox/termbox.h>
#include <cmath>
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

    tb_init();

    char charmap[] = {TB_RED, TB_GREEN, TB_BLUE, TB_YELLOW, TB_CYAN};

    size_t width = tb_width();
    size_t height = tb_height();

    iter = &topLevel;
    size_t col = 0;
    do {
        int x = col;
        int y = 0;
        int nth = 0;
        size_t maxSize = iter->getSize();
        for(const auto& ent : iter->getEntities()) {
            nth += 1;
            size_t size = lroundf(height * ((float) ent->getSize() / (float) maxSize));
            for(int i = 0; i < size; i++) {
                tb_change_cell(x, y, '#', charmap[nth % 5], charmap[nth % 5]);
                tb_change_cell(x+1, y, '#', charmap[nth % 5], charmap[nth % 5]);

                y += 1;
            }
        }

        iter = iter->getNext();
        col += 2;
    } while(iter->hasNext());

    tb_present();

    system("sleep 10");
    tb_shutdown();
}
