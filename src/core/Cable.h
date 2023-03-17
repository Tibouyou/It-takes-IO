#ifndef _CABLE_H
#define _CABLE_H 

#include "Entity.h" 
#include "Enum.h"

class Level;

class Cable 
{
    private : 
        int tileX; 
        int tileY;
        PowerType cablePower;
        unsigned char directionMaskCable;

    public :
        Cable(int tileX = 0, int tileY = 0, PowerType power = EMPTY, unsigned char directionMaskCable = 0b0000);
        void power(PowerType power, unsigned char directionMask, const Level& currentLevel);
        void update(const Level& currentLevel);
        PowerType getPowerType();
};

#endif