#ifndef _TRAP_H
#define _TRAP_H

#include "Block.h"
#include "Player.h"

class Level;

class Trap : public Block
{
    public :
        Trap(int x, int y, BlockType type = TRAP);
        bool isSolid();
        void update(Player& p0, Player& p1, Level& currentLevel);
}; 

#endif