#ifndef _SENSOR_H
#define _SENSOR_H

class Sensor : public Block
{
    public :
        bool isSolid();
        void update(const player& p0,const player& p1, const Level& level);
}; 


#endif