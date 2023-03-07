#ifndef _RECEPTACLE_H
#define _RECEPTACLE_H

#include "Enum.h"
#include "Pickable.h"

class Receptacle : public Block
{
    private :
        Pickable * heldItem;
    public :
        Receptacle(int x, int y);
        bool isSolid();
        void power(PowerType type);
        void update(const player& p0,const player& p1, const Level& level);
}; 


#endif