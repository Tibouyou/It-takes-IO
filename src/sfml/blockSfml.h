#ifndef _BLOCKSFML_H
#define _BLOCKSFML_H

#include <SFML/Graphics.hpp>
#include "../core/Level.h"

class BlockSfml
{
    private:
        /**
         * @brief The sprite of the block
         * 
         */
        sf::Sprite sprite;

        /**
         * @brief The texture of the block
         * 
         */
        sf::Texture texture;

        /**
         * @brief The size of the sprite
         * 
         */
        int spriteSize;

    public:

        /**
         * @brief Construct a new BlockSfml object
         *
         * @param level The level
         * @param spriteSize The size of the sprite
         * @param tileX The position x of the block in the level
         * @param tileY The position y of the block in the level
         */
        BlockSfml(Level * level, int spriteSize, int tileX, int tileY);

        /**
         * @brief Destroy the BlockSfml object
         * 
         */
        ~BlockSfml();

        /**
         * @brief Get the Sprite object
         * 
         * @return sf::Sprite The sprite of the block
         */
        sf::Sprite getSprite();
};

#endif