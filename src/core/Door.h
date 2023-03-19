#ifndef _DOOR_H
#define _DOOR_H

#include "Enum.h"
#include "Block.h"
#include "Player.h"

class Level;

class Door : public Block
{
    private :
        bool open;
    public :
        Door(int x, int y, BlockType type = DOOR);
        bool isSolid();
        bool isOpen();
        void setOpen();
        void update(Player& p0, Player& p1, Level& currentLevel);
};

#endif