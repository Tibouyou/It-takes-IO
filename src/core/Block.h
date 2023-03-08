#ifndef _BLOCK_H
#define _BLOCK_H

#include "Enum.h"
#include "Player.h"

class Block
{
    protected :
        int tileX;
        int tileY;

    public :
        Block(int x, int y);
        bool isSolid();
        void power(PowerType type);
        void update(const Player& p0,const Player& p1);
}; 


#endif




