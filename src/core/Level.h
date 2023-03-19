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
#include "Door.h"

class Level
{
    private :
        Player * p0;
        Player * p1;
        Door * door;
        std::vector<Block*> tabBlock;
        std::vector<Gate*> tabGate;
        std::vector<Cable*> tabCable;
        std::vector<Pickable*> tabPickable;
        int levelNumber;
        int height;
        int width;
        bool isWon;

    public :
        Level(int levelNumber);
        ~Level();
        int getHeight() const;
        int getWidth() const;
        void loadLevel();
        void resetLevel();
        void update();
        void win();
        bool getWin() const;
        std::vector<Gate*> getGate() const;
        std::vector<Pickable*> getPickable() const;
        Block * getBlock(int x, int y) const;
        Cable * getCable(int x, int y) const;
        Player * getPlayer0() const;
        Player * getPlayer1() const;
        Door * getDoor() const;
}; 


#endif
