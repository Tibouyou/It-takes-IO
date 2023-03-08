#ifndef CABLE_H
#define CABLE_H 

#include "Entity.h" 
#include "Enum.h"

class Cable 
{
    private : 
        int tileX; 
        int tileY;
        PowerType power;
        unsigned char directionMask;

    public :
        Cable(int tileX, int tileY, PowerType power, unsigned char directionMask);
        void power(PowerType power, unsigned char directionMask);
        void update(const Level& currentLevel);
        PowerType getPowerType();
}

#endif CABLE_H