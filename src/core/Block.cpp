#include "Block.h"
#include "Enum.h"
#include <iostream>

Block::Block(int x, int y, BlockType type)
{
    tileX = x;
    tileY = y;
    this->type = type;
}

bool Block::isSolid()
{
    return false;
}

BlockType Block::getType() {
    return type;
}

void Block::power(PowerType type, const Level& currentLevel) 
{

}

void Block::update(const Player& p0,const Player& p1, Level& currentLevel)
{

}