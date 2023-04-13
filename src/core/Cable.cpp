#include <iostream>
#include "Cable.h"
#include "Enum.h"
#include "Level.h"

Cable::Cable(int tileX, int tileY, unsigned char directionMaskCable,PowerType power)
{
    this->tileX = tileX;
    this->tileY = tileY;
    this->cablePower = power;
    this->directionMaskCable = directionMaskCable;
}

void Cable::power(PowerType power, unsigned char directionMask, const Level& currentLevel)
{
   if ((directionMask & directionMaskCable) || (directionMask == PowerDirection::NONE))
   {
       cablePower = power;
       if ((directionMaskCable & PowerDirection::RIGHT) && !(directionMask & PowerDirection::RIGHT))
       {
            currentLevel.getCable(tileX + 1, tileY)->power(power, PowerDirection::LEFT, currentLevel);
            currentLevel.getBlock(tileX + 1, tileY)->power(power, currentLevel, PowerDirection::LEFT);
       }

        if ((directionMaskCable & PowerDirection::LEFT) && !(directionMask & PowerDirection::LEFT))
        {
            currentLevel.getCable(tileX - 1, tileY)->power(power, PowerDirection::RIGHT, currentLevel);
            currentLevel.getBlock(tileX - 1, tileY)->power(power, currentLevel, PowerDirection::RIGHT);
        }

        if ((directionMaskCable & PowerDirection::UP) && !(directionMask & PowerDirection::UP))
        {
            currentLevel.getCable(tileX, tileY - 1)->power(power, PowerDirection::DOWN, currentLevel);
            currentLevel.getBlock(tileX, tileY - 1)->power(power, currentLevel, PowerDirection::DOWN);
        }
            
        if ((directionMaskCable & PowerDirection::DOWN) && !(directionMask & PowerDirection::DOWN))
        {
            currentLevel.getCable(tileX, tileY + 1)->power(power, PowerDirection::UP, currentLevel);
            currentLevel.getBlock(tileX, tileY + 1)->power(power, currentLevel, PowerDirection::UP);
        }
   }
}

void Cable::reset()
{
    cablePower = EMPTY;
}

PowerType Cable::getPowerType()
{
    return cablePower;
}

unsigned char Cable::getDirectionMask()
{
    return directionMaskCable;
}
