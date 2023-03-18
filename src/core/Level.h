#ifndef _LEVEL_H
#define _LEVEL_H

#include "Player.h"
#include "Block.h"
#include "Cable.h"
#include "Entity.h"
#include <vector>

class Level
{
    private :
        Player * p0;
        Player * p1;
        std::vector<Block*> tabBlock;
        //std::vector<Cable*> tabCable;
        std::vector<Entity*> tabEntity;
        int levelNumber;
        int height;
        int width;

    public :
        std::vector<Cable*> tabCable;
        Level(int levelNumber);
        ~Level();
        int getHeight() const;
        int getWidth() const;
        void loadLevel();
        void resetLevel();
        void update();
        Block * getBlock(int x, int y) const;
        Cable * getCable(int x, int y) const;
        Player * getPlayer0() const;
        Player * getPlayer1() const;
}; 


#endif
