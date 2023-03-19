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
        Cable(int tileX = 0, int tileY = 0, unsigned char directionMaskCable = PowerDirection::NONE,PowerType power = EMPTY);
        void power(PowerType power, unsigned char directionMask, const Level& currentLevel);
        void reset();
        unsigned char getDirectionMask();
        PowerType getPowerType();
};

#endif