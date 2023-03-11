#ifndef _TRAP_H
#define _TRAP_H

#include "Block.h"
#include "Player.h"


class Trap : public Block
{
    public :
        bool isSolid();
        void update(Player& p0,Player& p1);
        void power(PowerType type);
}; 


#endif