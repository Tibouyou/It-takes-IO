#ifndef _SENSOR_H
#define _SENSOR_H

#include "Block.h"
#include "Player.h"


class Sensor : public Block
{
    public :
        bool isSolid();
        void update(const Player& p0,const Player& p1);
        void power(PowerType type);
}; 


#endif