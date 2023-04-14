#include "Sensor.h"
#include "Level.h"
#include "Enum.h"
#include <math.h>

Sensor::Sensor(int x, int y, int spriteSize, BlockType type) : Block( x, y, type)
{
    activated = false;
    this->spriteSize = spriteSize;
}

bool Sensor::isSolid()
{
    return false;
}


void Sensor::update(Player& p0, Player& p1, Level& currentLevel)
{
    bool p0OnSensor = (p0.getTileX(p0.getWidth()/2) == tileX && p0.getTileY() == tileY);
    bool p1OnSensor = (p1.getTileX(p1.getWidth()/2) == tileX && p1.getTileY() == tileY);

    if (!(p0OnSensor && p1OnSensor)) 
    {    
        if (p0OnSensor)
        {
            currentLevel.getCable(tileX , tileY)->power(ZERO, PowerDirection::NONE, currentLevel);
            activated = true;
        }
    
        if (p1OnSensor)
        {
            currentLevel.getCable(tileX , tileY)->power(ONE, PowerDirection::NONE, currentLevel);
            activated = true;
        }
    } else {
        activated = false;
    } 
}

bool Sensor::isActivated()
{
    return activated;
}