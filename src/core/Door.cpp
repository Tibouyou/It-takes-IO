#include "Door.h"
#include "Level.h"

Door::Door(int x, int y, BlockType type) : Block(x, y, type)
{
    this->open = false;
}

bool Door::isSolid()
{
    return !open;
}

bool Door::isOpen()
{
    return open;
}

void Door::setOpen()
{
    this->open = true;
}

void Door::update(Player& p0, Player& p1, Level& currentLevel)
{
    if (currentLevel.getCable(tileX, tileY - 1)->getPowerType() == ONE)
    {
        this->setOpen();
    }
}

