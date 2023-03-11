#include "Trap.h"
#include "Block.h"
#include "Player.h"
#include <math.h>

bool Trap::isSolid()
{
    return false;
}

void Trap::power(PowerType type)
{
}

void Trap::update(Player& p0,Player& p1)
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