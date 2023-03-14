#include "Receptacle.h"
#include "Level.h"


Receptacle::Receptacle(int x, int y) : Block(x, y)
{
    heldItem = nullptr;
}

bool Receptacle::isSolid()
{
    return false;
}

void Receptacle::power(PowerType type)
{
}

void Receptacle::update(const Player& p0,const Player& p1, Level& currentLevel)
{
}