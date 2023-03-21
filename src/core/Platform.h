#ifndef _PLATFORM_H
#define _PLATFORM_H

#include "Block.h"

class Platform : public Block
{
    public :
        /**
         * @brief Get the solidity of the platform
         * 
         * @return true
         */
        bool isSolid();

        /**
         * @brief Construct a new Platform object
         * 
         * @param x x coordinate
         * @param y y coordinate
         * @param type type of the block
         */
        Platform(int x, int y, BlockType type = PLATFORM);
}; 


#endif