#include "Door.h"
#include "Level.h"
#include <iostream>

Door::Door(int x, int y, BlockType type) : Block(x, y, type)
{
    open = false;
    win = false;
}

bool Door::isSolid()
{
    return false;
}

bool Door::isOpened()
{
    return open;
}

void Door::setOpen()
{
    this->open = true;
}

void Door::update(Player& p0, Player& p1, Level& currentLevel)
{
    if (currentLevel.getCable(tileX, tileY + 1)->getPowerType() == ONE)
    {
        this->setOpen();
    }
    if (currentLevel.getPlayer0()->getTileX()==tileX && currentLevel.getPlayer0()->getTileY()==tileY && open)
    {
        currentLevel.win();
    }
    if (currentLevel.getPlayer1()->getTileX()==tileX && currentLevel.getPlayer1()->getTileY()==tileY && open)
    {
        currentLevel.win();
    }
}

void Door::reset()
{
    this->open = false;
    this->win = false;
}

