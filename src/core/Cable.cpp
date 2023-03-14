#include <iostream>
#include "Cable.h"

Cable::Cable(int tileX, int tileY, PowerType power, unsigned char directionMaskCable)
{
    this->tileX = tileX;
    this->tileY = tileY;
    this->cablePower = power;
    this->directionMaskCable = directionMaskCable;
}

void Cable::power(PowerType power, unsigned char directionMask)
{
   
}

void Cable::update(const Level& currentLevel)
{
    // Do nothing
}

PowerType Cable::getPowerType()
{
    return cablePower;
}

