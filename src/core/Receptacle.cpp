#include "Receptacle.h"
#include "Enum.h"
#include "Level.h"
#include "Player.h"
#include "Block.h"

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

void update(const Player& p0,const Player& p1)
{
}