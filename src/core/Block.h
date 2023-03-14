#ifndef _BLOCK_H
#define _BLOCK_H

#include "Enum.h"
#include "Player.h"

class Level;

class Block
{
    protected :
        int tileX;
        int tileY;
        BlockType type;

    public :
        Block(int x = 0, int y = 0, BlockType type = AIR);
        bool isSolid();
        BlockType getType();
        virtual void power(PowerType type);
        virtual void update(const Player& p0,const Player& p1, Level& currentLevel);
}; 


#endif




