#include "Sensor.h"
#include "Level.h"
#include "Enum.h"
#include <math.h>

Sensor::Sensor(int x, int y, BlockType type) : Block( x, y, type)
{
}

bool Sensor::isSolid()
{
    return false;
}


void Sensor::update(Player& p0, Player& p1, Level& currentLevel)
{
    bool p0OnSensor = (floor(p0.getX()/50) == tileX && floor(p0.getY()/50) == tileY);
    bool p1OnSensor = (floor(p1.getX()/50) == tileX && floor(p1.getY()/50) == tileY);

    if (!(p0OnSensor && p1OnSensor)) 
    {    
        if (p0OnSensor)
        {
            currentLevel.getCable(tileX +1 , tileY)->power(ZERO, PowerDirection::LEFT, currentLevel);
            currentLevel.getCable(tileX -1 , tileY)->power(ZERO, PowerDirection::RIGHT, currentLevel);
            currentLevel.getCable(tileX , tileY +1)->power(ZERO, PowerDirection::UP, currentLevel);
            currentLevel.getCable(tileX , tileY -1)->power(ZERO, PowerDirection::DOWN, currentLevel);
        }
    
        if (p1OnSensor)
        {
            currentLevel.getCable(tileX +1 , tileY)->power(ONE, PowerDirection::LEFT, currentLevel);
            currentLevel.getCable(tileX -1 , tileY)->power(ONE, PowerDirection::RIGHT, currentLevel);
            currentLevel.getCable(tileX , tileY +1)->power(ONE, PowerDirection::UP, currentLevel);
            currentLevel.getCable(tileX , tileY -1)->power(ONE, PowerDirection::DOWN, currentLevel);
        }
    }
        
}