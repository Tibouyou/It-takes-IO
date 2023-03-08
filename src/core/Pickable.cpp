#include <iostream>
#include "Pickable.h"

Pickable:: Pickable (PickableType type, int x, int y, int height, int width)
{
    this->type = type;
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
}


PickableType Pickable:: getType()
{
    return type;
}

void Pickable:: setHeld()
{
    held = !held;
}

bool Pickable:: getHeld()
{
    return held;
}

void Pickable:: update(const Level& currentLevel)
{
    // Do nothing
}