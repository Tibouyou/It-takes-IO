#ifndef _BLOCK_H
#define _BLOCK_H

#include "Enum.h"

class Block
{
    protected :
        int tileX;
        int tileY;

    public :
        Block(int x, int y);
        bool isSolid();
        void power(PowerType type);
        void update(const player& p0,const player& p1, const Level& level);
}; 


#endif




