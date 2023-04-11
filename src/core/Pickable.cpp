#include <iostream>
#include "Pickable.h"

Pickable::Pickable(PickableType type, int x, int y, int height, int width, int spriteSize) : Entity(x, y, height, width, spriteSize)
{
    this->type = type;
    this->isHeld = false;
}

Pickable::~Pickable()
{
}

void Pickable::update(const Level& currentLevel, float elapsed)
{
}

PickableType Pickable::getType()
{
    return type;
}

void Pickable::toggleHeld()
{
    isHeld = !isHeld;
}

bool Pickable::getHeld()
{
    return isHeld;
}
