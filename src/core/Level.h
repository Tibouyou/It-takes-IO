#ifndef _LEVEL_H
#define _LEVEL_H

#include "Pickable.h"
#include "Player.h"
#include "Block.h"
#include "Cable.h"
#include "Entity.h"
#include <vector>
#include "Receptacle.h"
#include "Gate.h"

class Level
{
    private :
        Player * p0;
        Player * p1;
        std::vector<Block*> tabBlock;
        //std::vector<Gate*> tabGate;
        std::vector<Cable*> tabCable;
        std::vector<Pickable*> tabPickable;
        int levelNumber;
        int height;
        int width;

    public :
        std::vector<Gate*> tabGate;
        Level(int levelNumber);
        ~Level();
        int getHeight() const;
        int getWidth() const;
        void loadLevel();
        void resetLevel();
        void update();
        std::vector<Pickable*> getPickable() const;
        Block * getBlock(int x, int y) const;
        Cable * getCable(int x, int y) const;
        Player * getPlayer0() const;
        Player * getPlayer1() const;
}; 


#endif
