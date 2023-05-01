#include "Receptacle.h"
#include "Enum.h"
#include "Level.h"

Receptacle::Receptacle(int x, int y, BlockType type) : Block(x, y, type)
{
    heldItem = nullptr;
}

bool Receptacle::isSolid()
{
    return false;
}

void Receptacle::power(PowerType type, const Level& currentLevel, unsigned char directionMask)
{    
    if (heldItem != nullptr)
    {
        if (heldItem->getType() == NON)
        {
            PowerType toSend;
            if (type == ZERO)
            {
                toSend = ONE;
            }
            else if (type == ONE)
            {
                toSend = ZERO;
            }
            if (directionMask & PowerDirection::LEFT)
            {
                if (heldItem->getDirection()) {
                    currentLevel.getCable(tileX + 1, tileY)->power(toSend, PowerDirection::LEFT, currentLevel);
                } else currentLevel.getCable(tileX + 1, tileY)->power(EMPTY, PowerDirection::LEFT, currentLevel);
            }
            if (directionMask & PowerDirection::RIGHT)
            {
                if (!heldItem->getDirection()) {
                    currentLevel.getCable(tileX - 1, tileY)->power(toSend, PowerDirection::RIGHT, currentLevel);
                } else currentLevel.getCable(tileX - 1, tileY)->power(EMPTY, PowerDirection::RIGHT, currentLevel);
            }
            if (directionMask & PowerDirection::UP)
            {
                currentLevel.getCable(tileX, tileY + 1)->power(toSend, PowerDirection::UP, currentLevel);
            }
            if (directionMask & PowerDirection::DOWN)
            {
                currentLevel.getCable(tileX, tileY - 1)->power(toSend, PowerDirection::DOWN, currentLevel);
            }
        }
    }
}

void Receptacle::setHeldItem(Pickable * item)
{
    heldItem = item;
}

Pickable * Receptacle::getHeldItem()
{
    return heldItem;
}

void Receptacle::reset()
{
    heldItem = nullptr;
}