#include <iostream>
#include "Cable.h"

Cable::Cable(int tileX, int tileY, PowerType power, unsigned char directionMask)
{
    this->tileX = tileX;
    this->tileY = tileY;
    this->power = power;
    this->directionMask = directionMask;
}

void Cable::power(PowerType power, unsigned char directionMask)
{
    this->power = power;
    this->directionMask = directionMask;
}

void Cable::update(const Level& currentLevel)
{
    // Do nothing
}

PowerType Cable::getPowerType()
{
    return power;
}

