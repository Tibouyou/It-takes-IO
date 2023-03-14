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
        Block * tabBlock;
        Cable * tabCable;
        std::vector<Entity> tabEntity;
        int levelNumber;
        int height;
        int width;

    public :
        Level(int levelNumber,int height,int width);
        ~Level();
        int getHeight() const;
        int getWidth() const;
        void loadLevel();
        void resetLevel();
        Block & getBlock(int x, int y) const;
        Cable & getCable(int x, int y) const;
        Player * getPlayer0();
        Player * getPlayer1();
}; 


#endif
