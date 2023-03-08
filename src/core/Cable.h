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
        unsigned char directionMask;

    public :
        Cable(int tileX, int tileY, PowerType power, unsigned char directionMask);
        void power(PowerType power, unsigned char directionMask);
        void update(const Level& currentLevel);
        PowerType getPowerType();
};

#endif