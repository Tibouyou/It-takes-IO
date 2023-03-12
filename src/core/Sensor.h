#ifndef _SENSOR_H
#define _SENSOR_H

#include "Block.h"
#include "Player.h"

class Level;

class Sensor : public Block
{
    public :
        bool isSolid();
        void update(const Player& p0,const Player& p1, Level& currentLevel);
}; 


#endif