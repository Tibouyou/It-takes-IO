#ifndef _TRAP_H
#define _TRAP_H

#include "Block.h"
#include "Player.h"


class Trap : public Block
{
    public :
        bool isSolid();
        void update(const Player& p0,const Player& p1);
        void power(PowerType type);
}; 


#endif