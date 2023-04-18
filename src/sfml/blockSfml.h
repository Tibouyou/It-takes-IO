#ifndef _BLOCKSFML_H
#define _BLOCKSFML_H

#include <SFML/Graphics.hpp>
#include "../core/Level.h"

class BlockSfml
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        int tileX;
        int tileY;
        int spriteSize;

    public:
        BlockSfml(Level * level, int spriteSize, int tileX, int tileY);
        ~BlockSfml();
        sf::Sprite getSprite();
};

#endif