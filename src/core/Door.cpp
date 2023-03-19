#include "Door.h"
#include "Level.h"
#include "Enum.h"
#include "Vector2D.h"
#include <math.h>

Door::Door(int x, int y,DoorType doorType, std::vector<Vector2D*> input, std::vector<Vector2D*> output, BlockType type) : Block( x, y, type)
{
    this->doorType = doorType;
    this->input = input;
    this->output = output;
}

bool Door::isSolid()
{
    return false;
}


void Door::update(const Player& p0,const Player& p1, Level& currentLevel)
{
        
}