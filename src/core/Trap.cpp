#include "Trap.h"
#include "Level.h"
#include <math.h>

Trap::Trap(int x, int y, BlockType type) : Block( x, y, type)
{
}

bool Trap::isSolid()
{
    return false;
}

void Trap::update(Player& p0, Player& p1, Level& currentLevel)
{
    if (p0.getTileX() == tileX && p0.getTileY() == tileY)
    {
        p0.setDead();
    }
    if (p1.getTileX() == tileX && p1.getTileY() == tileY)
    {
        p1.setDead();
    }  
}