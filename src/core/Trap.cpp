#include "Trap.h"
#include <math.h>

bool Trap::isSolid()
{
    return false;
}

void Trap::update(Player& p0,Player& p1, Level& currentLevel)
{
    if (floor(p0.getX()/50) == tileX && floor(p0.getY()/50) == tileY)
    {
        p0.setDead();
    }
    if (floor(p1.getX()/50) == tileX && floor(p1.getY()/50) == tileY)
    {
        p1.setDead();
    }  
}