#ifndef _RECEPTACLE_H
#define _RECEPTACLE_H

#include "Enum.h"
#include "Pickable.h"
#include "Block.h"
#include "Player.h"

class Level;

class Receptacle : public Block
{
    private :
        Pickable * heldItem;
    public :
        Receptacle(int x, int y, BlockType type = RECEPTACLE);
        bool isSolid();
        void power(PowerType type, const Level& currentLevel);
        void update(const Player& p0,const Player& p1, Level& currentLevel);
}; 


#endif