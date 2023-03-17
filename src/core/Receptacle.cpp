#include "Receptacle.h"
#include "Level.h"


Receptacle::Receptacle(int x, int y, BlockType type) : Block(x, y, type)
{
    heldItem = nullptr;
}

bool Receptacle::isSolid()
{
    return false;
}

void Receptacle::power(PowerType type, const Level& currentLevel)
{    
    if (heldItem != nullptr)
    {
        if (heldItem->getType() == NON)
        {
            if (type == ZERO)
            {
                currentLevel.getCable(tileX + 1, tileY)->power(ONE, 0b1000);
            }
            else if (type == ONE)
            {
                currentLevel.getCable(tileX + 1, tileY)->power(ZERO, 0b1000);
            }
        
        }
    }
}

void Receptacle::update(const Player& p0,const Player& p1, Level& currentLevel)
{
}