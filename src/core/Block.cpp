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

