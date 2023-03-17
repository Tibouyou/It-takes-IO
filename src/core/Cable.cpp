#include <iostream>
#include "Cable.h"
#include "Level.h"

Cable::Cable(int tileX, int tileY, PowerType power, unsigned char directionMaskCable)
{
    this->tileX = tileX;
    this->tileY = tileY;
    this->cablePower = power;
    this->directionMaskCable = directionMaskCable;
}

void Cable::power(PowerType power, unsigned char directionMask, const Level& currentLevel)
{
   if (directionMask & directionMaskCable)
   {
       cablePower = power;
       if ((directionMaskCable & PowerDirection::RIGHT) && !(directionMask & PowerDirection::RIGHT))
       {
            currentLevel.getCable(tileX + 1, tileY)->power(power, PowerDirection::LEFT, currentLevel);
            currentLevel.getBlock(tileX + 1, tileY)->power(power);
       }

        if ((directionMaskCable & PowerDirection::LEFT) && !(directionMask & PowerDirection::LEFT))
        {
            currentLevel.getCable(tileX - 1, tileY)->power(power, PowerDirection::RIGHT, currentLevel);
            currentLevel.getBlock(tileX - 1, tileY)->power(power);
        }

        if ((directionMaskCable & PowerDirection::UP) && !(directionMask & PowerDirection::UP))
        {
            currentLevel.getCable(tileX, tileY - 1)->power(power, PowerDirection::DOWN, currentLevel);
            currentLevel.getBlock(tileX, tileY - 1)->power(power);
        }
            
        if ((directionMaskCable & PowerDirection::DOWN) && !(directionMask & PowerDirection::DOWN))
        {
            currentLevel.getCable(tileX, tileY + 1)->power(power, PowerDirection::UP, currentLevel);
            currentLevel.getBlock(tileX, tileY + 1)->power(power);
        }
   }
}

void Cable::update(const Level& currentLevel)
{
    // Do nothing
}

PowerType Cable::getPowerType()
{
    return cablePower;
}

