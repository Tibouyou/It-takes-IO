#ifndef _DOOR_H
#define _DOOR_H

#include "Block.h"
#include "Enum.h"
#include "Player.h"
#include <vector>
#include "Cable.h"
#include "Vector2D.h"

class Level;

class Door : public Block
{
    private : 
        std::vector<Vector2D*> input;
        std::vector<Vector2D*> output;
        DoorType doorType;
    public :
        Door(int x, int y,DoorType doorType,std::vector<Vector2D*> input, std::vector<Vector2D*> output, BlockType type = DOOR);
        bool isSolid();
        void update(const Player& p0,const Player& p1, Level& currentLevel);
}; 


#endif