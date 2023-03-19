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
        Pickable * getHeldItem();
        void setHeldItem(Pickable * item);
        void power(PowerType type, const Level& currentLevel);
}; 


#endif