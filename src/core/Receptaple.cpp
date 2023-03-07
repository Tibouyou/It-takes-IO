#include "Receptacle.h"
#include "Enum.h"
#include "Level.h"
#include "Player.h"
#include "Block.h"

Receptacle::Receptacle(int x, int y)
{
    tileX = x;
    tileY = y;
    heldItem = NULL;
}

bool Receptacle::isSolid()
{
    return false;
}

void Receptacle::power(PowerType type)
{
}

void update(const Player& p0,const Player& p1, const Level& level)
{
}