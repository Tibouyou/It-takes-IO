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
    bool p0OnSensor = (floor(p0.getX()/spriteSize) == tileX && floor(p0.getY()/spriteSize) == tileY);
    bool p1OnSensor = (floor(p1.getX()/spriteSize) == tileX && floor(p1.getY()/spriteSize) == tileY);

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