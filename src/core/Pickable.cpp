#include <iostream>
#include "Pickable.h"

Pickable::Pickable(PickableType type, int x, int y, int height, int width) : Entity(x, y, height, width)
{
    this->type = type;
    this->isHeld = false;
}


PickableType Pickable:: getType()
{
    return type;
}

void Pickable:: toggleHeld()
{
    isHeld = !isHeld;
}

bool Pickable:: getHeld()
{
    return isHeld;
}

void Pickable:: update(const Level& currentLevel)
{
    // Do nothing
}