#include "Block.h"

Block::Block(int x, int y)
{
    tileX = x;
    tileY = y;
}

bool Block::isSolid()
{
    return false;
}

void Block::power(PowerType type)
{
}

void Block::update(const Player& p0,const Player& p1)
{
}