#include "Block.h"
#include "Enum.h"
#include <iostream>

Block::Block(int x, int y, BlockType type)
{
    tileX = x;
    tileY = y;
    this->type = type;
}

Block::~Block()
{

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

void Block::update(Player& p0, Player& p1, Level& currentLevel)
{

}

int Block::getX() {
    return tileX;
}

int Block::getY() {
    return tileY;
}